// n = 4
// w = 2, 1, 3, 2
// v = 3, 2, 4, 2
// W = 5
// 选择总重量为W，value v 总和最高的方案
//
#include <iostream>
#include <string.h>
using namespace std;

const int n = 4;
const int W = 5;

int w[4] = {2, 1, 3, 2};
int v[4] = {3, 2, 4, 2};

//-------------------------------------
// recursive
//-------------------------------------
int rec_package(int i,int s){
    int res ;
    if (i == n)
        res = 0;
    else if (s < w[i])// s : 剩余重量
        res = rec_package(i+1,s);
    else{
        int A = rec_package(i+1,s) ; //不选i
        int B = rec_package(i+1,s-w[i]) + v[i] ;// 选i
        res = max(A,B);
    }
    return res;
}


//-------------------------------------
// dynamic programming 
//-------------------------------------
int dp[n+1][W+1];

int dp_package(int i,int s){
    if(dp[i][s] >= 0){
        return dp[i][s];
    }
    int res ;
    if (i == n)
        res = 0;
    else if (s < w[i])// s : 剩余重量
        res = dp_package(i+1,s);
    else{
        int A = dp_package(i+1,s) ; //不选i
        int B = dp_package(i+1,s-w[i]) + v[i] ;// 选i
        res = max(A,B);
    }
    return dp[i][s] = res;
}

//-------------------------------------
// main
//-------------------------------------
int main(){
    int ans; 
    ans = rec_package(0,W);
    cout<< "recursive " << ans << endl;

    memset(dp,-1,sizeof(dp));
    ans = dp_package(0,W);
    cout<< "dynamic programming " << ans << endl;
    return 0;
}
