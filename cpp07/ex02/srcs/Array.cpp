/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:45:32 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 22:47:19 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->_arr = NULL;
	this->_len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_arr = new T[n];
	this->_len = n;
}

template <typename T>
Array<T>::Array(Array<T> const &a)
{
	this->_arr = new T[a._len];
	this->_len = a._len;
	for (int i = 0; i < a._len; i++)
		this->_arr[i] = a._arr[i];
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_arr)
		delete [] this->_arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &a)
{
	if (this != &a)
	{
		if (this->_arr)
			delete [] this->_arr;
		this->_arr = new T[a._len];
		this->_len = a._len;
		for (int i = 0; i < a._len; i++)
			this->_arr[i] = a._arr[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int i)
{
	if (i < 0 || i >= this->_len)
		throw std::exception();
	return (this->_arr[i]);
}

template <typename T>
int Array<T>::size(void) const
{
	return (this->_len);
}
