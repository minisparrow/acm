#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int nKeywords;
    cin >> nKeywords;
    // ------------------------------------------------
    // keywords 
    // ------------------------------------------------
    vector<string> vecKeyword(nKeywords);
    string sentence;
    for(int i = 0; i < nKeywords; i++) {
        cin >> vecKeyword[i];
    }
    vector<int> match_index;
    // ------------------------------------------------
    // sentence 
    // ------------------------------------------------
    cin >> sentence;

    // ------------------------------------------------
    // match_index 
    // ------------------------------------------------
    for (int i = 0; i < nKeywords; i++){
        size_t found = sentence.find(vecKeyword[i]);
        if (found != string::npos) {
           for(int j = 0; j < vecKeyword[i].size(); j++){
              match_index.push_back(found);
              found++;
           }
        }
    }

    sort(match_index.begin(),match_index.end());
    match_index.erase(unique(match_index.begin(),match_index.end()),match_index.end());
    // ------------------------------------------------
    // peek point 
    // ------------------------------------------------
    vector<int> peekPoint;
    peekPoint.push_back(match_index[0]);
    for(int i = 1; i < match_index.size()-1; i++){
        if (match_index[i] == match_index[i-1] + 1) {
            continue;
        } else {
            peekPoint.push_back(match_index[i-1]);
            peekPoint.push_back(match_index[i]);
        }
    }
    peekPoint.push_back(match_index[match_index.size()-1]);

    // for(int i = 0; i < peekPoint.size(); i++){
    //     cout << peekPoint[i] << " ";
    // }
    // cout << endl;
    
    int j = 0;
    for(int i = 0; i < sentence.size(); i++){
        if (i == peekPoint[j] && j % 2 == 0) {
            cout << "<b>";
            j++;
            cout << sentence[i];
        } else if (peekPoint[j] == i && j % 2 == 1) {
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
