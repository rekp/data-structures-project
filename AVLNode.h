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