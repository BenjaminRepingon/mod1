/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:56:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/22 17:51:18 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA
# define CAMERA
# include <string>
# include "AObject.hpp"
# include "Matrix4f.hpp"

class Camera : public AObject
{
public:
	Camera( Matrix4f const & projection );
	Camera( Camera const & src );
	~Camera( void );

	Camera &			operator=( Camera const & rhs );

	// GETTER

	// SETTER

	// METHODES
	virtual void		update( void );
	virtual void		render( Core const & core );
	Matrix4f			getViewProjection();

private:
	Camera( void );
	Matrix4f			_projection;

};

#endif

