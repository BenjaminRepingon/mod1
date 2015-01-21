/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:51:57 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 16:25:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER
# define SHADER
# include <string>
# include <fstream>
# include <iostream>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>

class Shader
{
public:
	Shader( std::string const & fileName );
	Shader( Shader const & src );
	~Shader( void );

	Shader &			operator=( Shader const & rhs );

	// GETTER

	// SETTER

	// FUNCTIONS
	void				bind( void ) const;
	void				updateUniforms();

private:
	Shader( void );
	GLuint				createShader( GLenum eShaderType, std::string const & strShaderFile );
	GLuint				createProgram( GLuint vertexShader, GLuint fragmentShader );
	std::string			loadShader( std::string const & file );
	GLuint				_program;
	GLuint				_positionBufferObject;
};

#endif

