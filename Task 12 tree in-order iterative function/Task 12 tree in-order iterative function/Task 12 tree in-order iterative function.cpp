#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include<vector>

using namespace std;


class BinTreeNode
{
public:
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	BinTreeNode* left;
	BinTreeNode* right;
};

BinTreeNode* tree_insert(BinTreeNode* tree, int item)
{
	if (tree == NULL)
		tree = new BinTreeNode(item);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item);
			else
				tree_insert(tree->right, item);
	return tree;
}

void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	cout << tree->value << endl;
}

void in_order(BinTreeNode* tree)
{
	BinTreeNode* currentNode = tree;
	stack<BinTreeNode*> myStack;   // creates stack of nodes
	bool finished = false;         // sets to true when finished
	while (!finished)
	{
		if (currentNode != NULL)  // navigates tree as long as the current node is not empty
		{
			myStack.push(currentNode);        //adds current node to stack
			currentNode = currentNode->left;  //gives the current node the value of the left child node
		}
		else if (currentNode == NULL && !myStack.empty())    // check if we reached bottom of tree while navigating all the left child nodes 
			{
				currentNode = myStack.top();   //sets current node to the top value of the stack once the current node reaches bottom of tree(eccounters a NULL node)
				cout << currentNode->value;    //prints current node(first prints all left children)
				currentNode = currentNode->right;  //gives the current node the value of the right child
				myStack.pop();
			}
			else
			{
				finished = true;
			}
		}
	}

	void tree_Sort(vector<int> values)
	{
		BinTreeNode* tree = tree_insert(0, values[0]);
		for (int value = 1; value < values.size(); value++)
		{
			tree_insert(tree, values[value]);
		}
		in_order(tree);
		cout << endl;
	}


	int main(int argc, char *argv[])
	{
		BinTreeNode* t = tree_insert(0, 6);
		tree_insert(t, 10);
		tree_insert(t, 5);
		tree_insert(t, 2);
		tree_insert(t, 3);
		tree_insert(t, 4);
		tree_insert(t, 11);
		in_order(t);
		cout << endl;

		vector<int> values = { 6,10,5,2,3,4,11 };

		tree_Sort(values);

		return 0;
	}
