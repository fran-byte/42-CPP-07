/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:07:57 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 18:56:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
};

template <typename T>
T min(const T &a, const T &b)
{
    if (a > b)
        return b;
    else
        return a;
};

template <typename T>
T max(const T &a, const T &b)
{
    if (a > b)
        return a;
    else
        return b;
};

#endif
