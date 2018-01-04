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
#include <functional>

using namespace std;

vector<int> giveCandies(vector<int>);
void writeCandies(vector<int>);
vector<int> initArray(int);
int getTrend(int, int);

int main() {

    int n = 0;
    cin >> n;

    vector<int > ratings(n);

    for(int i = 0; i < n ; ++i)
    {
        cin >> ratings[i];
    }

    vector<int> candies = giveCandies(ratings);
    //writeCandies(candies);

    long long res = 0;
    vector<int>::const_iterator it = candies.cbegin();
    while(it != candies.cend())
    {
        res += *it;
        ++it;
    }

    cout << res << endl;

    return 0;
}

int init(int trend, int a, int b)
{
    return trend == 1 ? b : a;
}

bool stopCond(int trend, int t, int a, int b)
{
    return trend == 1 ? t >= a : t <= b;
}

void next(int trend, int& k)
{
    if(trend == 1)
    {
        --k;
    }
    else
    {
        ++k;
    }
}

vector<int> giveCandies(vector<int> ratings)
{
    vector<int> res = initArray(ratings.size());
    for(int i = 0; i < ratings.size() - 1 ; ++i)
    {
        int j = i;
        vector<int> subRat;
        int trend = getTrend(ratings[i], ratings[i+1]);
        for(; j < ratings.size(); ++j)
        {
            subRat.push_back(ratings[j]);
            if(j == ratings.size() || getTrend(ratings[j], ratings[j + 1]) != trend) {
                break;
            }
        }

        int maxCandy = trend == 2 ? 1: subRat.size();

        for(int k = init(trend, i, j) ; stopCond(trend, k, i, j); next(trend, k))
        {
            if(maxCandy > res[k])
            {
                res[k] = maxCandy;
            }
            if (trend != 2)
            {
                --maxCandy;
            }
        }

        i = j - 1;
    }
    return res;
}

int getTrend(int l, int r)
{
    return (l < r) * 1 + (l == r) * 2 + (l > r) * 3;
}

vector<int> initArray(int size)
{
    vector<int > res(size);
    for(int i = 0; i < size; ++i)
    {
        res[i] = 0;
    }
    return res;
}

void writeCandies(vector<int> candies)
{
    for(int i; i < candies.size(); ++i)
    {
        cout << candies[i] << " ";
    }
    cout << endl;
}