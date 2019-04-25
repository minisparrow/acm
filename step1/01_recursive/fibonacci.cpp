#include <iostream>
#include <string>
using namespace std;

int fib(int n)
{
    if(n<=1) return n;
    else return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    int result;
    cout<<"please input integer for fibonacci"<<endl;
    cin>>n;
    result = fib(n);
    cout<<result<<endl;
    return 0;
}
