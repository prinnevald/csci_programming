#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#include <string>

vector<string> groupTransactions(vector<string> transactions) {

    map<string, int> result;
    vector<string> temp;

    for(int i = 0; i < transactions.size(); i++)
        if(result.find(transactions.at(i)) == result.end())
            result.insert(make_pair(transactions.at(i), 1));
        else
            result[transactions.at(i)]++;

    typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;
    Comparator comp = [](pair<string, int> el1 ,pair<string, int> el2){return el1.second > el2.second;};
    set<pair<string, int>, Comparator> res(result.begin(), result.end(), comp);

    for (pair<string, int> element : result)
        temp.push_back(element.first + " " + to_string(element.second));

    return temp;
}

int main(){
	
    ofstream fout(getenv("OUTPUT_PATH"));

    string transactions_count_temp;
    getline(cin, transactions_count_temp);

    int transactions_count = stoi(ltrim(rtrim(transactions_count_temp)));

    vector<string> transactions(transactions_count);

    for (int i = 0; i < transactions_count; i++) {
        string transactions_item;
        getline(cin, transactions_item);

        transactions[i] = transactions_item;
    }

    vector<string> result = groupTransactions(transactions);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
