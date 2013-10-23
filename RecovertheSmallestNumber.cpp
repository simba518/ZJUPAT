#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string warp(const string &num){

  assert(num.size() <= 9);
  string temp = num;
  for (int i = num.size(); i < 8; ++i){
	const int k = i%num.size();
    temp.push_back(num[k]);
  }
  return temp;
}

string removeHeadZero(const string &num){
  
  string temp;
  temp.reserve(num.size());
  for (int i = 0; i < num.size(); ++i){
	if(num[i] != '0'){
	  for (int j = i; j < num.size(); ++j)
		temp.push_back(num[j]);
	  break;
	}
  }
  return temp;
}

string obtainRealNum(const string &num){

  assert(num.size()==9);
  const int len = num[8] - '0';
  assert(len < 9);
  assert(len >= 0);
  string temp;
  temp.reserve(len);
  for (int i = 0; i < len; ++i){
	temp.push_back(num[i]);
  }
  return temp;
}

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int N;
  while(cin >> N){

	vector<string> num(N);
	for (int i = 0; i < N; ++i){
	  string s;
	  cin >> s;
	  num[i] = warp(s);
	  num[i].push_back(s.size()+'0');
	}
	sort(num.begin(), num.end());
	string smallestNum;
	for (int i = 0; i < N; ++i){
	  smallestNum += obtainRealNum(num[i]);
	}
	smallestNum = removeHeadZero(smallestNum);
	if (smallestNum.size() == 0)
	  smallestNum = "0";
	cout<< smallestNum << endl;
  }
  return 0;
}
