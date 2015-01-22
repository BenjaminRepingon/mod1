/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:21:01 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 18:56:53 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include "Vector3f.hpp"
#include <sstream>

Map::Map( void ) //: _shader( new Shader("Basic") )
{
	this->_vertex.push_back( Vertex( 0.0f, 0.0f, 0.0f ) );
	this->_vertex.push_back( Vertex( 0.0f, 0.0f, 20000.0f ) );
	this->_vertex.push_back( Vertex( 20000.0f, 0.0f, 20000.0f ) );
	this->_vertex.push_back( Vertex( 20000.0f, 0.0f, 0.0f ) );

	// glGenBuffers( 1, &this->_positionBuff );

	// glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	// glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
	// glBindBuffer( GL_ARRAY_BUFFER, 0 );

	// return ;
}

Map::Map( std::string fileMap ) : _fileMap( fileMap )//, _shader( new Shader("Basic") )
{
	this->_vertex.push_back( Vertex( 0.0f, 0.0f, 0.0f ) );
	this->_vertex.push_back( Vertex( 0.0f, 0.0f, 20000.0f ) );
	this->_vertex.push_back( Vertex( 20000.0f, 0.0f, 20000.0f ) );
	this->_vertex.push_back( Vertex( 20000.0f, 0.0f, 0.0f ) );

	this->loadMap();
	// glGenBuffers( 1, &this->_positionBuff );

	// glBindBuffer( GL_ARRAY_BUFFER, this->_positionBuff );
	// glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
	// glBindBuffer( GL_ARRAY_BUFFER, 0 );

	// return ;
}

void			Map::saveVertex( std::string file )
{
	unsigned int		j = 0;
	std::stringstream	s_num[3];
	float				f_num[3];

	for (size_t i = 0; i < file.size(); ++i)
	{
		if ( file[i] == ',' )
		{
			s_num[j] >> f_num[j];
			i++;
			j++;
		}

		s_num[j] << file[i];
	}
	s_num[j] >> f_num[j];
	std::cout << "Point: " << f_num[0] << ", " << f_num[1] << ", " << f_num[2] << std::endl;

	this->_vertex.push_back( Vertex(f_num[0], f_num[1], f_num[2]) );
}

void			Map::loadMap( void )
{
	std::ifstream		file;
	std::string			output;
	std::string			line;
	std::size_t			start = 0;
	std::size_t			end = 0;

	file.open( ( "./res/map/" + this->_fileMap ).c_str() );

	if ( !file.is_open() )
	{
		std::cerr << "Unable to load Map: " << this->_fileMap << std::endl;
		return ;
	}

	while ( file.good() )
	{
		getline( file, line );

		for (unsigned int i = 0; i < line.size(); ++i)
		{
			if ( isspace(line[i]) )
				line.erase( i, 1 );
		}
		output.append( line );
	}

	while ( start != std::string::npos && end != std::string::npos && end < output.size() - 1 )
	{
		start = output.find( '(', end );
		end = output.find( ')', start);
		this->saveVertex( output.substr(start + 1, end - start - 1));
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
