/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:31 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/20 16:44:48 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Window.hpp"

Window::Window() :
	_title( "SDL2 - OpenGL" ),
	_width( 850 ),
	_height( 550 ),
	_gWindow( 0 )
{
	return ;
}

Window::Window( std::string title, size_t width, size_t height ) :
	_title( title ),
	_width( width ),
	_height( height ),
	_gWindow( 0 )
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

// FUNCTIONS
bool		Window::init()
{
	bool		success = true;

	//Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Use OpenGL 2.1
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

		//Create window
		this->_gWindow = SDL_CreateWindow( this->_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->_width, this->_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if ( this->_gWindow == NULL )
		{
			std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//Create context
			this->_gContext = SDL_GL_CreateContext( this->_gWindow );
			if ( this->_gContext == NULL )
			{
				std::cerr << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				//Use Vsync
				if ( SDL_GL_SetSwapInterval( 1 ) < 0 )
					std::cerr << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << std::endl;

				//Initialize OpenGL
				if ( ! this->initGL() )
				{
					std::cerr << "Unable to initialize OpenGL!" << std::endl;
					success = false;
				}
			}
		}
	}
	return ( success );
}

bool		Window::initGL()
{
	bool		success = true;
	GLenum		error = GL_NO_ERROR;

	//Initialize Projection Matrix
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	//Check for error
	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		std::cerr << "Error initializing OpenGL!" << std::endl;
		success = false;
	}

	//Initialize Modelview Matrix
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	//Check for error
	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		std::cerr << "Error initializing OpenGL!" << std::endl;
		success = false;
	}

	//Initialize clear color
	glClearColor( 0.f, 0.f, 0.f, 1.f );

	//Check for error
	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		std::cerr << "Error initializing OpenGL!" << std::endl;
		success = false;
	}

	return success;
}

// GETTER
std::string			Window::getTitle() const
{
	return ( this->_title );
}

size_t				Window::getWidth() const
{
	return ( this->_width );
}

size_t				Window::getHeight() const
{
	return ( this->_height );
}

SDL_Window *		Window::getSDLWindow( void ) const
{
	return ( this->_gWindow );
}
