/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/07 12:08:19 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/09 14:59:16 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> generateJacobsthal(int N) {
    std::vector<int> jacobsthal;
    int J0 = 0, J1 = 1;
    
    jacobsthal.push_back(J1);

    int nextJacobsthal = J1;
    int n = 2;
    
    while (nextJacobsthal <= N) {
        nextJacobsthal = J1 + 2 * J0;
        if (nextJacobsthal <= N) {
            jacobsthal.push_back(nextJacobsthal);
        }
        J0 = J1;
        J1 = nextJacobsthal;
        n++;
    }
    return ( jacobsthal );
}



int parser(char *argument, data_t &data)
{
    data.input = argument; 
    std::istringstream iss(data.input);
    int number;
    
    while (iss >> number)
    {
        data.nums.push_back(number);
    }
    if (iss.fail() && !iss.eof())
    {
        std::cerr << "Error" << std::endl;
        return (FAILURE); 
    }
    data.even = (data.nums.size() % 2 == 0);
    for (size_t i = 0; i < (data.nums.size() - 1) + data.even; i+=2)
        data.pairs.emplace_back(data.nums.at(i), data.nums.at(i + 1));
    
    if (!data.even)
        data.unevenNum = data.nums.at(data.nums.size() - 1);

    for (const auto &p : data.pairs)
    {
        if (p.first > p.second)
        {
            data.main.emplace_back(p.first);
            data.pend.emplace_back(p.second);
        }
        else
        {
            data.main.emplace_back(p.second);
            data.pend.emplace_back(p.first);
        }
    }
    
    for (auto &p : data.pairs)
    {
        std::cout << p.first << " " << p.second << std::endl;
    }

    std::vector<int> jacobsthal = generateJacobsthal(data.pend.size());

    

    // std::sort(data.main.begin(), data.main.end());

    // std::cout << "Jacobsthal Numbers" << std::endl;
    // // for (int &i : jacobsthal)
    // {
    //     std::cout << i << " ";
    // }
    
    std::cout << std::endl;
    std::cout << "pend: ";
    for (int &i : data.pend)
        std::cout << i << ", ";

    std::cout << std::endl;
    std::cout << "main: ";
    for (int &i : data.main)
        std::cout << i << ", ";
    return (SUCCESS);
}

int main(int ac, char **av)
{
    data_t data;

    if (ac != 2)
        return (EXIT_FAILURE);
    if (parser(av[1], data) == FAILURE)
        return (EXIT_FAILURE);
    

    return (0);
}