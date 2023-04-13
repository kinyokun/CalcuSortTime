#include <iostream>
#include <vector>
#include <algorithm>
#include "runTime.h"
#include "sort.h"

constexpr auto tdp = 65ll;
const std::vector<int> vec = {3, 4, 1, 8, 0, 5, 14, 10, 12, 20, 23, 24, 2, 17, 6, 18, 9, 19};
std::vector<int> vec2sort;

// 对待排序vec进行一次bubble sort
auto sortBubble() {
    sort::bubbleSortASC(vec2sort.begin(), vec2sort.end());
}

auto sortInsert() {
    sort::insertSortASC(vec2sort.begin(), vec2sort.end());
}

auto sortQuick() {
    sort::quickSortASC(vec2sort.begin(), vec2sort.end());
}

// 一次测试
auto OneTest(auto sortFunc) {
    vec2sort = vec;
    auto time = 0ll;
    auto consumption = 0uz;
    time = RunTime.GetRunTimeNanoSec(sortFunc);
    consumption = RunTime.GetConsumptionNanoSec(tdp);

    for (auto i: vec2sort)
        std::cout << i << ' ';

    std::cout << std::endl << "Run time: ";
    RunTime.coutSecFromNano(time);
    std::cout << " consumption: ";
    RunTime.coutSecFromNano(consumption);
    std::cout << std::endl;
}

auto NTest(auto n, auto sortFunc) {
    auto time = 0ll, maxTime = 0ll, minTime = LONG_LONG_MAX, sumTime = 0ll;
    auto consumption = 0uz, maxConsumption = 0uz, minConsumption = SIZE_MAX, sumConsumption = 0uz;
    auto m = n;
    while (m > 0) {
        vec2sort = vec;
        time = RunTime.GetRunTimeNanoSec(sortFunc);
        consumption = RunTime.GetConsumptionNanoSec(tdp);

        maxTime = std::max(maxTime, time);
        maxConsumption = std::max(maxConsumption, consumption);
        minTime = std::min(minTime, time);
        minConsumption = std::min(minConsumption, consumption);

        sumTime += time;
        sumConsumption += consumption;
        m--;
    }
    std::cout << "avg_time: ";
    RunTime.coutSecFromNano((sumTime / n));
    std::cout << " max_time: ";
    RunTime.coutSecFromNano(maxTime);
    std::cout << " min_time: ";
    RunTime.coutSecFromNano(minTime);
    std::cout << std::endl << "avg_consumption: ";
    RunTime.coutSecFromNano((sumConsumption / n));
    std::cout << " max_consumption: ";
    RunTime.coutSecFromNano(maxConsumption);
    std::cout << " min_consumption: ";
    RunTime.coutSecFromNano(minConsumption);
    std::cout << std::endl;
}

int main() {
    std::cout << "BubbleSort 1 time:" << std::endl;
    OneTest(&sortBubble);
    std::cout << std::endl << "InsertSort 1 times:" << std::endl;
    OneTest(&sortInsert);
    std::cout << std::endl << "QuickSort 1 times:" << std::endl;
    OneTest(&sortQuick);

    std::cout << std::endl << std::endl;
    std::cout << "BubbleSort 10000 times:" << std::endl;
    NTest(10000, &sortBubble);
    std::cout << std::endl << "InsertSort 10000 times:" << std::endl;
    NTest(10000, &sortInsert);
    std::cout << std::endl << "QuickSort 10000 times:" << std::endl;
    NTest(10000, &sortQuick);

    return 0;
}
