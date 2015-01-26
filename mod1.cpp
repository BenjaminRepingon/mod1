/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 14:15:28 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include "Window.hpp"
# include "Map.hpp"
# include "Shader.hpp"
# include "Core.hpp"
# include "Triangle.hpp"
# include "Cube.hpp"
# include "Sphere.hpp"
# include "WaterParticular.hpp"

int		main( void )
{
	Core		test = Core();

	test.createWindow( "Mod1" , 850, 550 );

	Camera *	cam = new Camera( 70.0f * M_PI / 180.0f, test.getWindow().getAspect(), 0.1f, 1000.0f );

	cam->getTransform()->translate( 0, 0, 10 );
	test.setCamera( cam );

	GLuint		buff;

	float		point[6] = { 1.0f, 0, 0, 1.0f, 0, 0 };

	glGenBuffers( 1, &buff );

	glBindBuffer( GL_ARRAY_BUFFER, buff );
	glBufferData( GL_ARRAY_BUFFER, 6 * sizeof( float ), point, GL_STATIC_DRAW );

	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	WaterParticular *	s = new WaterParticular(buff);
	test.addObject( s );


	//END INIT

	test.start( );

	return ( 0 );
}
