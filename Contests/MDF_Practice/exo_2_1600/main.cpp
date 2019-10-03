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

int main()
{
    auto v = vector<vector<char>>(8, vector<char>(8, '\0'));
    auto d = map<char, int>();
    d.insert({'R', 0});
    d.insert({'J', 0});
    
    for(int i = 0 ; i < 8 ; ++i){
        for(int j = 0 ; j < 8; ++j) {
            cin >> v[i][j]; 
        }
    }
    
    int cnt = 0;
    int pts = 0;
    for(int i = 0 ; i < 8 ; ++i) {
        char prev = v[i][0], win = v[i][0];
        cnt = 1;
        for(int j = 1 ; j < 8 ; ++j) {
            if(prev == v[i][j]) {
                win = prev;
                ++cnt;
            }
            else {
                d[win] += max(cnt - 3, 0);
                win = v[i][j];
                prev = v[i][j];
                cnt = 1;
            }
        }
        d[win] += max(cnt - 3, 0);
    }
    
    for(int i = 0 ; i < 8 ; ++i) {
        char prev = v[0][i], win = v[i][0];
        cnt = 1;
        for(int j = 1 ; j < 8 ; ++j) {
            if(prev == v[j][i]) {
                win = prev;
                ++cnt;
            }
            else {
                d[win] += max(cnt - 3, 0);
                win = v[j][i];
                prev = v[i][j];
                cnt = 1;
            }
        }
        d[win] += max(cnt - 3, 0);
    }
    
    cout << (d['R'] > d['J'] ? "R" : (d['R'] == d['J'] ? "NOBODY" : "J")) << "\n";
    return 0;
}
