#include <iostream>
#include <fstream>


int main(int argc, char *argv[]) {
    // cmd line argument fail check
    if (argc > 2) {
        std::cout << "Too many arguments!!!!\n";
        return 1;
    }

    // Main Body
    int count;
    if (count = *argv[1] - '0') {
        int i = 100;
        do {
            std::cout << count;
            while (i > 0) 
                i--;
            i = 100;
            count--;
        } while (count > 0);
    }
}
