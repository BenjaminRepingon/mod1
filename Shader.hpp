/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:51:57 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 16:57:48 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER
# define SHADER
# include <string>
# include <fstream>
# include <iostream>
# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include <GLES2/gl2.h>
#  include <GL/glu.h>
# endif
# include "glm/glm.hpp"
# include "glm/gtc/type_ptr.hpp"

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
	void				updateUniform( std::string name, glm::mat4 const & m ) const;

private:
	Shader( void );
	GLuint				createShader( GLenum eShaderType, std::string const & strShaderFile );
	GLuint				createProgram( GLuint vertexShader, GLuint fragmentShader );
	std::string			loadShader( std::string const & file );
	GLuint				_program;
	GLuint				_positionBufferObject;
};

#endif

