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
    //cout << "N: " << N << " X: " << X << "\n";

    int B = 0, E = 0;
    int dir_b = 0, dir_e =0;
    int change_b = 0, change_e = 0;
    cin >> B >> E;
    wl(--N) {
        int new_b = 0, new_e = 0, new_dir_b = 0, new_dir_e = 0;

        cin >> new_b >> new_e;

        new_dir_b = new_b < B ? -1 : (int)(new_b > B);
        new_dir_e = new_e < E ? -1 : (int)(new_e > E);

        if(new_dir_b && new_dir_b == -dir_b) {
            ++change_b;
        }
        if(new_dir_e && new_dir_e == -dir_e) {
            ++change_e;
        }

        B = new_b;
        E = new_e;
        dir_b = new_dir_b ?  new_dir_b : dir_b;
        dir_e = new_dir_e ? new_dir_e : dir_e;
    }

    if(change_b > change_e) {
        cout << "ETHEREUM\n";
    }
    else if(change_e > change_b) {
        cout << "BITCOIN\n";
    }
    else {
        cout << "KO\n";
    }

    return 0;
}
