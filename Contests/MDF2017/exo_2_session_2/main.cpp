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
    int n = 0;
    cin >> n;
   
    char c = '#';
    auto v = vector<vector<char>>(n, vector<char>(n, '.'));
    for(int k = n ; k >= 3 ; --k) {
        c = c == '#' ? '*' : '#'; 
        for(int i = n-k ; i < k ; ++i) {
            for(int j = n-k ; j < k ; ++j) {
                if(i == n-k || i == k - 1) {
                    if(j != n-k && j != k-1) {
                        v[i][j] = c;
                    }
                }
                else {
                    v[i][j] = c;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    cout<<"\n";
}
