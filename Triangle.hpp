/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:12:13 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/21 13:47:41 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP
# include <OpenGL/gl.h>
# include "IObject.hpp"
# include "Shader.hpp"

class Triangle : public IObject
{
	public:
		Triangle( void );
		Triangle( Triangle const & src );
		~Triangle( void );

		Triangle &			operator=( Triangle const & rhs );

		void				update( void );
		void				render( void ) const;

	private:
		GLuint				_positionBuff;
		Shader *			_shader;
		// Vector3f			_pos;
		// Vector3f			_color;
};

#endif
