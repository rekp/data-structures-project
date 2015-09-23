#include "AVLNode.h"
#include <iomanip> 
#include <algorithm> 

#ifndef _myAVLTree
#define _myAVLTree

template <typename T>
class myAVLTree
{
	public:
		myAVLTree()
		{
			root = new AVLNode<T>;
			root -> dataWeight = 0;
			root -> left = NULL;
			root -> right = NULL;

			addDepth = 0;
			treeDepth = 0;
			dataCount = 0;
		}

		void add(T a);
		void print();
		int getDepth();
		int getDataCount();
		void findLeaves();
		T find(T x);
		T searchTree(T x, AVLNode<T> *n);

	private:
		AVLNode<T> *root;
		int addDepth;
		int treeDepth;
		int dataCount;

		void insert(T a, AVLNode<T>*& node);
		void addLeft(T c, AVLNode<T>*& node, int addWeight);
		void addRight(T c, AVLNode<T>*& node, int addWeight);
		int weightCalc(T f);
		void rotateLeftOnce(AVLNode<T>*& node);
		void rotateLeftTwice(AVLNode<T>*& node);
		void rotateRightOnce(AVLNode<T>*& node);
		void rotateRightTwice(AVLNode<T>*& node);
		int height(AVLNode<T> *n);	
		void printTree(AVLNode<T> *n, int indent = 0);
		int max( int lhs, int rhs ) const;
		void leafSearch(AVLNode<T> *n);
};
#endif

template <typename T>
void myAVLTree<T>::add(T b)
{
	insert(b, root);
}

template <typename T>
void myAVLTree<T>::insert(T b, AVLNode<T>*& node)
{
	int addWeight = weightCalc(b);
	
	if (node -> dataWeight == 0)
	{
		node -> data = b;
		node -> dataWeight = addWeight;
		node -> left = NULL;
		node -> right = NULL;

		dataCount++;
	}
	else if (addWeight < node -> dataWeight) // Move Left
	{
		addLeft(b, node -> left, addWeight); // drops into similar recursive method duo
	}
	else if (addWeight > node -> dataWeight && b != node -> data) // Move Right, Reason for &&: Some data may have the same weight but are not duplicates
	{
		addRight(b, node -> right, addWeight); // drops into similar recursive method duo

		if(height(node -> right) - height(node -> left) == 2)
		{
            if(node -> right -> dataWeight < addWeight)
                rotateRightOnce(node);
            else
                rotateRightTwice(node);
		}
	}
	else;
	node->depth = max( height( node->left ), height( node->right ) ) + 1;
}

template <typename T>
void myAVLTree<T>::addLeft(T c, AVLNode<T>*& node, int addWeight)
{
	addDepth++;
	
	if (node == NULL)
	{
		node  = new AVLNode<T>;
		node -> data = c;
		node -> dataWeight = addWeight;
		node -> left = NULL;
		node -> right = NULL;
		
		if(addDepth > treeDepth)
			treeDepth = addDepth;

		addDepth = 0; // reset addDepth
		dataCount++;
	}
	if (addWeight < node -> dataWeight) // Move Left
	{
		addLeft(c, node -> left, addWeight);
	}
	else if (addWeight >= node -> dataWeight && c != node -> data) // Move Right, Reason for &&: Some data may have the same weight but are not duplicates
	{
		addRight(c ,node -> right, addWeight);
	}
	if(height(node -> left) - height(node -> right) == 2) // balance check
	{
		if(addWeight < node -> dataWeight)
			rotateLeftOnce(node);
        else
            rotateLeftTwice(node);
	}
	else;
	node->depth = max( height( node->left ), height( node->right ) ) + 1;
}

