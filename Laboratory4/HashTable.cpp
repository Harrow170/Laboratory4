#include "HashTableh.h"
#include "HashTableItem.h"
#include <iostream>

using namespace std;

HashTable* Created()
{
	HashTable* table = new HashTable;
	int size = 5;
	table->Size = size;
	table->Count = 0;
	table->Items = new HashTableItem * [size];
	for (int i = 0; i < size; ++i)
	{
		table->Items[i] = nullptr;
	}

	return table;
}

void Add(HashTable* ht, const string& key, const string& value)
{
	if (static_cast <float> (ht->Count) / ht->Size >= FACTORIAL)
	{
		Rehash(ht);
	}

	int index = HashFunction(key.c_str(), 31, ht->Size);
	HashTableItem* newItem = new HashTableItem{ key, value, nullptr };
	if (!ht->Items[index])
	{
		ht->Items[index] = newItem;
	}

	else
	{
		HashTableItem* current = ht->Items[index];
		while (current->Next)
		{
			if (current->Key == key)
			{
				cout << "Duplicate " << endl;
				delete newItem;
				return;
			}

			current = current->Next;
		}

		current->Next = newItem;
	}

	ht->Count++;
}

void Remove(HashTable* ht, const string& key)
{
	int index = HashFunction(key.c_str(), 31, ht->Size);
	HashTableItem* current = ht->Items[index];
	HashTableItem* previous = nullptr;
	while (current)
	{
		if (current->Key == key)
		{
			if (previous)
			{
				previous->Next = current->Next;
			}

			else
			{
				ht->Items[index] = current->Next;
			}

			delete current;
			ht->Count--;
			return;
		}

		previous = current;
		current = current->Next;
	}
}

string Search(HashTable* ht, const string& key)
{
	int index = HashFunction(key.c_str(), 31, ht->Size);
	HashTableItem* current = ht->Items[index];
	while (current)
	{
		if (current->Key == key)
		{
			return current->Value;
		}

		current = current->Next;
	}

	return "";
}

void Free(HashTable* ht)
{
	for (int i = 0; i < ht->Size; ++i)
	{
		HashTableItem* current = ht->Items[i];
		while (current)
		{
			HashTableItem* temp = current;
			current = current->Next;
			delete temp;
		}
	}

	delete[] ht->Items;
	delete ht;
}

int HashFunction(const char* str, int a, int size)
{
	int hash = 0;
	for (; *str != '\0'; str++)
	{
		hash = (hash * a + *str) % size;
	}

	return hash;
}

void Rehash(HashTable* ht)
{
	int oldSize = ht->Size;
	ht->Size *= GROWTH_FACTOR;
	HashTableItem** newItem = new HashTableItem * [ht->Size];
	for (int i = 0; i < ht->Size; ++i)
	{
		newItem[i] = nullptr;
	}

	for (int i = 0; i < oldSize; ++i)
	{
		HashTableItem* item = ht->Items[i];
		while (item)
		{
			HashTableItem* nexItem = item->Next;
			int newIndex = HashFunction(item->Key.c_str(), 31, ht->Size);
			item->Next = newItem[newIndex];
			newItem[newIndex] = item;
			item = nexItem;
		}
	}

	delete[] ht->Items;
	ht->Items = newItem;
}