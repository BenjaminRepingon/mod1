/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:36:36 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 15:54:07 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include "Window.hpp"

int main(void)
{
	Window window( 850, 550, "Test" );

	window.createWindow();

	while ( ! glfwWindowShouldClose( window.getGLFW() ) )
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize( window.getGLFW(), &width, &height );
		ratio = width / (float) height;
		glViewport( 0, 0, width, height );
		glClear( GL_COLOR_BUFFER_BIT );
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
		glfwSwapBuffers( window.getGLFW() );
		glfwPollEvents();
	}
	glfwDestroyWindow( window.getGLFW() );
	glfwTerminate();
	exit( EXIT_SUCCESS );
}
