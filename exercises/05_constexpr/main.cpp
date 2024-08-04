#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    // 笔记: constexpr可以把一个函数挪到编译器，并且规定constexpr里面的任何东西都不能出现未定义行为，出现则拒接编译，比如强转指针
    // 在C++20之前没法在constexpr内做类型双关，所以C++委员会在C++20不得不引入一个新东西 std::bit_cast，这东西里面自带constexpr
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 20; // 要么把90改小
    constexpr auto ANS = fibonacci(ANS_N); // 要么把constexpr删掉
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
