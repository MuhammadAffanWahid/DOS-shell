#pragma once
#include <list>
#include<vector>
#include<string>
#include<iostream>
#include<ctime>
using namespace std;

class Folder
{
public:
	string name;
	vector<Folder*> Folders;
	vector<string> Files;
	Folder* parent;
	time_t creation_time;
	string owner;
	string path;
	bool hidden;
public:
	Folder(string n = "NUL", string p = "",Folder* parant = nullptr, vector<string> fs = vector<string>(), vector<Folder*> Fs = vector<Folder*>())
	{
		name = n;
		Folders = Fs;
		Files = fs;
		hidden = false;
		path = p;
		parent = parant;
	}
	void remove_file(string name)
	{
		for (int i = 0; i < Files.size(); i++)
		{
			if (Files[i] == name)
			{
				swap(Files[i], Files[Files.size() - 1]);
				Files.pop_back();
			}
		}
	}
	void print()
	{
		cout << "Directory of " << path << endl << endl;
		for (int i = 0; i < Folders.size(); i++)
		{
			cout << "              <DIR>     " << Folders[i]->name << endl;
		}
		for (int i = 0; i < Files.size(); i++)
		{
			cout << "                        " << Files[i] << endl;
		}
	}
};

