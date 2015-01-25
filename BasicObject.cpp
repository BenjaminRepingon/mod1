/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicObject.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:31:09 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 17:00:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BasicObject.hpp"

BasicObject::BasicObject() :
	_mesh( 0 ),
	_shader( new Shader("Basic") )
{
	this->_matrix = glm::mat4( 1 );
	return ;
}

BasicObject::BasicObject( BasicObject const & src )
{
	*this= src;
}

BasicObject::~BasicObject( void )
{
	return ;
}

BasicObject &	BasicObject::operator=( BasicObject const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void			BasicObject::update( void )
{

}

void			BasicObject::render( Core const & core )
{
	if ( this->_mesh )
		this->_mesh->render( core, * this->_shader, * getMatrix() );
}

// SETTER
void			BasicObject::setMesh( Mesh * mesh )
{
	this->_mesh = mesh;
}
