/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:00:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 16:32:13 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Core.hpp"

Core::Core() :
	_window( 0 ),
	_isRunning( false )
{
	return ;
}

Core::Core( Core const & src )
{
	*this = src;
}

Core::~Core( void )
{
	return ;
}

Core &	Core::operator=( Core const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void			Core::createWindow( int width, int height, std::string const & title )
{
	this->_window = new Window( width, height, title );
	this->_window->create();
}

void			Core::start()
{
	if ( this->_isRunning || this->_window == 0 )
		return ;
	this->_isRunning = true;
	this->run();
}

void			Core::addObject( Object * object )
{
	this->_objects.push_back( object );
}

void			Core::run()
{
	while ( ! glfwWindowShouldClose( this->_window->getGLFW() ) )
	{
		int width, height;
		glfwGetFramebufferSize( this->_window->getGLFW(), &width, &height );

		glViewport( 0, 0, width, height );
		glClear( GL_COLOR_BUFFER_BIT );

		this->renderAll();

		glfwSwapBuffers( this->_window->getGLFW() );
		glfwPollEvents();
	}
	glfwDestroyWindow( this->_window->getGLFW() );
	glfwTerminate();
}


void			Core::renderAll()
{
	std::vector<Object *>::iterator it;

	for ( it = this->_objects.begin(); it != this->_objects.end(); it++ )
		(*it)->render( * this );
}


// GETTER
Window *		Core::getWindow() const
{
	return ( this->_window );
}
