//****************************************************************************************************
//
//      File:                Stock.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #3
//
//      Course Name:         Data Structures II
//
//      Course Number:       COSC 3100 - 11
//
//      Due:                 November 10, 2020
//
//
//      This program creates a tree with random items and tests out the different
//		functions in the binary tree class. Then it imports a list of 20 stocks
//		from a file into a binary tree. Then, it gives the user the option to
//		search for a stock by it's symbol to find either the price or the name
//		of the stock. It also allows the user to insert another stock into the
//		tree. Finally, it allows the user to quit the program.
//
//      Other files required:
//		    1.    BinarySearchTree.cpp - contains the main function
//			2.	  BinarySearchTree.h - Contains the BinarySearchTree class
//			3.	  Stock.h - Contains the Stock structure
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename T>
struct Node
{
	T info;
	Node<T>* left;
	Node<T>* right;
};

//****************************************************************************************************

#endif NODE_H