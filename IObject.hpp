/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IObject.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:41:39 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/21 11:55:40 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOBJECT_HPP
# define IOBJECT_HPP

#include <iostream>

class IObject
{
	public:
		virtual void		update( void ) = 0;
		virtual void		render( void ) const = 0;

	protected:

};

#endif
