#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 30;

//    pair<int, int> res[n];
//    res[0] = make_pair(0, 0);
//    for (int i = 1; i < n; ++i)
//        res[i] = make_pair(0, n);
//
//    for (int j = 0; j < ; ++j)
//    {
//
//    }

//    int prev[n + 1];
    vector<int> prev(n + 1);
    for (int j = 0; j < n + 1; ++j)
        prev[j] = 0;

    for (int i = 1; i <= n; ++i)
    {

    }

    int start = n;
    string res = "";
    if(prev[n] == 0)
        return 0;

    while(start != 1){
        res = (char)(prev[start] - '0') + res;
        start = prev[start];
    }

    cout<<res<<endl;

    return 0;
}