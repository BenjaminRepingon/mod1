/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:33:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/23 16:33:24 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT
# define INPUT
# include <string>
# include <SDL2/SDL.h>
# include "Vector2f.hpp"
# include "Core.hpp"
# define NUM_SCANCODES 256
# define NUM_MOUSE_BUTTONS 5

class Input
{
public:
	// SETTER
	static void			setKeyState( int scancode, bool state );
	static void			setButtonState( int button, bool state );
	static void			setMousePosition( int x, int y );
	static void			setMousePosition( Vector2f const & pos );
	static void			setCore( Core * core );

	// GETTER
	static bool			getKeyDown( int scancode );
	static bool			getKeyUp( int scancode );
	static bool			getButtonDown( int button );
	static bool			getButtonUp( int button );
	static int			getMouseX( void );
	static int			getMouseY( void );
	static Vector2f		getMousePosition( void );
	static Core *		getCore( void );

private:
	Input( void );
	Input( Input const & src );
	~Input( void );
	Input &			operator=( Input const & rhs );

	static bool			_keysUpDown[NUM_SCANCODES];
	static bool			_buttonsUpDown[NUM_MOUSE_BUTTONS];
	static int			_mousePosX;
	static int			_mousePosY;
	static Core *		_core;
};

#endif

