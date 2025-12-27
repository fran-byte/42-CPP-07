/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:47:55 by frromero          #+#    #+#             */
/*   Updated: 2025/12/27 12:27:44 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    T *_arrayAddr;
    unsigned int _n;

public:
    Array(void);
    Array(unsigned int n);
    Array(Array const &copy);
    ~Array(void);
    Array &operator=(Array const &other);

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"

#endif