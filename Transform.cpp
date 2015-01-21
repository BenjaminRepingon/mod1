/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 17:40:25 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Transform.hpp"

Transform::Transform()
{
	return ;
}

Transform::Transform( Transform const & src )
{
	*this= src;
}

Transform::~Transform( void )
{
	return ;
}

Transform &	Transform::operator=( Transform const & rhs )
{
	if ( this != &rhs )
	{
		this->_pos = rhs.getPos();
		this->_rot = rhs.getRot();
		this->_scale = rhs.getScale();
	}
	return ( *this );
}

// GETTER

Vector3f			Transform::getPos() const
{
	return ( this->_pos );
}

Quaternion			Transform::getRot() const
{
	return ( this->_rot );
}

Vector3f			Transform::getScale() const
{
	return ( this->_scale );
}
