#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0){
            return 0;
        }
        vector<int> f(prices.size());
        int min_price = prices[0];
        for(int i = 0; i < prices.size(); i++ ){
            if (i == 0){
                f[i] = 0;
            }
            else {
                if (prices[i]  < min_price){
                    min_price = prices[i];
                }
                f[i] = max(f[i-1], prices[i] - min_price);
                //f[i] = max(f[i-1], prices[i] - *min_element(prices.begin(),prices.begin()+i))
            }
        }
        return f[prices.size()-1];
    }
};
