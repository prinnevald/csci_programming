#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool inBound(vector<vector<int>>* grid, int x, int y){
    return !(x<0 || y<0 || x>=grid->size() || y>=grid->at(x).size());
}

void Visit(vector<vector<int>>* grid, vector<vector<int>>* vis, int x, int y, int* a){

    vis->at(x).at(y) = 1;

    if(inBound(grid, x-1,y))
        if(grid->at(x-1).at(y) == 1 && !vis->at(x-1).at(y)){
            *a = *a + 1;
            Visit(grid, vis, x-1, y, a);
        }

    if(inBound(grid, x+1,y))
        if(grid->at(x+1).at(y) == 1 && !vis->at(x+1).at(y)){
            *a = *a + 1;
            Visit(grid, vis, x+1, y, a);
        }

    if(inBound(grid, x,y-1))
        if(grid->at(x).at(y-1) == 1 && !vis->at(x).at(y-1)){
            *a = *a + 1;
            Visit(grid, vis, x, y-1, a);
        }

    if(inBound(grid, x,y+1))
        if(grid->at(x).at(y+1) == 1 && !vis->at(x).at(y+1)){
            *a = *a + 1;
            Visit(grid, vis, x, y+1, a);
        }

    return;
}

vector<int> onesGroups(vector<vector<int>> grid, vector<int> queries) {

    vector<vector<int>> Visited(grid.size(), vector<int>(grid.at(0).size()));
    vector<int> groups;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.at(0).size(); j++){
            int amount = 0;
            if(!Visited.at(i).at(j)){
                if(grid.at(i).at(j)){
                    amount++;
                    Visit(&grid, &Visited, i, j, &amount);
                    groups.push_back(amount);
                } else {
                    Visited.at(i).at(j) = 1;
                }
            }
        }
    }

    //comparing with queue

    vector<int> result;

    for(auto el : queries){
        int q = 0;
        for(auto g : groups){
            if(g == el) q++;
        }
        result.push_back(q);
    }

    return result;
}

int main(){
	
    ofstream fout(getenv("OUTPUT_PATH"));

    string grid_rows_temp;
    getline(cin, grid_rows_temp);

    int grid_rows = stoi(ltrim(rtrim(grid_rows_temp)));

    string grid_columns_temp;
    getline(cin, grid_columns_temp);

    int grid_columns = stoi(ltrim(rtrim(grid_columns_temp)));

    vector<vector<int>> grid(grid_rows);

    for (int i = 0; i < grid_rows; i++) {
        grid[i].resize(grid_columns);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < grid_columns; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = onesGroups(grid, queries);

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
