#include "HashTableh.h"
#include "GetInput.h"
#include <iostream>

void DisplayTable(HashTable* ht)
{
	for (int i = 0; i < ht->Size; ++i)
	{
		cout << "[" << i << "]: ";
		HashTableItem* current = ht->Items[i];
		if (!current)
		{
			cout << "Empty " << endl;
		}

		else
		{
			while (current)
			{
				cout << "(" << current->Key << ", " << current->Value << ") ";
				current = current->Next;
				cout << endl;
			}
		}
	}
}

void HashTableMenu(HashTable* ht)
{
	//HashTable* ht = Created();
	while (true)
	{
		cout << "Current table: " << endl;
		DisplayTable(ht);
		cout << endl;
		int choise = GetInput("Hash table menu: \n 1. Add\n 2. Delete\n \
3. Search\n 0. Exit\n Your input: ");
		switch (choise)
		{
			case 1:
			{
				string key, value;
				cout << "Enter key to add: ";
				cin >> key;
				cout << "Enter value to add: ";
				cin >> value;
				Add(ht, key, value);
				cout << endl;
				break;
			}

			case 2:
			{
				string key;
				cout << "Enter key to remove: ";
				cin >> key;
				Remove(ht, key);
				cout << endl;
				break;
			}

			case 3:
			{
				string key;
				cout << "Enter key to search: " << key << endl;
				string value = Search(ht, key);
				if (!value.empty())
				{
					cout << "Value: " << value << endl;
				}

				else
				{
					cout << "value not found" << endl;
				}

				break;
			}

			case 0:
				Free(ht);
				return;
			default:
				cout << "Error" << endl;
		}
	}
}