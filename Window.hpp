/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:41:40 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 15:54:05 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW
# define WINDOW
# include <iostream>
# include <GLFW/glfw3.h>

class Window
{
public:
	Window( int width, int height, std::string const & title );
	Window( Window const & src );
	~Window( void );

	Window &			operator=( Window const & rhs );

	// GETTER
	GLFWwindow *		getGLFW( void ) const;


	// SETTER

	static void			key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );
	static void			error_callback( int error, const char* description );
	void				createWindow( void );

private:
	GLFWwindow *		_window;
	int					_width;
	int					_height;
	std::string			_title;

};

#endif

