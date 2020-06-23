#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Validation_.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
const int CASE = 'a';

class NODE
{
private:

	NODE *PARENT;
	NODE *CHILD[ALPHABET_SIZE];

	NODE* CURRENT_NODE;
	vector<char>WORD;
	bool IS_WORD_END;

	NODE *getNode(void)
	{
		NODE *PNODE = new NODE();
		PNODE->IS_WORD_END = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			PNODE->CHILD[i] = NULL;
		return PNODE;
	}

public:
	NODE()
	{
		PARENT = nullptr;
		CHILD[ALPHABET_SIZE] = {};
		CURRENT_NODE = nullptr;
		IS_WORD_END = false;
	}
	~NODE()
	{
		PARENT = nullptr;
		CHILD[ALPHABET_SIZE] = {};
		CURRENT_NODE = nullptr;
		IS_WORD_END = false;
	}
	

	bool insert(NODE *ROOT, const string WORD)
	{
		if (search(ROOT, WORD))
		{
			return false;
		}
		else
		{
			NODE *CURRENT = ROOT;
			for (int level = 0; level < WORD.length(); level++)
			{
				int index = CHAR_TO_INDEX(WORD[level]);
				if (!CURRENT->CHILD[index])
					CURRENT->CHILD[index] = getNode();
				CURRENT = CURRENT->CHILD[index];
			}
			CURRENT->IS_WORD_END = true;
		}
		return true;
	}

	bool search(NODE *ROOT, const string WORD)
	{
		int length = WORD.length();
		NODE *CURRENT = ROOT;
		for (int level = 0; level < length; level++)
		{
			int index = CHAR_TO_INDEX(WORD[level]);
			if (!CURRENT->CHILD[index])
				return false;
			CURRENT = CURRENT->CHILD[index];
		}
		return (CURRENT != NULL && CURRENT->IS_WORD_END);
	}

	NODE * search_(NODE* ROOT, const string WORD)
	{
		int length = WORD.length();
		NODE *CURRENT = ROOT;
		for (int level = 0; level < length; level++)
		{
			int index = CHAR_TO_INDEX(WORD[level]);
			if (!CURRENT->CHILD[index])
				return false;
			CURRENT = CURRENT->CHILD[index];
		}
		return (CURRENT != NULL && CURRENT->IS_WORD_END) ? CURRENT : nullptr;
	}

	bool isLastNode(NODE * ROOT)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			if (ROOT->CHILD[i])
				return 0;
		return 1;
	}

	void suggestionsRec(NODE* ROOT, string CURR_PREFIX)
	{
		if (ROOT->IS_WORD_END)
		{
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. " << CURR_PREFIX << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
		}
		if (isLastNode(ROOT))
			return;
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (ROOT->CHILD[i])
			{
				CURR_PREFIX.push_back(97 + i);
				suggestionsRec(ROOT->CHILD[i], CURR_PREFIX);
			}
		}
	}

	int printAutoSuggestions(NODE * ROOT, const string QUERY)
	{
		NODE* CURRENT = ROOT;
		int level;
		int n = QUERY.length();
		for (level = 0; level < n; level++)
		{
			int index = CHAR_TO_INDEX(QUERY[level]);
			if (!CURRENT->CHILD[index])
				return 0;
			CURRENT = CURRENT->CHILD[index];
		}
		bool isWord = (CURRENT->IS_WORD_END == true);
		bool isLast = isLastNode(CURRENT);
		if (isWord && isLast)
		{
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. "<< QUERY << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			return -1;
		}
		if (!isLast)
		{
			string prefix = QUERY;
			suggestionsRec(CURRENT, prefix);
			return 1;
		}
	}

	void PRE_ORDER_PRINT(NODE* TRIETREE, vector<char>WORD)
	{
		if (TRIETREE->IS_WORD_END)
		{
			cout << "\n\t\t\t\t";
			for (auto it = WORD.begin();it != WORD.end(); ++it)
			{
				cout << *it;
			}
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
		}

		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (TRIETREE->CHILD[i] != nullptr)
			{
				WORD.push_back(CASE + i);
				PRE_ORDER_PRINT(TRIETREE->CHILD[i], WORD);
				WORD.pop_back();

			}
		}
	}

	void PRINT(NODE* TRIETREE, vector<char>WORD_)
	{
		string WORD;
		if (TRIETREE->IS_WORD_END)
		{
			cout << "\n\t\t\t\t";
			for (auto it = WORD_.begin();it != WORD_.end(); ++it)
			{
				cout << *it;
				WORD += *it;
			}
			if (!WORD.empty())
			{


				string _WORD, _MEANING;
				fstream DIC_FILE("Dictionary.txt", ios::out | ios::in);
				if (DIC_FILE)
				{
					DIC_FILE.seekp(0);
					while (DIC_FILE)
					{
						getline(DIC_FILE, _WORD);
						getline(DIC_FILE, _MEANING);
						
						if (WORD==_WORD)
						{
							cout << " , \t" << _MEANING;
						}
					}
					DIC_FILE.close();
				}
			}
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
		}

		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if (TRIETREE->CHILD[i] != nullptr)
			{
				WORD_.push_back(CASE + i);
				PRINT(TRIETREE->CHILD[i], WORD_);
				WORD_.pop_back();

			}
		}
	}

	bool DELETE_NODE(NODE* TRIETREE, char * WORD)
	{
		NODE* CURRENT_NODE = search_(TRIETREE, WORD);
		if (CURRENT_NODE != nullptr)
		{
			CURRENT_NODE->IS_WORD_END = false;
			NODE* PARENT = nullptr;
			bool ISLEAF = true;

			for (int i = 0; i < ALPHABET_SIZE; i++)
			{
				if (CURRENT_NODE->CHILD[i] != nullptr)
				{
					ISLEAF = false;
					break;
				}
			}

			while (CURRENT_NODE->PARENT != nullptr&&ISLEAF&& CURRENT_NODE->IS_WORD_END == false)
			{
				PARENT = CURRENT_NODE->PARENT;
				for (int i = 0; i < ALPHABET_SIZE; i++)
				{
					if (PARENT->CHILD[i] == CURRENT_NODE)
					{
						PARENT->CHILD[i] = nullptr;
						delete CURRENT_NODE;
						CURRENT_NODE = PARENT;
					}
					else if (PARENT->CHILD[i] != nullptr)
					{
						ISLEAF = false;
						break;

					}
				}

			}
			return true;
		}
		else
			return false;

	}
};


