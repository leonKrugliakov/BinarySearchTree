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
//		    1.    Stock.h - contains the stock structure
//			2.	  BinarySearchTree.h - Contains the BinarySearchTree class
//			3.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "Stock.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

int main()
{
	BinarySearchTree<int> tree;
	srand(time(NULL));
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);
	tree.insert((rand() % 5000) + 1);

	cout << "Created a tree with ten random values from 1 to 5000." << endl
		<< "Displaying the values in inorder:" << endl;

	tree.inorder();
	cout << endl << endl
		<< "Displaying the values in postorder: " << endl;

	tree.postorder();
	cout << endl << endl
		<< "Displaying the values in preorder: " << endl;

	tree.preorder();
	cout << endl << endl;

	cout << "The height of the tree is:"
		<< tree.height() << endl << endl;

	tree.destory();

	cout << "The tree has been destroyed." << endl << endl;

	cout << string(50, '-');

	ifstream myfile;
	string name,
		symbol;
	double price;
	int size = 0;
	myfile.open("companydata.txt");
	BinarySearchTree<Stock> stockTree;

	if (myfile.is_open())
	{
		while (myfile >> name >> symbol >> price)
		{
			Stock s(name, symbol, price);
			stockTree.insert(s);
			size++;
		}
	}

	myfile.close();

	bool run = true;
	char answer;
	string stockSymbol;
	myfile.open("companydata.txt");


	while (run)
	{
		cout << endl << "What would you like to do?" << endl
			<< "A. Display a stock's name given it's symbol." << endl
			<< "B. Display a stock's price given it's symbol." << endl
			<< "C. Insert a new stock." << endl
			<< "D. Display all the stocks in the tree." << endl
			<< "E. Remove a stock based on it's symbol." << endl
			<< "Q. Quit the program." << endl << endl;

		cout << "Make your selection: ";
		cin >> answer;

		Stock temp("", "", 0);

		switch (tolower(answer))
		{
		case 'a':
			cout << "Enter the stock symbol to find it's name:";
			cin >> stockSymbol;
			temp.setSymbol(stockSymbol);
			cout << endl << stockTree.search(temp)->getName();
			break;
		case 'b':
			cout << "Enter the stock symbol to find it's price:";
			cin >> stockSymbol;
			temp.setSymbol(stockSymbol);
			cout << endl << stockTree.search(temp)->getPrice();
			break;
		case 'c':
			cout << "Enter the name of the stock:";
			cin >> name;
			cout << endl << "Enter the symbol of the stock:";
			cin >> symbol;
			cout << endl << "Enter the price of the stock:";
			cin >> price;
			temp.setName(name);
			temp.setPrice(price);
			temp.setSymbol(symbol);

			stockTree.insert(temp);
			break;
		case 'd':
			cout << "Displaying the entire tree:" << endl;
			stockTree.inorder();
			break;
		case 'e':
			cout << "Which stock would you like to delete?";
			cin >> stockSymbol;
			temp.setSymbol(stockSymbol);

			price = stockTree.search(temp)->getPrice();
			name = stockTree.search(temp)->getName();

			temp.setPrice(price);
			temp.setName(name);

			stockTree.deleteNode(temp);

			break;
		case 'q':
			cout << "Quitting..." << endl;
			stockTree.destory();
			run = false;
			break;
		default:
			cout << "You have entered an incorrect input. Please try again." << endl;
		}
	}
}

//****************************************************************************************************

/*
Created a tree with ten random values from 1 to 5000.
Displaying the values in inorder:
716
1534
1985
2384
2473
2567
3054
3587
3608
3658


Displaying the values in postorder:
1534
716
2384
3054
2567
3608
3658
3587
2473
1985


Displaying the values in preorder:
1985
716
1534
2473
2384
3587
2567
3054
3658
3608


The height of the tree is:5

The tree has been destroyed.

--------------------------------------------------
What would you like to do?
A. Display a stock's name given it's symbol.
B. Display a stock's price given it's symbol.
C. Insert a new stock.
D. Display all the stocks in the tree.
E. Remove a stock based on it's symbol.
Q. Quit the program.

Make your selection: d
Displaying the entire tree:
Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: AMD
Symbol:AMD
Price:85.88

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Alibaba
Symbol:BABA
Price:300.23

Company Name: Disney
Symbol:DIS
Price:127.91

Company Name: Facebook
Symbol:FB
Price:293.58

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: McDonalds
Symbol:MCD
Price:216.24

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Netflix
Symbol:NFLX
Price:513.58

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Paypal
Symbol:PYPL
Price:202.82

Company Name: Qualcomm
Symbol:QCOM
Price:145.27

Company Name: Shopify
Symbol:SHOP
Price:1040.66

Company Name: AT&T
Symbol:T
Price:27.54

Company Name: Target
Symbol:TGT
Price:161.42

Company Name: Walmart
Symbol:WMT
Price:145.77


What would you like to do?
A. Display a stock's name given it's symbol.
B. Display a stock's price given it's symbol.
C. Insert a new stock.
D. Display all the stocks in the tree.
E. Remove a stock based on it's symbol.
Q. Quit the program.

Make your selection: e
Which stock would you like to delete?FB

What would you like to do?
A. Display a stock's name given it's symbol.
B. Display a stock's price given it's symbol.
C. Insert a new stock.
D. Display all the stocks in the tree.
E. Remove a stock based on it's symbol.
Q. Quit the program.

Make your selection: d
Displaying the entire tree:
Company Name: Apple
Symbol:AAPL
Price:118.86

Company Name: Adobe
Symbol:ADBE
Price:495.78

Company Name: AMD
Symbol:AMD
Price:85.88

Company Name: Amazon
Symbol:AMZN
Price:3309.75

Company Name: Alibaba
Symbol:BABA
Price:300.23

Company Name: Disney
Symbol:DIS
Price:127.91

Company Name: Google
Symbol:GOOG
Price:1769.03

Company Name: Intel
Symbol:INTC
Price:45.45

Company Name: Coca-Cola
Symbol:KO
Price:49.66

Company Name: McDonalds
Symbol:MCD
Price:216.24

Company Name: Microsoft
Symbol:MSFT
Price:223.93

Company Name: Netflix
Symbol:NFLX
Price:513.58

Company Name: Nike
Symbol:NKE
Price:129.13

Company Name: Paypal
Symbol:PYPL
Price:202.82

Company Name: Qualcomm
Symbol:QCOM
Price:145.27

Company Name: Shopify
Symbol:SHOP
Price:1040.66

Company Name: AT&T
Symbol:T
Price:27.54

Company Name: Target
Symbol:TGT
Price:161.42

Company Name: Walmart
Symbol:WMT
Price:145.77


What would you like to do?
A. Display a stock's name given it's symbol.
B. Display a stock's price given it's symbol.
C. Insert a new stock.
D. Display all the stocks in the tree.
E. Remove a stock based on it's symbol.
Q. Quit the program.

Make your selection: q
Quitting...
*/