/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:41:39 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/22 17:50:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOBJECT_HPP
# define IOBJECT_HPP
# include <iostream>
# include "glm/glm.hpp"

class Core;

class AObject
{
	public:
		virtual void		update( void ) = 0;
		virtual void		render( Core const & core ) = 0;

		glm::mat4 *			getMatrix( void );

	protected:
		glm::mat4			_matrix;

};

#endif
