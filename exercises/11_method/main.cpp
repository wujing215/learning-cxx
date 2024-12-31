#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    Fibonacci() {
        cache[0] = 0;// 斐波那契数列的第 0 项
        cache[1] = 1;// 斐波那契数列的第 1 项
        cached = 2;  // 已经缓存的最大索引为 2（即 [0, 1]）
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        
        if (i < cached) {
            return cache[i];
        }
        for (int idx = cached; idx <= i; ++idx) {
            cache[idx] = cache[idx - 1] + cache[idx - 2];
        }
        cached = i + 1;
        return cache[i];
        
    }
};

int
main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
