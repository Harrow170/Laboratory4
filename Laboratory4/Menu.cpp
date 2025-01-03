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
	HashTable* table = CreateTable();
	Dictionary* dictionary = CreateDictionary();
	while (true)
	{
		int choice = GetInput("Menu: \n 1. Hash Table\n 2. Dictionary\n 0. Exit\n Your Input: ");
		switch (choice)
		{
			case 1:
			{
				HashTableMenu(table);
				break;
			}

			case 2:
			{
				DictionaryMenu(dictionary);
				break;
			}

			case 0:
				return;
			default:
				cout << "Error" << endl;
		}
	}
}