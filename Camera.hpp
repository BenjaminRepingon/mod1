/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:56:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/23 16:28:08 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA
# define CAMERA
# include <string>
# include "AObject.hpp"
# include "Matrix4f.hpp"

class Camera : public AObject
{
public:
	Camera( float fov, float aspect, float zNear, float zFar );
	Camera( Camera const & src );
	~Camera( void );

	Camera &			operator=( Camera const & rhs );

	// GETTER

	// SETTER

	// METHODES
	virtual void		update( void );
	virtual void		render( Core const & core );
	Matrix4f			getViewProjection();
	void				reshape( int width, int height );

private:
	Camera( void );
	Matrix4f			_projection;
	float				_fov;
	float				_aspect;
	float				_zNear;
	float				_zFar;
	bool				_mouseLocked;
	float				_sensitivity;

};

#endif

