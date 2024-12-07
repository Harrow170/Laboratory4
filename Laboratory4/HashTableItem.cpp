#include "HashTableh.h"

HashTableItem* Create(const string& key, const string& value)
{
	HashTableItem* item = new HashTableItem;
	item->Key = key;
	item->Value = value;
	item->Next = nullptr;
	return item;
}