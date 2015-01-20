/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:15:41 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/20 18:42:52 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS
# define UTILS
# include <string>
# include <vector>

class Utils
{
public:

	static std::vector<std::string>		Split( std::string const & s, char delim );

	// GETTER

	// SETTER

private:
	Utils( void );
	Utils( Utils const & src );
	Utils &			operator=( Utils const & rhs );
	~Utils( void );

};

#endif

