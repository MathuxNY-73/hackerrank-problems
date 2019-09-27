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
    int A = 0;
    cin >> A;
    int N = 0;
    cin >> N;

    int max = 0;
    wl(--N) {
        int M = 0, S = 0;
        cin >> M >> S;

        if (M <= A) {
            int diff = S - M;

            if(max < diff) {
                max = diff;
            }
        }
    }

    cout << max << "\n";

    return 0;
}
