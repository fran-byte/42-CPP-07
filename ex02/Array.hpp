/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:47:55 by frromero          #+#    #+#             */
/*   Updated: 2025/12/23 23:17:24 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T, typename F>
class Array
{
    private:
        T *_arrayAddr;
        F _function;
    public:
        Array(T *arrayAddr, size_t size, F function);
        ~Array();

};

#endif