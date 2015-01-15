/*
 * exprtree.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "exprtree.h"
#include "bintree.cpp"
#include "lstack.cpp"
#include "arithmetic.h"
#include "token.h"
#include <cstdlib>
#include <cstring>
#include <vector>


void ExpressionTree::deleteNode(ExpressionTreeNode* node)
{
	if (node != NULL)
	{
		delete node->data;
		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}
}

Token& ExpressionTreeIterator::operator*()
{
	return *ptr->data;
}

ExpressionTreeNode* ExpressionTree::copyNode(ExpressionTreeNode* src)
{
	if (src == NULL)
		return NULL;

	return new ExpressionTreeNode(new Token(*src->data), copyNode(src->left), copyNode(src->right));
}

ExpressionTree::ExpressionTree(const Token& data): BinaryTree<Token*>(new Token(data)) {}

ExpressionTree::ExpressionTree(const Token& data, ExpressionTree& left, ExpressionTree& right):
		BinaryTree<Token*>(new Token(data), left, right) {}

ExpressionTree::ExpressionTree(const ExpressionTree& other)
{
	root = copyNode(other.root);
}

ExpressionTree& ExpressionTree::operator=(const ExpressionTree& other)
{
	if (&other != this)
	{
		deleteNode(root);
		root = copyNode(other.root);
	}

	return *this;
}

ExpressionTree::~ExpressionTree()
{
	deleteNode(root);
}

void createTree(LinkedStack<ExpressionTree>& rstack, char op)
{
	ExpressionTree rtree = rstack.pop();
	ExpressionTree ltree = rstack.pop();
	rstack.push(ExpressionTree(Token(op), ltree, rtree));
}

ExpressionTree createExpressionTree(char const*& expr)
{
	LinkedStack<char> opstack;
	LinkedStack<ExpressionTree> rstack;

	if (!expr)
		return ExpressionTree();

	while (*expr && *expr != ';')
    {
		if (*expr >= '0' && *expr <= '9' || *expr == '-' && expr + 1 && *(expr + 1) >= '0' && *(expr + 1) <= '9')
			rstack.push(ExpressionTree(Token(expr, ATOM_INTEGER)));
		else if (*expr == '"')
			rstack.push(ExpressionTree(Token(expr, ATOM_STRING)));
		else if (*expr == '\\')
			rstack.push(ExpressionTree(Token(expr, ATOM_LAMBDA)));
		else if (*expr == '(')
			opstack.push(*expr);
		else if (*expr == ')')
        {
			char op = opstack.pop();

			while (op != '(') {
				createTree(rstack, op);
				op = opstack.pop();
			}
		}
        else if (*expr != ' ' && *expr != '\t' && *expr != '\n' && *expr != '\r')
        {
			// *expr е операция
			// първо: вадим всички операции
			// с по-висок или равен приоритет
			while (!opstack.empty() &&
				   priority(opstack.last()) >=
				   priority(*expr))
				createTree(rstack, opstack.pop());

			opstack.push(*expr);
		}

		expr++;
	}

	while (!opstack.empty())
		createTree(rstack, opstack.pop());

	return rstack.pop();
}
/*
AtomicExpression evaluate(ExpressionTreeIterator it, ATOM_TYPE type)
{
	if ((*it).getType() == TOKEN_VALUE)
		// листо
		return (*it).getInteger();
    else
        switch ((*it).getOperator())
        {
            case '+': return evaluate(++it) + evaluate(it++);
            case '-': return evaluate(++it) - evaluate(it++);
            case '*': return evaluate(++it) * evaluate(it++);
            case '/': return evaluate(++it) / evaluate(it++);
            case '^': return ipow(evaluate(++it), evaluate(it++));
            default: return 0;
        }
}
*/
