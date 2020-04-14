#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class Vertex{
  public:
    string adj;
    char color;

    Vertex(){ color = 'w'; }
};

void Visit(vector<Vertex>* graph, Vertex* v){
    v->color = 'g';
    for(int i = 0; i < v->adj.size(); i++)
        if(v->adj[i] == '1' && graph->at(i).color == 'w')
                Visit(graph, &graph->at(i));
    v->color = 'b';
}

int countGroups(vector<string> related) {
    
    int groups = 0;
    vector<Vertex> graph;

    for(string v : related){
        Vertex a;
        a.adj = v;
        graph.push_back(a);
    }

    for(int i = 0; i < graph.size() ; i++){
        if(graph.at(i).color == 'w'){
            Visit(&graph, &graph.at(i));
            groups++;
        }
    }

    return groups;
}
int main(){
	
    ofstream fout(getenv("OUTPUT_PATH"));

    string related_count_temp;
    getline(cin, related_count_temp);

    int related_count = stoi(ltrim(rtrim(related_count_temp)));

    vector<string> related(related_count);

    for (int i = 0; i < related_count; i++) {
        string related_item;
        getline(cin, related_item);

        related[i] = related_item;
    }

    int result = countGroups(related);

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
