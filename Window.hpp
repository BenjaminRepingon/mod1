/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:31 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 14:14:50 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW
# define WINDOW
# include <iostream>
# include <SDL2/SDL.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>

class Window
{
public:
	Window( void );
	Window( std::string title, size_t width, size_t height );
	Window( Window const & src );
	~Window( void );

	Window &			operator=( Window const & rhs );

	// GETTER
	float				getAspect() const;
	std::string			getTitle( void ) const;
	size_t				getWidth( void ) const;
	size_t				getHeight( void ) const;
	SDL_Window *		getSDLWindow( void ) const;

	// SETTER

	// FUNCTIONS
	bool				init( void );
	bool				initGL( void );

private:
	std::string			_title;
	size_t				_width;
	size_t				_height;
	SDL_Window *		_gWindow;
	SDL_GLContext		_gContext;

};

#endif

