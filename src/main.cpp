#include <iostream>
#include "Date.h"


int main() {
    try {
        Date obj1;
        std::cout << obj1;
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}