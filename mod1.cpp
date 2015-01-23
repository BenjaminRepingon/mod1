/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/23 17:35:58 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include "Window.hpp"
# include "Map.hpp"
# include "Shader.hpp"
# include "Core.hpp"
# include "Triangle.hpp"
# include "WaterParticular.hpp"

int		main( void )
{
	Core		test = Core();

	test.createWindow( "Mod1" , 850, 550 );

	//START INIT


	Camera *	cam = new Camera( 70.0f * M_PI / 180.0f, test.getWindow().getAspect(), 0.1f, 1000.0f );


	cam->getTransform()->translate( 0, 0, 10 );
	test.setCamera( cam );

	float vertexPositions[6] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	GLuint positionBuff;

	glGenBuffers( 1, &positionBuff );

	glBindBuffer( GL_ARRAY_BUFFER, positionBuff );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertexPositions ), vertexPositions, GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	// Triangle *	t = new Triangle();
	for (int i = 0; i < 4000; ++i)
	{
		WaterParticular * p = new WaterParticular( positionBuff );
		test.addObject( p );
		p->getTransform()->translate( i * 0.01f, 0, 0 );
	}


	// t->getTransform()->rotate( Vector3f( 0, 0, 0 ), 40.0f * M_PI / 180.0f );
	// t->getTransform()->translate( 1, 1, 0 );
	// test.addObject( t );

	// test.addObject( new Map( "demo2.mod1" ) );


	//END INIT

	test.start( );

	return ( 0 );
}
