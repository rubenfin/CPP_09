/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/05 11:33:13 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/05 17:20:57 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN data;
    std::string argumentInput(av[1]);
    
    if (ac != 2)
        return(err(), EXIT_FAILURE);
    if (!checkArguments(data, argumentInput))
        return(EXIT_FAILURE);
    if (!reversePolishNotation(data))
        return(EXIT_FAILURE);
    return (EXIT_SUCCESS);
}