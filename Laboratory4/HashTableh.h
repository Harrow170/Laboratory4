#pragma once
#include "HashTableItem.h"
#include <string>

using namespace std;

struct HashTable
{
	HashTableItem** Items;
	int Size;
	int Count;
};

const double GROWTH_FACTOR = 1.5;
const float FACTORIAL = 0.7;

HashTable* Created();

void Add(HashTable* ht, const string& key, const string& value);

void Remove(HashTable* ht, const string& key);

string Search(HashTable* ht, const string& key);

void Free(HashTable* ht);

int HashFunction(const char* str, int a, int size);

void Rehash(HashTable* ht);