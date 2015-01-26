/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaterParticular.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:05:25 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 15:41:02 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WaterParticular.hpp"

// WaterParticular::WaterParticular( void ) : _shader( new Shader("Basic") )
// {
// 	const float vertexPositions[] = {
// 		0.5f, 0.5f, 0.5f,
// 		0.0f, 1.0f, 0.0f
// 	};

// 	glGenBuffers( 1, &this->_positionBuff );

// 	glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
// 	glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
// 	glBindBuffer( GL_ARRAY_BUFFER, 0 );

// 	return ;
// }

WaterParticular::WaterParticular( GLuint positionBuffer ) : _shader( new Shader("Basic") )
{
	this->_positionBuff = positionBuffer;
	return ;
}

WaterParticular::WaterParticular( WaterParticular const & src )
{
	*this = src;
}

WaterParticular::~WaterParticular( void )
{
	if ( this->_shader )
		delete this->_shader;
	return ;
}

WaterParticular &			WaterParticular::operator=( WaterParticular const & rhs )
{
	this->_positionBuff = rhs._positionBuff;

	return ( *this );
}

void				WaterParticular::update( void )
{

}

void				WaterParticular::render( Core const & core )
{
	(void)core;
	this->_shader->bind();
	glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	glEnableVertexAttribArray( 0 );
	glEnableVertexAttribArray( 1 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (void *)( 3 * sizeof(float) ) );

	Matrix4f	worldMatrix = getTransform()->getTransformation();
	Matrix4f	projectedMatrix = core.getCamera().getViewProjection() * worldMatrix;

	this->_shader->updateUniform( "T_MVP", projectedMatrix );

	glDrawArrays( GL_GEOMETRY_INPUT_TYPE, 0, 1 );

	glDisableVertexAttribArray( 0 );
	glDisableVertexAttribArray( 1 );
	glUseProgram( 0 );
}
