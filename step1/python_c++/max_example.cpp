#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4};
    int ans;
    ans = *max_element(arr.begin(),arr.end());
    cout << ans << endl;
    return 0;
}
