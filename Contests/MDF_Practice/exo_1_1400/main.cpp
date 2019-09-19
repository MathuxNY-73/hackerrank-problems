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
    int N = 0, X = 0;
    cin >> N;
    cin >> X;
    //cout << "N: " << N << " X: " << X << "\n";

    auto m = map<int, deque<int>>();

    int i = 0;
    fl(i, 0, N) {
        int hour = 0, min = 0, runway = 0;
        (cin >> hour).ignore() >> min >> runway;

        if(m.find(runway) == m.cend()) {
            m.insert({runway, deque<int>()});
        }

        int time = hour * 60 + min;
        //cout << "hour: "<< hour << " min: " << min << "\n";
        if(!m[runway].empty() && abs(m[runway].back() - time) <= 6) {
            cout << "COLLISION\n";
            return 0;
        }

        m[runway].emplace_back(time);
        int diff = abs(m[runway].back() - m[runway].front());
        if(m[runway].size() > X && diff <= 45) {
            cout << "COLLISION\n";
            return 0;
        }
        while(diff > 45) {
            m[runway].pop_front();
            diff = abs(m[runway].back() - m[runway].front());
        }
    }

    cout << "OK\n";
    return 0;
}
