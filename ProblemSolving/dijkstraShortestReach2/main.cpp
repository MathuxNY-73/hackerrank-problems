#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>

#define INF 9999999

using namespace std;

vector<string> split_string(string);

struct MySort {
    private:
        vector<int> dist;
    
    public:
        bool operator()(const int& a, const int& b) const {
            return dist[a] < dist[b];
        }
    
        MySort(const vector<int>& a): dist(a) {}
        ~MySort() {}
};

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    auto adj_m = map<int, map<int, int>>();
    auto res = vector<int>(n-1);
    auto dist = vector<int>(n+1);
    auto q = vector<int>(n);
    
    for(auto i = 0 ; i < edges.size() ; ++i)
    {
        auto edge = edges[i];
        auto it = adj_m.find(edge[0]);
        
        if(it == adj_m.cend())
        {
            adj_m[edge[0]] = map<int, int>();
        }
        
        auto it_n = adj_m[edge[0]].find(edge[1]);
        if(it_n == adj_m[edge[0]].cend())
        {
            //cout << "edge[0]: " << edge[0] << ", edge[1]: " << edge[1] << endl;
            adj_m[edge[0]][edge[1]] = edge[2];
        }
        else
        {
            it_n->second = min(it_n->second, edge[2]);
        }
        
        it = adj_m.find(edge[1]);
        if(it == adj_m.cend())
        {
            adj_m[edge[1]] = map<int, int>();
        }
        
        it_n = adj_m[edge[1]].find(edge[0]);
        if(it_n == adj_m[edge[1]].cend())
        {
            adj_m[edge[1]][edge[0]] = edge[2];
        }
        else
        {
            it_n->second = min(it_n->second, edge[2]);
        }
    }
    
    for(auto i = 1 ; i < n + 1 ; ++i)
    {
        q[i-1] = i;
        dist[i] = INF;
    }
    
    dist[s] = 0;
    
    for(auto i = 0 ; i < n ; ++i)
    {
        auto min_it = min_element(q.begin(), q.end(), MySort(dist));
        iter_swap(min_it, q.end() - 1);
        auto cur_id = q.back();
        q.pop_back();
        
        cout << "cur_id: " << cur_id << endl;
        auto cur_w = dist[cur_id];
        cout << "cur_w: " << cur_w << endl;
        
        for(auto it = adj_m[cur_id].cbegin() ; it != adj_m[cur_id].cend() ; ++it)
        {
            auto arr = it->first;
            auto distance = it->second + cur_w;
            if(dist[arr] > distance)
            {
                dist[arr] = distance;
            }
        }
    }
    
    for(auto i = 1, j = 0 ; i < dist.size() ; ++i)
    {
        if(i != s)
        {
            res[j] = (dist[i] >= INF ? -1 : dist[i]);
            ++j;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
