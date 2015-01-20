/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:15:41 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/20 18:42:44 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"

std::vector<std::string>	Utils::Split( std::string const & s, char delim )
{
	std::vector<std::string>	elems;
	const char *				cstr = s.c_str();

	unsigned int				strLength = (unsigned int)s.length();
	unsigned int				start = 0;
	unsigned int				end = 0;

	while( end <= strLength )
	{
		while( end <= strLength )
		{
			if ( cstr[end] == delim )
				break;
			end++;
		}
		elems.push_back( s.substr( start, end - start ) );
		start = end + 1;
		end = start;
	}
	return ( elems );
}
