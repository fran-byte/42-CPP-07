/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:52:56 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 21:21:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

void Func(T array)
{
}

template <typename T, typename Func>
void inter(T *arrayAddr, size_t size, Func function)
{
    for (int i = 0; i < size; i++)
        function(arrayAddr[i]);
};

#endif