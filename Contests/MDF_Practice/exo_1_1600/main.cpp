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
    int N = 0, I = 0;
    cin >> N >> I;

    int bank = I, cnt = 0;

    cout << "bank: " << bank << "\n";

    while(N--) {
        int M = 0, R = 0;
        string Q = "\0";

        cin >> M >> Q >> R;

        cout << "M: " << M << " Q: " << Q << " R: " << R << "\n";

        bank -= M;

        if(Q == "P" && (!(R & 1) && R != 0)) {
            bank += 2*M;
        }
        else if (Q == "I" && (R&1)) {
            bank += 2*M;
        }
        else if(Q != "P" && Q != "I") {
            int q = stoi(Q);
            if(R == q) {
                bank += 36 * M;
            }
        }

        cout << bank << "\n";

        if(bank <= 0) {
            cout << "RACHAT\n";
            ++cnt;
            bank = I;
        }
    }

    cout << cnt << "\n";
    return 0;
}
