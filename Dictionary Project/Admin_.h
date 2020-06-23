#pragma once

#ifndef ADMIN_H
#define ADMIN_H

#include "Account_.h"
#include <iostream>
#include "Dictionary_.h"

using namespace std;


int check_mem_no()
{

	system("cls");
	string t = "members.txt";
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
				cout << "\n\n\n";
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Only " << RETURN << " Member Found" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				return RETURN;
			}
			else if (RETURN >1)
			{
				cout << "\n\n\n";
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Total " << RETURN << " Members Found" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
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

int check_mem_req(string t)
{

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
		int RETURN = count;

		reqfile.close();
		if (!(RETURN < 1))
		{
			RETURN /= 2;
			if (RETURN > 0 && RETURN <= 1)
			{
				cout << "\n\n\n";
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Only " << RETURN << " Request Found" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				return RETURN;
			}
			else if (RETURN >1)
			{
				cout << "\n\n\n";
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Total " << RETURN << " Requests Found" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
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

void req_user_name(char arr[], string str)
{
	string P_NAME;
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;
	string DASH, U_N, P, N, P_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM;
	int found = 0;
REQ_P:system("cls");
	cout << "\n\n\n";
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter Username" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Name : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, P_NAME);

	ofstream tempfile("tempfile.txt", ios::trunc);
	fstream check_req(arr, ios::in);
	check_req.seekp(0);
	while (!check_req.eof())
	{
		getline(check_req, dash);
		getline(check_req, u_n);
		getline(check_req, p);
		getline(check_req, n);
		getline(check_req, p_num);
		getline(check_req, dob);
		getline(check_req, c_addr);
		getline(check_req, p_addr);
		getline(check_req, dept);
		getline(check_req, deg);
		getline(check_req, smstr);
		getline(check_req, r_num);
		getline(check_req, dash);

		if (P_NAME == u_n)
		{
			found = 1;

			DASH = dash, U_N = u_n, P = p, N = n, P_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
			dash = "", u_n = "", p = "", n = "", p_num = "", dob = "", c_addr = "", p_addr = "", dept = "", deg = "", smstr = "", r_num = "";

		}

		else
		{
			if (check_req.eof() == 1)

				break;
			tempfile << dash << endl << u_n << endl << p << endl << n << endl << p_num << endl << dob << endl << c_addr << endl << p_addr << endl << dept << endl << deg << endl << smstr << endl << r_num << endl << dash << endl;
		}

	}

	tempfile.close();
	check_req.close();
	remove(arr);
	rename("tempfile.txt", arr);


	if (found == 1)
	{

		cout << "\n\n\n";
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. User Name Found" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[Y]. Press Y/y to Accept Request" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[N]. Press N/n to Reject Request" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Choice : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, CHOICE);
		if (CHOICE == "Y" || CHOICE == "y")
		{
			if (!str.empty())
			{
				string str_1 = str;
				str = "members.txt";
				vector<char>arr(str.data(), str.data() + str.size() + 1u);
				auto title = arr.data();
				ofstream member(title, ios::app);

				member << DASH << endl << U_N << endl << P << endl << N << endl << P_NUM << endl << DOB << endl << C_ADDR << endl << P_ADDR << endl << DEPT << endl << DEG << endl << SMSTR << endl << R_NUM << endl << DASH << endl;
				member.close();
				int no_of_mem;
				no_of_mem = check_mem_no();
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
				goto REQ_P;
			}

		}
		else if (CHOICE == "N")
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Request Cancelled" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
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
			goto REQ_P;
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. No Such Username Found!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto REQ_P;
	}
}

void req_roll_num(char arr[], string str)
{
	string P_NAME;
	string dash, u_n, p, n, p_num, dob, c_addr, p_addr, dept, deg, smstr, r_num;
	string DASH, U_N, P, N, P_NUM, DOB, C_ADDR, P_ADDR, DEPT, DEG, SMSTR, R_NUM;
	int found = 0;
REQ_P:system("cls");
	cout << "\n\n\n";
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter roll #" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Roll # : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, P_NAME);

	ofstream tempfile("tempfile.txt", ios::trunc);
	fstream check_req(arr, ios::in);
	check_req.seekp(0);
	while (!check_req.eof())
	{
		getline(check_req, dash);
		getline(check_req, u_n);
		getline(check_req, p);
		getline(check_req, n);
		getline(check_req, p_num);
		getline(check_req, dob);
		getline(check_req, c_addr);
		getline(check_req, p_addr);
		getline(check_req, dept);
		getline(check_req, deg);
		getline(check_req, smstr);
		getline(check_req, r_num);
		getline(check_req, dash);

		if (P_NAME == r_num)
		{
			found = 1;

			DASH = dash, U_N = u_n, P = p, N = n, P_NUM = p_num, DOB = dob, C_ADDR = c_addr, P_ADDR = p_addr, DEPT = dept, DEG = deg, SMSTR = smstr, R_NUM = r_num;
			dash = "", u_n = "", p = "", n = "", p_num = "", dob = "", c_addr = "", p_addr = "", dept = "", deg = "", smstr = "", r_num = "";

		}

		else
		{
			if (check_req.eof() == 1)

				break;
			tempfile << dash << endl << u_n << endl << p << endl << n << endl << p_num << endl << dob << endl << c_addr << endl << p_addr << endl << dept << endl << deg << endl << smstr << endl << r_num << endl << dash << endl;
		}

	}

	tempfile.close();
	check_req.close();
	remove(arr);
	rename("tempfile.txt", arr);


	if (found == 1)
	{

		cout << "\n\n\n";
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Roll# Found" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[Y]. Press Y/y to Accept Request" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[N]. Press N/n to Reject Request" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Choice : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, CHOICE);
		if (CHOICE == "Y" || CHOICE == "y")
		{
			if (!str.empty())
			{
				string str_1 = str;
				str = "members.txt";
				vector<char>arr(str.data(), str.data() + str.size() + 1u);
				auto title = arr.data();
				ofstream member(title, ios::app);

				member << DASH << endl << U_N << endl << P << endl << N << endl << P_NUM << endl << DOB << endl << C_ADDR << endl << P_ADDR << endl << DEPT << endl << DEG << endl << SMSTR << endl << R_NUM << endl << DASH << endl;
				member.close();
				int no_of_mem;
				no_of_mem = check_mem_no();
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
				goto REQ_P;
			}

		}
		else if (CHOICE == "N")
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Request Cancelled" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
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
			goto REQ_P;
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. No Such Roll Number Found!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto REQ_P;
	}
}


string word;
string mean;
string nword;

class Admin : private Account
{
private:
	void ADMIN_MODULE();
	bool SIGN_IN();
	void UPDATE_ACCOUNT();
	void REQ_MODULE();
public:
	void ADMIN();
};

// Admin CPP

string UNAME;
string PASS;
string DASH = "_";

bool Admin::SIGN_IN()
{
	system("cls");
	cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*] Default User Name => \"AB   \" [*] " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*] Default Password  => \"12345\" [*] " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);

	cout << "\n\n\n\n\n" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*] Enter Username : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, UNAME);
	ifstream admin_file("admin.txt");
	if (admin_file)
	{
		while (admin_file)
		{
			getline(admin_file, DASH);
			getline(admin_file, USER_NAME_);
			getline(admin_file, PASSWORD_);
			getline(admin_file, DASH);
		}
		if (UNAME == USER_NAME_)
		{
			cout << "\n\t\t\t\t[*] Enter Password : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			PASS = PASS_STARRIC(PASS);

			if (PASS == PASSWORD_)
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Wellcome Admin \" " << USER_NAME_ << " \"" << endl;
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
				cout << "\a\n\t\t\t\t[*]. Wrong Password!" << endl;
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
			cout << "\a\n\t\t\t\t[*]. No Such Username Found!" << endl;
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
		cout << "\a\n\t\t\t\t[*]. No Such ID Found!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		return false;
	}

}

