#include <cstddef>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <system_error>

#include "Decimal.h"

int main() {
    std::cout << "Input two decimal numbers separated by a space:\n" << std::endl;
    std::string a, b;
    std::cin >> a >> b;
    Decimal A(a);
    Decimal B(b);
    std::cout << "Thanks! Then choose option:" << std::endl;
    int ans;
    std::cout << "1 - Main menu\n2 - Add numbers\n3 - Subtract the second from the first\n4 - Check if the first is "
                 "greater than the second\n5- Check if the second is greater than the first\n6 - Compare for "
                 "equality\n0 - Quit"
              << std::endl;
    std::cin >> ans;
    while (ans != 0) {
        switch (ans) {
        case 1: {
            std::cout << "1 - Main menu\n2 - Add numbers\n3 - Subtract the second from the first\n4 - Check if the first is "
                         "greater than the second\n5- Check if the second is greater than the first\n6 - Compare for "
                         "equality\n0 - Quit\n"
                      << std::endl;
            break;
        }
        case 2: {
            Decimal C = A.Add(B);
            std::cout << "Answer is: ";
            C.Print();
            std::cout << "\n" << std::endl;
            break;
        }
        case 3: {
            try {
                Decimal C = A.Sub(B);
                std::cout << "Answer is: ";
                C.Print();
                std::cout << "\n" << std::endl;
            } catch (const std::logic_error &e) {
                std::cout << e.what() << "\n" << std::endl;
            }
            break;
        }
        case 4: {
            bool C = A.More(B);
            std::cout << "Answer is: " << C << "\n" << std::endl;
            break;
        }
        case 5: {
            bool C = A.Less(B);
            std::cout << "Answer is: " << C << "\n" << std::endl;
            break;
        }
        case 6: {
            bool C = A.Equal(B);
            std::cout << "Answer is: " << C << "\n" << std::endl;
            break;
        }
        case 0: {
            return 0;
        }
        default:
            std::cout << "Choose only 0 - 6 option\n" << std::endl;
        }
        std::cout << "Enter next option \n" << std::endl;
        std::cin >> ans;
    }
}
