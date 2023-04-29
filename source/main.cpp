#include <iostream>
#include <string>

#include "lib.hpp"

auto main(int argc, char **argv) -> int
{
    int ret = 0;

    if (argc > 1)
    {
        auto const lib = library {argv[1]};
        auto const message = "Hello from " + lib.name + "!";
        std::cout << message << '\n';
    }
    else
    {
        std::cerr << "Missing filename!" << '\n';
        ret = 1;
    }

  return ret;
}
