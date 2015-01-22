/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:38:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 13:26:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_HPP
# define VERTEX_HPP
# include "Vector3f.hpp"

class Vertex
{
	public:
		Vertex( void );
		Vertex( Vertex const & src );
		Vertex( Vector3f const & pos, Vector3f const & color = Vector3f() , Vector3f const & normal = Vector3f() );
		~Vertex( void );

		/*
		** OPERATOR
		*/
		Vertex &		operator=( Vertex const & lhs );

		/*
		** GET
		*/
		Vector3f		getPos( void ) const;
		Vector3f		getColor( void ) const;
		Vector3f		getNormal( void ) const;

		/*
		** SET
		*/
		void			setPos( Vector3f & data );
		void			setColor( Vector3f & data );
		void			setNormal( Vector3f & data );


	private:
		Vector3f		_pos;
		Vector3f		_color;
		Vector3f		_normal;

};

#endif
