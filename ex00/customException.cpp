/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   customException.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/02 12:54:20 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/09/02 12:54:32 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "customException.hpp"

customException::customException(const char *msg) : _msg(msg)
{
}

const char *customException::what() const throw()
{
    return (_msg.c_str());
}