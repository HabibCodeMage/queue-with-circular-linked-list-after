// queue with circular linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"circularlinkedlists.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	circularlinkedlist<string> object;
	char flag = ' ';
	string value;
	do
	{
		cout << "ENTER \"E\" TO ENQUE\n"
			<< "ENTER \"D\" TO DEQUE\n"
			<< "ENTER \"F\" TO FRONT\n"
			<< "ENTER \"A\" TO CLOSE PROGRAM\n";
		cin.get(flag);
		if (!(isspace(flag)))
		{
			cin.ignore();
		}
		switch (flag)
		{
		case'E':
		case'e':
			cout << "enter value:";
			getline(cin, value, '\n');
			object.addnode(value);
			object.advance();
			break;
		case'D':
		case'd':
			try
			{
				object.deletenode();
			}
			catch (const char* that)
			{
				cout << that << endl;
			}
			break;
		case'f':
		case'F':
			cout << "FRONT:";
			try
			{
				cout << object.front() << endl;
			}
			catch (const char* that)
			{
				cout << that << endl;
			}
			break;
		default:
			break;
		}


	} while (toupper(flag) != 'A');
	system("pause");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
