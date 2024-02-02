/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:11:22 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 19:13:51 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &rhs) : std::stack<T>(rhs) {
	
	this = rhs;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATORS::

template<typename T>
MutantStack<T> &	MutantStack<T>::operator=(MutantStack const &rhs) {
	
	if (this != &rhs)
		this->c = rhs.c;
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ITERATORS::

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	
	return std::stack<T>::c.end();
}


template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const {
	
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const {
	
	return std::stack<T>::c.end();
}