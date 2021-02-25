#include <iostream>

std::size_t hash(double d)
{
    return (unsigned&) d;
}

int main()
{
    std::cout << hash(12.046) << std::endl;
    return 0;
}
