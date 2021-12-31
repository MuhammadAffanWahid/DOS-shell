#pragma once
#include"Folder.h"

class tree
{
public:	
	Folder* root;
	Folder* CF;
public:
	tree()
	{
		CF = root = new Folder("V");
	}
	void insert(Folder* d)
	{
		CF->Folders.push_back(d);
	}
	void print(string user)
	{
		cout << user << "@" << CF->path << "\\" << CF->name << "\\>";
	}
	bool Folder_exists(string name)
	{
		for (int i = 0; i < CF->Folders.size(); i++)
		{
			if (CF->Folders[i]->name == name)
				return true;
		}
		return false;
	}
	Folder* Find(string name)
	{
		for (int i = 0; i < CF->Folders.size(); i++)
		{
			if (CF->Folders[i]->name == name)
				return CF->Folders[i];
		}
		return CF->Folders[0];
	}
};

