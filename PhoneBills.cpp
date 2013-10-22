#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

double toll[24];

vector<string> split(const string &str,const char sp=' '){
  vector<string> sv;
  istringstream ss(str);
  string st;
  while( getline(ss,st,sp) ){
	sv.push_back(st);
  }
  return sv;
}

int num(const string s){
  return (s[0]-'0')*10+(s[1]-'0');
}

void time(const string s,int t[3]){
  const int d1 = num(s.substr(0,2));
  const int h1 = num(s.substr(3,2));
  const int m1 = num(s.substr(6,2));
  t[0] = d1;
  t[1] = h1;
  t[2] = m1;
}

int diff(const string &s1, const string &s2){

  int t1[3],t2[3];
  time(s2,t1);
  time(s1,t2);
  return (t1[0]-t2[0])*24*60+(t1[1]-t2[1])*60+(t1[2]-t2[2]);
}

double pay(const string &s1, const string &s2){
  
  int t1[3],t2[3],t[3];
  time(s1,t1);
  time(s2,t2);
  double p = 0;
  const int T1 = t1[0]*24*60+t1[1]*60 + t1[2];
  const int T2 = t2[0]*24*60+t2[1]*60 + t2[2];
  int m = T1;
  if(t2[0] > t1[0] || t2[1] > t1[1]){
	p += double(toll[(m/60)%24]*(60.0f-m%60))/60.f;
	m += 60-T1%60;
	for (;m<=T2-60;m+=60){
	  p += toll[(m/60)%24];
	}
	p += double(toll[(T2/60)%24])*((T2-m)%60)/60.f;
  }else{
	p = toll[t1[1]]*(t2[2]-t1[2])/60.f;
  }
  return p;
}

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  for (int i = 0; i < 24; ++i){
    cin >> toll[i];
	toll[i] = toll[i]*60.0f/100.0f;
  }
  int N;
  cin >> N;
  string tempt;
  getline(cin,tempt);
  vector<string> bills(N);
  for (int i = 0; i < N; ++i)
	getline(cin,bills[i]);
  sort(bills.begin(),bills.end());
  vector<string> r1 = split(bills[0]);
  string name = r1[0];
  string month = split(r1[1],':')[0];
  cout << name<< " " << month << endl;
  float total = 0.0f;
  for (int i = 1; i < N; ++i){
	
	const vector<string> r2 = split(bills[i]);
	if(r2[0] != name){
	  printf("Total amount: $%.2f\n",total);
	  cout << r2[0]<< " " << month << endl;
	  r1 = r2;
	  name = r2[0];
	  total = 0.0f;
	  continue;
	}else if(r1[2] == string("off-line")){
	  r1 = r2;
	  continue;
	}else if(r2[2] == string("off-line")){
	  cout<<r1[1].substr(3,8) << " ";
	  cout<<r2[1].substr(3,8)<<" ";
	  cout<<diff(r1[1].substr(3,8),r2[1].substr(3,8)) << " ";
	  const float p=pay(r1[1].substr(3,8),r2[1].substr(3,8));
	  total += p;
	  printf("$%.2f\n",p);
	}
	r1 = r2;
  }
  printf("Total amount: $%.2f\n",total);
  return 0;
}
