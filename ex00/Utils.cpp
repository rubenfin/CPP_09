/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 11:06:34 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/05 11:17:34 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
#include <string.h>

time_t makeTime(int year, int month, int day)
{
    struct tm t;
    
    memset(&t, 0, sizeof(struct tm));
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    
    return (mktime(&t));
}

bool errMsg(const std::string &msg)
{
    std::cerr << msg << std::endl;
    return (false);
}

void openFileCheck(const char* filename, std::ifstream &file)
{
    file.open(filename, std::ios::in);
    if (!file.is_open())
        throw customException("Error: file couldn't be opened");
    else if (file.peek() == EOF)
        throw customException("Error: file is empty");
}

void trimSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}
