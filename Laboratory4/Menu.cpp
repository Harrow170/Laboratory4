#include "HashTableh.h"
#include "HashTableItem.h"
#include "Dictionary.h"
#include "HashTableMenu.h"
#include "DictionaryMenu.h"
#include "GetInput.h"
#include <iostream>

using namespace std;

void Menu()
{
	HashTable* ht = Created();
	Dictionary* d = Init();
	while (true)
	{
		int choice = GetInput("Menu: \n 1. Hash Table\n 2. Dictionary\n 0. Exit\n Your Input: ");
		switch (choice)
		{
		case 1:
		{
			HashTableMenu(ht);
			break;
		}

		case 2:
		{
			DictionaryMenu(d);
			break;
		}

		case 0:
			Free(ht);
			Free(d);
			return;
		default:
			cout << "Error" << endl;
		}
	}
}