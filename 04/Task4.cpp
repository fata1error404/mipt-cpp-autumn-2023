#include <iostream>
#include "header.hpp"

int main()
{
    std::string line = {"18446744073709551616 -11 18446744073709551615 0 1 00323 hello w0r1d 1234332 test 12.27"};
    Parse(line, StringHandler, NumberHandler);
}
