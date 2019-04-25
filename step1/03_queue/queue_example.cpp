#include <queue>
#include <iostream>

using namespace std;

int main(){
    queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.front()<<endl;
    s.pop();
    cout<<s.front()<<endl;
    s.pop();
    cout<<s.front()<<endl;
    return 0;
    
}
