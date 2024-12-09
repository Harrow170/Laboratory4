#include "Dictionary.h"
#include"GetInput.h"
#include "HashTableMenu.h"
#include <iostream>

using namespace std;

void DisplayDictionary(Dictionary* d)
{
	if (d == nullptr) {
		cout << "Dictionary not init." << endl;
		return;
	}

	if (d->Ht == nullptr) {
		cout << "Hash not init" << endl;
		return;
	}

	cout << "--- Dictionary ---" << endl;

	// Перебираем все элементы в хэш-таблице
	for (int i = 0; i < d->Ht->Size; ++i) {
		HashTableItem* item = d->Ht->Items[i]; // Получаем текущий бакет

		// Проверяем, есть ли элементы в бакете
		while (item != nullptr) {
			cout << "key: " << item->Key << ", value: " << item->Value << endl;
			item = item->Next; // Переход к следующему элементу в цепочке
		}
	}

	cout << "------------------------" << endl;
}

void DictionaryMenu(Dictionary* d)
{
	while (true)
	{
		cout << "Current Dictionary: " << endl;
		DisplayDictionary(d);
		cout << endl;
		int choice = GetInput("Dictionary menu: \n 1. Add\n 2. Remove\n 3. Search\n \
0. Exit\n Your Input: ");
		switch (choice)
		{
			case 1:
			{
				string key, value;
				cout << "Enter key to add; ";
				cin >> key;
				cout << "Enter value to add: ";
				cin >> value;
				Insert(d, key, value);
				break;
			}

			case 2:
			{
				string key;
				cout << "Enter key to remove: ";
				cin >> key;
				Delete(d, key);
				break;
			}

			case 3: 
			{
				string key;
				cout << "Enter key to search: ";
				cin >> key;
				string value = Search(d, key);
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
				Free(d);
				return;
			default:
				cout << "Error" << endl;
		}
	}
}