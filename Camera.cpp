/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:56:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 11:48:47 by rbenjami         ###   ########.fr       */
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
			this->getTransform()->rotate( glm::vec3( 0, 1, 0 ), (float)( ( deltaPos.x * this->_sensitivity ) * M_PI ) / 180.0f );
		if ( rotX )
			this->getTransform()->rotate( glm::vec3( 1, 0, 0 ), (float)( ( deltaPos.y * this->_sensitivity ) *  M_PI ) / 180.0f );
		if ( rotY || rotX )
			Input::setMousePosition( Input::getCore()->getWindow().getCenter() );
		std::cerr << this->getTransform()->getMatrix()[2][2] << std::endl;
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
	if ( Input::getKeyDown( SDL_SCANCODE_W ) )
		this->getTransform()->translate( glm::vec3( 0, 0, 0.1 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_S ) )
		this->getTransform()->translate( glm::vec3( 0, 0, -0.1 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_D ) )
		this->getTransform()->translate( glm::vec3( -0.1f, 0, 0 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_A ) )
		this->getTransform()->translate( glm::vec3( 0.1f, 0, 0 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_SPACE ) )
		this->getTransform()->translate( glm::vec3( 0, -0.1f, 0 ) );
	if ( Input::getKeyDown( SDL_SCANCODE_LSHIFT ) )
		this->getTransform()->translate( glm::vec3( 0, 0.1f, 0 ) );
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

glm::mat4	Camera::getProjection()
{
	return ( this->_projection );
}
