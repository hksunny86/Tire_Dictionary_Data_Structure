#pragma once
#ifndef USER_H
#define USER_H


#include "Account_.h"

string F_NAME;
string L_NAME;

int check_no_of_mem(string t)
{
	int RETURN;
	system("cls");
	vector<char>arr(t.data(), t.data() + t.size() + 1u);
	auto title = arr.data();
	fstream reqfile(title, ios::in | ios::out);
	if (!(reqfile.fail()))
	{
		string ln;
		int count = 0;
		while (reqfile >> ln)
		{
			if (ln == "_")
			{
				count++;
			}
			else
			{
				continue;
			}
		}
		RETURN = count;

		reqfile.close();
		if (!(RETURN < 1))
		{
			RETURN /= 2;
			if (RETURN > 0 && RETURN <= 1)
			{
				return RETURN;
			}
			else if (RETURN >1)
			{
				return RETURN;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 0;
}

string get_mobile_no()
{
	string no;
retr:
	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Your Phone Number" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Number : +92" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b";
	getline(cin, no);
	if (!no.empty())
	{
		vector<char>arr(no.data(), no.data() + no.size() + 1u);
		auto num = arr.data();
		if (WORD_SPACE(num))
		{
			if (!WORD_DIGIT(num))
			{
				if (mobile_num_len(num))
				{
					no = "+92" + no;
					return no;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Invalid Length(Length:-10, Exclude '0' From Start)!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto retr;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. No Char other Than Digit Allowed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto retr;
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
			goto retr;
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
		goto retr;
	}
	return "0";
}

struct DOB_U_V
{
	unsigned short YEAR_U_V;
	unsigned short MONTH_U_V;
	unsigned short DAY_U_V;
};

DOB_U_V get_DATE()
{
	DOB_U_V D;
	string D_, M, Y;
	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Enter The Date" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Formate : Year (enter) Month(1-12) (enter) Day(1-31) (enter)" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	E_K();

U_V_Y:	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Year : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, Y);
	vector<char>arr(Y.data(), Y.data() + Y.size() + 1u);
	auto y = arr.data();
	if (y_length(y))
	{
		if (!WORD_DIGIT(y))
		{
			D.YEAR_U_V = atoi(y);
			if (D.YEAR_U_V >= 2017)
			{

			U_V_M:	system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Month : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				getline(cin, M);
				vector<char>arr(M.data(), M.data() + M.size() + 1u);
				auto m = arr.data();
				//D.MONTH_U_V = atoi(m);
				if (d_length(m))
				{
					if (!WORD_DIGIT(m))
					{
						D.MONTH_U_V = atoi(m);
						if (D.MONTH_U_V >= 1 && D.MONTH_U_V <= 12)
						{

						U_V_D:	system("cls");
							cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\n\t\t\t\t[*]. Day : " << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							cursor_choice();
							getline(cin, D_);

							vector<char>arr(D_.data(), D_.data() + D_.size() + 1u);
							auto d = arr.data();
							//D.DAY_U_V = atoi(d);
							if (d_length(d))
							{
								if (!WORD_DIGIT(d))
								{
									D.DAY_U_V = atoi(d);
									if (D.MONTH_U_V == 1 || D.MONTH_U_V == 3 || D.MONTH_U_V == 5 || D.MONTH_U_V == 7 || D.MONTH_U_V == 8 || D.MONTH_U_V == 10 || D.MONTH_U_V == 12)
									{
										if (D.DAY_U_V >= 1 && D.DAY_U_V <= 31)
										{
											return D;
										}
										else
										{
											system("cls");
											cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\a\n\t\t\t\t[*]. Enter Valid Day (1-31)!" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											E_K();
											goto U_V_D;
										}
									}
									else if (D.MONTH_U_V == 2)
									{
										if (D.DAY_U_V >= 1 && D.DAY_U_V <= 29)
										{

											return D;
										}
										else
										{
											system("cls");
											cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\a\n\t\t\t\t[*]. Enter Valid Day (1-29)!" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											E_K();
											goto U_V_D;
										}
									}
									else
									{
										if (D.DAY_U_V >= 1 && D.DAY_U_V <= 30)
										{
											return D;
										}
										else
										{
											system("cls");
											cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\a\n\t\t\t\t[*]. Enter Valid Day(1-30)!" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											E_K();
											goto U_V_D;
										}
									}
								}
								else
								{
									system("cls");
									cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
									cout << "\a\n\t\t\t\t[*]. Enter Valid Day!" << endl;
									cout << "\t\t"; Print_Horizontal_Line('_', 70);
									cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
									cout << "\t\t"; Print_Horizontal_Line('_', 70);
									E_K();
									goto U_V_D;
								}

							}
							else
							{
								system("cls");
								cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
								cout << "\a\n\t\t\t\t[*]. Enter Valid Day!" << endl;
								cout << "\t\t"; Print_Horizontal_Line('_', 70);
								cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
								cout << "\t\t"; Print_Horizontal_Line('_', 70);
								E_K();
								goto U_V_D;
							}

						}
						else
						{
							system("cls");
							cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\a\n\t\t\t\t[*]. Enter Valid Month(1-12)!" << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							E_K();
							goto U_V_M;
						}
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Enter Valid Month(1-12)!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto U_V_M;
					}

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Enter Valid Month (1-12)!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto U_V_M;
				}

			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Enter Valid Year(2017 or above)!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto U_V_Y;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Enter Valid Year(2017 or above)!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto U_V_Y;
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Enter Valid Year(2017 or above)!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto U_V_Y;
	}
}

DOB_U_V get_DOB()
{
	DOB_U_V D;
	string D_, M, Y;
	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Enter Your Date Of Birth" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Formate : Year(1990-2017) (enter) Month(1-12) (enter) Day(1-31) (enter)" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	E_K();

U_V_Y:	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Year : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, Y);
	vector<char>arr(Y.data(), Y.data() + Y.size() + 1u);
	auto y = arr.data();
	if (y_length(y))
	{
		if (!WORD_DIGIT(y))
		{
			D.YEAR_U_V = atoi(y);
			if (D.YEAR_U_V >= 1900 && D.YEAR_U_V <= 2017)
			{

			U_V_M:	system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Month : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				getline(cin, M);
				vector<char>arr(M.data(), M.data() + M.size() + 1u);
				auto m = arr.data();
				//D.MONTH_U_V = atoi(m);
				if (d_length(m))
				{
					if (!WORD_DIGIT(m))
					{
						D.MONTH_U_V = atoi(m);
						if (D.MONTH_U_V >= 1 && D.MONTH_U_V <= 12)
						{

						U_V_D:	system("cls");
							cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\n\t\t\t\t[*]. Day : " << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							cursor_choice();
							getline(cin, D_);

							vector<char>arr(D_.data(), D_.data() + D_.size() + 1u);
							auto d = arr.data();
							//D.DAY_U_V = atoi(d);
							if (d_length(d))
							{
								if (!WORD_DIGIT(d))
								{
									D.DAY_U_V = atoi(d);
									if (D.MONTH_U_V == 1 || D.MONTH_U_V == 3 || D.MONTH_U_V == 5 || D.MONTH_U_V == 7 || D.MONTH_U_V == 8 || D.MONTH_U_V == 10 || D.MONTH_U_V == 12)
									{
										if (D.DAY_U_V >= 1 && D.DAY_U_V <= 31)
										{
											return D;
										}
										else
										{
											system("cls");
											cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\a\n\t\t\t\t[*]. Enter Valid Day (1-31)!" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											E_K();
											goto U_V_D;
										}
									}
									else if (D.MONTH_U_V == 2)
									{
										if (D.DAY_U_V >= 1 && D.DAY_U_V <= 29)
										{

											return D;
										}
										else
										{
											system("cls");
											cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\a\n\t\t\t\t[*]. Enter Valid Day (1-29)!" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											E_K();
											goto U_V_D;
										}
									}
									else
									{
										if (D.DAY_U_V >= 1 && D.DAY_U_V <= 30)
										{
											return D;
										}
										else
										{
											system("cls");
											cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\a\n\t\t\t\t[*]. Enter Valid Day(1-30)!" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
											cout << "\t\t"; Print_Horizontal_Line('_', 70);
											E_K();
											goto U_V_D;
										}
									}
								}
								else
								{
									system("cls");
									cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
									cout << "\a\n\t\t\t\t[*]. Enter Valid Day!" << endl;
									cout << "\t\t"; Print_Horizontal_Line('_', 70);
									cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
									cout << "\t\t"; Print_Horizontal_Line('_', 70);
									E_K();
									goto U_V_D;
								}

							}
							else
							{
								system("cls");
								cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
								cout << "\a\n\t\t\t\t[*]. Enter Valid Day!" << endl;
								cout << "\t\t"; Print_Horizontal_Line('_', 70);
								cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
								cout << "\t\t"; Print_Horizontal_Line('_', 70);
								E_K();
								goto U_V_D;
							}

						}
						else
						{
							system("cls");
							cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\a\n\t\t\t\t[*]. Enter Valid Month(1-12)!" << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
							cout << "\t\t"; Print_Horizontal_Line('_', 70);
							E_K();
							goto U_V_M;
						}
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Enter Valid Month(1-12)!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto U_V_M;
					}

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Enter Valid Month (1-12)!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto U_V_M;
				}

			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Enter Valid Year(1900-2017)!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto U_V_Y;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Enter Valid Year(1900-2017)!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto U_V_Y;
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Enter Valid Year(1900-2017)!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto U_V_Y;
	}

}

string get_current_addr()
{
	string ADD_U_V;
C_A_U_V:system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Enter Your Current Addres(Char :- Max: 130, Min : 15)" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Address : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cursor_choice();
	getline(cin, ADD_U_V);
	if (!ADD_U_V.empty())
	{
		vector<char>arr(ADD_U_V.data(), ADD_U_V.data() + ADD_U_V.size() + 1u);
		auto addr = arr.data();
		if (addr_length(addr))
		{
			return ADD_U_V;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
			cout << "\a\n\t\t\t\t[*]. Invalid Length!(Char :- Max: 130, Min : 15)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 75);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 75);
			E_K();
			goto C_A_U_V;
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
		cout << "\a\n\t\t\t\t[*]. Invalid Input!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 75);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 75);
		E_K();
		goto C_A_U_V;
	}
}

string get_permanent_addr()
{
	string P_ADD_U_V;
	//cin.ignore();
P_A_U_V:system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Enter Your permanent Addres(Char :- Max: 130, Min : 15)" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cout << "\n\t\t\t\t[*]. Address : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 75);
	cursor_choice();
	getline(cin, P_ADD_U_V);
	if (!P_ADD_U_V.empty())
	{
		vector<char>arr(P_ADD_U_V.data(), P_ADD_U_V.data() + P_ADD_U_V.size() + 1u);
		auto addr = arr.data();
		if (addr_length(addr))
		{
			return P_ADD_U_V;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
			cout << "\a\n\t\t\t\t[*]. Invalid Length!(Char :- Max: 130, Min : 15)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 75);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 75);
			E_K();
			goto P_A_U_V;
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 75);
		cout << "\a\n\t\t\t\t[*]. Invalid Input!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 75);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 75);
		E_K();
		goto P_A_U_V;
	}
}

string get_dept()
{
	string dept;
	//cin.ignore();
D_U_V:system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Your Departement Name" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Dept : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();

	getline(cin, dept);
	if (!dept.empty())
	{
		vector<char>arr(dept.data(), dept.data() + dept.size() + 1u);
		auto dpt = arr.data();
		if (dept_length(dpt))
		{
			return dept;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Invalid Length!(Char :- Max: 15, Min : 2)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto D_U_V;
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
		goto D_U_V;
	}
}

string get_degree_p()
{
	string deg;
	//cin.ignore();
D_P_U_V:system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Your Degree(Program)" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Deg(Name) " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, deg);
	if (!deg.empty())
	{
		vector<char>arr(deg.data(), deg.data() + deg.size() + 1u);
		auto degree = arr.data();
		if (dept_length(degree))
		{
			return deg;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Invalid Length!(Char :- Max: 15, Min: 2)" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto D_P_U_V;
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
		goto D_P_U_V;
	}
}

string get_smstr()
{
	string str, smster;
	//cin.ignore();
G_S_U_V:system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Your Current Semester()" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Semester(Example 2,8) : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, smster);

	if (!smster.empty())
	{
		vector<char>arr(smster.data(), smster.data() + smster.size() + 1u);
		auto smstr_ = arr.data();
		if (smstr_length(smstr_))
		{
			if (!WORD_DIGIT(smstr_))
			{
				int smstr = atoi(smstr_);
				if (smstr < 10 && smstr >= 1)
				{
					if (smstr == 1)
					{
						str = "1st";
						return str;
					}
					else if (smstr == 2)
					{
						str = "2nd";
						return str;
					}
					else if (smstr == 3)
					{
						str = "3rd";
						return str;
					}
					else if (smstr == 4)
					{
						str = "4th";
						return str;
					}
					else if (smstr == 5)
					{
						str = "5th";
						return str;
					}
					else if (smstr == 6)
					{
						str = "6th";
						return str;
					}
					else if (smstr == 7)
					{
						str = "7th";
						return str;
					}
					else if (smstr == 8)
					{
						str = "8th";
						return str;
					}
					else if (smstr == 9)
					{
						str = "9th";
						return str;
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
						goto G_S_U_V;
					}
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Invlaid input!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto G_S_U_V;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. invalid Input!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto G_S_U_V;
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
			goto G_S_U_V;
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. invalid Input!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto G_S_U_V;
	}
}

string get_roll_n()
{

	string str;

	C_MAIN
		:system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Your Roll Number(Without Dashes)" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Roll Number : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, str);
	if (!str.empty())
	{
		vector<char>arr(str.data(), str.data() + str.size() + 1u);
		auto r_num = arr.data();
		if (roll_num_l(r_num))
		{
			if (!WORD_DIGIT(r_num))
			{
				char arr[12];
				for (int x = 0; x < 9; x++)
				{
					if (x == 8)
					{
						arr[x] = '-';
					}
					else
						arr[x] = r_num[x];
				}
				for (int x = 9; x < 12; x++)
				{
					arr[x] = r_num[x - 1];
				}
				string a(arr, 0, 12);
				return a;
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. No Char Other Than Digit Allowed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C_MAIN;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Invlaid Length!(Valid Length :- 11)!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C_MAIN;
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
		goto C_MAIN;
	}
}

class Member :protected Account
{
private:
	string DASH;
	string PHONE_NUM;
	string DOB;
	string C_ADDR;
	string P_ADDR;
	string DEPT;
	string DEG;
	string SMSTR;
	string R_NUM;
	void login();
	void Member_Module_menu(string, string, string);
	void sign_up();
	bool enter_data();
	bool Check_M_Pass(string, string);
	bool Check_M_U_NAME(string, string);
	bool Check_M_R_NUM(string, string);
	bool modify_members_data(string, string, string, string, string, string, string, string, string, string, string, string, string, string);
	bool create_member_req_file(DOB_U_V);
	bool Check_M_U_NAME_F_REQ(string, string);
	bool Check_M_R_NUM_F_REQ(string, string);
public:
	Member()
	{
		DASH = "_";
		PHONE_NUM = "";
		DOB = "";
		C_ADDR = "";
		P_ADDR = "";
		DEPT = "";
		DEG = "";
		SMSTR = "";
		R_NUM = "";
	}
	void Member_menu();
	friend ostream &operator << (ostream&output, const Member &M)
	{
		output << "\n\n\n";
		output << "\t\t"; Print_Horizontal_Line('_', 70);
		output << "\n\t\t\t\t[*] Members Module [*]" << endl;
		output << "\t\t"; Print_Horizontal_Line('_', 70);
		output << "\n\t\t\t\t[1]. Login." << endl;
		output << "\t\t"; Print_Horizontal_Line('_', 70);
		output << "\n\t\t\t\t[2]. Signup." << endl;
		output << "\t\t"; Print_Horizontal_Line('_', 70);
		output << "\n\t\t\t\t[3]. Go Back." << endl;
		output << "\t\t"; Print_Horizontal_Line('_', 70);
		output << "\n\t\t\t\t[*]. Choice : " << endl;
		output << "\t\t"; Print_Horizontal_Line('_', 70);
		return output;
	}
};
string M_U_NAME = "";
string M_NAME = "";
string PASS_M = "";
string MOB_NUM_M = "";
string C_ADDRES_M = "";
string P_ADDRES_M = "";
string DEPARTEMENT_M = "";
string DEGREE_P_M = "";
string ROLL_NO_M = "";
string SEMESTER_M = "";
string TITLE_M = "";


bool Member::Check_M_R_NUM(string roll_num, string t_o_s)
{
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;
	vector<char>arr(t_o_s.data(), t_o_s.data() + t_o_s.size() + 1u);
	auto title = arr.data();

	fstream login(title, ios::in);
	if (!login.fail())
	{
		login.seekp(0);
		while (!login.eof())
		{
			getline(login, dash);
			getline(login, u_n);
			getline(login, p);
			getline(login, n);
			getline(login, p_num);
			getline(login, dob);
			getline(login, c_addr);
			getline(login, p_addr);
			getline(login, dept);
			getline(login, deg);
			getline(login, smstr);
			getline(login, r_num);
			getline(login, dash);

			if (roll_num == r_num)
			{
				return true;
				DASH = dash, USER_NAME_ = u_n, PASSWORD_= p, NAME_ = n, PHONE_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
	else
	{
		return false;
	}

	return false;
}

bool Member::Check_M_R_NUM_F_REQ(string roll_num, string t_o_s)
{
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;

	vector<char>arr(t_o_s.data(), t_o_s.data() + t_o_s.size() + 1u);
	auto title = arr.data();

	fstream login(title, ios::in);
	if (!login.fail())
	{
		login.seekp(0);
		while (!login.eof())
		{
			getline(login, dash);
			getline(login, u_n);
			getline(login, p);
			getline(login, n);
			getline(login, p_num);
			getline(login, dob);
			getline(login, c_addr);
			getline(login, p_addr);
			getline(login, dept);
			getline(login, deg);
			getline(login, smstr);
			getline(login, r_num);
			getline(login, dash);

			if (roll_num == r_num)
			{
				return true;
				DASH = dash, USER_NAME_= u_n, PASSWORD_= p, NAME_= n, PHONE_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
	else
	{
		return false;
	}

	return false;


}

bool Member::Check_M_Pass(string pass_word, string t_o_s)
{
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;

	vector<char>arr(t_o_s.data(), t_o_s.data() + t_o_s.size() + 1u);
	auto title = arr.data();

	fstream login(title, ios::in);
	if (!login.fail())
	{
		login.seekp(0);
		while (!login.eof())
		{
			getline(login, dash);
			getline(login, u_n);
			getline(login, p);
			getline(login, n);
			getline(login, p_num);
			getline(login, dob);
			getline(login, c_addr);
			getline(login, p_addr);
			getline(login, dept);
			getline(login, deg);
			getline(login, smstr);
			getline(login, r_num);
			getline(login, dash);

			if (pass_word == p)
			{
				return true;
				DASH = dash, USER_NAME_ = u_n, PASSWORD_= p, NAME_= n, PHONE_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
	else
	{
		return false;
	}

	return false;
}

bool Member::Check_M_U_NAME_F_REQ(string user_name, string t_o_s)
{
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;
	vector<char>arr(t_o_s.data(), t_o_s.data() + t_o_s.size() + 1u);
	auto title = arr.data();

	fstream login(title, ios::in);
	if (!login.fail())
	{
		login.seekp(0);
		while (!login.eof())
		{
			getline(login, dash);
			getline(login, u_n);
			getline(login, p);
			getline(login, n);
			getline(login, p_num);
			getline(login, dob);
			getline(login, c_addr);
			getline(login, p_addr);
			getline(login, dept);
			getline(login, deg);
			getline(login, smstr);
			getline(login, r_num);
			getline(login, dash);

			if (user_name == u_n)
			{
				DASH = dash, USER_NAME_ = u_n, PASSWORD_= p, NAME_= n, PHONE_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
				return true;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
	else
	{
		return false;
	}

	return false;
}

bool Member::Check_M_U_NAME(string user_name, string t_o_s)
{
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;
	vector<char>arr(t_o_s.data(), t_o_s.data() + t_o_s.size() + 1u);
	auto title = arr.data();

	fstream login(title, ios::in);
	if (!login.fail())
	{
		login.seekp(0);
		while (!login.eof())
		{
			getline(login, dash);
			getline(login, u_n);
			getline(login, p);
			getline(login, n);
			getline(login, p_num);
			getline(login, dob);
			getline(login, c_addr);
			getline(login, p_addr);
			getline(login, dept);
			getline(login, deg);
			getline(login, smstr);
			getline(login, r_num);
			getline(login, dash);

			if (user_name == u_n)
			{
				DASH = dash, USER_NAME_ = u_n, PASSWORD_= p, NAME_ = n, PHONE_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
				return true;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
	else
	{
		return false;
	}

	return false;
}

bool Member::modify_members_data(string user_name, string t_o_s, string u_n, string p, string n, string p_num, string dob, string c_addr, string p_addr, string dept, string deg, string smstr, string r_num, string dash = "_")
{
	int no_of_mem_ = check_no_of_mem("members.txt");
	t_o_s ="members.txt";
	vector<char>arr(t_o_s.data(), t_o_s.data() + t_o_s.size() + 1u);
	auto t_ti_tle = arr.data();
	fstream login(t_ti_tle, ios::in);
	if (!login.fail())
	{
		ofstream tempfile("temperoryfile.txt", ios::trunc);
		if (!tempfile.fail())
		{
			login.seekp(0);
			int n_ = no_of_mem_ * 13;
			unique_ptr <string[]> data(new string[n_]);
			for (int x = 0; x <n_; x++)
			{
				getline(login, data[x]);
			}
			int u_name_ = 1;
			int found_s = 0;
			int index_ = 0;
			for (int x = 0; x < no_of_mem_; x++)
			{
				if (user_name == data[u_name_])
				{
					found_s = 1;
				}
				else
				{
					index_ += 13;
					u_name_ += 13;
				}
			}
			if (found_s == 1)
			{
				data[(index_)] = "_";
				data[(index_ + 1)] = u_n;
				data[(index_ + 2)] = p;
				data[(index_ + 3)] = n;
				data[(index_ + 4)] = p_num;
				data[(index_ + 5)] = dob;
				data[(index_ + 6)] = c_addr;
				data[(index_ + 7)] = p_addr;
				data[(index_ + 8)] = dept;
				data[(index_ + 9)] = deg;
				data[(index_ + 10)] = smstr;
				data[(index_ + 11)] = r_num;
				data[(index_ + 12)] = "_";
				DASH = dash, USER_NAME_= u_n, PASSWORD_= p, NAME_= n, PHONE_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;

				for (int x = 0; x < n_; x++)
				{
					tempfile << data[x] << endl;
				}
				tempfile.close();
				login.close();
				remove(t_ti_tle);
				rename("temperoryfile.txt", t_ti_tle);

				return true;
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
	else
	{
		return false;
	}

	return false;

}

void Member::Member_Module_menu(string n_m_, string t_m_, string un_m_)
{
C:
	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. [*] Members Login Module [*] " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. [*] Wellcome \"" << n_m_ << "\" [*]" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[1]. Show Data(Your Own)." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[2]. Modify Data(Your Own)." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[3]. Search Word." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[4]. Request to Add Word in Dictionary." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[5]. Go Back." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Choice : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, CHOICE);
	if (CHOICE == "1")
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Name              : " << NAME_<< endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Username          : " << USER_NAME_ << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Phone Number      : " << PHONE_NUM << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Date Of Birth     : " << DOB << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Current Address   : " << C_ADDR << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Permanent Address : " << P_ADDR << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Departement       : " << DEPT << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Degree Program    : " << DEG << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Semester          : " << SMSTR << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Roll No           : " << R_NUM << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 90);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto C;
	}
	else if (CHOICE == "2")
	{
	A_M:
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Update Your Account" << " \"" << n_m_ << "\"" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();


		system("cls");
		cout << "\n\n\n";
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[1]. Name." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[2]. Username." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[3]. Phone Number." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[4]. Current Address." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[5]. Departement." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[6]. Degree Program." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[7]. Semester." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[8]. Roll No." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[9]. Password." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[10]. Go Back." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Choice : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, CHOICE);
		if (CHOICE == "1")
		{
			//modify_members_data(un_m_, t_m_, userName, password, name, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM);
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Name" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();

		M_F_:system("cls");
			cout << "\n\n\n";
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. First Name : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			getline(cin, F_NAME);
			if (NAME_Copy(F_NAME))
			{
			M_L_:	system("cls");
				cout << "\n\n\n";
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Last Name : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				getline(cin, L_NAME);
				if (NAME_Copy(L_NAME))
				{
					M_NAME = F_NAME + " " + L_NAME;
					if (modify_members_data(un_m_, t_m_, USER_NAME_, PASSWORD_, M_NAME, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM))
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto C;
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto C;
					}
				}
				else
				{
					goto M_L_;
				}
			}
			else
			{
				goto M_F_;
			}
		}
		else if (CHOICE == "2")
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your User Name" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
		M_U_:system("cls");
			cout << "\n\n\n";
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Username : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			getline(cin, M_U_NAME);
			if (Check_M_U_NAME(M_U_NAME, "members.txt"))
			{
				if (UNCopy(M_U_NAME))
				{
					if (modify_members_data(un_m_, t_m_, M_U_NAME,PASSWORD_, NAME_, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM))
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto C;
					}
					else
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto C;
					}
				}
				else
				{
					goto M_U_;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Username Already Exists Try Other" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto M_U_;
			}

		}
		else if (CHOICE == "3")
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Phone Number" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
		retr_num:	system("cls");


			MOB_NUM_M = get_mobile_no();
			if (MOB_NUM_M != "0")
			{
				if (modify_members_data(un_m_, t_m_, USER_NAME_, PASSWORD_, NAME_, MOB_NUM_M, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM))
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;
				}
			}
			else
			{
				goto retr_num;
			}
		}
		else if (CHOICE == "4")
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Current Address" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();

			C_ADDRES_M = get_current_addr();

			if (modify_members_data(un_m_, t_m_,USER_NAME_, PASSWORD_, NAME_, PHONE_NUM, DOB, C_ADDRES_M, P_ADDR, DEPT, DEG, SMSTR, R_NUM))
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;

			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;
			}

		}
		else if (CHOICE == "5")
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Update Your Departement" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();

			DEPARTEMENT_M = get_dept();

			if (modify_members_data(un_m_, t_m_, USER_NAME_, PASSWORD_, NAME_, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPARTEMENT_M, DEG, SMSTR, R_NUM))

			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;
			}
		}
		else if (CHOICE == "6")
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Degree Program" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();

			DEGREE_P_M = get_degree_p();
			if (modify_members_data(un_m_, t_m_, USER_NAME_, PASSWORD_, NAME_, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEGREE_P_M, SMSTR, R_NUM))
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;
			}

		}
		else if (CHOICE == "7")
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Semester" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();

			SEMESTER_M = get_smstr();

			if (modify_members_data(un_m_, t_m_, USER_NAME_, PASSWORD_, NAME_, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SEMESTER_M, R_NUM))
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;

			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C;
			}

		}
		else if (CHOICE == "8")
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Roll #" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
		R_NUM_V:
			ROLL_NO_M = get_roll_n();
			if (Check_M_R_NUM(ROLL_NO_M, "members.txt"))
			{
				if (modify_members_data(un_m_, t_m_, USER_NAME_, PASSWORD_, NAME_, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, ROLL_NO_M))
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Roll No Already Exists Try Other" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto R_NUM_V;
			}


		}
		else if (CHOICE == "9")
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Update Your Password" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();

		P_U_V_v_: system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Password : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			PASS_M = PASS_STARRIC(PASS_M);
			if (pass_match(PASS_M))
			{


				if (modify_members_data(un_m_, t_m_, USER_NAME_, PASS_M, NAME_, PHONE_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM))
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Update Failed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;
				}
			}
			else
			{
				goto P_U_V_v_;
			}

		}
		else if (CHOICE == "10")
		{
			goto C;
		}
		else
		{
			goto A_M;
		}
	}
	else if (CHOICE == "3")
	{
		string word;
		string mean;
		system("cls");
		cout << "\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Enter Word : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, word);
		if (!word.empty())
		{
			unique_ptr <Dictionary> Dptr(new Dictionary);
			if (Dptr->SEARCH_WORD(word))
			{
				mean = Dptr->RETURN_MEAN(word);
				if (mean != "")
				{
					system("cls");
					cout << "\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*] -  Word : " << word << "  |  " << "[*] - Meaning : " << mean << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Program Wasnt able to Read Meaning!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Word Not Found!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();

				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Did You Mean!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);cout << endl;
				Dptr->PRINT_SUGGESTION(word);

				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();

				goto C;

			}


			goto C;
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
			goto C;
		}
	}
	else if (CHOICE == "4")
	{
		/*unique_ptr <President> P_ptr(new President);
		if (P_ptr->show_run_event(title))
		{
			cout << "\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. No On Going Event Found!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K(E_K_C);
			
		}
		*/
		goto C;
	}
	else if (CHOICE == "5")
	{
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Wrong Choice!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto C;
	}
}

void Member::login()
{

C_SUB1:
	system("cls");

	cout << "\n\n\n";
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[1]. Login As a Member." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[2]. Go Back" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Choice : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();

	getline(cin, CHOICE);
	if (CHOICE == "1")
	{
		cout << "\n\t\t\t\t[*]. Enter Your Username : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, USER_NAME_);
		if (!USER_NAME_.empty())
		{
			if (Check_M_U_NAME(USER_NAME_, "members.txt"))
			{
				cout << "\n\t\t\t\t[*]. Username Found" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Enter Your Password : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				PASSWORD_= PASS_STARRIC(PASSWORD_);

				if (Check_M_Pass(PASSWORD_, "members.txt"))
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Wellcome \"" << NAME_<< "\"" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();

					Member_Module_menu(NAME_, "members", USER_NAME_);
					goto C_SUB1;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Incorrect Password" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C_SUB1;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Username Not Found" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C_SUB1;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. No Such Username Found" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C_SUB1;
		}
	}
	else if (CHOICE == "2")
	{
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. Wrong Choice" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto C_SUB1;
	}
}

bool Member::create_member_req_file(DOB_U_V dob)
{
	string t;
	t = "requests";
	ofstream req(t + ".txt", ios::app);
	if (!req.fail())
	{
		req << "_" << endl;
		req << USER_NAME_<< endl;
		req << PASSWORD_ << endl;
		req << NAME_ << endl;
		req << PHONE_NUM << endl;
		req << dob.YEAR_U_V << "/" << dob.MONTH_U_V << "/" << dob.DAY_U_V << endl;
		req << C_ADDR << endl;
		req << P_ADDR << endl;
		req << DEPT << endl;
		req << DEG << endl;
		req << SMSTR << endl;
		req << R_NUM << endl;
		req << "_" << endl;
		req.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Member::enter_data()
{
F_NAME:	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Your First Name : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, F_NAME);
	if (NAME_Copy(F_NAME))
	{
	L_NAME:	system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Enter Your Last Name : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, L_NAME);
		if (NAME_Copy(L_NAME))
		{
			NAME_ = F_NAME + " " + L_NAME;
		User_Name:	system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Select Your Username : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			getline(cin, USER_NAME_);
			if (!Check_M_U_NAME(USER_NAME_, "members"))
			{
				if (!Check_M_U_NAME_F_REQ(USER_NAME_, "requests"))
				{
					if (UNCopy(USER_NAME_))
					{
					P_U_V: system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Select Your Password : " << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cursor_choice();
						PASSWORD_ = PASS_STARRIC(PASSWORD_);
						if (pass_match(PASSWORD_))
						{
						R_num_:
							R_NUM = get_roll_n();
							if (!Check_M_R_NUM(R_NUM, "members.txt"))
							{
								if (!Check_M_R_NUM_F_REQ(R_NUM, "requests.txt"))
								{
									SMSTR = get_smstr();
								M_M_N:	PHONE_NUM = get_mobile_no();
									if (PHONE_NUM != "0")
									{
										DOB_U_V DOB_;
										DOB_ = get_DOB();
										C_ADDR = get_current_addr();
										P_ADDR = get_permanent_addr();
										DEPT = get_dept();
										DEG = get_degree_p();


										if (create_member_req_file(DOB_))
										{
											return true;
										}
										else
										{
											return false;
										}


									}
									else
									{
										goto M_M_N;
									}
								}
								else
								{
									system("cls");
									cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
									cout << "\a\n\t\t\t\t[*]. Roll Num Not Available Try New One!" << endl;
									cout << "\t\t"; Print_Horizontal_Line('_', 70);
									cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
									cout << "\t\t"; Print_Horizontal_Line('_', 70);
									E_K();
									goto R_num_;
								}

							}
							else
							{

								system("cls");
								cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
								cout << "\a\n\t\t\t\t[*]. Roll Num Already Exists Try New One!" << endl;
								cout << "\t\t"; Print_Horizontal_Line('_', 70);
								cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
								cout << "\t\t"; Print_Horizontal_Line('_', 70);
								E_K();
								goto R_num_;
							}
						}
						else
						{
							goto P_U_V;

						}
					}
					else
					{
						goto User_Name;
					}
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Username Not Available Try New One!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto User_Name;
				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Username Already Exists Try New One!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto User_Name;
			}
		}
		else
		{
			goto L_NAME;
		}
	}
	else
	{
		goto F_NAME;
	}
	return false;
}

void Member::sign_up()
{
C_SUB:
	system("cls");
	cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. WellCome To Registration" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[1]. To Continue Registration" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[2]. Go Back" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Choice : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, CHOICE);
	if (CHOICE == "1")
	{
		if (enter_data())
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Request Sent" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C_SUB;
		}
		else
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Request Sending Falied" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C_SUB;
		}
		goto C_SUB;
	}
	else if (CHOICE == "2")
	{
		return;
	}
	else
	{
		goto C_SUB;
	}
}

void Member::Member_menu()
{
	Member Memb;

	int a = 1;
	while (a)
	{
		system("cls");
		cout << Memb;
		cursor_choice();
		try {

			getline(cin, CHOICE);

			if (CHOICE == "1")
			{
				login();
				continue;
			}
			else if (CHOICE == "2")
			{
				sign_up();
				continue;
			}
			else if (CHOICE == "3")
			{
				return;
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
			cout << "\a\n\t\t\t\t[*]. Wrong Choice" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			continue;
		}
	}
}

#endif
