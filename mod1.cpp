/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/25 11:54:31 by dsousa           ###   ########.fr       */
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

	//START INIT


	Camera *	cam = new Camera( 70.0f * M_PI / 180.0f, test.getWindow().getAspect(), 0.1f, 1000.0f );

	cam->getTransform()->translate( 0, 0, 10 );
	test.setCamera( cam );

	Sphere *	s = new Sphere();
	test.addObject( s );


	//END INIT

	test.start( );

	return ( 0 );
}
