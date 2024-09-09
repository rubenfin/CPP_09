/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 13:37:13 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/04 15:46:02 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "customException.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <utility>
#include <array>
#include <iomanip>
#include <algorithm>
#include <list>
#include <time.h>

const std::array<int, 12> monthsAndDays = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

typedef struct data_t
{
    std::string filename;
    std::ifstream file;
    std::ifstream databaseFile;
    std::map<time_t, double> database;
} data_t;


/* BITCOIN EXCHANGE */
void findExchange(data_t &data, const std::string &date, const time_t& time, const double &exchange);

/* HANDLE INPUT */
bool checkDateInput(std::string& date, time_t& timeFound);
bool checkExchangeInput(std::string &exchange_rate);
void initializeInput(data_t &data);
bool errMsg(const std::string &str);

/* HANDLE DATA */
bool checkDateData(std::string& date, time_t& timeFound);
bool checkExchangeData(std::string &exchange_rate);
void initializeData(data_t &data);

/* UTILS */
void openFileCheck(const char* filename, std::ifstream &file);
void trimSpaces(std::string &str);
time_t makeTime(int year, int month, int day);
void databaseOrderCheck(const std::map<time_t, double>& database);