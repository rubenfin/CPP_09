/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 13:37:11 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/05 11:17:37 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    data_t data;
    
    try
    {
        if (ac == 2)
        {
            initializeData(data);
            if (data.database.empty())
                throw customException("Error: didn't find any good database information");
            data.filename = av[1];
            initializeInput(data);
        }
        else
            throw customException("Error: usage: ./btc [filename.csv]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
