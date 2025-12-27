/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:09:44 by frromero          #+#    #+#             */
/*   Updated: 2025/12/27 18:18:53 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _arrayAddr(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arrayAddr(new T[n]()), _n(n)
{ /* this is a standar initialized by default new int[5]()  */
}

// template <typename T>
// Array<T>::Array(unsigned int n) : _arrayAddr(new T[n]), _n(n)
// {
//     /* NOT initialized by default new int[5]  */
// }

template <typename T>
Array<T>::Array(Array const &copy)
{
    _n = copy._n;
    _arrayAddr = new T[_n];
    for (unsigned int i = 0; i < _n; i++)
        _arrayAddr[i] = copy._arrayAddr[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arrayAddr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete[] _arrayAddr;
        _n = other._n;
        _arrayAddr = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
            _arrayAddr[i] = other._arrayAddr[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _n)
        throw std::exception();
    return _arrayAddr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _n)
        throw std::exception();
    return _arrayAddr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _n;
}
#endif