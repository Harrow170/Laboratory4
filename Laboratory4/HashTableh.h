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

//! \brief size of table
const int INITIAL_SIZE = 5;

//! \brief growthfactor for resize
const int GROWTH_FACTOR = 2;

//! \brief constant when resize
const float FACTORIAL = 0.7;

//! \brief hash table init
//! \return hash table
HashTable* CreateTable();

//! \brief add to table
//! \param ht pointer
//! \param key to get element
//! \param value of element
void Add(HashTable* table, const string& key, const string& value);

//! \brief remove from table
//! \param ht pointer
//! \param key to get element
void Remove(HashTable* table, const string& key);

//! \brief search in table
//! \param ht pointer
//! \param key to get element
string Search(HashTable* table, const string& key);

//! \brief free table
//! \param ht pointer
void Free(HashTable* table);

//! \brief hash function
//! \param str = string
//! \param a for function work
//! \param size to mujltiply
int HashFunction(const char* str, int a, int size);

//! \brief rehash table
//! \param ht pointer
//! \param newSize new size btw
void Rehash(HashTable* table, int newSize);