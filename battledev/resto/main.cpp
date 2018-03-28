#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <functional>

using namespace std;

int main() {
    int n = 0;

    cin >> n;

    int best = -99999;

    for(auto i = 0 ; i < n ; ++i) {
        int f=0, w=0, r=0;

        cin >> f >> w >> r;

        int res = ceil((f+r+w)/3.0);

        if (res > best) {
            best = res;
        }
    }

    cout << best << endl;
}
