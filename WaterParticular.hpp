/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaterParticular.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:05:41 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 14:06:30 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WATERPARTICULAR_HPP
# define WATERPARTICULAR_HPP
# include <OpenGL/gl3.h>
# include "AObject.hpp"
# include "Shader.hpp"
# include "Core.hpp"

class WaterParticular : public AObject
{
	public:
		// WaterParticular( void );
		WaterParticular( GLuint positionBuff);
		WaterParticular( WaterParticular const & src );
		~WaterParticular( void );

		WaterParticular &			operator=( WaterParticular const & rhs );

		// GETTER

		virtual void		update( void );
		virtual void		render( Core const & core );

	private:
		GLuint				_positionBuff;
		Shader *			_shader;
};

#endif
