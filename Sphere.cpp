/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:32:33 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 11:54:04 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.hpp"
#include "Vector3f.hpp"
#include <iostream>
#include <Vector>
# include <cmath>

Sphere::Sphere( void ) : _shader( new Shader("Basic") )
{
	float		r = 1.0f;
	Vector3f	v = Vector3f( r, 0, -1.0f);
	Vector3f	pos;
	std::vector<float>		points;
	double			_rad;
	double			_cos;
	double			_sin;
	Vector3f		tmp;

	for (int j = 0; j < 360; ++j)
	{
		_rad = (float)j / 180.0f * 3.14159f;
		_cos = cos( _rad );
		_sin = sin( _rad );
		v =  Vector3f( r, (float) ( 0 * _cos - 1.0f * _sin ), (float) ( 0 * _sin + 1.0f * _cos ) );

		for (int i = 0; i < 360; ++i)
		{
			tmp = pos + v;
			points.push_back(tmp.getX());
			points.push_back(tmp.getY());
			points.push_back(tmp.getZ());
			_rad = (float)i / 180.0f * 3.14159f;
			_cos = cos( _rad );
			_sin = sin( _rad );
			v = Vector3f( (float) ( v.getX() * _cos - v.getY() * _sin ), (float) ( v.getX() * _sin + v.getY() * _cos ), v.getZ() );
		}
	}


	for (int i = 0; i < 129600 ; ++i)
	{
		points.push_back(1.0f);
		points.push_back(0);
		points.push_back(0);
	}

	glGenBuffers( 1, &this->_positionBuff );

	glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	glBufferData( GL_ARRAY_BUFFER, 129600 * 2 * 3 * sizeof( float ), &points[0], GL_STATIC_DRAW );

	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	return ;
}

Sphere::Sphere( Sphere const & src )
{
	*this = src;
}

Sphere::~Sphere( void )
{
	if ( this->_shader )
		delete this->_shader;
	return ;
}

Sphere &			Sphere::operator=( Sphere const & rhs )
{
	this->_positionBuff = rhs._positionBuff;

	return ( *this );
}

void				Sphere::update( void )
{

}

void				Sphere::render( Core const & core )
{
	(void)core;
	this->_shader->bind();
	glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	glEnableVertexAttribArray( 0 );
	glEnableVertexAttribArray( 1 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (void *)( 129600 * 3 * sizeof(float) ) );

	Matrix4f	worldMatrix = getTransform()->getTransformation();
	Matrix4f	projectedMatrix = core.getCamera().getViewProjection() * worldMatrix;

	this->_shader->updateUniform( "T_MVP", projectedMatrix );

	glDrawArrays( GL_POINTS, 0, 129600 );

	glDisableVertexAttribArray( 0 );
	glDisableVertexAttribArray( 1 );
	glUseProgram( 0 );
}
