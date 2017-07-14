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

#define INF 9999999999

using namespace std;

vector<int> readVector(int);
int solve(vector<int>, int);

int main() {

    int N = 0, K = 0;

    cin >> N;
    cin >> K;

    vector<int> intArray = readVector(N);
    cout << solve(intArray, K) << endl;
}

vector<int> readVector(int N) {
    vector<int> res(N);

    for(int i = 0; i < N; ++i)
    {
        int l;
        cin >> l;
        res[i] = l;
    }

    return res;
}

int solve(vector<int> intArray, int k)
{
    std::sort(intArray.begin(), intArray.end());

    int i = 0, fairness = INF;

    while(!intArray.empty() && i+k <= intArray.size())
    {
        int currF = intArray[i+k-1] - intArray[i]; 
        if(currF < fairness)
            fairness = currF;
        ++i;
    }

    return fairness;
}
