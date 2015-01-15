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
#include "token.h"
#include "value.h"


typedef TreeNode<Token*> ExpressionTreeNode;
typedef BinaryTreeIterator<Token*> ExpressionTreeIterator;

class ExpressionTree: public BinaryTree<Token*>
{
	static void createTree(LinkedStack<ExpressionTree>&, char);

	void deleteNode(ExpressionTreeNode* node);
	ExpressionTreeNode* copyNode(ExpressionTreeNode* src);

public:
	static ExpressionTree createExpressionTree(char const*&);

	ExpressionTree(): BinaryTree<Token*>() {}
	ExpressionTree(const Token*);
	ExpressionTree(const Token*, ExpressionTree&, ExpressionTree&);
	ExpressionTree(const ExpressionTree&);
	ExpressionTree& operator=(const ExpressionTree&);
	~ExpressionTree();

	ExpressionTreeIterator iterator() const { return ExpressionTreeIterator(root); }
	Value* evaluate();
};


#endif /* EXPRTREE_H_ */
