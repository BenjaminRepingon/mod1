/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:21:07 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/25 14:06:32 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <OpenGL/gl3.h>
# include <iostream>
# include <vector>
# include "AObject.hpp"
# include "Vertex.hpp"
# include "Shader.hpp"
# include "Core.hpp"

class Map : public AObject
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
		void					saveVertex( std::string file );

		std::string				_fileMap;
		std::vector<Vertex>		_vertex;
		// GLuint				_positionBuff;
		// Shader *				_shader;
};

#endif
