#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    //idea: f[i] = previous i sum,not include i: that is [0:i)
    //      f[0] = 0
    //      f[1] = nums[0]
    //      f[i] = f[i-1] + nums[i-1]
    NumArray(vector<int>& nums) {
        int sum;
        if (nums.size() == 0){
            f.push_back(0);
        }
        for (int i = 0; i < nums.size() + 1; i++){
            if ( i != 0 && i != 1 ){
                //f[i] = f[i-1] + nums[i-1];
                sum += nums[i-1];
                f.push_back(sum);
            }
            else if(i == 0) {
                sum = 0;
                f.push_back(sum);
            }
            else if(i == 1){
                sum = nums[i-1];
                f.push_back(sum);
            }
        }
    }

    int sumRange(int i, int j) {
        return f[j+1] - f[i];


    }
private:
    vector<int> f; // previous j sum

};

/*
void test(){
    vector<int> nums = {-2,0,3,-5,2,-1};
    NumArray* arr = new NumArray(nums);
    int a=  arr->sumRange(0,2);
    int b=  arr->sumRange(2,5);
    int c=  arr->sumRange(0,5);
    cout << a <<endl << b <<endl << c << endl;
}
*/

