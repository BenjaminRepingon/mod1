/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicObject.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:31:09 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/24 16:49:49 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICOBJECT
# define BASICOBJECT
# include <string>
# include "AObject.hpp"
# include "Mesh.hpp"
# include "Shader.hpp"

class BasicObject : public AObject
{
public:
	BasicObject( void );
	BasicObject( BasicObject const & src );
	~BasicObject( void );

	BasicObject &			operator=( BasicObject const & rhs );

	// GETTER

	// SETTER
	void					setMesh( Mesh * mesh );

	// METHODES
	virtual void			update( void );
	virtual void			render( Core const & core );

private:
	Mesh *					_mesh;
	Shader *				_shader;
};

#endif

