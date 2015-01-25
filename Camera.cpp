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
	_projection( glm::perspective( fov, aspect, zNear, zFar ) ),
	_fov( fov ),
	_aspect( aspect ),
	_zNear( zNear ),
	_zFar( zFar ),
	_mouseLocked( false ),
	_sensitivity( 0.2f ),
	_forward( 0, 0, 1 ),
	_up( 0, 1, 0 ),
	_right( 1, 0, 0 )
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
	this->_projection = glm::perspective( this->_fov, this->_aspect, this->_zNear, this->_zFar );
}

void		Camera::update( void )
{
	if ( this->_mouseLocked )
	{
		glm::vec2	mousePos( Input::getMousePosition() );
		glm::vec2	center( Input::getCore()->getWindow().getCenter() );
		glm::vec2	deltaPos = mousePos - center;

		bool rotY = deltaPos.x != 0;
		bool rotX = deltaPos.y != 0;

		if ( rotY )
		{
			this->_matrix = glm::rotate( this->_matrix, (float)( ( deltaPos.x * this->_sensitivity ) * M_PI ) / 180.0f, glm::vec3( 0, 1, 0 ) );
			// this->_forward = glm::rotate( this->_forward, (float)( ( deltaPos.x * this->_sensitivity ) * M_PI ) / 180.0f, glm::vec3( 0, 1, 0 ) );
		}
		if ( rotX )
			this->_matrix = glm::rotate( this->_matrix, /*this->getTransform()->getRot().getRight()*/(float)( ( deltaPos.y * this->_sensitivity ) *  M_PI ) / 180.0f, glm::vec3( 1, 0, 0 ) );
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
		this->_matrix = glm::translate( this->_matrix, glm::vec3( 0.1f, 0, 0 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_A ) )
		this->_matrix = glm::translate( this->_matrix, glm::vec3( -0.1f, 0, 0 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_W ) )
		this->_matrix = glm::translate( this->_matrix, glm::vec3( 0, 0, 0.1 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_S ) )
		this->_matrix = glm::translate( this->_matrix, glm::vec3( 0, 0, -0.1 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_SPACE ) )
		this->_matrix = glm::translate( this->_matrix, glm::vec3( 0, 0.1f, 0 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_LSHIFT ) )
		this->_matrix = glm::translate( this->_matrix, glm::vec3( 0, -0.1f, 0 ) );
	return ;
}

void		Camera::move( Vector3f const & direction, float amount )
{
	(void)direction;
	(void)amount;
	// this->getTransform()->translate( direction * amount );
}

void		Camera::render( Core const & core )
{
	(void)core;
	return ;
}

glm::mat4	Camera::getViewProjection()
{
	// Matrix4f	cameraRotation = this->getTransform()->getTransformedRot().conjugate().toRotationMatrix();
	// Matrix4f	cameraTranslation;

	// cameraTranslation.initTranslation( this->getTransform()->getTransformedPos() * -1 );
	// return ( this->_projection * cameraRotation * cameraTranslation );
	return ( this->_projection * this->_matrix );
}
