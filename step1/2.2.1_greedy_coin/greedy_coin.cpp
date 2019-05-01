#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////
// greedy search 
// 贪婪算法求解硬币问题
// 1元，5元，10元，50元，100元，500元硬币各有C1,C5,C10,C50,C100,C500个，
// 现在要用这些硬币支付A元，最少需要多少硬币。
// 
// C1 = 3,C5=2,C10 =1,C50 = 3,C100= 0,C500 = 2
// A = 620
///////////////////////////////////////////////////////////////////////
using namespace std;

const int VALUE[6] = {1,5,10,50,100,500};
const int COUNT[6] = {3,2,1,3,0,2};
int A = 620;

int solve(){
    int ans = 0;
    for(int i=5; i>=0; i--){
       int t = min(A/VALUE[i],COUNT[i]); //先选择最大的硬币，看可以有几个
       A -= t*VALUE[i];
       cout<<"coin "<<VALUE[i]<<":"<<t<<"numbers "<<endl;
       ans += t;
    }
    return ans;
}

int main() {
    int ans;
    ans = solve();
    cout<< ans <<endl;
    return 0;
}
