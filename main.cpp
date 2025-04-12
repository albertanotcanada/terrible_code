#include <list>
#include <bitset>
#include <functional>
#include "myheader.h"
#include "utils/math_utils.h"
#include "config/settings.h"
#include "logger/logger.h"

int main() {
    std::string name = "Alice";
    std::cout << "Hello, " << name << "!" << std::endl;

    myFunction(); // Suppose this is declared in "myheader.h"
    return 0;
}
