/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:24:27 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/21 19:17:00 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Core.hpp"

/*
** CONSTRUCT & DESTRUCT
*/

Core::Core( void ) : _win( NULL ), _started ( false )
{
	return ;
}

Core::Core( Core const & src )
{
	*this = src;
}

Core::~Core( void )
{
	if ( this->_win )
		delete this->_win;

	return ;
}

/*
** METHOD
*/

void			Core::createWindow( std::string title, size_t width, size_t height )
{
	if ( this->_win == NULL )
		this->_win = new Window( title, width, height );

	if ( this->_win->init() == false )
	{
		delete this->_win;
		this->_win = NULL;
		throw Error( "Window initializtion failed");
	}

	return ;
}

void			Core::start( void )
{
	if ( !this->_win )
		throw Error( "Please create a window");

	this->_view.initPerspective( ( 70.0 / 180 ) * M_PI, (double) this->_win->getWidth() / this->_win->getHeight(), 1.0, 100.0);

	glViewport( 0, 0, (GLsizei) this->_win->getWidth(), (GLsizei) this->_win->getHeight() );
	this->_started = true;

	while ( this->_started )
	{
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		this->updateAll();
		this->_started = this->catchEvent();

		this->renderAll();

		SDL_GL_SwapWindow( this->_win->getSDLWindow() );
		SDL_Delay( 10 );
	}

}

bool			Core::catchEvent( void ) const
{
	SDL_Event	event;
	bool		continue_event = true;

	while ( SDL_PollEvent( &event ) != 0 )
	{
		if ( event.type == SDL_QUIT )
			continue_event = false;
	}

	return ( continue_event );
}

void			Core::addObject( IObject * obj )
{
	this->_obj.push_back( obj );

	return ;
}

void			Core::updateAll( void )
{
	for (std::vector<IObject *>::const_iterator it = this->_obj.begin(); it != this->_obj.end(); ++it )
	{
		((*it)->update());
	}

	return ;
}

void			Core::renderAll( void ) const
{
	for (std::vector<IObject *>::const_iterator it = this->_obj.begin(); it != this->_obj.end(); ++it )
	{
		((*it)->render( *this ));
	}

	return ;
}

/*
** OPERATOR
*/

Core &			Core::operator=( Core const & rhs )
{
	this->_win = rhs.getWindow();

	return ( *this );
}

/*
** GET & SET
*/

Window *		Core::getWindow( void ) const
{
	return ( this->_win );
}


Matrix4f		Core::getView( void ) const
{
	return ( this->_view );
}

