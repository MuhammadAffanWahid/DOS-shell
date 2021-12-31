#pragma once
#include"tree.h"
#include <cctype>
#include<Windows.h>

//void getRowColbyLeftClick(int& rpos, int& cpos)
//{
//	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//	DWORD Events;
//	INPUT_RECORD InputRecord;
//	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
//	do
//	{
//		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
//		{
//			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
//			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
//			break;
//		}
//	} while (true);
//}
//void gotoRowCol(int rpos, int cpos)
//{
//	COORD scrn;
//	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
//	scrn.X = cpos;
//	scrn.Y = rpos;
//	SetConsoleCursorPosition(hOuput, scrn);
//}
//void coler(int k)
//
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, k);
//}
//string textColor(int colorID = 1, string textToColor = "")
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
//	return textToColor;
//}



class DOS
{
private:
	string lower(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}
public:
	tree t;
	string user = "Affan";
	DOS()
	{

	}
	void print()
	{
		cout << "\t\t\t\t\t" << "Muhammad Affan | BSCS19039 | DSA-ITU-2021" << endl << endl;
		t.print(user);
	}
	void run()
	{
		print();
		bool exit = false;
		while (!exit)
		{
			exit = input();
		}
	}
	bool input()
	{
		string command;
		getline(cin, command);

		//if (command.find(' ') != string::npos)
		//{

		//}
		string opr = command.substr(0, command.find(' '));
		opr = lower(opr);

		if (opr == "mkdir")
		{
				t.insert(new Folder(command.substr(6, command.length()),t.CF->path+t.CF->name,t.CF));
		}
		else if (opr == "create")
		{
			t.CF->Files.push_back(command.substr(7, command.length()));
		}
		else if (opr == "del")
		{
			t.CF->remove_file(command.substr(4, command.length()));
		}
		else if (opr == "cd")
		{
			string folder = command.substr(3, command.length());
			if (t.Folder_exists(folder))
				t.CF = t.Find(folder);
			else
				cout << "No such directory exists!" << endl;
			//cout << textColor(4, "No such directory exists!");
		}

		else if (opr == "cd..")
		{
			if (t.CF->parent != nullptr)
			{
				t.CF = t.CF->parent;
			}
		}
		else if (opr == "cd\\")
		{
			if (t.CF->parent != nullptr)
			{
				t.CF = t.root;
			}
		}
		else if (opr == "dir")
		{
			t.CF->print();
		}
		else if (opr == "cls")
		{
			system("cls");
			print();
		}
		else if (opr == "exit")
		{
			return true;
		}
		 
		if(opr != "cls")
			t.print(user);
		return false;
	}
};

