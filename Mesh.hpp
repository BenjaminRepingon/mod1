/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:13:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 18:41:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH
# define MESH
# include <string>
# include <vector>
# include "Vertex.hpp"
# include "Error.hpp"
# include "Core.hpp"
# include "Shader.hpp"
# include "Transform.hpp"

class Mesh
{
public:
	Mesh( void );
	Mesh( std::vector<Vertex> const & vertices );
	Mesh( Mesh const & src );
	~Mesh( void );

	Mesh &			operator=( Mesh const & rhs );

	// GETTER
	GLuint					getVbo( void ) const;
	GLuint					getIbo( void ) const;
	std::vector<Vertex>		getVertices( void ) const;
	std::vector<int>		getIndexes( void ) const;

	// SETTER

	// FUNCTIONS
	void					addVertex( Vertex const & v ) throw();
	void					addFace( int a, int b, int c ) throw();
	void					generateBuffer( void );
	void					render( Core const & core, Shader const & shader, Transform const & transform ) const throw();

private:
	GLuint					_vbo;
	GLuint					_ibo;
	std::vector<Vertex>		_vertices;
	std::vector<int>		_indexes;
	bool					_isGenerated;
};

#endif

