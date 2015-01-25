/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:06:55 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/24 11:58:08 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.hpp"

Cube::Cube( void ) : _shader( new Shader("Basic") )
{

	const float vertexPositions[] = {
		-1.0f,-1.0f,1.0f,
		-1.0f,-1.0f, 3.0f,
		-1.0f, 1.0f, 3.0f,
		1.0f, 1.0f,1.0f,
		-1.0f,-1.0f,1.0f,
		-1.0f, 1.0f,1.0f,
		1.0f,-1.0f, 3.0f,
		-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f, 1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,1.0f,
		-1.0f, 1.0f, 3.0f,
		-1.0f, 1.0f,1.0f,
		1.0f,-1.0f, 3.0f,
		-1.0f,-1.0f, 3.0f,
		-1.0f,-1.0f,1.0f,
		-1.0f, 1.0f, 3.0f,
		-1.0f,-1.0f, 3.0f,
		1.0f,-1.0f, 3.0f,
		1.0f, 1.0f, 3.0f,
		1.0f,-1.0f,1.0f,
		1.0f, 1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f, 1.0f, 3.0f,
		1.0f,-1.0f, 3.0f,
		1.0f, 1.0f, 3.0f,
		1.0f, 1.0f,1.0f,
		-1.0f, 1.0f,1.0f,
		1.0f, 1.0f, 3.0f,
		-1.0f, 1.0f,1.0f,
		-1.0f, 1.0f, 3.0f,
		1.0f, 1.0f, 3.0f,
		-1.0f, 1.0f, 3.0f,
		1.0f,-1.0f, 3.0f,
		0.583f, 0.771f, 0.014f,
		0.609f, 0.115f, 0.436f,
		0.327f, 0.483f, 0.844f,
		0.822f, 0.569f, 0.201f,
		0.435f, 0.602f, 0.223f,
		0.310f, 0.747f, 0.185f,
		0.597f, 0.770f, 0.761f,
		0.559f, 0.436f, 0.730f,
		0.359f, 0.583f, 0.152f,
		0.483f, 0.596f, 0.789f,
		0.559f, 0.861f, 0.639f,
		0.195f, 0.548f, 0.859f,
		0.014f, 0.184f, 0.576f,
		0.771f, 0.328f, 0.970f,
		0.406f, 0.615f, 0.116f,
		0.676f, 0.977f, 0.133f,
		0.971f, 0.572f, 0.833f,
		0.140f, 0.616f, 0.489f,
		0.997f, 0.513f, 0.064f,
		0.945f, 0.719f, 0.592f,
		0.543f, 0.021f, 0.978f,
		0.279f, 0.317f, 0.505f,
		0.167f, 0.620f, 0.077f,
		0.347f, 0.857f, 0.137f,
		0.055f, 0.953f, 0.042f,
		0.714f, 0.505f, 0.345f,
		0.783f, 0.290f, 0.734f,
		0.722f, 0.645f, 0.174f,
		0.302f, 0.455f, 0.848f,
		0.225f, 0.587f, 0.040f,
		0.517f, 0.713f, 0.338f,
		0.053f, 0.959f, 0.120f,
		0.393f, 0.621f, 0.362f,
		0.673f, 0.211f, 0.457f,
		0.820f, 0.883f, 0.371f,
		0.982f, 0.099f, 0.879f

	};

	glGenBuffers( 1, &this->_positionBuff );

	glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	// glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );

	return ;
}

Cube::Cube( Cube const & src )
{
	*this = src;
}

Cube::~Cube( void )
{
	if ( this->_shader )
		delete this->_shader;
	return ;
}

Cube &			Cube::operator=( Cube const & rhs )
{
	this->_positionBuff = rhs._positionBuff;

	return ( *this );
}

void				Cube::update( void )
{

}

void				Cube::render( Core const & core )
{
	(void)core;
	this->_shader->bind();
	glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	glEnableVertexAttribArray( 0 );
	glEnableVertexAttribArray( 1 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (void *)( 108 * sizeof(float) ) );
	// glVertexAttribPointer( 3, 3, GL_FLOAT, GL_FALSE, 0, (void *)( 24 * sizeof(float) ) );
	// glVertexAttribPointer( 4, 3, GL_FLOAT, GL_FALSE, 0, (void *)( 36 * sizeof(float) ) );
	// glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (void *)( 60 * sizeof(float) ) );

	Matrix4f	worldMatrix = getTransform()->getTransformation();
	Matrix4f	projectedMatrix = core.getCamera().getViewProjection() * worldMatrix;

	this->_shader->updateUniform( "T_MVP", projectedMatrix );

	glDrawArrays(GL_TRIANGLES, 0, 36);
	// glDrawArrays( GL_POLYGON, 0, 4 );

	glDisableVertexAttribArray( 0 );
	// glDisableVertexAttribArray( 1 );
	glUseProgram( 0 );
}
