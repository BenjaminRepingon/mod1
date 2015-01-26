/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:31 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 13:57:57 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW
# define WINDOW
# include <iostream>
# include <SDL2/SDL.h>
# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include <GL/gl.h>
#  include <GL/glu.h>
# endif
# include "glm/glm.hpp"
# include <GLFW/glfw3.h>

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
	glm::vec2			getCenter( void ) const;

	// SETTER

	// FUNCTIONS
	bool				init( void );
	bool				initGL( void );
	void				reshape( int width, int height );

private:
	std::string			_title;
	size_t				_width;
	size_t				_height;
	SDL_Window *		_gWindow;
	SDL_GLContext		_gContext;

};

#endif

