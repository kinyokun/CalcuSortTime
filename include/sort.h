//
// Created by 黄酱 on 2023/4/13.
//

#ifndef CALCUSORTTIME_SORT_H
#define CALCUSORTTIME_SORT_H

#include <iostream>

namespace sort {
    void bubbleSortASC(auto begin, auto end) {
        for (auto i = (end - 1); i >= begin; i--) {
            for (auto j = begin; (j + 1) <= i; j++) {
                if ((*i) < (*j)) {
                    std::swap(*i, *j);
                }
            }
        }
    }

    void insertSortASC(auto begin, auto end) {
        auto key = *begin;
        for (auto i = begin + 1; i < end; i++) {
            key = *i;
            auto j = i - 1;
            while ((j >= begin) && ((*j) > key)) {
                *(j + 1) = *j;
                j--;
            }
            *(j + 1) = key;
        }
    }

    void quickSortASCRecursive(auto begin, auto end) {
        if (begin >= end)
            return;
        auto mid = *end;
        auto left = begin, right = end - 1;
        while (left < right) {
            while ((*left) < mid && left < right)
                left++;
            while ((*right) >= mid && left < right)
                right--;
            std::swap(*left, *right);
        }
        if ((*left) >= (*end))
            std::swap((*left), (*end));
        else
            left++;

        quickSortASCRecursive(begin, left - 1);
        quickSortASCRecursive(left + 1, end);
    }

    void quickSortASC(auto begin, auto end) {
        quickSortASCRecursive(begin, end - 1);
    }
}

#endif //CALCUSORTTIME_SORT_H
