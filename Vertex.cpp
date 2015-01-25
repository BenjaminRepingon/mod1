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

Vertex::Vertex( glm::vec3 const & pos, glm::vec3 const & color, glm::vec3 const & normal ) :
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
		res[index++] = it->getPos().x;
		res[index++] = it->getPos().y;
		res[index++] = it->getPos().z;
		res[index++] = it->getColor().x;
		res[index++] = it->getColor().y;
		res[index++] = it->getColor().z;
		res[index++] = it->getNormal().x;
		res[index++] = it->getNormal().y;
		res[index++] = it->getNormal().z;
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
glm::vec3		Vertex::getPos( void ) const
{
	return ( this->_pos );
}

glm::vec3		Vertex::getColor( void ) const
{
	return ( this->_color );
}

glm::vec3		Vertex::getNormal( void ) const
{
	return ( this->_normal );
}

/*
** SET
*/
void			Vertex::setPos( glm::vec3 & data )
{
	this->_pos = data;
	return ;
}

void			Vertex::setColor( glm::vec3 & data )
{
	this->_color = data;
	return ;
}

void			Vertex::setNormal( glm::vec3 & data )
{
	this->_normal = data;
	return ;
}
