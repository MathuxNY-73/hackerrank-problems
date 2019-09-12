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
    int N = 0, S = 0;
    cin >> N;
    cin >> S;
    auto array = vector<int>(N, 0);

    int i;
    fl(i, 0, N){
       cin >> array[i];
    }

    auto n_day = 0;
    auto int_new = 0.0, int_old = 0.0;
    for(auto& c: array) {
        S += c;
        if(S < 0) {
            ++n_day;
        }
        else {
            n_day = 0;
        }

        // Old
        if(n_day >= 3) {
            int_old += 0.1 * abs(S);
        }

        // New
        if(n_day >= 4) {
            int_new += 0.3 * abs(S);
        }
        else if(n_day) {
            int_new += 0.2 * abs(S);
        }
    }

    cout << floor(int_new - int_old) + 1 << "\n";

    return 0;
}
