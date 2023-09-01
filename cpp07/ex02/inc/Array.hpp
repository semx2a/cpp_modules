/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:25:06 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/01 12:40:20 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array {
	
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const &a);
		~Array<T>(void);

		Array<T> &operator=(Array<T> const &a);
		T &operator[](int i);

		size_t size(void) const;

	private:
		T		*_arr;
		size_t	_len;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &a);

# include "../srcs/Array.tpp"

#endif