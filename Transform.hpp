/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transform.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:49 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 17:41:41 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM
# define TRANSFORM
# include <string>
# include "Vector3f.hpp"
# include "Quaternion.hpp"

class Transform
{
public:
	Transform( void );
	Transform( Transform const & src );
	~Transform( void );

	Transform &			operator=( Transform const & rhs );

	// GETTER
	Vector3f			getPos( void ) const;
	Quaternion			getRot( void ) const;
	Vector3f			getScale( void ) const;

	// SETTER

private:
	Vector3f			_pos;
	Quaternion			_rot;
	Vector3f			_scale;
};

#endif

