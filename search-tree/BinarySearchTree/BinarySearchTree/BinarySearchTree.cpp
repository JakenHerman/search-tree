// BinarySearchTree.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;
#define Null 0
class BinarySearchTree {
private:

	struct Node
	{
		char aChar;
		struct Node *Left;
		struct Node *Right;
	};

	typedef struct Node *NodePtr;
	struct Node *Root;

	struct Node *NewNode(const char Char)
	{
		struct Node *Point;
		Point = new Node;
		Point->aChar = Char;
		Point->Left = Null;
		Point->Right = Null;
		return Point;
	}

	void InsertNode(const char NewChar, NodePtr & Pt) // CBR required
	{
		cout << NewChar << " in insert \n";
		if (Pt == Null)
		{
			cout << "insert first node " << NewChar << "\n";
			Pt = NewNode(NewChar); return;
		}

		if (NewChar < Pt->aChar)
			if (Pt->Left == 0)
				Pt->Left = NewNode(NewChar);
			else
				InsertNode(NewChar, Pt->Left);
		else if (NewChar > Pt->aChar)
			if (Pt->Right == 0)
				Pt->Right = NewNode(NewChar);
			else
				InsertNode(NewChar, Pt->Right);
		else
			cerr << "\n#### Insert: " << NewChar << "is already in the tree";
	}

	void PrtInOrder(NodePtr Pt) //CBV Required
	{
		if (Pt != Null)
		{
			if (Pt->Left != 0) PrtInOrder(Pt->Left);
			cout << "In Order traversal: " << Pt->aChar << "\n";
			if (Pt->Right != 0) PrtInOrder(Pt->Right);
		}
	}

public:
	BinarySearchTree() { Root = Null; }

	void Insert(const char NewChar) { InsertNode(NewChar, Root); }
	void InOrder() { PrtInOrder(Root); }

}; // End class definition

//#include BinarySearchTree;
void main()
{
	char Dummy;

	BinarySearchTree BSTree;

	BSTree.Insert('f'); BSTree.Insert('e');
	BSTree.Insert('b'); BSTree.Insert('d');
	BSTree.Insert('a'); BSTree.Insert('c');
	BSTree.Insert('g'); BSTree.Insert('z');
	BSTree.Insert('f');

	BSTree.InOrder();

	cin >> Dummy;
}