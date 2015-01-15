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
#include "atom.h"
#include "token.h"


typedef TreeNode<Token*> ExpressionTreeNode;
typedef BinaryTreeIterator<Token*> ExpressionTreeIterator;

class ExpressionTree: public BinaryTree<Token*>
{
	void deleteNode(ExpressionTreeNode* node);
	ExpressionTreeNode* copyNode(ExpressionTreeNode* src);

public:
	ExpressionTree(): BinaryTree<Token*>() {}
	ExpressionTree(const Token*);
	ExpressionTree(const Token*, ExpressionTree&, ExpressionTree&);
	ExpressionTree(const ExpressionTree&);
	ExpressionTree& operator=(const ExpressionTree&);
	~ExpressionTree();

	ExpressionTreeIterator iterator() const { return ExpressionTreeIterator(root); }
};

void createTree(LinkedStack<ExpressionTree>&, char);
ExpressionTree createExpressionTree(char const*&);
AtomicExpression* evaluate(ExpressionTreeIterator, ATOM_TYPE);


#endif /* EXPRTREE_H_ */
