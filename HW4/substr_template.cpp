//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <stdlib.h>
//
//using namespace std;
//vector<int> getBorders(string input, int subst_size)
//{
//	int length = input.length();
////    vector<int> borders(length);
//	int* borders = new int[length];
//	borders[0] = 0;
//
//	vector<int> indices;
//	for(int i = 1; i < length; ++i)
//	{
//		int j = borders[i-1];
//		while (j > 0 && input[i] != input[j])
//			j = borders[j-1];
//		if (input[i] == input[j])
//			++j;
//		borders[i] = j;
//		if(j == subst_size)
//			indices.push_back(i - 2 * subst_size);
//	}
//
//
//	delete[] borders;
//	return indices;
//}
//
//vector<int> getSubstrings(string t, string p)
//{
//	return getBorders(p + '$' + t, p.length());
//}
//
//int main()
//{
//	string t;
//	string p;
//	vector<int> res;
//
//	ifstream fin;
//	fin.open("input.txt");
//	if (fin.is_open())
//	{
//		getline(fin, t);
//		getline(fin, p);
//		fin.close();
//	}
//
//	res = getSubstrings(t, p);
//
//	fstream fout;
//	fout.open("output.txt", ios::out);
//	fout << res.size() << "\n";
//	for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
//		fout << *i << "\n";
//	fout.close();
//
//	return 0;
//}