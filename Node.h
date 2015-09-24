// File: Node.h
// Author: Patrick Rek
// Date : Spring 2014 
// Last Updated by: Patrick Rek 24/09/15
// Description: Class for nodes, specificly pairs with myLinkedList.h

#pragma once

#ifndef _Node
#define _Node

template <typename T>
class Node
{
	public:
		T data;
		Node*next;
};
#endif