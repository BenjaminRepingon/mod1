/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:00:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 16:26:33 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE
# define CORE
# include <vector>
# include "Window.hpp"
# include "Object.hpp"

class Core
{
public:
	Core( void );
	Core( Core const & src );
	~Core( void );

	Core &					operator=( Core const & rhs );

	// GETTER
	Window *				getWindow( void ) const;

	// SETTER

	// FUNCTIONS
	void					createWindow( int width, int height, std::string const & title );
	void					start( void );
	void					addObject( Object * object );

private:
	void					run( void );
	void					renderAll( void );
	Window *				_window;
	bool					_isRunning;
	std::vector<Object *>	_objects;
};

#endif

