#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Validation_.h"
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

class Account
{
protected:
	string NAME_;
	string USER_NAME_;
	string PASSWORD_;
	bool SET_NAME_(string);
	bool SET_USER_NAME_(string);
	bool SET_PASSWORD_(string);
	string GET_NAME_()
	{
		return(NAME_);
	}
	string GET_USER_NAME_()
	{
		return (USER_NAME_);
	}
	string GET_PASSWORD_()
	{
		return (PASSWORD_);
	}
public:
	Account()
	{
		NAME_ = "Not Set";
		USER_NAME_ = "Not Set";
		PASSWORD_ = "Not Set";
	}

};

//  Account CPP 

int RETURN;
string CHOICE;
bool NAME_Copy(string str)
{
	if (!str.empty())
	{
		vector<char>arr(str.data(), str.data() + str.size() + 1u);
		auto p = arr.data();

		if (NAME_LENGTH(p))
		{
			if (WORD_SPACE(p))
			{
				if (WORD_DIGIT(p))
				{
					if (WORD_SYMBOLS(p))
					{
						return true;
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. No Special Symbol Allowed!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						return false;
					}
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. No Digit Allowed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					return false;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. No Spaces Allowed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				return false;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. invalid Length!(Char:- Min: 3 , Max: 9)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			return false;
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Invalid Input!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}

	return false;
}

bool UNCopy(string str)
{
	if (!str.empty())
	{
		vector<char>arr(str.data(), str.data() + str.size() + 1u);
		auto p = arr.data();

		if (USER_NAME_LENGTH(p))
		{
			if (WORD_SPACE(p))
			{
				if (WORD_SYMBOLS(p))
				{
					return true;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. No Special Symbol Allowed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					return false;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. No Spaces Allowed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				return false;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Invalid Length!(Char:- Min: 5 , Max: 15)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			return false;
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Invalid Input!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

bool passCopy(string str)
{
	if (!str.empty())
	{
		vector<char>arr(str.data(), str.data() + str.size() + 1u);
		auto p = arr.data();
		if (PASSWORD_LENGTH(p))
		{
			if (WORD_SPACE(p))
			{
				if (!WORD_UPPER_CASE(p))
				{
					if (!WORD_DIGIT(p))
					{
						if (!WORD_SYMBOLS(p))
						{
							return true;
						}
						else
						{
							system("cls");
							cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\a\n\t\t\t\t[*]. Password Must Have Atleast one Special Symbol!" << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							E_K();
							return false;
						}
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Password Must Have Atleast One Digit!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						return false;
					}
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Password Must Have Atleast One Uppercase Letter!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					return false;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. No Spaces Allowed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				return false;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Invalid Length!(Char:- Min 7 , Max 20)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			return false;
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Invalid Input!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

bool Account::SET_NAME_(string n)
{
	RETURN = 0;
	RETURN = NAME_Copy(n);
	if (RETURN != 0)
	{
		NAME_ = n;
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Name Saved" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return true;
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Name Wasnt Saved" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

bool Account::SET_USER_NAME_(string un)
{
	RETURN = 0;
	RETURN = UNCopy(un);
	if (RETURN != 0)
	{
		USER_NAME_ = un;
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Username Saved" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return true;
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Username Wasnt Saved!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

bool pass_match(string pass1)
{
	RETURN = 0;
	RETURN = passCopy(pass1);
	if (RETURN != 0)
	{
		string pass;
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Renter Your Password." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Password : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		pass = PASS_STARRIC(pass);
		if (pass == pass1)
		{
			return true;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Passwords Doesnt Matched!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			return false;
		}
	}
	return false;
}

bool Account::SET_PASSWORD_(string p)
{
	RETURN = 0;
	RETURN = pass_match(p);
	if (RETURN != 0)
	{
		PASSWORD_ = p;
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Password Saved" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();

		return true;
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Password Wasnt Saved!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

#endif