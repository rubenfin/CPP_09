/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 13:37:15 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/04 15:40:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void findExchange(data_t &data, const std::string &date, const time_t& time, const double &exchange)
{
    std::map<time_t, double>::iterator it = data.database.find(time);
    if (it == data.database.end())
    {
        it = data.database.lower_bound(time);
        if (it == data.database.end() || it == data.database.begin())
        {
            errMsg("Error: couldn't find exact date or any lower date");
            return;
        }
        it--;
    }
    std::cout << date << " => " << exchange << " = " << (exchange * it->second) << std::endl;
}
