////
//// Created by Stas Don on 04/03/2018.
////
//
//
//#include <iostream>
//#include <fstream>
//#include <stdlib.h>
//#include <vector>
//#include <string>
//using namespace std;
//
//int Wagner_Fischer(string s, string t)
//{
//    int costs[s.length() + 1][t.length() + 1];
//    for (int i = 0; i <= s.length(); ++i)
//        costs[i][0] = i;
//    for (int i = 0; i <= t.length(); ++i)
//        costs[0][i] = i;
//
//    for (int j = 1; j <= t.length(); ++j)
//    {
//        for (int i = 1; i <= s.length(); ++i)
//        {
//            if(s[i - 1] == t[j - 1])
//                costs[i][j] = costs[i - 1][j - 1];
//            else
//                costs[i][j] = min(costs[i - 1][j],
//                                  min(costs[i][j - 1], costs[i - 1][j - 1])) + 1;
//        }
//    }
//
//    return costs[s.length()][t.length()];
//}
//int main(int argc, const char * argv[]) {
//
//    int n;
//    fstream fin;
//    fstream fout;
//    fin.open("input.txt",ios::in);
//    fout.open("output.txt",ios::out);
//    if(fin.is_open()) {
//        string N;
//        getline(fin,N);
//        int n = atoi( N.c_str());
//        for (int i = 0; i < n; i++) {
//            string s;
//            string t;
//            getline(fin,s);
//            getline(fin,t);
//            fout << Wagner_Fischer(s, t) << (i == n-1 ? "" : " ");
//        }
//        fout.close();
//        fin.close();
//    }
//
//    return 0;
//}
