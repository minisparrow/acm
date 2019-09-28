#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int nKeywords;
    cin >> nKeywords;
    vector<string> vecKeyword(nKeywords);
    string sentence;
    for(int i = 0; i < nKeywords; i++) {
        cin >> vecKeyword[i];
    }
    vector<int> index;
    cin >> sentence;

    for (int i = 0; i < nKeywords; i++){
        size_t found = sentence.find(vecKeyword[i]);
        if (found != string::npos) {
           for(int j = 0; j < vecKeyword[i].size(); j++){
              index.push_back(found);
              found++;
           }
        }
    }

    sort(index.begin(),index.end());
    index.erase(unique(index.begin(),index.end()),index.end());
    //for(int i = 0; i < index.size(); i++){
    //    cout << index[i] << endl;
    //}
    vector<int> label;
    label.push_back(index[0]);
    for(int i = 1; i < index.size()-1; i++){
        if (index[i] == index[i-1] + 1) {
            continue;
        } else {
            label.push_back(index[i-1]);
            label.push_back(index[i]);
        }
    }
    label.push_back(index[index.size()-1]);

    // for(int i = 0; i < label.size(); i++){
    //     cout << label[i] << " ";
    // }
    // cout << endl;
    
    int j = 0;
    for(int i = 0; i < sentence.size(); i++){
        if (i == label[j] && j % 2 == 0) {
            cout << "<b>";
            j++;
            cout << sentence[i];
        } else if (label[j] == i && j % 2 == 1) {
            cout << sentence[i];
            cout << "<\\b>";
            j++;
        } else {
            cout << sentence[i];
        }
    }
    cout << endl;

    return 0;
}