void Admin::UPDATE_ACCOUNT()
{
	int a = 1;
	while (a)
	{
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*] Modify Admin's Data Module [*] " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[1]. Change Username." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[2]. Change Password." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[3]. Go Back." << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Choice : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		try
		{

			getline(cin, CHOICE);
			if (CHOICE == "1")
			{
				cout << "\n\n" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*] Enter New Username : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				getline(cin, UNAME);
				if (UNCopy(UNAME))
				{
					fstream admin_file("admin.txt", ios::in);
					ofstream temp_file("tempfile.txt", ios::trunc);
					while (!admin_file.eof())
					{
						getline(admin_file, DASH);
						getline(admin_file, USER_NAME_);
						getline(admin_file, PASSWORD_);
						getline(admin_file, DASH);

						if (admin_file.eof() == 1)
						{
							break;
						}
					}
					temp_file << "_" << endl << UNAME << endl << PASSWORD_ << endl << "_" << endl;
					admin_file.close();
					temp_file.close();
					remove("admin.txt");
					rename("tempfile.txt", "admin.txt");
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Successfuly Changed" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					continue;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Updating Failed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					continue;

				}

			}
			else if (CHOICE == "2")
			{
				cout << "\n\n" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*] Enter New Password : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				PASS = PASS_STARRIC(PASS);
				if (pass_match(PASS))
				{
					fstream admin_file("admin.txt", ios::in);
					ofstream temp_file("tempfile.txt", ios::trunc);
					while (admin_file)
					{
						getline(admin_file, DASH);
						getline(admin_file, USER_NAME_);
						getline(admin_file, PASSWORD_);
						getline(admin_file, DASH);

						if (admin_file.eof() == 1)
						{
							break;
						}
					}
					temp_file << "_" << endl << USER_NAME_ << endl << PASS << endl << "_" << endl;
					admin_file.close();
					temp_file.close();
					remove("admin.txt");
					rename("tempfile.txt", "admin.txt");

					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Successfuly Updated" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					continue;
				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Updating Failed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					continue;

				}

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
			cout << "\a\n\t\t\t\t[*]. Wrong Choice!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			continue;

		}
	}
}

