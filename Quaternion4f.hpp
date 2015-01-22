/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quaternion4f.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:00:41 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 13:21:01 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION4F
# define QUATERNION4F
# include <iostream>
# include <math.h>
# include "Vector3f.hpp"
# include "Matrix4f.hpp"

class Quaternion4f
{
public:
	Quaternion4f( void );
	Quaternion4f( float x, float y, float z, float w );
	Quaternion4f( Vector3f const & axis, float angle );
	Quaternion4f( Matrix4f const & m );
	Quaternion4f( Quaternion4f const & src );
	~Quaternion4f( void );

	Quaternion4f &			operator=( Quaternion4f const & rhs );

	// GETTER
	float					getX() const;
	float					getY() const;
	float					getZ() const;
	float					getW() const;

	// SETTER
	void					setX( float x );
	void					setY( float y );
	void					setZ( float z );
	void					setW( float w );

	// FUNCTIONS
	float					length( void ) const ;
	Quaternion4f			normalized( void ) const ;
	Quaternion4f			conjugate( void ) const ;
	float					dot( Quaternion4f r ) const;
	Matrix4f				toRotationMatrix() const;
	Quaternion4f			operator+( Quaternion4f const & r ) const;
	Quaternion4f			operator-( Quaternion4f const & r ) const;
	Quaternion4f			operator*( float r ) const;
	Quaternion4f			operator*( Quaternion4f r ) const;
	Quaternion4f			operator*( Vector3f r ) const;
	bool					operator==( Quaternion4f const & rhs ) const;
	bool					operator!=( Quaternion4f const & rhs ) const;

private:
	float					_x;
	float					_y;
	float					_z;
	float					_w;
};

std::ostream &		operator<<( std::ostream & lhs, Quaternion4f const & q );

#endif

