/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:41:40 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 15:55:35 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Window.hpp"

Window::Window( int width, int height, std::string const & title ) :
	_width( width ),
	_height( height ),
	_title( title )
{
	return ;
}

Window::Window( Window const & src )
{
	*this= src;
}

Window::~Window( void )
{
	return ;
}

Window &	Window::operator=( Window const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void		Window::error_callback( int error, const char* description )
{
	std::cerr << "Error: " << error << ": " << description << std::endl;
}


void		Window::key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	glfwSetWindowShouldClose(window, GL_TRUE);
}


void		Window::createWindow()
{
	 glfwSetErrorCallback( error_callback );

	if ( ! glfwInit() )
		std::cerr << "glfwInit error !" << std::endl;

	this->_window = glfwCreateWindow( this->_width, this->_height, this->_title.c_str(), 0, 0 );
	if ( ! this->_window )
	{
		glfwTerminate();
	}
	glfwMakeContextCurrent( this->_window );
	glfwSwapInterval( 1 );
	glfwSetKeyCallback( this->_window, Window::key_callback );
}

// GETTER
GLFWwindow *		Window::getGLFW( void ) const
{
	return ( this->_window );
}
