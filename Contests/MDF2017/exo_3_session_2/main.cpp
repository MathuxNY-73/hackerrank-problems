#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

static const auto _____ = []()
                          {
                              ios::sync_with_stdio(false);
                              cin.tie(nullptr);
                              cout.tie(nullptr);
                              return nullptr;
                          }();

struct MyHash
{
    std::size_t operator()(pair<int,int> const& p) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(p.first);
        std::size_t h2 = std::hash<int>{}(p.second);
        return h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
    }
};

struct MyEq
{
    bool operator()(pair<int,int> const& a, pair<int,int> const& b) const noexcept
    {
        return a.first == b.first && a.second == b.second;
    }
};

int main()
{
   int h = 0, l = 0;
   cin >> h >> l;
   int pos_h = 0, pos_l = 0;
   
   auto v = vector<vector<char>>(h, vector<char>(l, '.'));
   
   for(int i = 0 ; i < h ; ++i) {
       for(int j = 0 ; j < l ; ++j) {
           cin >> v[i][j];
           if(v[i][j] == 'x') {
               pos_h = h; pos_l = l;
           }
       }
   }
   cout<<"pos_h:"<<pos_h<<",pos_l:"<<pos_l<<"\n";
   
   auto q = queue<pair<int, int>>();
   auto s = unordered_set<pair<int, int>, MyHash, MyEq>(); 
   auto cnt = 0;
   
   q.push({pos_h, pos_l});
   s.insert({pos_h, pos_l});
   ++cnt;
   
   while(!q.empty()) {
       auto cur = q.front();
       q.pop();
       auto c_pos_h = cur.first, c_pos_l = cur.second;
       for(int i = c_pos_h - 1 ; i <= c_pos_h + 1 ; ++i) {
           for(int j = c_pos_l - 1; j <= c_pos_l + 1; ++j) {
               if(i >= 0 && i < h) {
                    if(j >= 0 && j < l) {
                        if(v[i][j] != '*') {
                            auto r = s.insert({i, j});
                            if(r.second) {
                                cout << "(i:" << i <<",j:"<<j<<")\n";
                                q.push({i, j});
                                ++cnt;
                            }
                                
                        }
                    }
                   
               }
           }
       }
   }
   
   cout << cnt << "\n";
   
   
}
