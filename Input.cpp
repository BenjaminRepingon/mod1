/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:33:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/23 16:50:42 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Input.hpp"

bool			Input::_keysUpDown[NUM_SCANCODES] = { false };
bool			Input::_buttonsUpDown[NUM_MOUSE_BUTTONS] = { false };
int				Input::_mousePosX = 0;
int				Input::_mousePosY = 0;
Core *			Input::_core = 0;

Input::Input()
{
	return ;
}

Input::Input( Input const & src )
{
	*this= src;
}

Input::~Input( void )
{
	return ;
}

Input &			Input::operator=( Input const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

// SETTER
void			Input::setCore( Core * core )
{
	Input::_core = core;
}

void			Input::setKeyState( int scancode, bool state )
{
	if ( scancode < NUM_SCANCODES )
		Input::_keysUpDown[scancode] = state;
}

void			Input::setButtonState( int button, bool state )
{
	if ( button < NUM_MOUSE_BUTTONS )
		Input::_buttonsUpDown[button] = state;
}

void			Input::setMousePosition( int x, int y )
{
	Input::_mousePosX = x;
	Input::_mousePosY = y;
}

void			Input::setMousePosition( glm::vec2 const & pos )
{
	SDL_WarpMouseInWindow( Input::_core->getWindow().getSDLWindow(), (int)pos.x, (int)pos.y );
}

// GETTER
Core *			Input::getCore()
{
	return ( Input::_core );
}

bool			Input::getKeyDown( int scancode )
{
	if ( scancode < NUM_SCANCODES )
		return ( Input::_keysUpDown[scancode] );
	return ( false );
}

bool			Input::getKeyUp( int scancode )
{
	if ( scancode < NUM_SCANCODES )
		return ( ! Input::_keysUpDown[scancode] );
	return ( false );
}

bool			Input::getButtonDown( int button )
{
	if ( button < NUM_MOUSE_BUTTONS )
		return ( Input::_buttonsUpDown[button] );
	return ( false );
}

bool			Input::getButtonUp( int button )
{
	if ( button < NUM_MOUSE_BUTTONS )
		return ( ! Input::_buttonsUpDown[button] );
	return ( false );
}

int				Input::getMouseX( void )
{
	return ( Input::_mousePosX );
}

int				Input::getMouseY( void )
{
	return ( Input::_mousePosY );
}

glm::vec2		Input::getMousePosition( void )
{
	return ( glm::vec2( Input::_mousePosX, Input::_mousePosY ) );
}

