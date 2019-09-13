#include <iostream>

#include <sstream>

#include <vector>

using namespace std;

int main(){
    vector<int> arr_list;
    string str_;
    int n;
    getline(cin,str_);
    stringstream ss(str_);
    while(ss>>n){
        arr_list.push_back(n);
    }
    for(int i=0; i<arr_list.size();i++){
        cout<<arr_list[i]<<" "<<endl;
    }
    return 0;

}
