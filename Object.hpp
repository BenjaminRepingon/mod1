/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:13:07 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 16:29:10 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT
# define OBJECT
# include <string>
# include <GLFW/glfw3.h>

class Core;

class Object
{
public:
	Object( void );
	Object( Object const & src );
	virtual ~Object( void );

	Object &			operator=( Object const & rhs );

	// GETTER

	// SETTER

	// METHODES
	virtual void				render( Core const & core );

private:

};

#endif

