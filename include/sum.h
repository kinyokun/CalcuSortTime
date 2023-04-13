//
// Created by 黄酱 on 2023/4/13.
//

#ifndef CALCUSORTTIME_SUM_H
#define CALCUSORTTIME_SUM_H

#include <iostream>

namespace sum {
    void sum() {
        auto sum = 0ull;
        for (auto i = 1ull; i <= 10000; i++)
            sum += i;
    }
}

#endif //CALCUSORTTIME_SUM_H
