/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:38:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/24 17:38:47 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_HPP
# define VERTEX_HPP
# include <vector>
# include "glm/glm.hpp"

class Vertex
{
	public:
		Vertex( void );
		Vertex( Vertex const & src );
		Vertex( glm::vec3 const & pos, glm::vec3 const & color, glm::vec3 const & normal );
		Vertex( float x, float y, float z );
		~Vertex( void );

		/*
		** OPERATOR
		*/
		Vertex &		operator=( Vertex const & lhs );

		/*
		** GET
		*/
		glm::vec3		getPos( void ) const;
		glm::vec3		getColor( void ) const;
		glm::vec3		getNormal( void ) const;

		/*
		** SET
		*/
		void			setPos( glm::vec3 & data );
		void			setColor( glm::vec3 & data );
		void			setNormal( glm::vec3 & data );

		/*
		** FUNCTIONS
		*/
		static float *	createBuffer( std::vector<Vertex> const & vertices );


	private:
		glm::vec3		_pos;
		glm::vec3		_color;
		glm::vec3		_normal;

};

#endif
