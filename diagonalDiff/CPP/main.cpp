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

int diagonalDifference(vector<vector<int>> a) {
    long sum_d1 = 0 , sum_d2 =0;
    int size = a[0].size();

    for (int k = 0 ; k < a.size() ; ++k)
    {
        sum_d1 += a[k][k];
        sum_d2 += a[k][size - k - 1];
    }
    
    return labs(sum_d1 - sum_d2);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(n);

        for (int a_column_itr = 0; a_column_itr < n; a_column_itr++) {
            cin >> a[a_row_itr][a_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    cout << result << "\n";

    return 0;
}