/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:52:56 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 22:46:58 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

template <typename T>
void Func(T array)
{
    std::cout << array << std::endl;
}

template <typename T, typename Func>
void inter(T *arrayAddr, size_t size, Func function)
{
    for (size_t i = 0; i < size; i++)
        function(arrayAddr[i]);
};

#endif