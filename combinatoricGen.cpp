#include <iostream>


int factorial(int n) {
    int total = 1;
    for (int i = 1; i <= n; ++i) {
        total *= i;
    }
    return total;
}


int combin(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int permut(int n, int r){
    return (factorial(n) / factorial(n-r));
}

int main() {
    int n = 8, k = 3;
    std::cout << "C(" << n << ", " << k << ") = " << combin(n, k) << std::endl;
    std::cout << "P(" << n << ", " << k << ") = " << permut(n, k) << std::endl;

    return 0;
}
