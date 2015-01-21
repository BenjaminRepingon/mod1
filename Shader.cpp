/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:51:57 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 16:25:32 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"
# include "Shader.hpp"

Shader::Shader( std::string const & fileName )
{
	GLuint vertexShader = createShader( GL_VERTEX_SHADER, this->loadShader( fileName + ".vert" ) );
	GLuint fragmentShader = createShader( GL_FRAGMENT_SHADER, this->loadShader( fileName + ".frag" ) );
	this->_program = createProgram( vertexShader, fragmentShader );
	return ;
}

Shader::Shader( Shader const & src )
{
	*this= src;
}

Shader::~Shader( void )
{
	return ;
}

Shader &	Shader::operator=( Shader const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void		Shader::bind() const
{
	glUseProgram( this->_program );
}

void		Shader::updateUniforms()
{
	return ;
}

std::string	Shader::loadShader( std::string const & fileName )
{
	std::ifstream	file;
	std::string		output;
	std::string		line;

	file.open( ( "./res/shaders/" + fileName ).c_str() );

	if ( file.is_open() )
	{
		while ( file.good() )
		{
			getline( file, line );
			if ( line.find( "#include" ) == std::string::npos )
				output.append( line + "\n" );
			else
			{
				std::string includeFileName = Utils::Split( line, ' ' )[1];
				includeFileName = includeFileName.substr( 1, includeFileName.length() - 2 );
				std::string toAppend = this->loadShader( includeFileName );
				output.append( toAppend + "\n" );
			}
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}
	return ( output );
}

GLuint		Shader::createShader( GLenum eShaderType, std::string const & strShaderFile )
{
	GLuint shader = glCreateShader( eShaderType );
	const char *strFileData = strShaderFile.c_str();
	glShaderSource( shader, 1, &strFileData, NULL );

	glCompileShader( shader );

	GLint		status;
	glGetShaderiv( shader, GL_COMPILE_STATUS, &status );
	if ( status == GL_FALSE )
	{
		GLint infoLogLength;
		glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &infoLogLength );

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog( shader, infoLogLength, NULL, strInfoLog );

		const char *strShaderType = NULL;
		switch( eShaderType )
		{
			case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
			// case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
			case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		std::cerr << "Compile failure in " << strShaderType << " shader:\n" << strInfoLog << std::endl;
		delete[] strInfoLog;
	}
	return ( shader );
}

GLuint		Shader::createProgram( GLuint vertexShader, GLuint fragmentShader )
{
	GLuint program = glCreateProgram();

	glAttachShader( program, vertexShader );
	glAttachShader( program, fragmentShader );

	glLinkProgram( program );

	GLint status;
	glGetProgramiv( program, GL_LINK_STATUS, &status );
	if ( status == GL_FALSE )
	{
		GLint infoLogLength;
		glGetProgramiv( program, GL_INFO_LOG_LENGTH, &infoLogLength );

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog( program, infoLogLength, NULL, strInfoLog );
		std::cerr << "Linker failure: " << strInfoLog << std::endl;
		delete[] strInfoLog;
	}

	glDetachShader( program, vertexShader );
	glDetachShader( program, fragmentShader );
	return ( program );
}
