/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:32:26 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/06 13:43:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack <T> {
	
	public:
		MutantStack();
		MutantStack(MutantStack const&);
		virtual ~MutantStack();

		MutantStack&	operator=(MutantStack const&);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin(void) const;
		const_iterator end(void) const;
		
};

#include "../srcs/MutantStack.tpp"

#endif