/*
    Binary Search Tree Program
    Author: Ryan Spadt
    Revisions: 1.1
    Date 7 November 2020
*/

#include <iostream>
#include "BSTree.h"


int main()
{
	BSTree tree;
	string s;

	cout << "Enter strings to insert into the binary search tree.\n";
	cout << "When finished, press ENTER.\n\n";
	cout << "> ";
	getline(cin, s);
	while (s.size()) {
		tree.insert(s);
		cout << "> ";
		getline(cin, s);
	}

	cout << "\nAn inorder traversal:\n";
	tree.print_inorder();

	cout << "\nA preorder traversal:\n";
	tree.print_preorder();

	cout << "\nThe height:\n";
	tree.height();

	cout << "\nThe leaves:\n";
	tree.leaves();

	cout << "\nEnter a string to find it's parent\n";
	getline(cin, s);
	cout << "\nThe parent of the string entered is\n";
	tree.parent(s);
	cout << "\nThe sibling of the string entered is\n";
	tree.sibling(s);

	return 0;
}