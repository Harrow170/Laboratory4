#include "Dictionary.h"
#include "HashTableh.h"

using namespace std;

Dictionary* Init()
{
	Dictionary* item = new Dictionary;
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
	Search(d->Ht, key);
	return "";
}

void Free(Dictionary* d)
{
	Free(d->Ht);
}