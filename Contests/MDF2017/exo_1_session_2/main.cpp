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
    int N = 0;
    cin >> N;
    auto v = vector<int>(N, 0);
   
    for(int i = 0 ; i < N ; ++i) {
        cin >> v[i];
    }
   
    sort(v.begin(), v.end(), std::less<int>());
    
    for(int i = 1 ; i < N - 1 ; i += 2) {
        auto tmp = v[i];
        v[i]  = v[i + 1];
        v[i + 1] = tmp; 
    }
    
    for(int i = 0 ; i < N ; ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}
