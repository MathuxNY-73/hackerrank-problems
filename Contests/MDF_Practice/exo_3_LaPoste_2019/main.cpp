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
    for(auto i = 0 ; i < N ; ++i) {
        cin >> v[i];
    }

    for(auto i = 0 ; i < N ; ++i) {
        int idx = 0;
        for(int j = 0 ; j < N - i ; ++j) {
            if(v[idx] < v[j]) {
                idx = j;
            }
        }

        reverse(v.begin(), v.begin() + idx + 1);

        cout << idx + 1 << " ";

        reverse(v.begin(), v.begin() + N - i);

        cout << N - i << " ";
    }
    cout << "\n";
    return 0;
}
