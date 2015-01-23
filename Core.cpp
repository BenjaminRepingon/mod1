/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:24:27 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/23 12:19:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <typeinfo>
# include "Core.hpp"

/*
** CONSTRUCT & DESTRUCT
*/

Core::Core( void ) :
	_win( NULL ),
	_started( false ),
	_camera( 0 )
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

	this->_started = true;

	while ( this->_started )
	{
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		this->catchEvent();

		if ( Input::getKeyDown( SDL_SCANCODE_ESCAPE ) )
			this->_started = false;

		this->updateAll();

		this->renderAll();

		SDL_GL_SwapWindow( this->_win->getSDLWindow() );
		SDL_Delay( 10 );
	}

}

bool			Core::catchEvent( void )
{
	SDL_Event	event;

	while ( SDL_PollEvent( &event ) != 0 )
	{
		switch( event.type )
		{
			case SDL_QUIT:
			this->_started = false;
			break;

			case SDL_KEYDOWN:
			Input::setKeyDown( event.key.keysym.scancode );
			break;

			case SDL_KEYUP:
			Input::setKeyUp( event.key.keysym.scancode );
			break;

			case SDL_WINDOWEVENT:
			if ( event.window.event == SDL_WINDOWEVENT_RESIZED )
			{
				this->_win->reshape( event.window.data1, event.window.data2 );
				if ( this->_camera != 0 )
					this->_camera->reshape( event.window.data1, event.window.data2 );
			}
			break;

			default:
			break;
		}
	}
	return ( true );
}

void			Core::addObject( AObject * obj )
{
	this->_obj.push_back( obj );

	return ;
}

void			Core::updateAll( void )
{
	if ( this->_camera != 0 )
		this->_camera->update();

	for ( std::vector<AObject *>::const_iterator it = this->_obj.begin(); it != this->_obj.end(); ++it )
	{
		((*it)->update());
	}

	return ;
}

void			Core::renderAll( void ) const
{
	for ( std::vector<AObject *>::const_iterator it = this->_obj.begin(); it != this->_obj.end(); ++it )
	{
		( (*it)->render( *this ) );
	}

	return ;
}

/*
** OPERATOR
*/

Core &			Core::operator=( Core const & rhs )
{
	this->_win = & rhs.getWindow();

	return ( *this );
}

/*
** GET & SET
*/

Window &		Core::getWindow( void ) const
{
	return ( * this->_win );
}

void			Core::setCamera( Camera * camera )
{
	this->_camera = camera;
}

Camera &		Core::getCamera( void ) const
{
	return ( * this->_camera );
}

