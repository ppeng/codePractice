#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <sstream>
#include <hash_map>
#include<unordered_map>
#include<time.h>
#include <cstdio>
#include<algorithm>
#include<iomanip>//输出格式控制

using namespace std;
//int main(){
//	int num;
//	cin >> num;
//	vector<long long>nums;
//	for (int i = 0; i < num; i++){
//		nums.push_back(num);
//	}
//
//}


/*int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>>guanxi;
	vector<int>help;
	int a, b;
	map<int, int>nan;
	map<int, int>nv;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		help.push_back(a);
		help.push_back(b);
		
		guanxi.push_back(help);
		help.clear();
	}
	for (int i = 0; i < m; i++){
		nan[guanxi[i][0]]++;
		nv[guanxi[i][1]]++;
	}
	int resNum = 0;
	vector<int>result;
	for (int i = 0; i <=n; i++){
		if (nan[i] > 1){
			resNum++;
			result.push_back(i );
		}
		if (nan[i] == 1){
			resNum++;
			result.push_back(i );

		}
	}
		for (int i = n; i <=2*n; i++){
			if (nv[i] > 1){
				resNum++;
				result.push_back(i );
			}

		}

		cout << resNum << endl;
		int length = result.size();
		for (int i = 0; i < length; i++)
			cout << result[i] << " ";


}*/

//字符回退
//int main()
//{
//	string strs;
//	string str;
//	cin >> str;
//	int length3 = str.size();
//	if (length3 < 3)
//		cout << "" << endl;
//	size_t firPos = 0;
//	size_t secPos = 0;
//	secPos = str.find(";");
//	string huitui;
//	huitui = str.substr(firPos, secPos - firPos);
//	strs=str.substr(secPos + 1, -1);
//	string::iterator itr = strs.begin();
//	int i = 0;
//	while (strs.find(huitui[0]) != -1){
//		int length = strs.size();
//		vector<int>help;
//		
//
//		if (strs[i] != huitui[0] && strs[i + 1] == huitui[0]){
//			
//			strs.erase(itr + i);
//			strs.erase(itr + i + 1);
//			i = 0;
//
//		}
//		else if (strs[i] == huitui[0]){
//			help.push_back(i);
//			strs.erase(itr + i);
//			i = 0;
//
//		}
//		else
//		i++;
//
//	}
//	cout << strs << endl;
//}
		
			

//int main(){
//	string str;
//	cin >> str;
//	map<char, int>help;
//	int length = str.length();
//	for (int i = 0; i < length; i++){
//		help[str[i]]++;
//	}
//	vector<pair<char, int>>vec(help.begin(), help.end());
//	sort(vec.begin(), vec.end());
//
//	int length2 = vec.size();
//	for (int i = 0; i < vec.size(); i++){
//		if (i == length2 - 1)
//			cout << vec[i].first << ":" << vec[i].second;
//		else
//			cout << vec[i].first << ":" << vec[i].second << ",";
//	}
//
//}



//int main()
//{
//	vector<string>strs;
//	string str;
//	cin >> str;
//
//	size_t firPos = 0;
//	size_t secPos = 0;
//	secPos = str.find(",");
//	string yuan;
//	string mubiao;
//	yuan = str.substr(firPos, secPos );
//	mubiao = str.substr(secPos+1,-1);
//	int length1 = yuan.size();
//	int length2 = mubiao.size();
//	cout << abs(length1 - length2) << endl;
//}


//int main(){
//	int a[10] = { 1, 2, 3, 3, 5, 0, 0, 7, 6, 88 };
//	sort(a, a + 10);
//	int n=unique(a, a + 10)-a;
//	for (int i = 0; i < n; i++)
//		cout << a[i] << endl;
//
//}
	
		
	
