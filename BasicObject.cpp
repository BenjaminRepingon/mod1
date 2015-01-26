/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicObject.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:31:09 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/25 16:00:18 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BasicObject.hpp"

BasicObject::BasicObject() :
	_mesh( 0 ),
	_shader( new Shader("Basic") )
{
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
	// this->getTransform()->rotate( Quaternion4f( Vector3f( 0, 1, 0 ), 1.0f * M_PI / 180.0f ) );
}

void			BasicObject::render( Core const & core )
{
	if ( this->_mesh )
		this->_mesh->render( core, * this->_shader, * this->getTransform() );
}

// SETTER
void			BasicObject::setMesh( Mesh * mesh )
{
	this->_mesh = mesh;
}
