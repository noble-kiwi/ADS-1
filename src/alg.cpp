// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    } else if (value == 2 || value == 3) {
        return true;
    } else if (value % 2 == 0 || value % 3 == 0) {
        return false;
    } else {
        for (int i = 4; i < (value/2)+1; i++) {
            if (value % i == 0) {
                return false;
            }
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        return 0;
    }
    uint64_t number = 0;
    uint64_t count = 0;
    while (1) {
        if (checkPrime(number)) {
            count++;
            if (count == n) {
                return number;
            }
        }
        number++;
    }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t number = value + 1;
    while (1) {
        if (checkPrime(number)) {
            return number;
        }
        number++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum = sum + i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    for (uint64_t i = lbound; i < hbound-2; i++) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            count++;
        }
    }
    return count;
}
