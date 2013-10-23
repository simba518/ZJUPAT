#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long LINT;

typedef struct onetask{
  string t;
  int p;
  bool operator < (const struct onetask&tt)const{
	return this->t < tt.t;
  }
  static LINT num(const string &s){
	assert(s.size()==2);
	return (s[0]-'0')*10+s[1]-'0';
  }
  static LINT seconds(const string &tt){
	const LINT h = num(tt.substr(0,2));
	const LINT m = num(tt.substr(3,2));
	const LINT s = num(tt.substr(6,2));
	return h*60*60 + m*60 + s;
  }
  LINT seconds()const{
	return seconds(t);
  }
}task;

int nextWindow(const vector<LINT> &w){
  int p = 0;
  LINT min = 1e18;
  for (int i = 0; i < w.size(); ++i){
    if(w[i] < min){
	  min = w[i];
	  p = i;
	}
  }
  return p;
}

int main(int argc, char *argv[]){
  
  freopen("in.txt","r",stdin);
  const string beginstr = string("08:00:00");
  const string endstr = string("17:00:00");
  const LINT begin = task::seconds(beginstr);
  const LINT end = task::seconds(endstr);
  int N,W;
  cin >> N >> W;
  vector<LINT> windows(W,begin);
  string time;
  int P;
  vector<task> tasks(N);
  for (int i = 0; i < N; ++i){
	cin >> tasks[i].t >> tasks[i].p;
  }
  sort(tasks.begin(),tasks.end());
  int count = 0;
  double average = 0;  
  for (int i = 0; i < N; ++i){
	if(tasks[i].t > endstr){
	  continue;
	}
	if(tasks[i].t < beginstr){
	  average += (begin-tasks[i].seconds());
	  tasks[i].t = beginstr;
	}
	count ++;
	const int wi = nextWindow(windows);
	if(windows[wi] > tasks[i].seconds()){
	  average += (windows[wi]-tasks[i].seconds());
	}else{
	  windows[wi] = tasks[i].seconds();
	}
	windows[wi] += (tasks[i].p>60? 60*60:tasks[i].p*60);
  }
  average /= 60.0f;
  if(count > 0)
	average = average/(double)count;
  printf("%0.1f\n",average);
  return 0;
}
