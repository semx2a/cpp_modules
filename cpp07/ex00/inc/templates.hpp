/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:14:30 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/31 16:57:33 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>
void	swap(T &lhs, T &rhs) {
	
	T	tmp;

	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template <typename T>
T		min(T lhs, T rhs) {
	
	return (lhs < rhs) ? lhs : rhs;
}

template <typename T>
T		max(T lhs, T rhs) {
	
	return (lhs > rhs) ? lhs : rhs;
}

#endif