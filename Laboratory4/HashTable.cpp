#include "HashTableh.h"
#include "HashTableItem.h"
#include <iostream>
#include "HashBase.h"

using namespace std;

HashTable* CreateTable()
{
	HashTable* table = new HashTable;
	//int size = 5;
	//table->Size = size;
	table->Count = 0;
	table->Items = new HashTableItem * [INITIAL_SIZE];
	for (int i = 0; i < INITIAL_SIZE; ++i)
	{
		table->Items[i] = nullptr;
	}

	return table;
}

void Add(HashTable* table, const string& key, const string& value)
{
	int index = HashFunction(key.c_str(), HASH_BASE, table->Size);
	HashTableItem* newItem = new HashTableItem{ key, value};
	if (!table->Items[index])
	{
		table->Items[index] = newItem;
	}

	else
	{
		HashTableItem* current = table->Items[index];
		while (current->Next)
		{
			if (current->Key == key)
			{
				delete newItem;
				return;
			}

			current = current->Next;
		}

		current->Next = newItem;
	}

	table->Count++;
	if (static_cast<float>(table->Count) / table->Size > FACTORIAL)
	{
		Rehash(table, table->Size * GROWTH_FACTOR);
	}
}

void Remove(HashTable* table, const string& key)
{
	int index = HashFunction(key.c_str(), HASH_BASE, table->Size);
	HashTableItem* current = table->Items[index];
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
				table->Items[index] = current->Next;
			}

			delete current;
			table->Count--;
			return;
		}

		previous = current;
		current = current->Next;
	}

	if (static_cast<float>(table->Count) / table->Size < \
		FACTORIAL / GROWTH_FACTOR)
	{
		Rehash(table, table->Size / GROWTH_FACTOR);
	}
}

string Search(HashTable* table, const string& key)
{
	int index = HashFunction(key.c_str(), 31, table->Size);
	HashTableItem* current = table->Items[index];
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

void Free(HashTable* table)
{
	for (int i = 0; i < table->Size; ++i)
	{
		HashTableItem* current = table->Items[i];
		while (current)
		{
			HashTableItem* temp = current;
			current = current->Next;
			delete temp;
		}
	}

	delete[] table->Items;
	delete table;
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

/*void Rehash(HashTable* ht)
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
}*/

void Rehash(HashTable* table, int newSize)
{
	HashTableItem** oldNode = table->Items;
	int oldSize = table->Size;

	table->Size = newSize;
	table->Items = new HashTableItem * [newSize];
	for (int i = 0; i < newSize; ++i)
	{
		table->Items[i] = nullptr;
	}

	for (int i = 0; i < oldSize; ++i)
	{
		HashTableItem* item = oldNode[i];
		while (item != nullptr)
		{
			HashTableItem* nextNode = item->Next;
			int newIndex = HashFunction(item->Key.c_str(), 31, table->Size);
			item->Next = table->Items[newIndex];
			table->Items[newIndex] = item;
			item = nextNode;
		}
	}

	delete[] oldNode;
}
