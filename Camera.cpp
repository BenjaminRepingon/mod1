/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:56:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/23 12:21:19 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Input.hpp"
# include "Camera.hpp"

Camera::Camera()
{
	return ;
}

Camera::Camera( float fov, float aspect, float zNear, float zFar ) :
	_projection( Matrix4f().initPerspective( fov, aspect, zNear, zFar ) ),
	_fov( fov ),
	_aspect( aspect ),
	_zNear( zNear ),
	_zFar( zFar ),
	_mouseLocked( false )
{
	return ;
}

Camera::Camera( Camera const & src )
{
	*this= src;
}

Camera::~Camera( void )
{
	return ;
}

Camera &	Camera::operator=( Camera const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void		Camera::reshape( int width, int height )
{
	this->_aspect = (float)width / (float)height;
	this->_projection = Matrix4f().initPerspective( this->_fov, this->_aspect, this->_zNear, this->_zFar );
}

void		Camera::update( void )
{
	if ( Input::getKeyDown( SDL_SCANCODE_SPACE ) )
		this->getTransform()->translate( 0, 0.1f, 0 );
	if ( Input::getKeyDown( SDL_SCANCODE_LSHIFT ) )
		this->getTransform()->translate( 0, -0.1f, 0 );
	if ( Input::getKeyDown( SDL_SCANCODE_UP ) )
		this->getTransform()->translate( 0, 0, -0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_DOWN ) )
		this->getTransform()->translate( 0, 0, 0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_LEFT ) )
		this->getTransform()->rotate( Vector3f( 0, 1 ,0 ), 1.0f * M_PI / 180.0f );
	if ( Input::getKeyDown( SDL_SCANCODE_RIGHT ) )
		this->getTransform()->rotate( Vector3f( 0, 1 ,0 ), -1.0f * M_PI / 180.0f );
	return ;
}

void		Camera::render( Core const & core )
{
	(void)core;
	return ;
}

Matrix4f	Camera::getViewProjection()
{
	Matrix4f	cameraRotation = this->getTransform()->getTransformedRot().conjugate().toRotationMatrix();
	Matrix4f	cameraTranslation;

	cameraTranslation.initTranslation( this->getTransform()->getTransformedPos() * -1 );
	return ( this->_projection * cameraRotation * cameraTranslation );
}
