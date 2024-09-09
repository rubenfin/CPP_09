/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handleInput.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 11:43:50 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/04 15:31:11 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkDateInput(std::string& date, time_t& timeFound)
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
        int iYear = std::stoll(year);
        int iMonth = std::stoll(month);
        int iDay = std::stoll(day);

        if (iYear < 1900 || iYear > 2024)
            return (errMsg("Year should be between 0 and 2024"));
        if (iMonth < 0 || iMonth > 12)
            return (errMsg("Month should be between 0 and 12"));
        int maxDays = monthsAndDays[iMonth - 1];
        if (iYear % 4 == 0 && iMonth == 2)
            maxDays += 1;
        if (iDay < 0 || iDay > maxDays)
             return errMsg("Day should be between 0 and " + std::to_string(maxDays));
            
        timeFound = makeTime(iYear, iMonth, iDay);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (false);
    }
    
    return (true);
}

bool checkExchangeInput(std::string &exchange_rate)
{
    long long llExchange;
    
    trimSpaces(exchange_rate);
    if (exchange_rate.empty())
        return(errMsg("Error: Exchange rate field is empty"));
    if (exchange_rate.at(0) == '-')
        return(errMsg("Error: not a positive number"));
    else if (!isdigit(exchange_rate.at(0)))
        return(errMsg("Error: exchange rate doesn't start with a number"));
    
    for (char &c : exchange_rate)
    {
        if (!isdigit(c) && c != '.')
            return(errMsg("Error: Exchange rate has a non-digit character"));
    }
    try
    {
        llExchange = std::stoll(exchange_rate);
        if (llExchange > 1000 || llExchange < 0)    
            return(errMsg("Error: Invalid exchange rate"));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (false);
    }
    return(true);
}

void initializeInput(data_t &data)
{
    std::string line;
    std::size_t pos;
    std::string date;
    std::string value;
    time_t timeFound;
    if (data.filename.empty())
        throw customException("Error: filename is empty");
    openFileCheck(data.filename.c_str(), data.file);
    while(std::getline(data.file, line))
    {
        timeFound = 0;
        if (line.empty() || line.find("date | value") != std::string::npos)
            continue;
        pos = line.find('|');
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            if (!checkDateInput(date, timeFound))
                continue ;
            value = line.substr(pos + 1, pos - line.size());
            if (!checkExchangeInput(value))
                continue;
            findExchange(data, date, timeFound, std::stod(value));
        }
        else
            errMsg("Error: couldn't find '|' separator");
    }
    
}