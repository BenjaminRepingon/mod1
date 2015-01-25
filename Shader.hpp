/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:51:57 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 14:13:13 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER
# define SHADER
# include <string>
# include <fstream>
# include <iostream>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include "Matrix4f.hpp"

class Shader
{
public:
	Shader( std::string const & fileName );
	Shader( Shader const & src );
	~Shader( void );

	Shader &			operator=( Shader const & rhs );

	// GETTER
	GLuint				getProgramID( void ) const;

	// SETTER

	// FUNCTIONS
	void				bind( void ) const;
	void				updateUniform( std::string name, Matrix4f const & m );
	void				updateUniform( std::string name, float f );


private:
	Shader( void );
	GLuint				createShader( GLenum eShaderType, std::string const & strShaderFile );
	GLuint				createProgram( GLuint vertexShader, GLuint fragmentShader );
	std::string			loadShader( std::string const & file );
	GLuint				_program;
	GLuint				_positionBufferObject;
};

#endif

