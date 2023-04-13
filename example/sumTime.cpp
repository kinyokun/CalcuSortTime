//
// Created by 黄酱 on 2023/4/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "runTime.h"
#include "sum.h"

constexpr auto tdp = 65ll;

// 一次测试
auto OneTest(auto Func) {
    auto time = 0ll;
    auto consumption = 0uz;
    time = RunTime.GetRunTimeNanoSec(Func);
    consumption = RunTime.GetConsumptionNanoSec(tdp);

    std::cout << std::endl << "Run time: ";
    RunTime.coutSecFromNano(time);
    std::cout << " consumption: ";
    RunTime.coutSecFromNano(consumption);
    std::cout << std::endl;
}

// N次测试
auto NTest(auto n, auto Func) {
    auto time = 0ll, maxTime = 0ll, minTime = LONG_LONG_MAX, sumTime = 0ll;
    auto consumption = 0uz, maxConsumption = 0uz, minConsumption = SIZE_MAX, sumConsumption = 0uz;
    auto m = n;
    while (m > 0) {
        time = RunTime.GetRunTimeNanoSec(Func);
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
    std::cout << "Sum 10000 time:" << std::endl;
    NTest(10000, sum::sum);
    return 0;
}