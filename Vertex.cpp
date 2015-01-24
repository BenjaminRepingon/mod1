/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:38:30 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/24 18:22:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vertex.hpp"


Vertex::Vertex( void )
{
	return ;
}

Vertex::Vertex( Vector3f const & pos, Vector3f const & color, Vector3f const & normal ) :
	_pos( pos ),
	_color( color ),
	_normal( normal )
{
	return ;
}

Vertex::Vertex( float x, float y, float z ) :
	_pos( x, y, z ),
	_color( 1, 1, 1 ),
	_normal( 0, 1, 0 )
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
** FUNCTIONS
*/
float *			Vertex::createBuffer( std::vector<Vertex> const & vertices )
{
	float *		res = new float[vertices.size() * sizeof( Vertex )];
	size_t		index = 0;

	std::vector<Vertex>::const_iterator it;

	for ( it = vertices.begin(); it != vertices.end(); it++ )
	{
		res[index++] = it->getPos().getX();
		res[index++] = it->getPos().getY();
		res[index++] = it->getPos().getZ();
		res[index++] = it->getColor().getX();
		res[index++] = it->getColor().getY();
		res[index++] = it->getColor().getZ();
		res[index++] = it->getNormal().getX();
		res[index++] = it->getNormal().getY();
		res[index++] = it->getNormal().getZ();
	}
	return ( res );
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
