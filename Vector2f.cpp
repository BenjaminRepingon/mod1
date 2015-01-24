/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2f.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/24 19:02:16 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2f.hpp"

/*
** CONSTRUCT & DESTRUCT
*/

Vector2f::Vector2f( void ) : _x( 0 ), _y( 0 )
{
	return ;
}

Vector2f::Vector2f( int x, int y ) : _x( x ), _y( y )
{
	return ;
}

Vector2f::Vector2f( float x, float y ) : _x( x ), _y( y )
{
	return ;
}

Vector2f::Vector2f( Vector2f const & cpy )
{
	*this = cpy;

	return ;
}

Vector2f::~Vector2f( void )
{
	return ;
}

/*
** METHODE
*/

float				Vector2f::length( void ) const
{
	return ( sqrt( this->_x * this->_x + this->_y * this->_y ) );
}

Vector2f			Vector2f::rotate( float angle ) const
{
	double			_rad = angle / 180 * _PI_;
	double			_cos = cos( _rad );
	double			_sin = sin( _rad );
	Vector2f		*tmp = new Vector2f( (float) ( this->_x * _cos - this->_y * _sin ), (float) ( this->_x * _sin + this->_y * _cos ) );


	return ( *tmp );
}

Vector2f			Vector2f::abs( void ) const
{
	float			x = this->_x < 0 ? this->_x * (-1) : this->_x;
	float			y = this->_y < 0 ? this->_y * (-1) : this->_y;
	Vector2f		*tmp = new Vector2f( x, y );

	return ( *tmp );
}

/*
** OPERATOR
*/

Vector2f &		Vector2f::operator=( Vector2f const & rhs )
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();

	return ( *this );
}

Vector2f &		Vector2f::operator+( Vector2f & rhs ) const
{
	float		x = this->_x + rhs.getX();
	float		y = this->_y + rhs.getY();
	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator-( Vector2f & rhs ) const
{
	float		x = this->_x - rhs.getX();
	float		y = this->_y - rhs.getY();
	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator*( float rhs ) const
{
	float		x = this->_x * rhs;
	float		y = this->_y * rhs;
	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator*( int rhs ) const
{
	float		x = this->_x * (float)rhs;
	float		y = this->_y * (float)rhs;
	Vector2f 	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator*( Vector2f & rhs ) const
{
	float		x = this->_x * rhs.getX();
	float		y = this->_y * rhs.getY();
	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator/( float rhs ) const
{
	float		x = this->_x / rhs;
	float		y = this->_y / rhs;
	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator/( int rhs ) const
{
	float		x = this->_x / (float)rhs;
	float		y = this->_y / (float)rhs;
	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator/( Vector2f & rhs ) const
{
	float		x = this->_x / rhs.getX();
	float		y = this->_y / rhs.getY();

	Vector2f	*tmp = new Vector2f( x, y );

	return ( *tmp );
}

/*
** GETTER & SETTER
*/

float			Vector2f::getX( void ) const
{
	return ( this->_x );
}

float			Vector2f::getY( void ) const
{
	return ( this->_y );
}

void			Vector2f::setX( float x )
{
	this->_x = x;

	return ;
}

void			Vector2f::setY( float y )
{
	this->_y = y;

	return ;
}
