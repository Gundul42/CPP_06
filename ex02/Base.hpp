/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:50:14 by graja             #+#    #+#             */
/*   Updated: 2022/03/07 12:00:18 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

class Base
{
	public:
		virtual ~Base(void) {};
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

#endif
