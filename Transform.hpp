/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 13:33:30 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM
# define TRANSFORM
# include <string>
# include "Vector3f.hpp"
# include "Matrix4f.hpp"
# include "Quaternion4f.hpp"

class Transform
{
public:
	Transform( void );
	Transform( Vector3f const & pos, Quaternion4f const & rot, Vector3f const & scale );
	Transform( Transform & src );
	~Transform( void );

	Transform &			operator=( Transform & rhs );

	// GETTER
	Transform &			getParent( void ) const;
	Matrix4f			getParentMatrix( void );
	Vector3f			getPos( void ) const;
	Quaternion4f		getRot( void ) const;
	Vector3f			getScale( void ) const;

	// SETTER

	// FUNCTIONS
	void				update( void );
	bool				hasChanged( void ) const;
	void				translate( float x, float y, float z );
	void				translate( Vector3f const & vec );
	void				rotate( Vector3f const & axis, float angle );
	void				lookAt( Vector3f const & point, Vector3f up );
	Matrix4f			getTransformation();

private:
	Quaternion4f		getLookAtRotation( Vector3f const & point, Vector3f const & up );

	Vector3f			_pos;
	Quaternion4f		_rot;
	Vector3f			_scale;
	Transform *			_parent;
	Matrix4f			_parentMatrix;
	Vector3f			_oldPos;
	Quaternion4f		_oldRot;
	Vector3f			_oldScale;
	bool				_isInitialized;
};

#endif

