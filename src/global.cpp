using namespace std;
#include<string>

#include "./../lib/global.hh"

int yyyymmdd;
int power(int n, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp & 1)
            res *= n, exp--;
        else
            n *= n, exp >>= 1;
    }
    return res;
}
int strToNum(string s) {
    int res = 0;
    int sign = 1;
    int startIdx = 0;

    if (s[0] == '-') {
        sign = -1;
        startIdx = 1;
    }

    for (int i = startIdx; i < s.size(); i++) {
        res = res * 10 + (s[i] - '0');
    }

    return sign * res;
}