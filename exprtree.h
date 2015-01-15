/*
 * exprtree.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef EXPRTREE_H_
#define EXPRTREE_H_

#include "bintree.cpp"
#include "lstack.cpp"
#include "atomtype.h"


class AtomicExpressionToken;
class AtomicExpression;

typedef TreeNode<AtomicExpressionToken*> ExpressionTreeNode;

class ExpressionTreeIterator: public BinaryTreeIterator<AtomicExpressionToken*>
{
public:
	ExpressionTreeIterator(ExpressionTreeNode* _ptr = NULL): BinaryTreeIterator<AtomicExpressionToken*>(_ptr) {}

	AtomicExpressionToken& operator*();
};

class ExpressionTree: public BinaryTree<AtomicExpressionToken*>
{
	void deleteNode(ExpressionTreeNode* node);
	ExpressionTreeNode* copyNode(ExpressionTreeNode* src);

public:
	ExpressionTree(): BinaryTree<AtomicExpressionToken*>() {}
	ExpressionTree(const AtomicExpressionToken&);
	ExpressionTree(const AtomicExpressionToken&, ExpressionTree&, ExpressionTree&);
	ExpressionTree(const ExpressionTree&);
	ExpressionTree& operator=(const ExpressionTree&);
	~ExpressionTree();

	ExpressionTreeIterator iterator() const { return ExpressionTreeIterator(root); }
};

void createTree(LinkedStack<ExpressionTree>&, char);
ExpressionTree createExpressionTree(char const*&);
AtomicExpression evaluate(ExpressionTreeIterator, ATOM_TYPE);


#endif /* EXPRTREE_H_ */
