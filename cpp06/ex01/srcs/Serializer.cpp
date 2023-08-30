/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:50 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 19:03:57 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const & src)
{
	*this = src;
}

Serializer::~Serializer() {}

Serializer &	Serializer::operator=(Serializer const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

uintptr_t *	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t *>(ptr);
}

Data *		Serializer::deserialize(uintptr_t * raw)
{
	return reinterpret_cast<Data *>(raw);
}
