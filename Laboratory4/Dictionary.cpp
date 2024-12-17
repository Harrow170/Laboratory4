#include "Dictionary.h"
#include "HashTableh.h"
#include <iostream>

using namespace std;

Dictionary* Init()
{
	Dictionary* item = new Dictionary;
	item->Ht = new HashTable;
	item->Ht->Size = 5;
	item->Ht->Items = new HashTableItem * [5]();
	string key, value;
	item->Key = key;
	item->Value = value;
	return item;
}

void Insert(Dictionary* d, const string& key, const string& value)
{
	if (static_cast<float>(d->Ht->Count) / d->Ht->Size > FACTORIAL)
	{
		Rehash(d->Ht);
	}

	int index = HashFunction(key.c_str(), 31, d->Ht->Size);
	HashTableItem* current = d->Ht->Items[index];
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
	newItem->Next = d->Ht->Items[index];
	d->Ht->Items[index] = newItem;
	d->Ht->Count++;

	//Add(d->Ht, key, value);
	//HashTableItem* current = d->Ht->Items[index];
}

void Delete(Dictionary* d, const string& key)
{
	Remove(d->Ht, key);
}

string Search(Dictionary* d, const string& key)
{
	int index = HashFunction(key.c_str(), 31, d->Ht->Size);
	HashTableItem* current = d->Ht->Items[index];
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

void Free(Dictionary* d)
{
	Free(d->Ht);
}