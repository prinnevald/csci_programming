#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

string v = "aeiou";
int allLen = v.length() + 1;

bool isIn(string* v, string* s, vector<vector<int>>* res, int i, int j){
    return (0 < res->at(i - 1).at(j - 1) || i == 1) && (v->at(i-1) == s->at(j-1));
}

int longestVowelSubsequence(string s) {

    vector<vector<int>> res(allLen, vector<int>(1 + s.size(), 0));
    
    for (int i = 1; i < allLen; i++)
        for (int j = 1; j <= s.size(); j++) 
            if (isIn(&v, &s, &res, i, j)) res[i][j] = 1 + max(res[i - 1][j], res[i][j - 1]);
            else res[i][j] = res[i][j - 1];

    return res[allLen-1][s.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = longestVowelSubsequence(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
