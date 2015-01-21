/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:25:53 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 15:19:42 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include "Window.hpp"
# include "Shader.hpp"
# include "Core.hpp"
# include "Triangle.hpp"

int		main( void )
{
	Core test = Core();

	test.createWindow( "Mod1" , 850, 550 );

	//START INIT

	test.addObject( new Triangle() );

	//END INIT

	test.start( );

	return ( 0 );
}
