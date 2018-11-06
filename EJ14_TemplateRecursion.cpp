#include <iostream>
using namespace std;
/*
 This program use templates to make the fibonacci secuence at compile time.
 Pro: Increase runtime performance.
 Cons: Increase compile time.
*/
// TODO: Fix program

template<int N>
struct Fibonacci
{
   static const int value = Fibonacci<N-2>::value + Fibonacci<N-1>::value;
};

template<>
struct Fibonacci<0>
{
   static const int value = 0;
};


template<>
struct Fibonacci<1>
{
   static const int value = 1;
};


template<>
struct Fibonacci<2>
{
   static const int value = 1;
};

int main()
{
    cout << Fibonacci<11>::value << endl;

    return 0;
}