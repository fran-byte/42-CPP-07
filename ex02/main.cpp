/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:02:06 by frromero          #+#    #+#             */
/*   Updated: 2025/12/27 20:01:28 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

void my_tests()
{
    std::cout << "1. Empty constructor: emptyArray" << std::endl;
    Array<int> emptyArray;
    std::cout << "   Size: " << emptyArray.size() << std::endl;

    std::cout << std::endl
              << "2. Constructor with size 5:" << std::endl;
    Array<int> fiveArray(5);
    std::cout << "   Size: " << fiveArray.size() << std::endl;

    std::cout << std::endl
              << "3. Write and read elements:" << std::endl;
    fiveArray[0] = 42;
    fiveArray[1] = 21;
    fiveArray[4] = 84;
    std::cout << "   fiveArray[0] = " << fiveArray[0] << std::endl;
    std::cout << "   fiveArray[1] = " << fiveArray[1] << std::endl;
    std::cout << "   fiveArray[4] = " << fiveArray[4] << std::endl;

    std::cout << std::endl
              << "4. Copy constructor (deep copy test):"
              << std::endl;
    Array<int> copy(fiveArray);
    std::cout << "   Original[0] = " << fiveArray[0] << std::endl;
    std::cout << "   Copy[0] = " << copy[0] << std::endl;

    std::cout << std::endl
              << "5. Assignment operator:" << std::endl;
    Array<int> assignedArray;
    assignedArray = fiveArray;
    std::cout << "   Original[4] = " << fiveArray[4] << std::endl;
    std::cout << "   Assigned[4] = " << assignedArray[4] << std::endl;

    std::cout << std::endl
              << "6. Const array access:" << std::endl;
    const Array<int> constArray(fiveArray);
    std::cout << "   constArray[1] = " << constArray[1] << std::endl;
    std::cout << "   Size of constArray: " << constArray.size() << std::endl;
    // constArray[1] = 777; // This should NOT compile

    std::cout << std::endl
              << "7. Out of bounds exception tests:" << std::endl;

    std::cout << "   Trying five[5] (index = size): "; // Five index 0 to 4
    std::cout << std::endl
              << "8. Default initialization test (must be zeros):" << std::endl;

    int *dirtyArray = new int[10];
    for (int i = 0; i < 10; i++)
        dirtyArray[i] = 999; // basura
    delete[] dirtyArray;

    Array<int> defaultInitArray(10);
    std::cout << "   ";
    for (unsigned int i = 0; i < defaultInitArray.size(); i++)
    {
        std::cout << defaultInitArray[i];
        if (i < defaultInitArray.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    try
    {
        fiveArray[5] = 0;
        std::cout << "ERROR: Should have thrown exception!" << std::endl; // in not OK
    }
    catch (const std::exception &e)
    {
        std::cout << "OK: Exception caught: " << e.what() << std::endl; // is ok
    }

    std::cout << "   Trying five[-1] (negative index): ";
    try
    {
        fiveArray[-1] = 0;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "OK: Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

int main(int, char **)
{
    std::cout << std::endl
              << "=== MY TESTS ===" << std::endl
              << std::endl;

    my_tests();

    std::cout << "=== RUNNING ORIGINAL SUBJECT TESTS ===" << std::endl;

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror;
    return 0;
}