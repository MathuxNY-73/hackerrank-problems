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
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

#define BUF_SIZE 20
#define INF 9999999

using namespace std;

inline char fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;

    return c;
}

inline int fastscan_string(array<char, BUF_SIZE> &str) {
    int c = 0, cnt = 0;
    c = getchar_unlocked();

    for(; c != (int)' ' &&
          c != '\n' &&
          c != '\0' &&
          c != EOF &&
          cnt < BUF_SIZE; c = getchar_unlocked(), ++cnt) {
        str[cnt] = (char)c;
    }

    str[cnt] = '\0';

    return cnt;
}

// This solution works on sample test case. However due to hackerrank non editable code. I had to provide another solution.
class Matrix {
private:
    vector<vector<int>> matrix;
    int n, m;

    class Proxy {
        friend class Matrix;

        const vector<int>& v;

        Proxy(const vector<int>& v): v(v) {}
    public:
        int operator[](int i) const {return v[i];}
    };

public:
    Matrix(const vector<vector<int>>& mat, int n, int m): matrix(mat), n(n), m(m) {}
    ~Matrix() {}

    Matrix& operator+=(const Matrix& other) {
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m; ++j)
            {
               matrix[i][j] += other[i][j];
            }
        }
        return *this;
    }

    void print() const {
        for(int i = 0; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    static Matrix read_matrix_from_stdin(int n, int m) {
        auto mat = vector<vector<int>>(n);

        for(int i = 0 ; i < n ; ++i)
        {
            mat[i] = vector<int>(m);
            for(int j = 0 ; j < m ; ++j)
            {
                fastscan(mat[i][j]);
            }
        }

        return Matrix(mat, n, m);
    }

    Proxy operator[](int i) const {return matrix[i];}
};

class Solution {
private:
public:
    void solve() {
        int t = 0;
        fastscan(t);

        wl(t)
        {
            int n=0, m=0;
            fastscan(n);
            fastscan(m);

            auto a = Matrix::read_matrix_from_stdin(n,m);
            auto b = Matrix::read_matrix_from_stdin(n,m);

            a+=b;

            a.print();
        }
    }
};

int main()
{
    auto sol = Solution();
    sol.solve();
    return 0;
}
