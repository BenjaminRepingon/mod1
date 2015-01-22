/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:33:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 19:05:36 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT
# define INPUT
# include <string>
# include <SDL2/SDL.h>
# define NUM_SCANCODES 256

class Input
{
public:

	// GETTER
	static bool			getKeyDown( int scancode );
	static bool			getKeyUp( int scancode );

	// SETTER
	static void			setKeyDown( int scancode );
	static void			setKeyUp( int scancode );

private:
	Input( void );
	Input( Input const & src );
	~Input( void );
	Input &			operator=( Input const & rhs );

	static bool			_keysUpDown[NUM_SCANCODES];

};

#endif

