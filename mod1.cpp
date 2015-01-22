/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 13:32:15 by dsousa           ###   ########.fr       */
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
	Core test = Core();

	test.createWindow( "Mod1" , 850, 550 );

	//START INIT

	test.addObject( new Triangle() );
	test.addObject( new Map( "demo2.mod1" ) );

	//END INIT

	test.start( );

	return ( 0 );
}
