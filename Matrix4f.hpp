/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix4f.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:43:50 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 17:11:23 by rbenjami         ###   ########.fr       */
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
	float const *		operator[]( int index ) const;

	// SETTER
	void				set( int x, int y, float value );

	// FUNCTIONS
	Matrix4f &			initTranslation( float x, float y, float z );
	Matrix4f &			initTranslation( Vector3f const & v );
	Matrix4f &			initScale( float x, float y, float z );
	Matrix4f &			initScale( Vector3f const & v );
	Matrix4f &			initRotation( float x, float y, float z );
	Matrix4f &			initRotation( Vector3f const & forward, Vector3f const & up, Vector3f const & right );
	Matrix4f &			initRotation( Vector3f const & forward, Vector3f const & up );
	Matrix4f &			initIdentity();
	Matrix4f &			initPerspective( float fov, float aspect, float zNear, float zFar );
	Matrix4f			operator*( Matrix4f const & r );
	Vector3f			transform( Vector3f const & r );

private:
	float				_m[4][4];

};

std::ostream &			operator<<( std::ostream & lhs, Matrix4f const & v );

#endif

