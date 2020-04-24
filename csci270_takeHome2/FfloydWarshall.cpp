#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// it merely checks whether
// an element in in the vector

bool isIn(vector<int> a, int b){
    for(auto el : a) if(el == b) return true;
    return false;
}

int minCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){
    
    // half of the cases catch 
    // on this single if! 
    // how stupid is that? XD

    if(!isIn(g_to, g_nodes)) return 1;

    int graph[g_nodes + 1][g_nodes + 1];

    // filling the default graph
    // this dumbass is filled as:
    //
    // 0 1 1 1 1
    // 1 0 1 1 1
    // 1 1 0 1 1
    // 1 1 1 0 1
    // 1 1 1 1 0

    for(int i = 0; i < g_nodes; i++)
        for(int j = 0; j < g_nodes; j++)
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = 1;

    // filling the weight values
    
    for(int i = 0; i < g_from.size(); i++){
        graph[g_from.at(i) - 1][g_to.at(i) - 1] = g_weight.at(i);
        graph[g_to.at(i) - 1][g_from.at(i) - 1] = g_weight.at(i);
    }
    
    // finally finding the way 
    // using Pink-Floyd algo XD
    // slowly. but surely

    for (int k = 0; k < g_nodes; ++k)
        for (int i = 0; i < g_nodes; ++i)
            for (int j = 0; j < g_nodes; ++j)
                if (graph[i][k] < INT_MAX && graph[k][j] < INT_MAX)
                    graph[i][j] = min (graph[i][j], graph[i][k] + graph[k][j]); 

    // damn, getting results from
    // this bitch. I was messing
    // with it for a good 3 days

    return graph[0][g_nodes-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int result = minCost(g_nodes, g_from, g_to, g_weight);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
