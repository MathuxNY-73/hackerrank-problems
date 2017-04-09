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

vector<unordered_set<int> > addElementToCountry(vector<unordered_set<int> >, int, int);
bool countryContains(unordered_set<int>, int);
unordered_set<int> mergeSets(unordered_set<int>, unordered_set<int>);
long long getNumberOfCombination(vector<unordered_set<int> >);
void printTheMap(vector<unordered_set<int> >);

int main() {

    int n = 0, I = 0;
    cin >> n >> I;

    vector<unordered_set<int> > countries(n);

    for(int i = 0; i < n ; ++i)
    {
        unordered_set<int> country;
        country.insert(i);
        countries[i] = country;
    }

        printTheMap(countries);

    for (int i = 0 ; i < I ; ++i) {
        int a, b;

        cin >> a >> b;

        countries = addElementToCountry(countries, a, b);
        printTheMap(countries);
    }

    long long result = getNumberOfCombination(countries);

    cout << result << endl;
    return 0;
}

vector<unordered_set<int> > addElementToCountry(vector<unordered_set<int> > countries, int a, int b){
    vector<unordered_set<int> > result;
    vector<unordered_set<int> >::const_iterator iterA, iterB, iter = countries.cbegin();

    while(iter != countries.end())
    {
       if(countryContains(*iter, a))
            iterA = iter;
       if(countryContains(*iter, b))
           iterB = iter;
        ++iter;
    }

    unordered_set<int> set = mergeSets(*iterA, *iterB);
    iter = countries.cbegin();
    while(iter != countries.end())
    {
        if(iter != iterA && iter != iterB)
        {
            result.push_back(*iter);
        }
        ++iter;
    }
    result.push_back(set);
    return result;
}

unordered_set<int> mergeSets(unordered_set<int> a, unordered_set<int> b)
{
    unordered_set<int> result(a.size() +  b.size());
    unordered_set<int>::const_iterator iterA = a.cbegin(), iterB = b.cbegin();
    while(iterA != a.cend())
    {
        result.insert(*iterA);
        ++iterA;
    }
    while(iterB != b.cend())
    {
        result.insert(*iterB);
        ++iterB;
    }
    return result;
}

bool countryContains(unordered_set<int> country, int item) 
{
    unordered_set<int>::const_iterator got = country.find(item);
    if(got != country.cend())
        return true;
    return false;
}

long long getNumberOfCombination(vector<unordered_set<int> > countries)
{
    vector<unordered_set<int> >::const_iterator iter1 = countries.cbegin();
    long long result = 0;

    while(iter1 != countries.cend())
    {
        vector<unordered_set<int> >::const_iterator iter2 = iter1 + 1;
        while(iter2 != countries.cend())
        {
            result += iter1->size() * iter2->size();
            ++iter2;
        }
        ++iter1;
    }
    return result;
}

void printTheMap(vector<unordered_set<int> > countries) 
{
    for(unordered_set<int> country: countries)
    {
        unordered_set<int>::const_iterator iter = country.cbegin();
        while(iter != country.end())
        {
            cout << *iter << " ";
            ++iter;
        }
        cout << endl;
    }
}
