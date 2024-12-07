#pragma once
#include <string>

using namespace std;

struct HashTableItem
{
	string Key;
	string Value;
	HashTableItem* Next;
};

HashTableItem* Create(const string& key, const string& value);