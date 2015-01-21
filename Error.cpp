/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:59:08 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/21 11:12:34 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

Error::Error( std::string error ) : std::exception(), _msg( error )
{
	return ;
}

Error::Error( Error const & cpy ) : std::exception()
{
	*this = cpy;

	return ;
}

Error::~Error( void ) throw()
{
	return ;
}

Error &			Error::operator=( Error const & rhs )
{
	this->_msg = rhs._msg;

	return ( *this );
}

const char *	Error::what( void ) const throw()
{
	return ( this->_msg.c_str() );
}
