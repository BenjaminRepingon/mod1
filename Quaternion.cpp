/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quaternion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:40:45 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 17:40:53 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Quaternion.hpp"

Quaternion::Quaternion()
{
	return ;
}

Quaternion::Quaternion( Quaternion const & src )
{
	*this= src;
}

Quaternion::~Quaternion( void )
{
	return ;
}

Quaternion &	Quaternion::operator=( Quaternion const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}
