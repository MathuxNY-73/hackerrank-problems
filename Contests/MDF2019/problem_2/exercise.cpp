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

void ContestExerciseImpl::main() {
    string msg = "\0";
    string txt = "";
    int l = 0;
    getline(cin, msg);
    msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());
    for(auto& c: msg) {
        printf("%c: %d ", c, c);
    }
    cout << "\n";
    cerr << msg << "\n";
    cin >> l;
    cin.ignore();
    while(l--) {
        cout << l << "\n";
        string line = "\0";
        getline(cin, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        cout << line << "\n";
        txt.append(line);
    }

    int i = 0;
    for(auto& c: txt) {
        cerr << i << "\n";
        if(i >= msg.size()) {
            break;
        }
        if(c == msg[i]) {
            cerr << "OK \n";
            ++i;
        }
    }
    cerr << "\n";
    if(i >= msg.size()) {
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}
