#include <iostream>

std::size_t hash(double d)
{
    return (unsigned&) d % 500;
}

int main()
{
    std::cout << hash(178.041) << std::endl;
    return 0;
}
