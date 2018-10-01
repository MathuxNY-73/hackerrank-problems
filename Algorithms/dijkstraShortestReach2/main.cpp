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

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

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
vector<int> shortestReach(int n, vector<array<int, 3>> edges, int s) {
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

        //cout << "cur_id: " << cur_id << endl;
        auto cur_w = dist[cur_id];
        //cout << "cur_w: " << cur_w << endl;

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

inline void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fastscan(t);

    wl(t)
    {
        int n, m;
        fastscan(n);
        fastscan(m);

        vector<array<int, 3>> edges(m);

        int i;
        fl(i,0,m)
        {
            int j;
            fl(j,0,3) {
                fastscan(edges[i][j]);
            }
        }

        int s;
        fastscan(s);

        vector<int> result = shortestReach(n, edges, s);

        fl(i,0,result.size())
        {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}