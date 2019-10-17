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

#include "exercise.hpp"

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

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

void ContestExerciseImpl::main() {
    int my_g = 1, my_l = 0, h_g = 0 , h_l = 0;
    cin >> my_g >> my_l >> h_g >> h_l;

    if(h_g > my_g) {
            int t = h_g;
            while(t % my_l) {
                if(t == 36) {
                    t = 0;
                } else {
                    t += h_l;
                }
            }
            cout << t << "\n";
    }
    else if(my_g > h_g) {
            int t = my_g;
            while(t % h_l) {
                if(t == 36) {
                    t = 0;
                } else {
                    t += my_l;
                }
            }
            cout << t << "\n";
    }
}
