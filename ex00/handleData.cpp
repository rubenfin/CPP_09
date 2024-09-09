/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handleData.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 11:18:18 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/04 15:47:23 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkDateData(std::string& date, time_t& foundTime)
{
    std::size_t sign_one;
    std::size_t sign_two;
    std::string year;
    std::string month;
    std::string day;
    
    int minusSign = 0;
    trimSpaces(date);
    if (date.empty())
        return(errMsg("Error: date field is empty"));
    if (!isdigit(date.at(0)))
      return(errMsg("Error: a date doesn't start with a digit"));
        
    for (char &c : date)
    {
        if (c == '-')
            minusSign++;
        if (minusSign > 3)
            return (errMsg("Error: too many minus signs"));
        if (c != '-' && !isdigit(c))
            return (errMsg("Error: found a non-digit character in the date"));
    }

    sign_one = date.find('-');
    sign_two = date.find('-', sign_one + 1);
    year = date.substr(0, sign_one);
    month = date.substr(sign_one + 1, (date.size() - 1) - sign_two);
    day = date.substr(sign_two + 1, date.size());
  
    try
    {
        int iYear = std::stod(year);
        int iMonth = std::stod(month);
        int iDay = std::stod(day);
        
        if (iYear < 1900 || iYear > 2024)
            return (errMsg("Year should be between 0 and 2024"));
        if (iMonth < 0 || iMonth > 12)
            return (errMsg("Month should be between 0 and 12"));
        int maxDays = monthsAndDays[iMonth - 1];
        if (iYear % 4 == 0 && iMonth == 2)
            maxDays += 1;
        if (iDay < 0 || iDay > maxDays)
            return (errMsg("Day should be between 0 and " + std::to_string(maxDays)));
        foundTime = makeTime(iYear, iMonth, iDay);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (false);
    }
    
    return (true);
}

bool checkExchangeData(std::string &exchange_rate)
{
    long long llExchange;
    
    trimSpaces(exchange_rate);
    if (exchange_rate.empty())
        return(errMsg("Error: Exchange rate field is empty"));

    if (!isdigit(exchange_rate.at(0)))
        return(errMsg("Error: Exchange doesn't start with a digit"));
    
    for (char &c : exchange_rate)
    {
        if (!isdigit(c) && c != '.')
            return(errMsg("Error: Exchange rate has a non-digit character"));
    }
    
    try
    {
        llExchange = std::stoll(exchange_rate);
        if (llExchange > INT32_MAX || llExchange < 0)    
            return(errMsg("Error: Invalid exchange rate"));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (false);
    }
    return(true);
}

void initializeData(data_t &data)
{
    std::string line;
    std::string date;
    std::string exchange;
    std::size_t pos;
    time_t timeFound;
    
    openFileCheck("data.csv", data.databaseFile);
    while(std::getline(data.databaseFile, line))
    {
        timeFound = {0};
        if (line.empty() || line.find("date,exchange_rate") != std::string::npos)
            continue;
        pos = line.find(',');
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            if (!checkDateData(date, timeFound))
                continue ;
            exchange = line.substr(pos + 1, pos - line.size());
            if (!checkExchangeData(exchange))
                continue;
            data.database.insert({timeFound, std::stod(exchange)});
        }
        else
            errMsg("Error: couldn't find ',' seperator");
    }
    
}
