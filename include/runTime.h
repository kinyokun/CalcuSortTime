//
// Created by 黄酱 on 2023/4/13.
//

#ifndef CACUSORTTIME_RUNTIME_H
#define CACUSORTTIME_RUNTIME_H

#include <chrono>
#include <iostream>

static class runTime {
private:
    long long _runTime = 0;
    uint64_t consumption = 0;


public:
    // get runtime of function
    auto GetRunTimeNanoSec(auto);

    // get consumption of runtime with tdp(NanoSec)
    auto GetConsumptionNanoSec(auto);

    // get consumption of runtime with tdp(Sec)
    auto coutSecFromNano(auto);
} RunTime;

auto runTime::GetRunTimeNanoSec(auto FuncP) {
    // end time of func (nanoseconds)
    auto endTimeC = std::chrono::high_resolution_clock::now();
    // begin time of func (nanoseconds)
    auto begTimeC = std::chrono::high_resolution_clock::now();
    // begin
    (*FuncP)();
    // end
    // end time of func
    endTimeC = std::chrono::high_resolution_clock::now();

    // duration of func, long long
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeC - begTimeC);
    // long long duration(nanoseconds)
    _runTime = duration.count();

    return _runTime;
}

auto runTime::GetConsumptionNanoSec(auto tdp) {
    consumption = (uint64_t) (_runTime * tdp / 10);
    return consumption;
}


auto runTime::coutSecFromNano(auto nano) {
    auto intPart = 0u, decPart = 0u;
    auto rank = -9;
    while ((nano / 10) >= 1) {
        decPart = decPart * 10 + nano % 10;
        rank++;
        nano /= 10;
    }
    intPart = nano;
    std::cout << intPart << "." << decPart << "e" << rank;
}


#endif //CACUSORTTIME_RUNTIME_H
