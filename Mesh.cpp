/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:13:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 18:41:22 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Mesh.hpp"

Mesh::Mesh() :
	_isGenerated( false )
{
	glGenBuffers( 1, &this->_vbo );
	glGenBuffers( 1, &this->_ibo );

	return ;
}

Mesh::Mesh( std::vector<Vertex> const & vertices ) :
	_isGenerated( false )
{
	glGenBuffers( 1, &this->_vbo );
	glGenBuffers( 1, &this->_ibo );

	this->_vertices = vertices;

	return ;
}

Mesh::Mesh( Mesh const & src )
{
	*this = src;
}

Mesh::~Mesh( void )
{
	glDeleteBuffers( 1, & this->_vbo );
	glDeleteBuffers( 1, & this->_ibo );
	return ;
}

Mesh &				Mesh::operator=( Mesh const & rhs )
{
	if ( this != &rhs )
	{
		this->_vbo = rhs._vbo;
		this->_ibo = rhs._ibo;
		this->_vertices = rhs._vertices;
	}
	return ( *this );
}

void				Mesh::addVertex( Vertex const & v ) throw()
{
	if ( this->_isGenerated )
		throw ( Error( "Mesh already generated !" ) );
	this->_vertices.push_back( v );
}

void				Mesh::addFace( int a, int b, int c ) throw()
{
	if ( this->_isGenerated )
		throw ( Error( "Mesh already generated !" ) );
	this->_indexes.push_back( a );
	this->_indexes.push_back( b );
	this->_indexes.push_back( c );
}

void				Mesh::generateBuffer( void )
{
	glBindBuffer( GL_ARRAY_BUFFER, this->_vbo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( Vertex ) * this->_vertices.size(), Vertex::createBuffer( this->_vertices ), GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	glBindBuffer( GL_ARRAY_BUFFER, this->_ibo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( int ) * this->_indexes.size(), & this->_indexes[0], GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	this->_isGenerated = true;
}

void				Mesh::render( Core const & core, Shader const & shader, Transform const & transform ) const throw()
{
	if ( ! this->_isGenerated )
		throw ( Error( "Mesh not generated !, can't render it" ) );

	shader.bind();
	glBindBuffer( GL_ARRAY_BUFFER, this->_vbo );
	glEnableVertexAttribArray( 0 );
	glEnableVertexAttribArray( 1 );
	glEnableVertexAttribArray( 2 );

	glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, 9 * 4, 0 );
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_TRUE, 9 * 4, (void *)12 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 9 * 4, (void *)24 );

	Matrix4f	worldMatrix = transform.getTransformation();
	Matrix4f	projectedMatrix = core.getCamera().getViewProjection() * worldMatrix;

	shader.updateUniform( "T_Model", worldMatrix );
	shader.updateUniform( "T_MVP", projectedMatrix );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->_ibo );
	glDrawElements( GL_TRIANGLES, this->_indexes.size(), GL_UNSIGNED_INT, 0 );

	glDisableVertexAttribArray( 0 );
	glDisableVertexAttribArray( 1 );
	glDisableVertexAttribArray( 2 );
	glUseProgram( 0 );
}

GLuint				Mesh::getVbo() const
{
	return ( this->_vbo );
}

GLuint				Mesh::getIbo() const
{
	return ( this->_ibo );
}

std::vector<Vertex>	Mesh::getVertices() const
{
	return ( this->_vertices );
}

std::vector<int>	Mesh::getIndexes() const
{
	return ( this->_indexes );
}
