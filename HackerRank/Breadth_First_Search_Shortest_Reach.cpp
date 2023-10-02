#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// 注意！起點可能沒有被connected!

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    int a[n+1][n+1];
    int dist[n+1];
    bool shortest[n+1];
    int max_v = 1000000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) a[i][j] = 0;
            else a[i][j] = max_v;
        }
    }
    for(int i=0;i<edges.size();i++){
        a[edges[i][0]][edges[i][1]] = 6;
        a[edges[i][1]][edges[i][0]] = 6;
    }
    for(int i=1;i<=n;i++){
        dist[i] = a[s][i];
        shortest[i] = false;
    }
    int iter = 0, min_d, min_i;
    while(iter<n){
        min_d = max_v;
        for(int i=1;i<=n;i++){
            if(i!=s && !shortest[i] && dist[i]<min_d){
                min_d = dist[i];
                min_i = i;
            }
        }
        if(min_d == max_v) break;
        shortest[min_i] = true;
        for(int i=1;i<=n;i++){
            if(s!=i && !shortest[i])
            dist[i] = min(dist[i], min_d + a[min_i][i]);
        }
        iter++;
    }

    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(i!=s){
            if(dist[i] == max_v) ans.push_back(-1);
            else ans.push_back(dist[i]);
        }
    }

    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
