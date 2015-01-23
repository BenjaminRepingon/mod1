/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:24:11 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/23 17:46:36 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"

Triangle::Triangle( void ) : _shader( new Shader("Basic") )
{
	const float		vertexBuffer[] = {
		-0.5f, -0.5f, 0.0f,
		1.0f, 0.0, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.0, 1.0f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0, 0.0f, 1.0f
	};

	const int		indexBuffer[] = {
		0, 1, 2
	};

	glGenBuffers( 1, &this->_vbo );

	glBindBuffer( GL_ARRAY_BUFFER, this->_vbo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertexBuffer ), vertexBuffer, GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	glGenBuffers( 1, &this->_ibo );

	glBindBuffer( GL_ARRAY_BUFFER, this->_ibo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( indexBuffer ), indexBuffer, GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	return ;
}

Triangle::Triangle( Triangle const & src )
{
	*this = src;
}

Triangle::~Triangle( void )
{
	if ( this->_shader )
		delete this->_shader;
	return ;
}

Triangle &			Triangle::operator=( Triangle const & rhs )
{
	this->_vbo = rhs._vbo;

	return ( *this );
}

void				Triangle::update( void )
{

}

void				Triangle::render( Core const & core )
{
	(void)core;
	this->_shader->bind();
	glBindBuffer( GL_ARRAY_BUFFER, this->_vbo );
	glEnableVertexAttribArray( 0 );
	glEnableVertexAttribArray( 1 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * 4, 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_TRUE, 6 * 4, (void *)12 );

	Matrix4f	worldMatrix = getTransform()->getTransformation();
	Matrix4f	projectedMatrix = core.getCamera().getViewProjection() * worldMatrix;

	this->_shader->updateUniform( "T_MVP", projectedMatrix );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->_ibo );
	glDrawElements( GL_TRIANGLES, 3 /* nb vertex */, GL_UNSIGNED_INT, 0 );

	glDisableVertexAttribArray( 0 );
	glDisableVertexAttribArray( 1 );
	glUseProgram( 0 );
}
