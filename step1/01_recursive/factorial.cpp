#include <iostream>
#include <string>
using namespace std;


int fact(int n){
    if (n == 0)  return 1;
    else return n*fact(n-1);
}

int main(){
    int n; 
    int result;
    cin>>n;
    result = fact(n);
    cout<<result<<endl;
    return 0;
}
