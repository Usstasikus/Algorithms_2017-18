////
//// Created by Stas Don on 02/03/2018.
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
//
//int LevenshteinDistance(string s, int len_s, string t, int len_t)
//{
//    int cost = 0;
//    if(len_s == 0 || len_t == 0)
//        return abs(len_s - len_t);
//    if(s[len_s - 1] != t[len_t - 1])
//        cost = 1;
//    return min(LevenshteinDistance(s, len_s - 1, t, len_t - 1) + cost,
//               min(LevenshteinDistance(s, len_s, t, len_t - 1) + 1, LevenshteinDistance(s, len_s - 1, t, len_t) + 1));
//}
//
//int main()
//{
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
//            fout << LevenshteinDistance(s,s.length(), t, t.length()) << (i == n-1 ? "" : " ");
//        }
//        fout.close();
//        fin.close();
//    }
//    return 0;
//}
