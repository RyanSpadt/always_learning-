#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BSTree {
private:

	// Sub-class to represent nodes within the tree
	class node {
	public:
		string data;
		node* left;
		node* right;
		node() { left = right = nullptr; }
	};

	// Pointer to the root node, initially NULL
	node* root;

	// Finds a node in a given subtree. Returns true/false to indicate if
	//	node with given string is in the subtree.
	bool find(const string& s, node* p) const;

	// Inserts a new node into the subtree at the given pointer.
	void insert(const string& s, node* p);

	// Performs an inorder traversal of the subtree at node p. For each node
	//	prints the string stored at that node.
	void print_inorder(node* p) const;

	// Perform a preorder traversal of the subtree at node p, also given the
	//	depth at node p. For each node, prints the string stored at the node
	//	with prefix showing the depth.
	void print_preorder(node* p, size_t depth) const;

public:

	// Constructor - Sets the root node to NULL
	BSTree() { root = nullptr; }

	// Find a string in the tree. Returns true/false to indicate if the given
	//	string is in the tree.
	bool find(const string& s) const;

	// Inserts a string into the tree. If the string already exists in the
	//	tree, does nothing.
	void insert(const string& s);

	// Perform an inorder traversal on the tree. The traversal simply prints
	//	the string stored at each node.
	void print_inorder() const { print_inorder(root); }

	// Perform a preorder traversal, printing strings stored at each node
	//	while showing tree structure.
	void print_preorder() const { print_preorder(root, 0); }

	// Returns the height of the tree (longest path from root to a leaf
	size_t height(node* p) const { if (root == NULL) return 0; else return max(p->left ? 1 + height(p->left) : 0, p->right ? 1 + height(p->right) : 0); }

	// blank parameter for calling main function
	void height() const { cout << height(root); }

	// Returns the number of leaf nodes in the tree
	size_t leaves(node* p) const;

	void leaves() const { cout << leaves(root); }

	// Returns the string stored in the parent node of the node with the
	//	given string. If the given string does not exist in the tree, or
	//	exists in the root, returns an empty string.
	string parent(const string& s, node* p) const;

	void parent(const string& s) const { cout << parent(s, root); }

	// Returns the string stored in the sibling node of the node with the
	//	given string. If the given string does not exist in the tree, or
	//	exists in a node that has no sibling node, returns an empty string.
	string sibling(const string& s, node* p) const;

	void sibling(const string& s) const { cout << sibling(s, root); }
};