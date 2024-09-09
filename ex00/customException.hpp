/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   customException.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/02 12:53:31 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/02 12:53:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>

class customException : public std::exception
{
private:
    std::string _msg;
public:
    customException(const char *msg);
    const char* what() const throw() override;
};