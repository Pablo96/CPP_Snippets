#include <iostream>
using namespace std;
/*
 This program use templates to make the fibonacci secuence at compile time.
 Pro: Increase runtime performance.
 Cons: Increase compile time.
*/
// TODO: Explore the flexibilty of templates recursion.
// TODO: Fix program

template<int N>
struct Fibonacci
{
    static const int value = Fibonacci<N-2>::value + Fibonacci<N-1>::value;
};

template<>
Fibonacci<0>
{
    static const int value = 1;
};
template<>
Fibonacci<1>
{
    static const int value = 1;
};


int main()
{
 
    cout << Fibonacci<3>::value << endl;

    return 0;
}