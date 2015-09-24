// File: AVLNode.h
// Author: Patrick Rek
// Date : Spring 2014 
// Last Updated by: Patrick Rek 24/09/15
// Description: Class for constructing nodes specific to the AVL tree.

#pragma once

#ifndef _AVLNode
#define _AVLNode

template <typename T>
class AVLNode
{
	public:
		T data;
		int dataWeight;
		int depth;

		AVLNode()
		{
			depth = 0;
		}

		AVLNode*left;
		AVLNode*right;
};
#endif