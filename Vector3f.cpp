/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3f.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:24:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 10:16:16 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Vector3f.hpp"

Vector3f::Vector3f() :
	_x( 0 ),
	_y( 0 ),
	_z( 0 )
{
	return ;
}

Vector3f::Vector3f( float x, float y, float z ) :
	_x( x ),
	_y( y ),
	_z( z )
{
	return ;
}

Vector3f::Vector3f( Vector3f const & src )
{
	*this = src;
}

Vector3f::~Vector3f( void )
{
	return ;
}

Vector3f &			Vector3f::operator=( Vector3f const & rhs )
{
	if ( this != &rhs )
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
		this->_z = rhs.getZ();
	}
	return ( *this );
}

// FUNCTIONS
Vector3f			Vector3f::normalized() const
{
	float	length = this->length();

	if ( length == 0 )
		return ( Vector3f( 0, 0, 0 ) );
	return ( Vector3f( this->_x / length, this->_y / length, this->_z / length ) );
}

float				Vector3f::length() const
{
	return ( (float) sqrt( this->_x * this->_x + this->_y * this->_y + this->_z * this->_z ) );
}

float				Vector3f::dot( Vector3f const & v ) const
{
	return ( this->_x * v.getX() + this->_y * v.getY() + this->_z * v.getZ() );
}

Vector3f			Vector3f::cross( Vector3f const & v ) const
{
	float	x = this->_y * v.getZ() - this->_z * v.getY();
	float	y = this->_z * v.getX() - this->_x * v.getZ();
	float	z = this->_x * v.getY() - this->_y * v.getX();
	return ( Vector3f( x, y, z ) );
}

Vector3f			Vector3f::reflect( Vector3f const & normal ) const
{
	return ( *this - ( normal * ( this->dot( normal ) * 2 ) ) );
}

Vector3f			Vector3f::operator+( Vector3f const & v ) const
{
	return ( Vector3f( this->_x + v.getX(), this->_y + v.getY(), this->_z + v.getZ() ) );
}

Vector3f			Vector3f::operator-( Vector3f const & v ) const
{
	return ( Vector3f( this->_x - v.getX(), this->_y - v.getY(), this->_z - v.getZ() ) );
}

Vector3f			Vector3f::operator*( float f ) const
{
	return ( Vector3f( this->_x * f, this->_y * f, this->_z * f ) );
}

Vector3f			Vector3f::operator/( float f ) const
{
	return ( Vector3f( this->_x / f, this->_y / f, this->_z / f ) );
}

Vector3f &			Vector3f::operator+=( Vector3f const & v )
{
	this->_x += v.getX();
	this->_y += v.getY();
	this->_z += v.getZ();
	return ( *this );
}

Vector3f &			Vector3f::operator-=( Vector3f const & v )
{
	this->_x -= v.getX();
	this->_y -= v.getY();
	this->_z -= v.getZ();
	return ( *this );
}

Vector3f &			Vector3f::operator*=( float f )
{
	this->_x *= f;
	this->_y *= f;
	this->_z *= f;
	return ( *this );
}

Vector3f &			Vector3f::operator/=( float f )
{
	this->_x /= f;
	this->_y /= f;
	this->_z /= f;
	return ( *this );
}

bool				Vector3f::operator==( Vector3f const & v ) const
{
	return ( *this == v || ( this->_x == v.getX() && this->_y == v.getY() && this->_z == v.getZ() ) );
}

bool				Vector3f::operator!=( Vector3f const & v ) const
{
	return ( this->_x != v.getX() || this->_y != v.getY() || this->_z != v.getZ() );
}

std::ostream &		operator<<( std::ostream & lhs, Vector3f const & v )
{
	return ( lhs << "Vector3f( x: " << v.getX() << ", y: " << v.getY() << ", z: " << v.getZ() << ")" << std::endl );
}

// GETTER
float				Vector3f::getX( void ) const
{
	return ( this->_x );
}

float				Vector3f::getY( void ) const
{
	return ( this->_y );
}

float				Vector3f::getZ( void ) const
{
	return ( this->_z );
}


// SETTER
void				Vector3f::setX( float x )
{
	this->_x = x;
	return ;
}

void				Vector3f::setY( float y )
{
	this->_y = y;
	return ;
}

void				Vector3f::setZ( float z )
{
	this->_z = z;
	return ;
}

