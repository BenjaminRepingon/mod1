/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:06:48 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/24 11:07:15 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_HPP
# define CUBE_HPP
# include <OpenGL/gl.h>
# include "AObject.hpp"
# include "Shader.hpp"
# include "Core.hpp"

class Cube : public AObject
{
	public:
		Cube( void );
		Cube( Cube const & src );
		~Cube( void );

		Cube &			operator=( Cube const & rhs );

		// GETTER

		virtual void		update( void );
		virtual void		render( Core const & core );

	private:
		GLuint				_positionBuff;
		Shader *			_shader;
};

#endif
