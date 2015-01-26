/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 13:52:02 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Transform.hpp"

Transform::Transform() :
	_parent( 0 ),
	_matrix( glm::mat4( 1.0f ) ),
	_parentMatrix( glm::mat4( 1.0f ) )
{
	return ;
}

Transform::Transform( Transform const & src )
{
	*this = src;
}

Transform::~Transform( void )
{
	return ;
}

Transform &	Transform::operator=( Transform const & rhs )
{
	if ( this != &rhs )
	{
		this->_parent = & rhs.getParent();
		this->_matrix = rhs._matrix;
		this->_parentMatrix = rhs._parentMatrix;
	}
	return ( *this );
}

void					Transform::translate( float x, float y, float z )
{
	this->_pos = this->_pos + glm::vec3( x, y, z );
}

void					Transform::translate( glm::vec3 const & vec )
{
	this->_pos = this->_pos + vec;
}

void					Transform::rotate( glm::vec3 const & axis, float angle )
{
	this->_rot = glm::normalize( this->_rot * glm::angleAxis( angle, axis ) );
	// this->_matrix = glm::rotate( this->_matrix, angle, axis );
	// (void)axis;
	// (void)angle;
	// std::cerr << getPos().x << " " << getPos().y << " " << getPos().z << std::endl;
	// this->_matrix = glm::lookAt( getPos(), glm::vec3( 0, 0, 0 ),  glm::vec3( 0, 1, 0 ) );
}

void					Transform::lookAt( glm::vec3 const & point, glm::vec3 up )
{
	this->_matrix = glm::lookAt( this->getPos(), point, up );
}

// GETTER
glm::mat4				Transform::getTransformation()
{
	glm::mat4 translation = glm::translate( glm::mat4( 1.0f ), this->_pos );

	// this->_matrix = this->_matrix * translation * glm::toMat4( this->_rot );

	return ( this->_parentMatrix * translation * glm::toMat4( this->_rot ) );
}

glm::vec3				Transform::getTransformedPos()
{
	glm::vec4	tmp = getParentMatrix() * glm::vec4( this->_pos, 0 );
	glm::vec3	res( tmp.x, tmp.y, tmp.z );
	return ( res );
}

glm::quat				Transform::getTransformedRot()
{
	glm::quat parentRotation( 0, 0, 0, 1 );

	if ( this->_parent != 0 )
		parentRotation = this->_parent->getTransformedRot();
	return ( parentRotation * this->_rot );
}


glm::mat4				Transform::getMatrix() const
{
	return ( this->_matrix );
}

Transform &				Transform::getParent() const
{
	return ( * this->_parent );
}

glm::mat4				Transform::getParentMatrix() const
{
	return ( this->_parentMatrix );
}

glm::vec3				Transform::getPos() const
{
	return ( glm::vec3( this->_matrix[3][0], this->_matrix[3][1], this->_matrix[3][2] ) );
}

glm::quat				Transform::getRot() const
{
	return ( glm::quat( 0, 0, 0, 1 ) );
}

glm::vec3				Transform::getScale() const
{
	return ( glm::vec3( 0, 0, 0 ) );
}


