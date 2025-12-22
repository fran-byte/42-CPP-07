/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:52:56 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 23:00:47 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

template <typename T>
void printed(const T& value)
{
    std::cout << array << std::endl;
}

template <typename T, typename F>
void iter(T *arrayAddr, size_t size, F function)
{
    for (size_t i = 0; i < size; i++)
        function(arrayAddr[i]);
};

#endif