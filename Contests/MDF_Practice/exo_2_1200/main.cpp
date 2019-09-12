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
    auto h_map = unordered_map<string, double>();
    auto nb_fail = unordered_map<string, map<int, int>>();

    int i;
    fl(i, 0, N){
        string n;
        double h;
        char c;
        cin >> n >> h >> c;

        if(h_map.find(n) == h_map.cend()) {
            h_map.insert({n, 0});
            nb_fail.insert({n, map<int,int>()});
        }

        if(nb_fail[n].find(h) == nb_fail[n].cend()) {
            nb_fail[n].insert({h, 0});
        }

        if(c == 'S') {
            h_map[n] = max(h_map[n], h);
        }
        if(c == 'E') {
            ++(nb_fail[n])[h];
        }
    }

    auto max_h = 0.0;
    auto name = string("KO");

    for(auto&& t: h_map) {
        auto n = t.first;
        auto h = t.second;
        if(h > max_h) {
            name = n;
            max_h = h;
        }
        else if(h != 0 && h == max_h) {
            if((nb_fail[n])[h] < nb_fail[name][h]) {
                name = n;
            }
            else if(nb_fail[n][h] == nb_fail[name][h]) {
                auto acc = [](const int& l, const pair<int, int>& r) -> int {
                               return move(l) + r.second;
                           };

                auto l_f = accumulate(nb_fail[n].cbegin(),
                                 nb_fail[n].cend(), 0,
                                 acc);

                auto r_f = accumulate(nb_fail[name].cbegin(),
                                 nb_fail[name].cend(), 0,
                                 acc);
                if(l_f < r_f) {
                    name = n;
                }
                else if (l_f == r_f) {
                    name = "KO";
                }
            }
        }
    }

    cout << name << "\n";

    return 0;
}
