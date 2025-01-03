#include "Dictionary.h"
#include "HashTableh.h"
#include <iostream>
#include "HashBase.h"

using namespace std;

Dictionary* CreateDictionary()
{
	Dictionary* item = new Dictionary;
	item->HashTable = new HashTable;
	item->HashTable->Size = 5;
	item->HashTable->Items = new HashTableItem * [5]();
	string key, value;
	item->Key = key;
	item->Value = value;
	return item;
}

void Insert(Dictionary* dictionary, const string& key, const string& value)
{
	//TODO: RSDN
	if (static_cast<float>(dictionary->HashTable->Count) / \
		dictionary->HashTable->Size > FACTORIAL)
	{
		Rehash(dictionary->HashTable, dictionary->HashTable->Size * GROWTH_FACTOR);
	}

	int index = HashFunction(key.c_str(), HASH_BASE, dictionary->HashTable->Size);
	HashTableItem* current = dictionary->HashTable->Items[index];
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			current->Value = value;
			return;
		}

		current = current->Next;
	}

	HashTableItem* newItem = new HashTableItem(key, value);
	newItem->Next = dictionary->HashTable->Items[index];
	dictionary->HashTable->Items[index] = newItem;
	dictionary->HashTable->Count++;

	//Add(d->Ht, key, value);
	//HashTableItem* current = d->Ht->Items[index];
}

void Delete(Dictionary* dictionary, const string& key)
{
	Remove(dictionary->HashTable, key);
}

string Search(Dictionary* dictionary, const string& key)
{
	int index = HashFunction(key.c_str(), HASH_BASE, dictionary->HashTable->Size);
	HashTableItem* current = dictionary->HashTable->Items[index];
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

void Free(Dictionary* dictionary)
{
	Free(dictionary->HashTable);
}