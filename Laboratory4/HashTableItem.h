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
};

//! \brief node create
//! \param key to get element
//! \param value of element
HashTableItem* Create(const string& key, const string& value);