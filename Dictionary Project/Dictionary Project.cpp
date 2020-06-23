// Dictionary Project.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Validation_.h"
#include "Admin_.h"
#include "User_.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <conio.h>
#include <fstream>

using namespace std;


void display_menu()
{
	int a = 1;
	while (a)
	{

		system("color 80");
		system("cls");


		cout << "\n\t"; Print_Horizontal_Line('*', 91);
		cout << "\n\t------------------------------[Wellcome To Basic Dictionary]-------------------------------";
		cout << "\n\t"; Print_Horizontal_Line('*', 91);

		cout << "\n\n\n\t"; Print_Horizontal_Line('_', 91);
		cout << "\n\t\t[1] - [Administrator Mode]";
		cout << "\n\t"; Print_Horizontal_Line('_', 91);
		cout << "\n\t\t[2] - [User Mode]";
		cout << "\n\t"; Print_Horizontal_Line('_', 91);
		cout << "\n\t\t[3] - [Guest Mode]";
		cout << "\n\t"; Print_Horizontal_Line('_', 91);
		cout << "\n\t\t[4] - [About]";
		cout << "\n\t"; Print_Horizontal_Line('_', 91);
		cout << "\n\t\t[5] - [Exit]";
		cout << "\n\t"; Print_Horizontal_Line('_', 91);

		cout << "\n\n\n\t"; Print_Horizontal_Line('*', 91);
		cout << "\n\t"; Print_Horizontal_Line('-', 91);
		cout << "\n\t"; Print_Horizontal_Line('*', 91);


		cout << "\n\n\t\t"; Print_Horizontal_Line('_', 76);
		cout << "\n\t\t\t\t[*] - [Enter   Your  Choice] : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 76);
		cursor_choice();
		try
		{
			getline(cin, CHOICE);
			if (CHOICE == "1")
			{
				unique_ptr <Admin> Aptr(new Admin);
				Aptr->ADMIN();
				continue;
			}
			else if (CHOICE == "2")
			{
				unique_ptr <Member> Mptr(new Member);
				Mptr->Member_menu();
				continue;
			}
			else if (CHOICE == "3")
			{
				continue;
			}
			else if (CHOICE == "4")
			{
				fstream aboutfile("about.txt", ios::in | ios::out);
				if (!aboutfile.fail())
				{
					system("cls");
					cout << "\n";
					cout << "\t\t"; Print_Horizontal_Line('_', 74);
					string ln;
					while (!aboutfile.eof())
					{
						getline(aboutfile, ln);
						cout << "\t\t" << ln << endl;
					}

					cout << "\t\t"; Print_Horizontal_Line('_', 74);
					cout << "\n\t\t\t\t[* - [Press Enter key to continue]" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 74);
					E_K();
					continue;
				}
				else
				{
					cout << "\n\n\n";
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*] - [Error Loading About] !" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n";
					continue;
				}
			}
			else if (CHOICE == "5")
			{
				cout << "\n\n\t\t";
				exit(0);
			}
			else
			{
				throw 1;
			}
		}
		catch (int)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*] - [Wrong Choice] !" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*] - [Press Enter key to continue]" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			continue;
		}
	}
}

void main()
{
	display_menu();
	while (CHOICE == "n" || "N")
	{
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[Y] - [Enter Y/y To Review Main Menu]" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[N] - [Enter N/n To Exit     Program]" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*] - [Choice] : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		CHOICE = _getche();
		if (CHOICE == "Y" || CHOICE == "y")
		{
			system("cls");
			display_menu();
		}
		else if (CHOICE == "N" || CHOICE == "n")
		{
			cout << "\n\n\n";
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*] - [Exiting Program...........]" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n";
			exit(0);
		}

	}

}


/*
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "Dictionary_.h"

using namespace std;







int main()
{
	vector <char> WORD;

	NODE* root = new NODE();
	root->insert(root, "hello");
	root->insert(root, "dog");
	root->insert(root, "hell");
	root->insert(root, "cat");
	root->insert(root, "a");
	root->insert(root, "hel");
	root->insert(root, "help");
	root->insert(root, "helps");
	root->insert(root, "helping");
	int comp = root->printAutoSuggestions(root,"help");
	if (comp == -1)
		cout << "No other strings found with this prefix\n";
	else if (comp == 0)
		cout << "No string found with this prefix\n";
	string a;
	root->PRE_ORDER_PRINT(root, WORD);
	root->DELETE_NODE(root, "hello");
	root->DELETE_NODE(root, "dog");
	root->DELETE_NODE(root, "hell");
	cout << "\n\n";
	root->PRE_ORDER_PRINT(root, WORD);
	return 0;
}

*/