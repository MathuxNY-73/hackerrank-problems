#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
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

using namespace std;

struct Astro {
    int id;
    Astro* p;
    int rank;

    ~Astro() {
        p = NULL;
    }
};

void setUnion(Astro& x, Astro& y) {
    if(x.rank > y.rank)
    {
        y.p = &x;
    }
    else
    {
        x.p = &y;
        if(x.rank == y.rank)
        {
            ++(y.rank);
        }
    }
}

Astro* findSet(Astro* x) {
    if(x->p != x)
    {
        x->p = findSet(x->p);
    }
    return x->p;

}

int main() {

    int n = 0, p = 0;
    cin >> n >> p;

    map<int, Astro*> astros;
    vector<int> counts(n);

    for(auto i = 0 ; i < n ; ++i)
    {
        Astro* a = new Astro();
        a->id = i;
        a->rank = 0;
        a->p = a;
        astros.insert(make_pair(i, a));
        counts[i] = 0;
    }

    for (auto i = 0; i < p ; ++i)
    {
        int r,l;
        cin >> r >> l;
        setUnion(*findSet(astros[r]), *findSet(astros[l]));
    }

    for(auto it = astros.cbegin(); it != astros.cend() ; ++it)
    {
        ++counts[findSet(it->second)->id];
    }

    unsigned long res = 0;
    for(auto it = counts.cbegin() ; it != counts.cend() ; ++it)
    {
        res += *it * (n - *it);
    }

    cout << res/2 << endl;

    for(auto it = astros.cbegin() ; it != astros.cend() ; ++it)
    {
        delete it->second;
    }

    astros.clear();
    return 0;
}