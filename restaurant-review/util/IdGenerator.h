#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <atomic>

class IdGenerator {
    std::atomic<int> counter {1};
public:
    int next() { return counter.fetch_add(1); }
};
#endif