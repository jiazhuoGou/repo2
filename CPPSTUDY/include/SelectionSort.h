#pragma once

#include<iostream>
#include<array>

template <typename T>
void selectionSort(T list[], const std::size_t size)
{
    for (std::size_t i = 0; i < size - 1; i++)
    {
        T min = list[i];
        int index = i;

        for (std::size_t j = i + 1; j < size; j++)
        {
            if (list[j] < min)
            {
                index = j;
                min = list[j];
            }
        }

        if (index != i)
        {
            list[index] = list[i];
            list[i] = min;
        }
    }
}

template <typename T, int N>
void selectionSort(std::array<T, N> &list)
{
    constexpr int size = N;
    for (std::size_t i = 0; i < size - 1; i++)
    {
        T min = list[i];
        int index = i;

        for (std::size_t j = i + 1; j < size; j++)
        {
            if (list[j] < min)
            {
                index = j;
                min = list[j];
            }
        }

        if (index != i)
        {
            list[index] = list[i];
            list[i] = min;
        }
    }
}