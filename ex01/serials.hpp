/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serials.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:49:47 by graja             #+#    #+#             */
/*   Updated: 2022/03/06 13:58:29 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALS_H
# define SERIAL_H

# include <iostream>
# include <string>

typedef	struct s_data
{
	std::string	name;
	std::string	fname;
	std::string	street;
	int			number;
	int			postcode;
	std::string		city;
}	t_data;

#endif
