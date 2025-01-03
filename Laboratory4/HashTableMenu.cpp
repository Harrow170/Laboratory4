#include "HashTableh.h"
#include "GetInput.h"
#include <iostream>

void DisplayTable(HashTable* table)
{
	for (int i = 0; i < table->Size; ++i)
	{
		cout << "[" << i << "]: ";
		HashTableItem* current = table->Items[i];
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

void HashTableMenu(HashTable* table)
{
	//HashTable* ht = Created();
	while (true)
	{
		cout << "Current table: " << endl;
		DisplayTable(table);
		cout << endl;
		int choise = GetInput("Hash table menu: \n 1. Add\n 2. Delete\n \
3. Search\n 0. Exit\n Your input: ");
		switch (choise)
		{
			case 1:
			{
				int key = GetInput("Enter key to add: ");
				int value = GetInput("Enter value to add: ");
				Add(table, to_string(key), to_string(value));
				cout << endl;
				break;
			}

			case 2:
			{
				int key = GetInput("Enter key to remove: ");
				string value = Search(table, to_string(key));
				if (!value.empty())
				{
					Remove(table, to_string(key));
				}
				else
				{
					cout << "HAHHAHAHHAH, no " << endl;
				}

				break;
			}

			case 3:
			{
				int key = GetInput("Enter key to search: ");
				string value = Search(table, to_string(key));
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
				Free(table);
				return;
			default:
				cout << "Error" << endl;
		}
	}
}