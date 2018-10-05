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

class Graph {
    unordered_map<int, vector<int>> edges;
    int number_of_edges;
    int number_of_nodes;
    
    public:
        Graph(int n): edges(unordered_map<int, vector<int>>()), number_of_edges(n), number_of_nodes(n) {
            for(auto i = 1 ; i <= n ; ++i)
            {
                edges.insert({i, vector<int>()});
            }
        }
    
        void add_edge(int u, int v) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            //printf("Start is %d\n", start);
            
            auto q = queue<int>();
            auto distance = vector<int>(number_of_nodes);
            auto visited = unordered_set<int>();
            
            for(auto i = 0 ; i < number_of_nodes ; ++i)
            {
                distance[i] = -1;
            }
            
            distance[start] = 0;
            visited.insert(start);
            q.push(start);
            
            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();
                
                //printf("Studying node %d now.\n", cur);
                
                auto children = *edges.find(cur);             
                
                //printf("Children are: ");
                
                for(auto x: children.second)
                {
                    //printf("%d ", x);
                    if(visited.find(x) == visited.cend())
                    {
                        visited.insert(x);
                        distance[x] = distance[cur] + 6;
                        q.push(x);
                    }
                }
                
                //printf("\n");
            }
            
            return distance;
        }
    
};

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
    int q;
    fastscan(q);

    wl(q)
    {
        int n = 0 , m = 0; 
        fastscan(n);
        fastscan(m);

        //printf("n: %d, m: %d\n", n, m);
        auto g = Graph(n);

        int i;
        fl(i,0,m)
        {
            int u, v;
            fastscan(u);
            fastscan(v);

            g.add_edge(--u,--v);
        }

        int s;
        fastscan(s);

        auto res = g.shortest_reach(--s);
        for(auto i = 0 ; i < n ; ++i)
        {
            if(s != i)
            {
                printf("%d ", res[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
