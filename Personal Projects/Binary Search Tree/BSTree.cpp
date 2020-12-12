#include "BSTree.h"

// Finds a node in a given subtree. Returns true/false to indicate if
//	node with given string is in the subtree.
bool BSTree::find(const string& s, node* p) const {
	// Given: p is a pointer to an existing node
	if (s == p->data)
		return true;
	if (s < p->data)
		return p->left && find(s, p->left);
	return p->right && find(s, p->right);
}

// Inserts a new node into the subtree at the given pointer.
void BSTree::insert(const string& s, node* p) {
	// Given: p is a pointer to an existing node (root of a subtree)
	if (s < p->data) { // Insert into left subtree
		if (p->left) // Left subtree exists
			insert(s, p->left);
		else { // No left subtree, insert the new node
			p->left = new node;
			p->left->data = s;
		}
	}
	else if (s > p->data) { // Insert into right subtree
		if (p->right)
			insert(s, p->right);
		else {
			p->right = new node;
			p->right->data = s;
		}
	}
}

// Performs an inorder traversal of the subtree at node p. For each node
	//	prints the string stored at that node.
void BSTree::print_inorder(node* p) const {
	// Print all values in subtree, in order
	if (p) {
		print_inorder(p->left);
		cout << p->data << endl;
		print_inorder(p->right);
	}
}

// Perform a preorder traversal of the subtree at node p, also given the
//	depth at node p. For each node, prints the string stored at the node
//	with prefix showing the depth.
void BSTree::print_preorder(node* p, size_t depth) const {
	if (p) {
		for (size_t i = 0; i < depth; i++)
			cout << '-';
		cout << p->data << endl;
		print_preorder(p->left, depth + 1);
		print_preorder(p->right, depth + 1);
	}
}

// Find a string in the tree. Returns true/false to indicate if the given
	//	string is in the tree.
bool BSTree::find(const string& s) const {
	return root && find(s, root);
}

// Inserts a string into the tree. If the string already exists in the
//	tree, does nothing.
void BSTree::insert(const string& s) {
	// Is tree empty?
	if (!root) {
		root = new node;
		root->data = s;
	}
	else if (s < root->data) {
		// New node goes on left side of root
		if (root->left) // If there is a left subtree
			insert(s, root->left);
		else { // No left subtree, create node
			root->left = new node;
			root->left->data = s;
		}
	}
	else if (s > root->data) {
		if (root->right)
			insert(s, root->right);
		else {
			root->right = new node;
			root->right->data = s;
		}
	}
}

// Returns the number of leaf nodes in the tree
size_t BSTree::leaves(node* p) const
{
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 1;
	else
		return (leaves(p->left) + leaves(p->right));
}

// Returns the string stored in the parent node of the node with the
//	given string. If the given string does not exist in the tree, or
//	exists in the root, returns an empty string.
string BSTree::parent(const string& s, node* p) const
{
	if (find(s))
	{
		if (root == NULL)
			return " ";
		if (p->right != nullptr && p->right->data == s || p->left != nullptr && p->left->data == s)
			return p->data;
		else
		{
			if (s < p->data)
				return parent(s, p->left);
			return parent(s, p->right);
		}
	}
	else
		return " ";
}

// Returns the string stored in the sibling node of the node with the
//	given string. If the given string does not exist in the tree, or
//	exists in a node that has no sibling node, returns an empty string.
string BSTree::sibling(const string& s, node* p) const
{
	if (find(s))
	{
		if (root == NULL)
			return " ";
		if (p->right != nullptr && p->right->data == s && p->left != nullptr)
			return p->left->data;
		if (p->left != nullptr && p->left->data == s && p->right != nullptr)
			return p->right->data;
		if (p->right != nullptr && p->right->data == s && p->left == nullptr)
			return " ";
		if (p->left != nullptr && p->left->data == s && p->right == nullptr)
			return " ";
		else
		{
			if (s < p->data)
				return sibling(s, p->left);
			return sibling(s, p->right);
		}
	}
	else
		return " ";
}