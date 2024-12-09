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
	Add(d->Ht, key, value);
}

void Delete(Dictionary* d, const string& key)
{
	Remove(d->Ht, key);
}

string Search(Dictionary* d, const string& key)
{
	Search(d, key);
	return "";
}

void Free(Dictionary* d)
{
	Free(d->Ht);
}