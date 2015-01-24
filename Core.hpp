/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:17:54 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 18:52:36 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP
# include <iostream>
# include <SDL2/SDL.h>
# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include <GL/gl.h>
#  include <GL/glu.h>
# endif
# include <vector>
# include "Window.hpp"
# include "Error.hpp"
# include "AObject.hpp"
# include "Matrix4f.hpp"
# include "Camera.hpp"
# include "Input.hpp"

class Core
{
	public:
		Core( void );
		Core( Core const & src );
		~Core( void );

		Core &					operator=( Core const & rhs );

		Window &				getWindow( void ) const;
		Camera &				getCamera( void ) const;

		void					setCamera( Camera * camera );

		void					createWindow( std::string title, size_t width, size_t height );
		void					start( void );
		void					addObject( AObject * obj );

	private:
		Window *				_win;
		bool					_started;
		std::vector<AObject *>	_obj;
		Camera *				_camera;

		bool					catchEvent( void );
		void					updateAll( void );
		void					renderAll( void ) const;
};

#endif

