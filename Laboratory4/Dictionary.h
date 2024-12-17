#pragma once
#include "HashTableh.h"
#include "HashTableItem.h"

//! \brief dictionary struct
struct Dictionary
{
	//! \brief key to get element
	string Key;

	//! \brief value of element
	string Value;

	//! \brief pointer
	HashTable* Ht;
};

//! \brief dictionary initilization
//! \return dictionary
Dictionary* Init();

//! \brief insert element to dictionary
//! \param d pointer
//! \param key to get element
//! \param value of element
void Insert(Dictionary* d, const string& key, const string& value);

//! \brief delete element from dictionary
//! \param d pointer
//! \param key to get element
void Delete(Dictionary* d, const string& key);

//! \brief search element in dictionary
//! \param d pointer
//! \param key to get element
string Search(Dictionary* d, const string& key);

//! \brief free dictionary
//! \param d pointer
void Free(Dictionary* d);