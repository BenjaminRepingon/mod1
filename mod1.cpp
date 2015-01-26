/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 14:08:51 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include "Window.hpp"
# include "Map.hpp"
# include "Shader.hpp"
# include "Core.hpp"
# include "Triangle.hpp"
# include "BasicObject.hpp"
# include "Vertex.hpp"

int		main( void )
{
	Core		test = Core();
	Input::setCore( &test );

	test.createWindow( "Mod1" , 850, 550 );

	//START INIT

std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	Camera *	cam = new Camera( 70.0f, test.getWindow().getAspect(), 0.1f, 1000.0f );
	// cam->getMatrix()->translate( 0, 0, 10 );
	test.setCamera( cam );

	// std::vector<Vertex> vertices;

	// glm::vec3 normal( 0, 1, 0 );

	// vertices.push_back( Vertex( glm::vec3( -1.0f, -1.0f, -1.0f ), glm::vec3( 1.0f, 0.0f, 0.0f ), normal ) );
	// vertices.push_back( Vertex( glm::vec3( -1.0f, -1.0f, 1.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ), normal ) );
	// vertices.push_back( Vertex( glm::vec3( 1.0f, -1.0f, -1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), normal ) );
	// vertices.push_back( Vertex( glm::vec3( 1.0f, -1.0f, 1.0f ), glm::vec3( 1.0f, 0.0f, 1.0f ), normal ) );

	// BasicObject *	testMesh = new BasicObject();
	// Mesh			mesh( vertices );
	// mesh.addFace( 0, 1, 2 );
	// mesh.addFace( 2, 1, 3 );
	// mesh.generateBuffer();

	// testMesh->setMesh( & mesh );
	// test.addObject( testMesh );

	Triangle *	t = new Triangle();
	// t->getTransform()->rotate( glm::vec3( 0, 0, 0 ), 40.0f * M_PI / 180.0f );
	// t->getTransform()->translate( 1, 1, 0 );
	test.addObject( t );

	// test.addObject( new Map( "demo2.mod1" ) );


	//END INIT

	test.start( );

	return ( 0 );
}
