#include <iostream>
using namespace std;

int add(int a, int b, int c = 0)
{
    return a+b+c;
}

int main()
{
    cout << "Addition : " << add(3, 4, 3) << endl;

    return 0;
}