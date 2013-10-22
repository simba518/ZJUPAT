#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

int getNum(const string s){
  return atoi(s.c_str());
}

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  string N;
  while(cin >> N){
	int c = 0;
	for (int i = 0; i < N.size(); ++i){
	  int a = N[i]-'0';
	  const int lenX = i;
	  const int lenY = N.size()-lenX-1;
	  const int X = getNum(N.substr(0,lenX));
	  const int Y = getNum(N.substr(i+1,lenY));
	  c += X*pow(10,lenY);
	  if (a > 1){
		c += pow(10,lenY);
	  }else if(a == 1){
		c += (Y+1);
	  }
	}
	cout << c << endl;
  }
  return 0;
}
