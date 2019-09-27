cd #include <cassert>
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
   
    int size = 3 * N - 2;
    int empty = 2 * (N - 1) / 2;
   
    for(int i = 0 ; i < size ; ++i) {
        for(int j = 0 ; j < size; ++j) {
            if((i == 0 || i == size - 1) && (j >= empty && j < empty + N)) {
                cout << "X";
            }
            else if((i == empty || i == empty + N - 1) && ((j >= 0 && j < N) || (j >= (size - N) && j < size))) {
                cout << "X";
            }
            else if ((i >= empty && i < empty + N) && (j == 0 || j == size - 1)) {
                cout << "X";
            }
            else if((i < empty || i >= empty + N) && (j == empty || j == empty + N - 1)) {
                cout << "X"; 
            }
            else {
                cout << ".";
            }
        }
        cout << "\n";
    }

    return 0;
}
