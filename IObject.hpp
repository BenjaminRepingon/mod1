/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IObject.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:41:39 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/21 18:52:38 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOBJECT_HPP
# define IOBJECT_HPP
# include <iostream>
# include "Matrix4f.hpp"

class Core;

class IObject
{
	public:
		virtual void		update( void ) = 0;
		virtual void		render( Core const & core ) const = 0;

	protected:
		Matrix4f			_transform;

};

#endif
