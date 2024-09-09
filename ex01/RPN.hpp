/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/05 11:33:26 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/05 16:04:53 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stack>

#define SUCCES 1
#define FAILURE 0

struct RPN
{
    std::string input;
    std::stack<int> stack;
    char currentChar;
};

int err(void);
int validChar(const char& c);
int checkArguments(RPN &data, std::string &arg);
int reversePolishNotation(RPN &data);