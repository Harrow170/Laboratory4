#include "Dictionary.h"
#include"GetInput.h"
#include "HashTableMenu.h"
#include <iostream>

using namespace std;

void DisplayDictionary(Dictionary* d)
{
	if (!d->Ht)
	{
		cout << "Empty" << endl;
		return;
	}

	DisplayTable(d->Ht);
}

void DictionaryMenu(Dictionary* d)
{
	while (true)
	{
		cout << "Current Dictionary: " << endl;
		DisplayDictionary(d);
		cout << endl;
		int choice = GetInput("Dictionary menu: \n 1. Add\n 2. Remove\n 3. Search\n 0. Exit\n Your Input: ");
		switch (choice)
		{
		case 1:
		{
			string key, value;
			cout << "Enter key to add; " << key << endl;
			cout << "Enter value to add: " << value << endl;
			Insert(d, key, value);
			break;
		}

		case 2:
		{
			string key;
			cout << "Enter key to remove: " << key << endl;
			Delete(d, key);
			break;
		}

		case 3: 
		{
			string key;
			cout << "Enter key to search: " << key << endl;
			string value = Search(d, key);
			if (!value.empty())
			{
				cout << "value: " << endl;
			}

			else
			{
				cout << "value not found " << endl;
			}

			break;
		}

		case 0:
			Free(d);
			return;
		default:
			cout << "Error" << endl;
		}
	}
}