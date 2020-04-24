#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int countPerms(int n) {

    if (n == 0) return 0;
     
    size_t a, e, i, o, u, m = pow(10, 9) + 7;
    size_t letters[5] = {1, 1, 1, 1, 1};
    a = e = i = o = u = 1;

    while(n-- > 1){
        //counting
    
        letters[0] = (e + i + u) % m;
        letters[1] = (a + i) % m;
        letters[2] = (e + o) % m;
        letters[3] = i;
        letters[4] = (i + o) % m;

        // updating
      
        a = letters[0]; e = letters[1];
        i = letters[2]; o = letters[3];
        u = letters[4]; 
    }

    size_t res = 0;
    for(auto a: letters) res += a;

    return res % m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = countPerms(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
