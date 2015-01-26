/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:32:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 14:06:32 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_HPP
# define SPHERE_HPP
# include <OpenGL/gl3.h>
# include "AObject.hpp"
# include "Shader.hpp"
# include "Core.hpp"

class Sphere : public AObject
{
	public:
		Sphere( void );
		Sphere( Sphere const & src );
		~Sphere( void );

		Sphere &			operator=( Sphere const & rhs );

		// GETTER

		virtual void		update( void );
		virtual void		render( Core const & core );

	private:
		GLuint				_positionBuff;
		Shader *			_shader;
};

#endif
