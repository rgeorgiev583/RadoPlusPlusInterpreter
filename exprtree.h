/*
 * exprtree.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef EXPRTREE_H_
#define EXPRTREE_H_

#include "lstack.cpp"
#include "token.h"
#include "value.h"
#include "identifier.h"
#include "environment.h"
#include <map>


struct ExpressionTreeNode
{
	Token* value;
	ExpressionTreeNode *left, *right;

	ExpressionTreeNode(Token* _value = NULL, bool doClone = false,
					   ExpressionTreeNode* _left = NULL, ExpressionTreeNode* _right = NULL):
			value(doClone ? _value->clone() : _value), left(_left), right(_right) {}
	ExpressionTreeNode(const ExpressionTreeNode& other);
	ExpressionTreeNode& operator=(const ExpressionTreeNode& other);
	~ExpressionTreeNode();

private:
	void copy(const ExpressionTreeNode& other);
	void destroy();
};

class ExpressionTreeConstIterator
{
	ExpressionTreeNode* ptr;

public:
	ExpressionTreeConstIterator(ExpressionTreeNode* _ptr = NULL): ptr(_ptr) {}

	const Token* operator*() const { return ptr ? ptr->value : NULL; }
	ExpressionTreeConstIterator operator++() const { return ptr ? ExpressionTreeConstIterator(ptr->left) : *this; }
	ExpressionTreeConstIterator operator++(int) const { return ptr ? ExpressionTreeConstIterator(ptr->right) : *this; }
	operator bool() const { return ptr; }
};

class ExpressionTreeIterator
{
	ExpressionTreeNode* ptr;

public:
	ExpressionTreeIterator(ExpressionTreeNode* _ptr = NULL): ptr(_ptr) {}

	const Token* operator*() const { return ptr ? ptr->value : NULL; }
	Token* operator*() { return ptr ? ptr->value : NULL; }
	ExpressionTreeIterator operator++() const { return ptr ? ExpressionTreeIterator(ptr->left) : *this; }
	ExpressionTreeIterator operator++(int) const { return ptr ? ExpressionTreeIterator(ptr->right) : *this; }
	operator bool() const { return ptr; }
};

class ExpressionTree
{

	static void createTree(LinkedStack<ExpressionTree>&, char);
	static Value* evaluateExpression(ExpressionTreeConstIterator, Environment&);

	ExpressionTreeNode* root;

	void deleteNode(ExpressionTreeNode* node);
	ExpressionTreeNode* copyNode(ExpressionTreeNode* src);


	void adopt(ExpressionTreeNode*& newNode, ExpressionTreeNode*& oldNode) { newNode = oldNode; oldNode = NULL; }
	void adoptLeft(ExpressionTreeNode*& node) { adopt(root->left, node); }
	void adoptRight(ExpressionTreeNode*& node) { adopt(root->right, node); }

public:
	static ExpressionTree createExpressionTree(char const*&);

	ExpressionTree(): root(NULL) {}
	ExpressionTree(Token* value, bool doClone = false): root(new ExpressionTreeNode(value, doClone)) {}
	ExpressionTree(Token*, ExpressionTree&, ExpressionTree&, bool = false);
	ExpressionTree(const ExpressionTree&);
	ExpressionTree& operator=(const ExpressionTree&);
	~ExpressionTree();

	ExpressionTreeIterator getIterator() { return ExpressionTreeIterator(root); }
	ExpressionTreeConstIterator getConstIterator() const { return ExpressionTreeConstIterator(root); }

	Value* evaluate(Environment& environment) const { return evaluateExpression(getIterator(), environment); }
};


#endif /* EXPRTREE_H_ */
