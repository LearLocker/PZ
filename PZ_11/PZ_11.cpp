// PZ_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct BigInteger {
    int value;
    BigInteger(int x) : value(x) {}
};

std::ostream& operator<<(std::ostream& out, const BigInteger& f)
{
    return out << f.value;
}

bool ascending(BigInteger a, BigInteger b)
{
    return a.value > b.value;
}

BigInteger max(BigInteger a, BigInteger b, bool (*comparisonFcn)(BigInteger, BigInteger)) {
    if (comparisonFcn(a, b)) {
        return a;
    }
    else {
        return b;
    }
}

int main()
{
    BigInteger value1(13);
    BigInteger value2(20);

    BigInteger maxValue = max(value1, value2, ascending);

    std::cout << "First BigInteger number is " << value1 << std::endl;
    std::cout << "Second BigInteger number is " << value2 << std::endl;
    std::cout << "Max BigInteger number is " << maxValue << std::endl;
}
