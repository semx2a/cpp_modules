/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:52:15 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 19:03:33 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <stdint.h>

# include "Data.hpp"

class Serializer {

	public:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();

		Serializer &	operator=(Serializer const & rhs);
		
		uintptr_t *	serialize(Data *ptr);
		Data *		deserialize(uintptr_t* raw);
};

#endif