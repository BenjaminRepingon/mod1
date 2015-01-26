/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:56:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 11:46:34 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA
# define CAMERA
# include <string>
# include "AObject.hpp"
# include "glm/glm.hpp"
# include "glm/gtx/transform.hpp"

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
	glm::mat4			getProjection( void );
	void				reshape( int width, int height );
	void				move( Vector3f const & direction, float amount );
	void				oriantation( int xRel, int yRel );

private:
	Camera( void );
	glm::mat4			_projection;
	float				_fov;
	float				_aspect;
	float				_zNear;
	float				_zFar;
	bool				_mouseLocked;
	float				_sensitivity;
	glm::vec3			_forward;
	glm::vec3			_up;
	glm::vec3			_right;
};

#endif

