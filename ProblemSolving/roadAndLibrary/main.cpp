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

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if(c_lib <= c_road)
    {
        return (long)(c_lib * n);
    }
    
    auto edges = map<int, vector<int>>();
    auto visited = unordered_set<int>();
    auto nodes = set<int>();

    for(auto c: cities)
    {
        auto c_d = c[0];
        auto c_a = c[1];
        
        if(edges.find(c_d) == edges.cend())
        {
            edges.insert({c_d, vector<int>()});
        }
        
        if(edges.find(c_a) == edges.cend())
        {
            edges.insert({c_a, vector<int>()});
        }
        
        edges[c_d].push_back(c_a);
        edges[c_a].push_back(c_d);
        
        nodes.insert(c_d);
        nodes.insert(c_a);
    }
    
    long res = 0;
    while(visited.size() != nodes.size()) {
        auto q = queue<int>();
        auto cur_it = find_if(nodes.cbegin(), nodes.cend(), [&visited](auto n) -> bool {
           return visited.find(n) == visited.cend();
        });
        q.push(*cur_it);
        visited.insert(*cur_it);
        res += c_lib;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
            for(auto x: edges[cur])
            {
                if(visited.find(x) == visited.cend())
                {
                    res += c_road;
                    visited.insert(x);
                    q.push(x);
                }
            }
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
    auto q=0;
    fastscan(q);

    wl(q)
    {
        auto n = 0, m = 0, c_lib=0, c_road = 0;
        fastscan(n);
        fastscan(m);
        fastscan(c_lib);
        fastscan(c_road);

        auto g = vector<vector<int>>(m);

        int i;
        fl(i,0,m)
        {
            g[i] = vector<int>(2);
            fastscan(g[i][0]);
            fastscan(g[i][1]);
        }

        auto res = roadsAndLibraries(n, c_lib, c_road, g);

        printf("%ld\n", res);
    }

    return 0;
}
