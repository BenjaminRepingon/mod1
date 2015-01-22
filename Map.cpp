/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:21:01 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 13:32:49 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include "Vector3f.hpp"

Map::Map( void ) //: _shader( new Shader("Basic") )
{
	this->_vertex.push_back( Vertex( Vector3f( ) ) );
	this->_vertex.push_back( Vertex( Vector3f( 0.0f, 0.0f, 20000.0f ) ) );
	this->_vertex.push_back( Vertex( Vector3f( 20000.0f, 0.0f, 20000.0f ) ) );
	this->_vertex.push_back( Vertex( Vector3f( 20000.0f, 0.0f, 0.0f ) ) );

	// glGenBuffers( 1, &this->_positionBuff );

	// glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	// glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
	// glBindBuffer( GL_ARRAY_BUFFER, 0 );

	// return ;
}

Map::Map( std::string fileMap ) : _fileMap( fileMap )//, _shader( new Shader("Basic") )
{
	this->_vertex.push_back( Vertex( Vector3f( ) ) );
	this->_vertex.push_back( Vertex( Vector3f( 0.0f, 0.0f, 20000.0f ) ) );
	this->_vertex.push_back( Vertex( Vector3f( 20000.0f, 0.0f, 20000.0f ) ) );
	this->_vertex.push_back( Vertex( Vector3f( 20000.0f, 0.0f, 0.0f ) ) );

	this->loadMap();
	// glGenBuffers( 1, &this->_positionBuff );

	// glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	// glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
	// glBindBuffer( GL_ARRAY_BUFFER, 0 );

	// return ;
}

void			Map::loadMap( void )
{
	std::ifstream	file;
	std::string		output;
	std::string		line;

	file.open( ( "./res/map/" + this->_fileMap ).c_str() );

	if ( file.is_open() )
	{
		while ( file.good() )
		{
			getline( file, line );
			output.append( line );
		}
		std::cout << output << std::endl;
	}
	else
	{
		std::cerr << "Unable to load Map: " << this->_fileMap << std::endl;
	}

}

Map::Map( Map const & src )
{
	*this = src;
}

Map::~Map( void )
{
	// if ( this->_shader )
	// 	delete this->_shader;
	return ;
}

Map &			Map::operator=( Map const & rhs )
{
	this->_fileMap = rhs._fileMap;

	return ( *this );
}

void				Map::update( void )
{

}

void				Map::render( Core const & core ) const
{
	(void)core;
	// this->_shader->bind();
	// glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	// glEnableVertexAttribArray( 0 );
	// glEnableVertexAttribArray( 1 );

	// glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, 0, 0 );
	// glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 0, (void *)(12 * sizeof(float)) );

	// glUniformMatrix4fv( glGetUniformLocation( this->_shader->getProgramID(), "projection" ), 1, GL_FALSE, &( core.getView()[0][0] ) );
	// glUniformMatrix4fv( glGetUniformLocation( this->_shader->getProgramID(), "modelview" ), 1, GL_FALSE, &( this->_transform[0][0] ) );
	// glDrawArrays( GL_MapS, 0, 3 );

	// glDisableVertexAttribArray( 0 );
	// glUseProgram( 0 );
}
