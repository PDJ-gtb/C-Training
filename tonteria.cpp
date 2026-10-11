#include <iostream>
#include <string>
#include <vector>

int main() {

    std::string name = "Paco";

    std::vector<int> numbers = {10, 20, 30};

    std::cout << "Hola " << name << "\n";

    for (int number : numbers) {
        std::cout << number << "\n";
    }

    return 0;
}