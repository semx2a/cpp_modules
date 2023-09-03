/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:08:01 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/01 17:38:37 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>

class CustomException : public std::exception {
		virtual const char* what() const throw() {
			return ("Element not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n) {

	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw CustomException();
	return (it);
}

#endif