void Admin::REQ_MODULE()
{
	int NO_OF_REQ = check_mem_req("requests.txt");
	if (NO_OF_REQ != 0)
	{

		RETURN = (NO_OF_REQ * 13);
		string t = "requests.txt";
		vector<char>arr(t.data(), t.data() + t.size() + 1u);
		auto t_ = arr.data();

		fstream file(t_, ios::in);
		if (!file.fail())
		{
			unique_ptr <string[]> request_data(new string[RETURN]);

			for (int x = 0; x < RETURN; x++)
			{
				getline(file, request_data[x]);
				if (file.eof() == 1)
				{
					break;
				}
			}
			int i = 13;
			int un = 1;
			int rn = 11;

			system("cls");

			cout << "\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. No Of Requests : " << NO_OF_REQ << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);

			for (int x = 0; x < NO_OF_REQ; x++)
			{
				cout << "\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Req # " << (x + 1);
				cout << "\n\t\t\t\t[*]. Username : " << request_data[un];
				cout << "\n\t\t\t\t[*]. Roll no  : " << request_data[rn];
				cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
				rn += i;
				un += i;
			}
			file.close();
			cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
		REQ_P_: system("cls");


			cout << "\n\n" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*] Enter Username/Roll # to Accept/Reject Request [*] " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[1]. Username." << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[2]. Roll No." << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[3]. Go Back." << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Choice : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			getline(cin, CHOICE);

			if (CHOICE == "1")
			{
				req_user_name(t_, "requests.txt");
				goto REQ_P_;
			}
			else if (CHOICE == "2")
			{
				req_roll_num(t_, "requests.txt");
				goto REQ_P_;

			}
			else if (CHOICE == "3")
			{
				return;
			}
			else
			{
				system("cls");
				goto REQ_P_;
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Error Loading Requests!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
		}

	}
	else
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. No Request Found!" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
	}
}

