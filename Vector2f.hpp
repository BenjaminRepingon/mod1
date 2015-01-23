/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2f.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:15 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/10 14:35:44 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2F_HPP
# define VECTOR2F_HPP
# include <iostream>
# include <cmath>
# define _PI_ 3.14159265359

class Vector2f
{
	public:
		Vector2f( void );
		Vector2f( int x, int y );
		Vector2f( float x, float y );
		Vector2f( Vector2f const & cpy );
		~Vector2f( void );

		Vector2f &		operator=( Vector2f const & rhs );
		Vector2f &		operator+( Vector2f & rhs ) const;
		Vector2f &		operator-( Vector2f & rhs ) const;
		Vector2f &		operator*( float rhs ) const;
		Vector2f &		operator*( int rhs ) const;
		Vector2f &		operator*( Vector2f & rhs ) const;
		Vector2f &		operator/( float rhs ) const;
		Vector2f &		operator/( int rhs ) const;
		Vector2f &		operator/( Vector2f & rhs ) const;

		float			getX( void ) const;
		float			getY( void ) const;
		void			setX( float x );
		void			setY( float y );

		float			length( void ) const;
		Vector2f		rotate( float angle ) const;
		Vector2f		abs( void ) const;

	private:
		float			_x;
		float			_y;
};

#endif
