// File: myLinkedList.h
// Author: Patrick Rek
// Date : Spring 2014 
// Last Updated by: Patrick Rek 24/09/15
// Description: My linked list class modified for AVL Tree.

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "stdafx.h"

#ifndef _myLinkedList
#define _myLinkedList

template <typename T>
class myLinkedList
{
	public:
		Node<T> *front; 
		Node<T> *curs;
		Node<T> *elementTemp;
		int listCount;

		myLinkedList()
		{
			front = new Node<T>;
			curs = front;
			elementTemp = front;
			listCount = 1;
		}

		void add(T a);
		T returnElement(); // Will traverse list one element at a time until exhausted, then resets to the beginning
		T lookElement(); // Glances at current element from returnElement()
		void readTxtByWord(std::string txt);
		void readTxtByChar(std::string txt);
		void seqSearch(T c);
		int getListCount();
};
#endif

template <typename T>
myLinkedList<T> operator+(myLinkedList<T>& ll, T& a)
{
	ll.curs->data = a;
	ll.curs->next = new Node<T>;
	ll.curs = ll.curs->next;
}

template <typename T>
std::ostream& operator << (std::ostream& os, myLinkedList<T>& ls)
{
	Node<T> *temp; 
	temp = ls.front;

	if(ls.front == NULL)
	{
		std::cout << "List is empty" << std::endl;
	}
	while (temp != NULL)
	{
		os << "[" << temp->data << "]" << std::endl;
		temp = temp->next;
	}
	return os;
}

template <typename T>
void myLinkedList<T>::add(T b)
{
	Node<T> *tempCheck;
	tempCheck = front;

	while(tempCheck -> next != NULL) // checking for duplicates
	{
		if(tempCheck -> data == b)
			return;

		tempCheck = tempCheck -> next;
	}

	curs->data = b;
	curs->next = new Node<T>;
	curs = curs->next;
	listCount ++;
}

template <typename T>
T myLinkedList<T>::returnElement()
{
	T element;

	if (elementTemp -> next == NULL) // resets the method once the list has been completely traversed.
	{
		elementTemp = front;
	}
	if(elementTemp == NULL)
	{
		return "NULL NULL NULL";
	}
	while (elementTemp != NULL)
	{
		element = elementTemp->data;
		elementTemp = elementTemp->next;
		return element;
	}
}

template <typename T>
T myLinkedList<T>::lookElement()
{
	Node<T> *temp;
	temp = elementTemp;
	
	return temp->data;
}

template <typename T>
void myLinkedList<T>::readTxtByWord(std::string txt)
{
	std::fstream infile(txt);
	std::cout << "Reading File By Word, please wait... " << std::endl;
	std::string s;
	std::size_t found;
	infile >> std::ws;
	while (!infile.eof())
	{
		getline(infile,s,' '); 
		found = s.find_first_of(' '); // appears to do nothing
		if (found!=std::string::npos)
			s.erase (found, s.length());
		add(s);
	}
	infile.close();
}

template <typename T>
void myLinkedList<T>::readTxtByChar(std::string txt)
{
	std::fstream infile(txt);
	std::stringstream ss;
	std::cout << "Reading file by letter, please wait... \n" << std::endl;
	std::string s;
	char c;
	infile >> std::ws;
	while (!infile.eof())
	{
		infile.get(c);
		ss << c;
		ss >> s;
		ss.clear();
		//std::string s = std::string(c); This doesn't work to convert char to string. Why?
		add(s);
	}
	infile.close();
}

template <typename T>
void myLinkedList<T>::seqSearch(T c)
{
	int position = 0;
	Node<T> *temp; 
	temp = front;
	
	if(front == NULL)
	{
		std::cout << "List is empty" << std::endl;
		
	}
	while (temp != NULL)
	{
		if(temp->data == c)
		{
			std::cout << "First instance of " << c << " found at position: " << position << std::endl;
			break;
		}
		else if(temp->next == NULL)
		{
			std::cout << "No instance of " << c << " found." << std::endl;
			break;
		}
		temp = temp->next;
		position++;
	}
}

template <typename T>
int myLinkedList<T>::getListCount()
{
	return listCount;
}