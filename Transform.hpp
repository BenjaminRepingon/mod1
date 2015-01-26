/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/26 12:28:58 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM
# define TRANSFORM
# include <iostream>
# include "glm/glm.hpp"
# include "glm/gtc/type_ptr.hpp"
# include "glm/gtx/transform.hpp"
# include "glm/gtx/quaternion.hpp"

class Transform
{
public:
	Transform( void );
	Transform( Transform const & src );
	~Transform( void );

	Transform &			operator=( Transform const & rhs );

	// GETTER
	glm::mat4			getTransformation( void );
	glm::mat4			getMatrix( void ) const;
	Transform &			getParent( void ) const;
	glm::mat4			getParentMatrix( void ) const;
	glm::vec3			getPos( void ) const;
	glm::quat			getRot( void ) const;
	glm::vec3			getScale( void ) const;
	glm::vec3			getTransformedPos( void );
	glm::quat			getTransformedRot( void );

	// SETTER

	// FUNCTIONS
	void				translate( float x, float y, float z );
	void				translate( glm::vec3 const & vec );
	void				rotate( glm::vec3 const & axis, float angle );
	void				lookAt( glm::vec3 const & point, glm::vec3 up );

private:
	Transform *			_parent;
	glm::vec3			_pos;
	glm::quat			_rot;
	glm::mat4			_matrix;
	glm::mat4			_parentMatrix;
};

#endif

