#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

string getStdFormat(const int N,const string inin,int &d){

  assert(inin.size() > 0);
  assert(N > 0);
  string in;
  bool useDot = false;
  for (int i = 0; i < inin.size(); ++i){
	if(inin[i] > '0'){
	  useDot = true;
	}else if( i+1 < inin.size() && inin[i+1] == '.'){
	  useDot = true;
	}
	if (useDot) in.push_back(inin[i]);
  }

  string out(N+6,'0');
  out[1] = '.';
  out[N+2] = '*';
  out[N+1+2] = '1';
  out[N+2+2] = '0';
  out[N+3+2] = '^';
  
  d = 0;
  if (in[0] > '0'){
	int i = 0, x = 1, j = 2;
	for (; i < in.size(); ++i){
	  if (in[i] == '.'){
		x = 0;
		continue;
	  }
	  if (j < N+2){
		out[j] = in[i];
		j++;
	  }
	  d += x;
	}
  }else{
	int i = 2, x = -1, j = 2;
	for (; i < in.size(); ++i){
	  if (in[i] > '0')
		x = 0;
	  if (x == 0 && j < N+2){
		out[j] = in[i];
		j++;
	  }
	  d += x;
	}
	if ( -1 == x)
	  d = 0;
  }
  return out;
}

int main(int argc, char *argv[]){
  
  freopen("in.txt","r",stdin);
  int N;
  while(cin >> N){
	string n1,n2;
	cin >> n1 >> n2;
	int d1,d2;
	const string fn1 = getStdFormat(N,n1,d1);
	const string fn2 = getStdFormat(N,n2,d2);
	if(d1 == d2 && fn1 == fn2){
	  cout << "YES "<< fn1 << d1 << endl;
	}else{
	  cout << "NO "<< fn1 << d1 << " " << fn2 << d2 << endl;
	}
  }
  return 0;
}
