// File: AVLFinalProject.cpp
// Author: Patrick Rek
// Date : Spring 2014 
// Last Updated by: Patrick Rek 24/09/15
// Description: Main for AVLTree project.

#include "stdafx.h"
#include "myLinkedList.h"
#include "myAVLTree.h"
#include "myTime.h"
#include <math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string temp;
	std::string input = "";
	std::string result = "";
	std::string response = "";
	myLinkedList<std::string> decList;
	myAVLTree<std::string> tree;
	myTime tim;

	std::cout << "\n\n\n" << std::endl;


	std::cout << "********************************** STEP 1 **********************************\n" << std::endl;
	decList.readTxtByWord("Declaration.txt");

	for(int i = 0; i < decList.getListCount(); i++) // Add Declaration into tree
	{
		temp = decList.returnElement();
		tree.add(temp);
	}
	/*tree.add("a"); // Proof of concept test
	tree.add("bb");
	tree.add("ccc");
	tree.add("dddd");
	tree.add("eeeee");
	tree.add("ffffff");*/
	std::cout << "Elements Stored Within AVL: COMPLETE\n" << std::endl;


	std::cout << "\n\n\n********************************** STEP 2 **********************************\n" << std::endl;
	std::cout << "Report:" << std::endl;
	std::cout << "       Tree Depth: " << tree.getDepth() << std::endl;
	std::cout << "       Total Elements: " << tree.getDataCount() << "\n\n";


	std::cout << "\n\n\n********************************** STEP 3 **********************************\n" << std::endl;
	std::cout << "Searching for Leaves, please wait..." << std::endl;
	std::cout << "Leaves:" << std::endl;
	tree.findLeaves();
	do
	{
		std::cout << "\nWhat would you like to search for?: ";
		std::getline(std::cin,input);
		tim.markStart();
		result = tree.find(input);
		tim.markEnd();
		
		if (result != "NULL-999")
		{
			std::cout << "     -------" << input << " is within the tree." << "-------" << std::endl;
			std::cout << "     Log(depth) calculation of: Log(" << tree.getDepth() << ") is ";
			std::cout << log10(tree.getDepth());
			std::cout << "\n     While the search ";
			tim.markTotal(); 
			std::cout << std::endl;
		}
		else
			std::cout << "-------" << input << " Not found." << "-------\n" << std::endl;
	
		std::cout << "\nWould you like to search again? Y/N: " ;
		std::getline(std::cin,response);
		std::cout << std::endl;
		std::transform(response.begin(), response.end(),response.begin(), ::toupper);
	}while(response == "Y");


	std::cout << "\n\n\n********************************** STEP 4 **********************************\n" << std::endl;
	std::cout << "Rendering Confusing AVL Tree..." << std::endl;
	std::cout << std::endl;
	tree.print();
	std::cout << std::endl;


	std::cout << "*************************** Coded by Patrick Rek ***************************" << std::endl;

	return 0;
}

