/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:38:30 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 18:56:00 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vertex.hpp"


Vertex::Vertex( void )
{
	return ;
}

Vertex::Vertex( Vector3f const & pos, Vector3f const & color, Vector3f const & normal ) : _pos( pos ), _color( color ), _normal( normal )
{
	return ;
}

Vertex::Vertex( float x, float y, float z ) : _pos( Vector3f(x, y, z) ), _color( ), _normal( )
{
	return ;
}

Vertex::Vertex( Vertex const & src )
{
	*this = src;
	return ;
}

Vertex::~Vertex( void )
{
	return ;
}

/*
** OPERATOR
*/
Vertex &		Vertex::operator=( Vertex const & lhs )
{
	this->_pos = lhs.getPos();
	this->_color = lhs.getColor();
	this->_normal = lhs.getNormal();

	return ( *this );
}

/*
** GET
*/
Vector3f		Vertex::getPos( void ) const
{
	return ( this->_pos );
}

Vector3f		Vertex::getColor( void ) const
{
	return ( this->_color );
}

Vector3f		Vertex::getNormal( void ) const
{
	return ( this->_normal );
}

/*
** SET
*/
void			Vertex::setPos( Vector3f & data )
{
	this->_pos = data;
	return ;
}

void			Vertex::setColor( Vector3f & data )
{
	this->_color = data;
	return ;
}

void			Vertex::setNormal( Vector3f & data )
{
	this->_normal = data;
	return ;
}
