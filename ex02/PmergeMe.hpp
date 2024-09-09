/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/07 12:08:13 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/09 14:44:23 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility> 
#include <algorithm>

#define SUCCESS 1
#define FAILURE -1

struct data_t
{
    std::string input;
    std::vector<int> nums;
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> main;
    std::vector<int> pend;
    int unevenNum;
    bool even;
};
