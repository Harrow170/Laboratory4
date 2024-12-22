#pragma once
#include "HashTableItem.h"
#include <string>

using namespace std;

//! \brief Hash table struct
struct HashTable
{
	//! \brief pointer to node
	HashTableItem** Items;

	//! \brief size of table
	int Size;

	//! \brief count of elements
	int Count;
};

//! \brief growthfactor for resize
const int GROWTH_FACTOR = 2;

//! \brief constant when resize
const float FACTORIAL = 0.7;

//! \brief hash table init
//! \return hash table
HashTable* Created();

//! \brief add to table
//! \param ht pointer
//! \param key to get element
//! \param value of element
void Add(HashTable* ht, const string& key, const string& value);

//! \brief remove from table
//! \param ht pointer
//! \param key to get element
void Remove(HashTable* ht, const string& key);

//! \brief search in table
//! \param ht pointer
//! \param key to get element
string Search(HashTable* ht, const string& key);

//! \brief free table
//! \param ht pointer
void Free(HashTable* ht);

//! \brief hash function
//! \param str = string
//! \param a for function work
//! \param size to mujltiply
int HashFunction(const char* str, int a, int size);

//! \brief rehash table
//! \param ht pointer
//! \param newSize new size btw
void Rehash(HashTable* ht, int newSize);