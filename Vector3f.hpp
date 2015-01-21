/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3f.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:24:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 16:39:53 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3F
# define VECTOR3F
# include <iostream>
# include <math.h>

class Vector3f
{
public:
	Vector3f( void );
	Vector3f( float x, float y, float z );
	Vector3f( Vector3f const & src );
	~Vector3f( void );

	Vector3f &			operator=( Vector3f const & rhs );

	// GETTER
	float				getX( void ) const;
	float				getY( void ) const;
	float				getZ( void ) const;

	// SETTER
	void				setX( float x );
	void				setY( float y );
	void				setZ( float z );

	// FUNCTIONS
	Vector3f			normalized( void ) const;
	float				length( void ) const;
	float				dot( Vector3f const & v ) const;
	Vector3f			cross( Vector3f const & v ) const;
	Vector3f			reflect( Vector3f const & normal ) const;
	Vector3f			operator+( Vector3f const & v ) const;
	Vector3f			operator-( Vector3f const & v ) const;
	Vector3f			operator*( float f ) const;
	Vector3f			operator/( float f ) const;
	Vector3f &			operator+=( Vector3f const & v );
	Vector3f &			operator-=( Vector3f const & v );
	Vector3f &			operator*=( float f );
	Vector3f &			operator/=( float f );
	bool				operator==( Vector3f const & v ) const;
	bool				operator!=( Vector3f const & v ) const;

private:
	float				_x;
	float				_y;
	float				_z;

};

std::ostream &		operator<<( std::ostream & lhs, Vector3f const & v );

#endif

