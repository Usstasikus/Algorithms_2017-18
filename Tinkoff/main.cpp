#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

//1
//int main() {
//    int M, K;
//    cin >> K >> M;
//    cout << (K == M ? 0 : K + M - 1);
//    return 0;
//}

//2
//int main() {
//    string phrase;
//    getline(cin, phrase);
//    int f_ind = -1, l_ind = -1;
//    for (int i = 0; i < phrase.size(); ++i) {
//        if (f_ind == -1 && phrase[i] == '@')
//            f_ind = i;
//        if(phrase[i] == '@')
//            l_ind = i;
//    }
//    std::reverse(phrase.begin() + f_ind, phrase.begin() + l_ind + 1);
//    cout << phrase;
//    return 0;
//}


//3

int countMetrics3(const vector<int> &array, const vector<int> &metrics, int pos)
{
    return metrics[pos - 3] + (array[pos] - array[pos - 1] + array[pos - 1] - array[pos - 2]);
}
int countMetrics2(const vector<int> &array, const vector<int> &metrics, int pos)
{
    return metrics[pos - 2] + (array[pos] - array[pos - 1]);
}


//int main()
//{
//    int n;
//    cin >> n;
//    int analytics[n], dynamic_array[n];
//
//    for (int i = 0; i < n; ++i)
//        cin >> analytics[i];
//
//    std::sort(analytics, analytics + n);
//
//
//    dynamic_array[0] = 0;
//    dynamic_array[1] = analytics[1] - analytics[0];
//    if(n > 2)
//    {
//        dynamic_array[2] = analytics[1] - analytics[0] + analytics[2] - analytics[1];
//        if(n > 3)
//        {
//            dynamic_array[3] = analytics[1] - analytics[0] + analytics[3] - analytics[2];
//            for (int i = 4; i < n; ++i)
//            {
//                int first = dynamic_array[i - 3] + (analytics[i - 1] - analytics[i - 2] + analytics[i] - analytics[i - 1]);
//                int sec = dynamic_array[i - 2] + (analytics[i] - analytics[i - 1]);
//                if(first > sec)
//                    dynamic_array[i] = sec;
//                else
//                    dynamic_array[i]= first;
//            }
//        }
//    }
//
//    cout << dynamic_array[n - 1];
//    return 0;
//}
//
//const int MAXN = 1e3;
const int INF = 1e9;