class Dictionary
{
private:

	NODE* TRIETREE_;
	vector<char>WORD_;

	bool SAVE_DICT(string, string);
	bool LOAD_DICT();
	bool DELTE_WORD_DICT(string);
	bool UPDATE_WORD_DICT(string, string, string);
	bool SEARCH_FILE(string);
	
public:
	Dictionary()
	{
		TRIETREE_ = new NODE();
		LOAD_DICT();
	}
	~Dictionary()
	{
		delete TRIETREE_;
	}

	bool ADD_WORD(string, string);
	bool DELETE_WORD(string);
	bool UPDATE_WORD(string, string, string);
	bool SEARCH_WORD(string);
	string RETURN_MEAN(string WORD_);
	void PRINT_SUGGESTION(string WORD_)
	{
		int comp = TRIETREE_->printAutoSuggestions(TRIETREE_,WORD_);
		if (comp == -1)
		{
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. No other strings found with this prefix" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
		}
		else if (comp == 0)
		{
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. No other strings found with this prefix" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
		}
	}
	void PRINT()
	{
		system("cls");
		cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*] - Words In Lexic Order - [*]" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		TRIETREE_->PRE_ORDER_PRINT(TRIETREE_,WORD_);
		
	}
	void PRINT_M()
	{
		system("cls");
		cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*] - Words - [*]  |  [*] - Meaning - [*]" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		TRIETREE_->PRINT(TRIETREE_, WORD_);
	}
};


