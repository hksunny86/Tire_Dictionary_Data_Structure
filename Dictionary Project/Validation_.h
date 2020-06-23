#pragma once

#ifndef VALIDATION_H
#define VALIDATION_H

#include <conio.h>
#include <cstring>
#include <cctype>
#include <vector>
#include <iostream>


using namespace std;

int LENGTH = 0;
int COUNT = 0;

template <class T>

void Print_Horizontal_Line(T type, int length)
{
	for (int x = 0; x < length; x++)
	{
		cout << type;
	}
}

template<class A >
A PASS_STARRIC(A pass)
{
	pass = "";
	char c;
	do {
		c = _getch();
		switch (c) {
		case 0:
			_getch();
			break;
		case 13:
			cout << endl;
			break;
		case 8:
			if (pass.length() > 0) {
				pass.erase(pass.end() - 1);
				cout << c << ' ' << c;
			}
			break;
		default:
			pass += c;
			cout << '*';
			break;
		}
	} while (c != 13);
	return pass;
}


void E_K()
{
	char ch[1];
a:char a = _getch();
	for (int i = 0;;)
	{
		if (a == '\r')
		{
			ch[i] = '\0';
			break;
		}
		else
		{
			goto a;
		}
	}
}

bool WORD_SPACE(char input[])
{
	LENGTH = strlen(input);
	for (COUNT = 0; COUNT < LENGTH; COUNT++)
	{
		if (isspace(input[COUNT]))
		{
			return false;
		}
	}
	return true;
}

bool WORD_DIGIT(char input[])
{
	LENGTH = strlen(input);
	for (COUNT = 0; COUNT < LENGTH; COUNT++)
	{
		if (isdigit(input[COUNT]))
		{
			return false;
		}
	}
	return true;
}

bool WORD_SYMBOLS(char input[])
{
	LENGTH = strlen(input);
	for (COUNT = 0; COUNT < LENGTH; COUNT++)
	{
		if (ispunct(input[COUNT]))
		{
			return false;
		}
	}
	return true;
}

bool WORD_UPPER_CASE(char input[])
{
	LENGTH = strlen(input);
	for (COUNT = 0; COUNT < LENGTH; COUNT++)
	{
		if (isupper(input[COUNT]))
		{
			return false;
		}
	}
	return true;
}

bool WORD_LENGTH(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 1 && LENGTH <= 29)
	{
		return true;
	}
	else
		return false;

}

bool MEAN_LENGTH(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 1 && LENGTH <= 50)
	{
		return true;
	}
	else
		return false;

}

bool NAME_LENGTH(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 3 && LENGTH <= 9)
	{
		return true;
	}
	else
		return false;

}

bool USER_NAME_LENGTH(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 5 && LENGTH <= 15)
	{
		return true;
	}
	else
		return false;

}

bool PASSWORD_LENGTH(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 7 && LENGTH <= 20)
	{
		return true;
	}
	else
		return false;

}

bool mobile_num_len(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH == 10)

	{
		return true;
	}
	else
		return false;
}

bool addr_length(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 15 && LENGTH <= 130)//Min 15 , Max 130 
	{
		return true;
	}
	else
		return false;
}

bool dept_length(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 2 && LENGTH <= 15)//Min 2 , Max 15  
	{
		return true;
	}
	else
		return false;
}

bool roll_num_l(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH == 11)
	{
		return true;
	}
	else
		return false;
}

bool d_length(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 1 && LENGTH <= 2)
	{
		return true;
	}
	else
		return false;
}

bool smstr_length(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH == 1)
	{
		return true;
	}
	else
		return false;
}

bool msg_length(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH >= 1 && LENGTH <= 75)
	{
		return true;
	}
	else
		return false;

}

bool y_length(char input[])
{
	LENGTH = strlen(input);
	if (LENGTH == 4)
	{
		return true;
	}
	else
		return false;
}

void cursor_choice()
{
	cout << "\r\r\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";

}

#endif