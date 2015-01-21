/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix4f.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:43:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 17:33:11 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4F
# define MATRIX4F
# include <string>
# include "Vector3f.hpp"

class Matrix4f
{
public:
	Matrix4f( void );
	Matrix4f( Matrix4f const & src );
	~Matrix4f( void );

	Matrix4f &			operator=( Matrix4f const & rhs );

	// GETTER
	float				get( int x, int y ) const;

	// SETTER
	void				set( int x, int y, float value );

	// FUNCTIONS
	Matrix4f &			initTranslation( float x, float y, float z );
	Matrix4f &			initTranslation( Vector3f const & v );
	Matrix4f &			initScale( float x, float y, float z );
	Matrix4f &			initRotation( float x, float y, float z );
	Matrix4f &			initIdentity();
	Matrix4f &			initPerspective( float fov, float aspect, float zNear, float zFar );
	Matrix4f			operator*( Matrix4f const & r );
	Vector3f			transform( Vector3f const & r );

private:
	float				_m[4][4];

};

#endif

