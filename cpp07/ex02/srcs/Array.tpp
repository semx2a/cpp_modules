/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:45:32 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 12:12:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

template <typename T>
Array<T>::Array(void) : _arr(0), _len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) {
	
	this->_arr = new T[n]();
	this->_len = static_cast<size_t>(n);
}

template <typename T>
Array<T>::Array(Array<T> const &a) : _arr(0), _len(0){

	*this = a;
}

template <typename T>
Array<T>::~Array(void) {

	if (this->_arr)
		delete [] this->_arr;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATORS::

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &a) {
	
	if (this != &a)
	{
		if (this->_len > 0)
			delete [] this->_arr;
		this->_arr = new T[a._len];
		this->_len = a._len;
		for (size_t i = 0; i < a._len; i++)
			this->_arr[i] = a._arr[i];
	}
	return (*this);
}


template <typename T>
T &Array<T>::operator[](int i) {
	
	if (i < 0 || static_cast<size_t>(i) >= this->_len)
		throw std::exception();
	return (this->_arr[i]);
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

template <typename T>
size_t Array<T>::size(void) const {
	
	return (this->_len);
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OVERLOAD OPERATORS::

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &a) {
	
	if (a.size() == 0)
		o << "Array is empty" << std::endl;
	else
	{
		for (int i = 0; static_cast<size_t>(i) < a.size(); i++)
			o << "arr[" << i << "] = " << a[i] << std::endl;
	}
	return (o);
}
