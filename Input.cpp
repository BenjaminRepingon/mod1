/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:33:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 19:03:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Input.hpp"

bool			Input::_keysUpDown[NUM_SCANCODES] = { false };

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

void			Input::setKeyDown( int scancode )
{
	if ( scancode < NUM_SCANCODES )
		Input::_keysUpDown[scancode] = true;
}

void			Input::setKeyUp( int scancode )
{
	if ( scancode < NUM_SCANCODES )
		Input::_keysUpDown[scancode] = false;
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
