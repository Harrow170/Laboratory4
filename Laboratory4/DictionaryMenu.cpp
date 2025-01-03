#include "Dictionary.h"
#include"GetInput.h"
#include "HashTableMenu.h"
#include <iostream>

using namespace std;

void DisplayDictionary(Dictionary* dictionary)
{
	if (dictionary == nullptr) 
	{
		cout << "Dictionary not init." << endl;
		return;
	}

	if (dictionary->HashTable == nullptr) 
	{
		cout << "Hash not init" << endl;
		return;
	}

	cout << "--- Dictionary ---" << endl;
	for (int i = 0; i < dictionary->HashTable->Size; ++i) 
	{
		HashTableItem* item = dictionary->HashTable->Items[i];
		while (item != nullptr) 
		{
			cout << "key: " << item->Key << ", value: " << item->Value << endl;
			item = item->Next; 
		}
	}

	cout << "------------------------" << endl;
}

void DictionaryMenu(Dictionary* dictionary)
{
	while (true)
	{
		cout << "Current Dictionary: " << endl;
		DisplayDictionary(dictionary);
		cout << endl;
		int choice = GetInput("Dictionary menu: \n 1. Add\n 2. Remove\n 3. Search\n \
0. Exit\n Your Input: ");
		switch (choice)
		{
			case 1:
			{
				int key = GetInput("Enter key to add: ");
				int value = GetInput("Enter value to add: ");
				Insert(dictionary, to_string(key), to_string(value));
				break;
			}

			case 2:
			{
				int key = GetInput("Enter key to remove: ");
				string value = Search(dictionary, to_string(key));
				if (!value.empty())
				{
					Delete(dictionary, to_string(key));
				}
				else
				{
					cout << "Nope " << endl;
				}

				break;
			}

			case 3: 
			{
				int key = GetInput("Enter key to search: ");
				string value = Search(dictionary, to_string(key));
				if (!value.empty())
				{
					cout << "value: " << value << endl;
				}

				else
				{
					cout << "value not found " << endl;
				}

				break;
			}

			case 0:
				Free(dictionary);
				return;
			default:
				cout << "Error" << endl;
		}
	}
}