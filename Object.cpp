/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:13:07 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 16:29:05 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Object.hpp"
# include "Core.hpp"

Object::Object()
{
	return ;
}

Object::Object( Object const & src )
{
	*this= src;
}

Object::~Object( void )
{
	return ;
}

Object &	Object::operator=( Object const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void		Object::render( Core const & core )
{
	float ratio;
	int width, height;
	glfwGetFramebufferSize( core.getWindow()->getGLFW(), &width, &height );
	ratio = width / (float) height;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	glOrtho( -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity( );
	glRotatef( ( float) glfwGetTime( ) * 50.f, 0.f, 0.f, 1.f );
	glBegin( GL_TRIANGLES );
	glColor3f( 1.f, 0.f, 0.f );
	glVertex3f( -0.6f, -0.4f, 0.f );
	glColor3f( 0.f, 1.f, 0.f );
	glVertex3f( 0.6f, -0.4f, 0.f );
	glColor3f( 0.f, 0.f, 1.f );
	glVertex3f( 0.f, 0.6f, 0.f );
	glEnd( );
}
