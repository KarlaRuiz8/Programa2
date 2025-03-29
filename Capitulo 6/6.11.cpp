#include <iostream>
#include <cmath>

int main() {
    double x;

    // a) x = fabs(7.5)
    x = fabs(7.5);
    std::cout << "a) x = " << x << std::endl;  

    // b) x = floor(7.5)
    x = floor(7.5);
    std::cout << "b) x = " << x << std::endl;  

    // c) x = fabs(0.0)
    x = fabs(0.0);
    std::cout << "c) x = " << x << std::endl;  

    // d) x = ceil(0.0)
    x = ceil(0.0);
    std::cout << "d) x = " << x << std::endl;  

    // e) x = fabs(-6.4)
    x = fabs(-6.4);
    std::cout << "e) x = " << x << std::endl;  

    // f) x = ceil(-6.4)
    x = ceil(-6.4);
    std::cout << "f) x = " << x << std::endl;  

    // g) x = ceil(-fabs(-8) + floor(-5.5))
    x = ceil(-fabs(-8) + floor(-5.5));
    std::cout << "g) x = " << x << std::endl;  

    return 0;
}
