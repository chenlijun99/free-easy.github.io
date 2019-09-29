#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

int main(int argc, char* argv[])
{
    int numbers[] = { 1, 2, -4, -8, 2, 3, -1, 3, 4, -3, 10, -3, 2 };
    int sum = std::accumulate(std::begin(numbers), std::end(numbers), 0);
    std::cout << sum << std::endl;
    return 0;
}
