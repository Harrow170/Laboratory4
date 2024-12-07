#pragma once
#include "HashTableh.h"

struct Dictionary
{
	string Key;
	string Value;
	HashTable* Ht;
};

Dictionary* Init();

void Insert(Dictionary* d, const string& key, const string& value);

void Delete(Dictionary* d, const string& key);

string Search(Dictionary* d, const string& key);

void Free(Dictionary* d);