//
int main() {
    int n;

    cin >> n;

    vector<int> a(n);
    vector<vector<int>> d(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    d[0][0] = 0;
    d[0][1] = INF;
    for (int i = 1; i < n; ++i) {
        d[i][0] = d[i - 1][1];
        d[i][1] = min(d[i - 1][0], d[i - 1][1]) + (a[i] - a[i - 1]);
    }
    cout << d[n - 1][1] << endl;
    cin >> n;
    return 0;
}

//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> array(n);
//    for (int i = 0; i < n; ++i)
//        cin >> array[i];
//
//    std::sort(array.begin(), array.end());
//
//    vector<int> metrics;
//
//    metrics.emplace_back(0);
//    metrics.emplace_back(array[1] - array[0]);
//    if(n > 2)
//    {
//        metrics.emplace_back(array[2] - array[1] + array[1] - array[0]);
//        if(n > 3){
//            metrics.emplace_back(array[3] - array[2] + array[1] - array[0]);
//            for (int i = 4; i < n; ++i)
//                metrics.emplace_back(min(countMetrics3(array, metrics, i), countMetrics2(array, metrics, i)));
//        }
//    }
//    cout << metrics[metrics.size() - 1];
//    return 0;
//}


// => 28
//11
//1 3 23 24 26 27 28 122 144 145 146

// => 5
//8
//1 2 3 5 80 81 90 91

// => 17
//9
//1 3 4 5 25 35 38 44 45

// => 21
//15
//1 3 4 5 6 7 13 14 16 42 43 44 56 72 73

//4
//const long double espilon = 1e-5;
//
//int check(const vector<long double> &t, long double x) {
//    long double minimum = t[0] + x, maximum = minimum + 1;
//    for (int i = 1; i < t.size(); ++i)
//    {
//        if (t[i] > maximum)
//            return -1;
//        if (t[i] + 1 < minimum)
//            return 1;
//        minimum = max(t[i], minimum) + x;
//        maximum = min(t[i] + 1, maximum) + x;
//    }
//    return 0;
//}
//
//long double minBinSearch(const vector<long double> &t)
//{
//    long double l = 0, r = t[t.size() - 1] + 1;
//    while (r - l > espilon)
//    {
//        long double m = (l + r) / 2;
//        if (check(t, m) < 0)
//            l = m;
//        else
//            r = m;
//    }
//    return r;
//}
//
//long double maxBinSearch(const vector<long double> &t)
//{
//    long double l = 0, r = t[t.size() - 1] + 1;
//    while (r - l > espilon)
//    {
//        long double m = (l + r) / 2;
//        if (check(t, m) <= 0)
//            l = m;
//        else
//            r = m;
//    }
//    return l;
//}
//
//int main()
//{
//    int n;
//    vector<long double> time;
//    long double temp;
//    cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> temp;
//        time.emplace_back(temp);
//    }
//    long double minTime = minBinSearch(time), maxTime = maxBinSearch(time);
//    if (check(time, minTime) != 0 || check(time, maxTime) != 0)
//        cout << "kukuha" << endl;
//    else {
//        cout << std::setprecision(3) << fixed;
//        cout << minTime << ' ' << maxTime << endl;
//    }
//    return 0;
//}


//6
//int main() {
//    double x, y;
//    cin >> x >> y;
//
//    cout << (((y < 0.5 * abs(x) + 0.5) && (1 / 2. * x * x + y * y < 1) && ((x - 0.5) * (x - 0.5) + y * y > 0.3) &&
//             ((x + 0.5) * (x + 0.5) + y * y > 0.3)) ? "YES" : "NO");
//}
//



//5

//vector<int> mt;
//vector<char> used;
//
//bool areMoreChains(const vector<vector<int>> &g, int v) {
//    if (used[v])
//        return false;
//    used[v] = true;
//    for (int i = 0; i < g[v].size(); ++i)
//    {
//        int to = g[v][i];
//        if (mt[to] == -1 || areMoreChains(g, mt[to]))
//        {
//            mt[to] = v;
//            return true;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    vector < vector<int> > g(m);
//
//    int temp;
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j)
//        {
//            cin >> temp;
//            if(temp)
//                g[i].emplace_back(j);
//        }
//    }
//
//    mt = vector<int>(m, -1);
//    for (int v=0; v<n; ++v) {
//        used.assign (n, false);
//        areMoreChains(g, v);
//    }
//
//    int count = 0;
//    for(int p: mt)
//        if (p != -1)
//            ++count;
//    cout << count;
//}


// => 3
//3 5
//1 0 1
//1 0 0
//1 1 0
//1 0 0
//0 0 0

// => 2
//3 5
//1 1 1
//0 0 1
//0 0 1
//0 0 1
//0 0 1

//7
//#include <map>
//
//struct Worker{
//    int level;
//    string boss;
//    Worker(){};
//    Worker(string boss, int level):level(level), boss(boss){}
//};
//
//int getLevel(string worker, map<string, Worker> &stuff)
//{
//    if(stuff[worker].level < 0)
//        stuff[worker].level = getLevel(stuff[worker].boss, stuff) + 1;
//
//    return stuff[worker].level;
//
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    string worker, boss;
//    map<string, Worker> stuff;
//    stuff["X"] = Worker("", 0);
//    for (int i = 0; i < n - 1; ++i)
//    {
//        cin >> worker;
//        cin >> boss;
//        stuff[worker] = Worker(boss, -1);
//    }
//    for (auto it=stuff.begin(); it!=stuff.end(); ++it)
//        std::cout << it->first << " " << getLevel(it->first, stuff) << '\n';
//}