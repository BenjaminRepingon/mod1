/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:21:07 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 13:25:39 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <OpenGL/gl.h>
# include <iostream>
# include <vector>
# include "IObject.hpp"
# include "Vertex.hpp"
# include "Shader.hpp"
# include "Core.hpp"

class Map : public IObject
{
	public:
		Map( void );
		Map( std::string fileMap );
		Map( Map const & src );
		~Map( void );

		Map &					operator=( Map const & rhs );

		virtual void			update( void );
		virtual void			render( Core const & core ) const;

	private:
		void					loadMap( void );
		std::string				_fileMap;
		std::vector<Vertex>		_vertex;
		// GLuint				_positionBuff;
		// Shader *				_shader;
};

#endif
