#pragma once
#include <string>

using namespace std;
//! \brief node of table
struct HashTableItem
{
	//! \brief key to get element
	string Key;

	//! \brief value of element
	string Value;

	//! \brief pointer to next element
	HashTableItem* Next;

	//! \brief constructor
	HashTableItem(const string& key, const string& value) : Key(key), Value(value), Next(nullptr) {};
};