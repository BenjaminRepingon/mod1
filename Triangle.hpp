/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:12:13 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 15:34:12 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP
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
		GLuint				_vbo;
		GLuint				_ibo;
		Shader *			_shader;
};

#endif
