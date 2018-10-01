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
    int p = 0, n=0;

    cin >> p;
    cin >> n;

    long double res = 0;
    for(auto i = 0 ; i < n ; ++i) {
        int nb_pers = 0;

        cin >> nb_pers;

        double sub = nb_pers * p;

        if(nb_pers >= 10)
        {
            sub = sub * 0.7;
        }
        else if(nb_pers >= 6) {
            sub = sub * 0.8;
        }
        else if(nb_pers >= 4) {
            sub = sub * 0.9;
        }
        res += sub;
    }

    cout << ceil(res) << endl;
}
