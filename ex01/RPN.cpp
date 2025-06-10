/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/05 11:33:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/05 17:16:20 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int err(void)
{
    std::cerr << "Error" << std::endl;
    return (FAILURE);
}

int validChar(const char& c)
{
    return(isdigit(c) || c == '*' || c == '/' || c == '+' || c == '-' || c == ' ');   
}

int isAnOperator(const char& c)
{
    return(c == '*' || c == '/' || c == '+' || c == '-');   
}

int checkArguments(RPN &data, std::string &arg)
{
    if (arg.empty())
        return (false);
    for (char &c : arg)
    {
        if (validChar(c))
            data.input += c;
        else
            return(err());
    }
    return (SUCCES);
}

int calculateOperations(RPN &data, const char& c)
{
    int numOne = 0;
    int numTwo = 0;
    int sum = 0;

    if (data.stack.size() < 2)
        return (err());
    numTwo = data.stack.top();
    data.stack.pop();
    numOne = data.stack.top();
    data.stack.pop();
    
    if (c == '+')
        sum = numOne + numTwo;
    else if (c == '-')
        sum = numOne - numTwo;
    else if (c == '*')
        sum = numOne * numTwo;
    else if (c == '/')
    {
        if (numTwo == 0)
            return(err());
        sum = numOne / numTwo;
    }
    data.stack.push(sum);
    return (SUCCES);
}

int reversePolishNotation(RPN &data)
{
    std::string savedNum;
    
    for (char &c : data.input)
    {
        if (c != ' ' && !isAnOperator(c))
            savedNum += c;
        else if (c == ' ' && !savedNum.empty())
        {
            try 
            {
                data.stack.push(std::stoi(savedNum));
            }
            catch (const std::exception &e)
            {
                return (err());
            }
            savedNum = "";
        }
        else if (isAnOperator(c))
        {
            if (!calculateOperations(data, c))
                return (err());
        }
    }
    if (data.stack.size() == 1)
        std::cout << "Final Answer: " << data.stack.top() << std::endl;
    else
        return(err());
    return (SUCCES);
}