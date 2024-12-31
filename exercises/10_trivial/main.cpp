#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 如果第 i 项已经在缓存中，直接返回
    if (i < cache.cached) {
        return cache.cache[i];
    }

    // 动态填充缓存，直到计算出第 i 项
    for (int idx = cache.cached; idx <= i; ++idx) {
        cache.cache[idx] = cache.cache[idx - 1] + cache.cache[idx - 2];
    }

    // 更新缓存的最大索引
    cache.cached = i + 1;
    // for (; false; ++cached) {
    //     cache[cached] = cache[cached - 1] + cache[cached - 2];
    // }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib = {};
    fib.cache[0] = 0;// 斐波那契数列的第 0 项
    fib.cache[1] = 1;// 斐波那契数列的第 1 项
    fib.cached = 2;  // 已经缓存的最大索引为 2（即 [0, 1]）
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
