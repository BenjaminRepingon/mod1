/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix4f.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:43:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/25 17:31:07 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Matrix4f.hpp"

Matrix4f::Matrix4f()
{
	this->initIdentity();
	return ;
}

Matrix4f::Matrix4f( Matrix4f const & src )
{
	*this = src;
}

Matrix4f::~Matrix4f( void )
{
	return ;
}

Matrix4f &			Matrix4f::operator=( Matrix4f const & rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < 4; i++ )
		{
			for ( int j = 0; j < 4; j++ )
				this->_m[i][j] = rhs[i][j];
		}
	}
	return ( *this );
}

Matrix4f &			Matrix4f::initTranslation( float x, float y, float z )
{
	this->_m[3][0] = x;
	this->_m[3][1] = y;
	this->_m[3][2] = z;
	return ( *this );
}

Matrix4f &			Matrix4f::initTranslation( Vector3f const & v )
{
	return ( this->initTranslation( v.getX(), v.getY(), v.getZ() ) );
}

Matrix4f &			Matrix4f::initScale( float x, float y, float z )
{
	this->_m[0][0] = x;	this->_m[1][0] = 0;	this->_m[2][0] = 0;	this->_m[3][0] = 0;
	this->_m[0][1] = 0;	this->_m[1][1] = y;	this->_m[2][1] = 0;	this->_m[3][1] = 0;
	this->_m[0][2] = 0;	this->_m[1][2] = 0;	this->_m[2][2] = z;	this->_m[3][2] = 0;
	this->_m[0][3] = 0;	this->_m[1][3] = 0;	this->_m[2][3] = 0;	this->_m[3][3] = 1;
	return ( *this );
}

Matrix4f &			Matrix4f::initScale( Vector3f const & v )
{
	return ( this->initScale( v.getX(), v.getY(), v.getZ() ) );
}

Matrix4f &			Matrix4f::initIdentity()
{
	return ( this->initScale( 1, 1, 1 ) );
}

Matrix4f &			Matrix4f::initRotation( float x, float y, float z )
{
	Matrix4f rx;
	Matrix4f ry;
	Matrix4f rz;

	x = ( (float)( x * M_PI / 180.0f ) );
	y = ( (float)( y * M_PI / 180.0f ) );
	z = ( (float)( z * M_PI / 180.0f ) );

	rz.set( 0, 0, (float) cos( z ) );
	rz.set( 1, 0, -(float) sin( z ) );
	rz.set( 0, 1, (float) sin( z ) );
	rz.set( 1, 1, (float) cos( z ) );

	rx.set( 1, 1, (float) cos( x ) );
	rx.set( 2, 1, -(float) sin( x ) );
	rx.set( 1, 2, (float) sin( x ) );
	rx.set( 2, 2, (float) cos( x ) );

	ry.set( 0, 0, (float) cos( y ) );
	ry.set( 2, 0, -(float) sin( y ) );
	ry.set( 0, 2, (float) sin( y ) );
	ry.set( 2, 2, (float) cos( y ) );

	return ( *this = rz * ry * rx );
}

Matrix4f &			Matrix4f::initRotation( Vector3f const & forward, Vector3f const & up )
{
	Vector3f	f = forward.normalized();
	Vector3f	r = up.normalized().cross( f );
	Vector3f	u = f.cross( r );
	return ( this->initRotation( f, u, r ) );
}

Matrix4f &			Matrix4f::initRotation( Vector3f const & n, Vector3f const & v, Vector3f const & u )
{
	this->_m[0][0] = u.getX();	this->_m[1][0] = u.getY();	this->_m[2][0] = u.getZ();	this->_m[3][0] = 0;
	this->_m[0][1] = v.getX();	this->_m[1][1] = v.getY();	this->_m[2][1] = v.getZ();	this->_m[3][1] = 0;
	this->_m[0][2] = n.getX();	this->_m[1][2] = n.getY();	this->_m[2][2] = n.getZ();	this->_m[3][2] = 0;
	this->_m[0][3] = 0;			this->_m[1][3] = 0;			this->_m[2][3] = 0;			this->_m[3][3] = 1;

	return ( *this );
}

Matrix4f &			Matrix4f::initPerspective( float fov, float aspect, float zNear, float zFar )
{
	float	tanHalfFOV = tanf( fov / 2 );
	float	zRange = zNear - zFar;

	this->_m[0][0] = 1 / ( tanHalfFOV * aspect );	this->_m[1][0] = 0;				this->_m[2][0] = 0;							this->_m[3][0] = 0;
	this->_m[0][1] = 0;								this->_m[1][1] = 1 / tanHalfFOV;this->_m[2][1] = 0;							this->_m[3][1] = 0;
	this->_m[0][2] = 0;								this->_m[1][2] = 0;				this->_m[2][2] = (-zNear - zFar) / zRange ;	this->_m[3][2] = 2 * zFar * zNear / zRange;
	this->_m[0][3] = 0;								this->_m[1][3] = 0;				this->_m[2][3] = 1;							this->_m[3][3] = 0;

	return ( *this );
}

Matrix4f			Matrix4f::operator*( Matrix4f const & r )
{
	Matrix4f res;

	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
		{
			// res.set( i, j,	this->_m[0][j] * r[i][0] +
							// this->_m[1][j] * r[i][1] +
							// this->_m[2][j] * r[i][2] +
							// this->_m[3][j] * r[i][3] );
			res.set( i, j,	this->_m[0][i] * r[j][0] +
							this->_m[1][i] * r[j][1] +
							this->_m[2][i] * r[j][2] +
							this->_m[3][i] * r[j][3] );
		}
	}
	return ( res );
}

Vector3f			Matrix4f::transform( Vector3f const & r )
{
	Vector3f res(	this->_m[0][0] * r.getX() + this->_m[1][0] * r.getY() + this->_m[2][0] * r.getZ() + this->_m[3][0],
					this->_m[0][1] * r.getX() + this->_m[1][1] * r.getY() + this->_m[2][1] * r.getZ() + this->_m[3][1],
					this->_m[0][2] * r.getX() + this->_m[1][2] * r.getY() + this->_m[2][2] * r.getZ() + this->_m[3][2] );
	return ( res );
}

std::ostream &		operator<<( std::ostream & lhs, Matrix4f const & m )
{
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
			lhs << m[j][i] << " ";
		lhs << std::endl;
	}
	return ( lhs );
}

// GETTER
float const *		Matrix4f::operator[]( int index ) const
{
	return ( &( this->_m[index][0] ) );
}

// SETTER
void				Matrix4f::set( int x, int y, float value )
{
	this->_m[x][y] = value;
	return ;
}
