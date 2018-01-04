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

int searchIndexPal(string w);

int main() {

    int n = 0;
    cin >> n;

    vector<string > words(n);

    for(int i = 0; i < n ; ++i)
    {
        string word;
        cin >> word;
        cout << searchIndexPal(word) << endl;
    }

    return 0;
}

int searchIndexPal(string w)
{
    int l = w.length();
    vector<char > letters(l);
    stringstream ssin(w);
    for(int i = 0;ssin.good() && i < l; ++i)
    {
        ssin >> letters[i];
    }

    int index = -1;
    for(int i = 0 ; i < ceil(l/2.0) - 1; ++i)
    {
        if(letters[i] != letters[l - 1 - i])
        {
            if(index != -1)
            {
                index = -1;
                break;
            }
            else if(letters[i + 1] == letters[l - 1 - i])
            {
                index = i;
                ++i;
            }
            else if(letters[i] == letters[l - 2 - i])
            {
                index = l - 1 - i;
            }
        }
    }

    return index;   
}