bool CHECK_WORD(char _WORD[])
{
	if (WORD_UPPER_CASE(_WORD))
	{
		if (WORD_SYMBOLS(_WORD))
		{
			if (WORD_DIGIT(_WORD))
			{
				if (WORD_SPACE(_WORD))
				{
					if (WORD_LENGTH(_WORD))
					{
						return true;
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Max 29 Letters are Allowed!" << endl;
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
				cout << "\a\n\t\t\t\t[*]. No Digits are Allowed!" << endl;
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
			cout << "\a\n\t\t\t\t[*]. No Symbols are Allowed!" << endl;
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
		cout << "\a\n\t\t\t\t[*]. Use Lower Case Only!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

bool CHECK_MEAN(char _WORD[])
{
	if (WORD_UPPER_CASE(_WORD))
	{
		if (WORD_SYMBOLS(_WORD))
		{
			if (WORD_DIGIT(_WORD))
			{
				if (MEAN_LENGTH(_WORD))
				{
					return true;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Max 50 Letters are Allowed!" << endl;
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
				cout << "\a\n\t\t\t\t[*]. No Spaces are Allowed!" << endl;
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
			cout << "\a\n\t\t\t\t[*]. No Digits are Allowed!" << endl;
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
		cout << "\a\n\t\t\t\t[*]. Use Lower Case Only!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
	return false;
}

bool Dictionary::ADD_WORD(string WORD_, string MEANING_)
{
	vector<char>arr(WORD_.data(), WORD_.data() + WORD_.size() + 1u);
	auto _WORD = arr.data();
	if (CHECK_WORD(_WORD))
	{
		if (CHECK_MEAN(_WORD))
		{
			if (TRIETREE_->insert(TRIETREE_, _WORD))
			{
				if (SAVE_DICT(WORD_, MEANING_))
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Word Added Succesfuly" << endl;
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
					cout << "\a\n\t\t\t\t[*]. Operation Failed!" << endl;
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
				cout << "\a\n\t\t\t\t[*]. Word Already Existed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Dictionary::DELETE_WORD(string WORD_)
{
	if (SEARCH_FILE(WORD_))
	{
		if (DELTE_WORD_DICT(WORD_))
		{
			LOAD_DICT();
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Word Deleted Succesfuly" << endl;
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
			cout << "\a\n\t\t\t\t[*]. Operation Failed!" << endl;
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
		cout << "\a\n\t\t\t\t[*]. No Such Word Has Been Found!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
}

bool Dictionary::UPDATE_WORD(string WORD_,string nWORD,string MEANING)
{
	if (SEARCH_FILE(WORD_))
	{
		if (UPDATE_WORD_DICT(WORD_,nWORD,MEANING))
		{
			LOAD_DICT();
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Word Updated Succesfuly" << endl;
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
			cout << "\a\n\t\t\t\t[*]. Operation Failed!" << endl;
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
		cout << "\a\n\t\t\t\t[*]. No Such Word Has Been Found!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}
}

bool Dictionary::LOAD_DICT()
{
	string WORD, MEANING;
	fstream DIC_FILE("Dictionary.txt", ios::out | ios::in);
	if (DIC_FILE)
	{
		DIC_FILE.seekp(0);
		while (DIC_FILE)
		{
			getline(DIC_FILE, WORD);
			getline(DIC_FILE, MEANING);

			vector<char>arr(WORD.data(), WORD.data() + WORD.size() + 1u);
			auto _WORD = arr.data();

			TRIETREE_->insert(TRIETREE_, _WORD);
			if (DIC_FILE.eof())
			{
				DIC_FILE.close();
				return true;
			}
		}
		DIC_FILE.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::SAVE_DICT(string WORD, string MEANING)
{
	fstream DIC_FILE("Dictionary.txt", ios::out | ios::in | ios::app);
	if (DIC_FILE)
	{
		DIC_FILE << WORD << endl;
		DIC_FILE << MEANING << endl;
		DIC_FILE.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::DELTE_WORD_DICT(string WORD)
{
	fstream DIC_FILE("Dictionary.txt", ios::out | ios::in);
	ofstream TEMP_FILE("temp.txt", ios::trunc);
	if (DIC_FILE)
	{
		DIC_FILE.seekp(0);
		string word, mean;
		while (!DIC_FILE.eof())
		{
			getline(DIC_FILE, word);
			getline(DIC_FILE, mean);
			if (WORD == word)
			{
				word = "";
				mean = "";
			}
			else
			{
				if (DIC_FILE.eof() == 1)
					break;
				TEMP_FILE << word << endl << mean<< endl;
			}
		}

		TEMP_FILE.close();
		DIC_FILE.close();
		remove("Dictionary.txt");
		rename("temp.txt", "Dictionary.txt");

		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::UPDATE_WORD_DICT(string WORD,string nWORD,string MEANING)
{
	fstream DIC_FILE("Dictionary.txt", ios::out | ios::in);
	ofstream TEMP_FILE("temp.txt", ios::trunc);
	if (DIC_FILE)
	{
		DIC_FILE.seekp(0);
		string word, mean;
		while (!DIC_FILE.eof())
		{
			getline(DIC_FILE, word);
			getline(DIC_FILE, mean);
			if (WORD == word)
			{
				word = nWORD;
				mean = MEANING;
				TEMP_FILE << word << endl << mean << endl;
			}
			else
			{
				if (DIC_FILE.eof() == 1)
					break;
				TEMP_FILE << word << endl << mean << endl;
			}
		}

		TEMP_FILE.close();
		DIC_FILE.close();
		remove("Dictionary.txt");
		rename("temp.txt", "Dictionary.txt");

		return true;
	}
	else
	{
		return false;
	}
}

bool Dictionary::SEARCH_FILE(string WORD_)
{
	string WORD, MEANING;
	bool flag = false;
	fstream DIC_FILE("Dictionary.txt", ios::out | ios::in);
	if (DIC_FILE)
	{
		DIC_FILE.seekp(0);
		while (DIC_FILE)
		{
			getline(DIC_FILE, WORD);
			getline(DIC_FILE, MEANING);
			if (WORD_ == WORD)
			{
				flag = true;
			}
		}

		DIC_FILE.close();
		return flag;
	}
	else
		return false;
}

string Dictionary::RETURN_MEAN(string WORD_)
{
	if (TRIETREE_->search(TRIETREE_, WORD_))
	{
		string WORD, MEANING;
		fstream DIC_FILE("Dictionary.txt", ios::out | ios::in);
		if (DIC_FILE)
		{
			DIC_FILE.seekp(0);
			while (DIC_FILE)
			{
				getline(DIC_FILE, WORD);
				getline(DIC_FILE, MEANING);

				if (WORD_==WORD)
				{
					DIC_FILE.close();
					return MEANING;
				}
			}
		}
		else
		{
			return "";
		}
	}
	else
	{
		return "";
	}
	return "";
}

bool Dictionary::SEARCH_WORD(string WORD_)
{
	if (TRIETREE_->search(TRIETREE_,WORD_))
		return true;
	return false;
}

#endif