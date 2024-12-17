#pragma once
#include <iostream>
#include <string>
#include <limits>

using namespace std;

//! \brief функция получения значения 
//! \param const string& ссылка на строку, которая не сможет быть изменена 
//! \param prompt для вывода на экран строки
int GetInput(const string& prompt);