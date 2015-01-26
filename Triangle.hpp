/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:12:13 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 14:06:31 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP
# include <OpenGL/gl3.h>
# include "AObject.hpp"
# include "Shader.hpp"
# include "Core.hpp"

class Triangle : public AObject
{
	public:
		Triangle( void );
		Triangle( Triangle const & src );
		~Triangle( void );

		Triangle &			operator=( Triangle const & rhs );

		// GETTER

		virtual void		update( void );
		virtual void		render( Core const & core );

	private:
		GLuint				_positionBuff;
		Shader *			_shader;
};

#endif
