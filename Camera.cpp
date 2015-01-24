/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:56:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 19:19:56 by rbenjami         ###   ########.fr       */
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
	_mouseLocked( false ),
	_sensitivity( 0.2f )
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
	if ( this->_mouseLocked )
	{
		Vector2f	mousePos( Input::getMousePosition() );
		Vector2f	center( Input::getCore()->getWindow().getCenter() );
		Vector2f	deltaPos = mousePos - center;

		bool rotY = deltaPos.getX() != 0;
		bool rotX = deltaPos.getY() != 0;

		if ( rotY )
			this->getTransform()->rotate( Vector3f( 0, 1, 0 ), ( ( deltaPos.getX() * this->_sensitivity ) * M_PI ) / 180.0f );
		if ( rotX )
			this->getTransform()->rotate( this->getTransform()->getRot().getRight(), ( ( deltaPos.getY() * this->_sensitivity ) *  M_PI ) / 180.0f );
		if ( rotY || rotX )
			Input::setMousePosition( Input::getCore()->getWindow().getCenter() );
	}
	if ( Input::getButtonDown( SDL_BUTTON_LEFT ) )
	{
		this->_mouseLocked = true;
		SDL_ShowCursor( 0 );
		Input::setMousePosition( Input::getCore()->getWindow().getCenter() );
	}
	if ( Input::getKeyDown( SDL_SCANCODE_ESCAPE ) )
	{
		this->_mouseLocked = false;
		SDL_ShowCursor( 1);
	}
	if ( Input::getKeyDown( SDL_SCANCODE_D ) )
		this->move( this->getTransform()->getRot().getRight(), 0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_A ) )
		this->move( this->getTransform()->getRot().getLeft(), 0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_W ) )
		this->move( this->getTransform()->getRot().getForward(), 0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_S ) )
		this->move( this->getTransform()->getRot().getBack(), 0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_SPACE ) )
		this->move( this->getTransform()->getRot().getUp(), 0.1f );
	if ( Input::getKeyDown( SDL_SCANCODE_LSHIFT ) )
		this->move( this->getTransform()->getRot().getDown(), 0.1f );
	return ;
}

void		Camera::move( Vector3f const & direction, float amount )
{
	this->getTransform()->translate( direction * amount );
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
