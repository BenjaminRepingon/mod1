/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:55:14 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/21 11:41:52 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

#include <exception>
#include <iostream>

class Error : public std::exception
{
	public:
		Error( std::string error );
		Error( Error const & cpy );
		~Error( void ) throw();

		Error &			operator=( Error const & rhs );

		const char *	what( void ) const throw();
	private:
		Error( void );
		std::string		_msg;
};

#endif