void Admin::ADMIN_MODULE()
{
C_MAIN:
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*] Welcome To Admin Module Menu [*] " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[1]. Add Word in Dictionary." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[2]. Delete Word From Dictionary." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[3]. Update Word In Dictionary." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[4]. Update Meaning Of Word In Dictionary." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[5]. View All Words In Lexic Order Form." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[6]. View All Words In Lexic Order With Meaning." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[7]. Check Requests." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[8]. Go Back." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter   Your  Choice : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, CHOICE);


	if (CHOICE == "1")
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Enter the Word    : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, word);
		if (!word.empty())
		{
			cout << "\n\t\t\t\t[*]. Enter the Meaning : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			getline(cin, mean);
			if (!mean.empty())
			{
				unique_ptr <Dictionary> Dptr(new Dictionary);
				if (!Dptr->ADD_WORD(word, mean))
				{
					system("cls");
					cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\a\n\t\t\t\t[*]. Operation Failed!" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
					cout << "\t\t"; Print_Horizontal_Line('_', 70);
					E_K();
					goto C_MAIN;
				}
				else
				{
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
	else if (CHOICE == "2")
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Enter the Word    : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, word);
		if (!word.empty())
		{
			unique_ptr <Dictionary> Dptr(new Dictionary);
			if (!Dptr->DELETE_WORD(word))
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\a\n\t\t\t\t[*]. Operation Failed!" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				E_K();
				goto C_MAIN;
			}
			else
			{
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
	else if (CHOICE == "3")
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Enter the Word : " << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cursor_choice();
		getline(cin, word);
		if (!word.empty())
		{
			cout << "\n\t\t\t\t[*]. Enter Updated Word : " << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cursor_choice();
			getline(cin, nword);
			if (!nword.empty())
			{
				cout << "\n\t\t\t\t[*]. Enter Updated Meaning : " << endl;
				cout << "\t\t"; Print_Horizontal_Line('_', 70);
				cursor_choice();
				getline(cin, mean);
				if (!mean.empty())
				{
					unique_ptr <Dictionary> Dptr(new Dictionary);
					if (!Dptr->UPDATE_WORD(word,nword, mean))
					{
						system("cls");
						cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\a\n\t\t\t\t[*]. Operation Failed!" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
						cout << "\t\t"; Print_Horizontal_Line('_', 70);
						E_K();
						goto C_MAIN;
					}
					else
					{
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
	else if (CHOICE == "4")
	{
		goto C_MAIN;
	}
	else if (CHOICE == "5")
	{
		unique_ptr <Dictionary> Dptr(new Dictionary);
		Dptr->PRINT();
		cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto C_MAIN;
	}
	else if (CHOICE == "6")
	{
		unique_ptr <Dictionary> Dptr(new Dictionary);
		Dptr->PRINT_M();
		cout << "\n\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();
		goto C_MAIN;
	}
	else if (CHOICE == "7")
	{
		REQ_MODULE();
		goto C_MAIN;
	}
	else if (CHOICE == "8")
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
		goto C_MAIN;
	}
	goto C_MAIN;
}

void Admin::ADMIN()
{
C_MAIN:

	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*] Welcome To Administrator Module [*] " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[1]. Login as Administrator." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[2]. Modify Admin Data." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[3]. Go Back." << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cout << "\n\t\t\t\t[*]. Enter   Your  Choice : " << endl;
	cout << "\t\t"; Print_Horizontal_Line('_', 70);
	cursor_choice();
	getline(cin, CHOICE);

	if (CHOICE == "1")
	{

		if (SIGN_IN())
		{
			ADMIN_MODULE();
			goto C_MAIN;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Login Failed!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C_MAIN;
		}
	}
	else if (CHOICE == "2")
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\a\n\t\t\t\t[*]. You Must Login First" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
		cout << "\t\t"; Print_Horizontal_Line('_', 70);
		E_K();

		if (SIGN_IN())
		{
			UPDATE_ACCOUNT();
			goto C_MAIN;
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\a\n\t\t\t\t[*]. Access Denied!" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			cout << "\n\t\t\t\t[*]. Press Enter key to continue" << endl;
			cout << "\t\t"; Print_Horizontal_Line('_', 70);
			E_K();
			goto C_MAIN;
		}
	}
	else if (CHOICE == "3")
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
		goto C_MAIN;
	}
}


#endif