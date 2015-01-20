/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/20 18:52:24 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include "Window.hpp"
# include "Shader.hpp"

GLuint positionBufferObject;

const float vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
};

void	render( Shader const & shader )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );

	shader.bind();

	glBindBuffer( GL_ARRAY_BUFFER, positionBufferObject );
	glEnableVertexAttribArray( 0 );

	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 0, 0 );

	glDrawArrays( GL_TRIANGLES, 0, 3 );

	glDisableVertexAttribArray( 0 );
	glUseProgram( 0 );
}

void	initializeVertexBuffer( void )
{
	glGenBuffers( 1, &positionBufferObject );

	glBindBuffer( GL_ARRAY_BUFFER, positionBufferObject );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void	reshape( int w, int h )
{
	glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
}

int		main( void )
{
	Window		win( "Test", 850, 550 );
	bool		quit = false;
	SDL_Event	e;

	win.init();

	Shader		shader( "Basic" );
	initializeVertexBuffer();

	reshape( 850, 550 );

	while( ! quit )
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if ( e.type == SDL_QUIT )
				quit = true;
			//Handle keypress with current mouse position
			// else if( e.type == SDL_TEXTINPUT )
			// {
			// 	int x = 0, y = 0;
			// 	SDL_GetMouseState( &x, &y );
			// 	handleKeys( e.text.text[ 0 ], x, y );
			// }
		}
		render( shader );
		SDL_GL_SwapWindow( win.getSDLWindow() );
		SDL_Delay( 10 );
	}

	return ( 0 );
}
