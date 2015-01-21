/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quaternion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:40:45 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/21 17:40:59 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION
# define QUATERNION
# include <string>

class Quaternion
{
public:
	Quaternion( void );
	Quaternion( Quaternion const & src );
	~Quaternion( void );

	Quaternion &			operator=( Quaternion const & rhs );

	// GETTER

	// SETTER

private:

};

#endif

