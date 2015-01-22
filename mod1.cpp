/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 18:28:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include "Window.hpp"
# include "Map.hpp"
# include "Shader.hpp"
# include "Core.hpp"
# include "Triangle.hpp"

int		main( void )
{
	Core		test = Core();

	test.createWindow( "Mod1" , 850, 550 );

	//START INIT


	Camera *	cam = new Camera( Matrix4f().initPerspective( 70.0f * M_PI / 180.0f, test.getWindow().getAspect(), 0.1f, 1000.0f) );


	cam->getTransform()->translate( 0, 0, 10 );
	test.setCamera( cam );

	Triangle *	t = new Triangle();
	std::cerr << t->getTransform()->getPos() << std::endl;
	// t->getTransform()->rotate( Vector3f( 0, 0, 0 ), 40.0f * M_PI / 180.0f );
	// t->getTransform()->translate( 1, 0, 0 );
	std::cerr << t->getTransform()->getPos() << std::endl;
	test.addObject( t );

	// test.addObject( new Map( "demo2.mod1" ) );


	//END INIT

	test.start( );

	return ( 0 );
}