template <typename T>
void myAVLTree<T>::addRight(T d, AVLNode<T>*& node, int addWeight)
{
	addDepth++;

	if (node == NULL)
	{
		node = new AVLNode<T>;
		node -> data = d;
		node -> dataWeight = addWeight;	
		node -> left = NULL;
		node -> right = NULL;

		if (addDepth > treeDepth)
			treeDepth = addDepth;

		addDepth = 0; // reset addDepth
		dataCount++;
	}
	if (addWeight < node -> dataWeight) // Move Left
	{
		addLeft(d, node -> left, addWeight);
	}
	else if (addWeight >= node -> dataWeight && d != node -> data) // Move Right, Reason for &&: Some data may have the same weight but are not duplicates
	{
		addRight(d, node -> right, addWeight);
	}
	if (height(node -> right) - height (node -> left) == 2)// balance check
	{
		if (node -> right -> dataWeight < addWeight)
			rotateRightOnce(node);
		else
			rotateRightTwice(node);
	}
	else;
	node->depth = max( height( node->left ), height( node->right ) ) + 1;
}

template <typename T>
int myAVLTree<T>::weightCalc(T f)
{
	int weightKey = 0;
    for (unsigned int i = 0; i < f.length();  i++)
    {
      weightKey = weightKey + f[i] + f.length();
	}
    return weightKey;
}

template <typename T>
void myAVLTree<T>::rotateLeftOnce(AVLNode<T>*& node)
{
	if(node != NULL && node -> left !=NULL) // Used to catch the "ghost in the machine" (access violation during large amount of tree inserts)
	{
		AVLNode<T> *otherNode = node -> left;

		node -> left = otherNode -> right;
		otherNode -> right = node;

		node -> depth = max (height (node -> left), height (node -> right)) + 1;
		otherNode -> depth = max (height(otherNode -> left), node -> depth) + 1;

		node = otherNode;
	}
	else
	;
}

template <typename T>
void myAVLTree<T>::rotateLeftTwice(AVLNode<T>*& node)
{
     rotateRightOnce (node -> left);
     rotateLeftOnce (node);
}

template <typename T>
void myAVLTree<T>::rotateRightOnce(AVLNode<T>*& node)
{
    AVLNode<T> *otherNode = node -> right;

    node -> right = otherNode -> left;
    otherNode -> left = node;

	node -> depth = max (height (node -> left), height (node -> right)) + 1;
    otherNode -> depth = max (height (otherNode -> right), node -> depth) + 1;

    node = otherNode;
}

template <typename T>
void myAVLTree<T>::rotateRightTwice(AVLNode<T>*& node)
{
     rotateLeftOnce (node -> right);
     rotateRightOnce (node);
}

template <typename T>
int myAVLTree<T>::getDepth()
{
	return treeDepth;
}

template <typename T>
int myAVLTree<T>::getDataCount()
{
	return dataCount;
}

template <typename T>
void myAVLTree<T>::print()
{
   printTree (root);
}

template <typename T>
void myAVLTree<T>::printTree(AVLNode<T> *n, int indent = 0) // mildy confusing print
{
	if (n != NULL)
	{
	   std::cout <<"     ["<< n -> data << "]" /*<<": "<< n -> dataWeight*/ << std::endl;
       if (n -> left) printTree (n -> left, indent+4);
       if (n -> right) printTree (n -> right, indent+4);
	   if (indent)
	   {
		   std::cout << std::setw (indent) << ' ';
	   }
   }
   else
   {
	   std::cout << "Tree is empty" << std::endl;
	   return;
   }	
}

template <typename T>
int myAVLTree<T>::height(AVLNode<T> *n)
{
	if (n == NULL)
		return -1;
	else
		return n -> depth;
}

template <typename T>
int myAVLTree<T>::max(int lhs,int rhs) const
{
    if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

template <typename T>
void myAVLTree<T>::findLeaves()
{
   leafSearch(root);
}

template <typename T>
void myAVLTree<T>::leafSearch(AVLNode<T> *n)
{
    if (n != NULL)
    {
		leafSearch(n -> left);
		if (n -> left == NULL && n -> right == NULL)
			std::cout <<"       " << n -> data << std::endl;
		leafSearch(n -> right);
    }
}

template <typename T>
T myAVLTree<T>::find(T x)
{
	return (searchTree(x, root));
}

template <typename T>
T myAVLTree<T>::searchTree(T x, AVLNode<T> *n)
{
	 while( n != NULL )
     if( weightCalc(x) < n -> dataWeight )
		n = n -> left;
      else if( n -> dataWeight < weightCalc(x) )
		n = n -> right;
      else
		return x;    // Match

       return "NULL-999";   // No match
}