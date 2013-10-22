#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <map>
using namespace std;

// 有重复时注意排名顺序。 1 2 3 3 5   不是 1 2 3 3 4 
int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  const char dic[4]={'A','C','M','E'};
  int N,M,s;
  while(!(cin>>N).eof()){

	cin >> M;
	multimap<float,int> gs[4];
	for (int i = 0; i < N; ++i){
	  float cmea[4];
	  cin >> s >> cmea[1] >> cmea[2] >> cmea[3];
	  cmea[0] = (cmea[1]+cmea[2]+cmea[3])/3;
	  for (int j = 0; j < 4; ++j)
		gs[j].insert(make_pair(cmea[j],s));
	}

	map<int,int>sg[4];
	for (int j = 0; j < 4; ++j){
	  int rank = 0;
	  int step = 1;
	  float lastGrad = -1.0f;
	  multimap<float,int>::reverse_iterator it;
	  for (it=gs[j].rbegin();it != gs[j].rend(); ++it){
		if(lastGrad !=it->first ){
		  rank += step;
		  step = 0;
		}
		step ++;
		sg[j][it->second] = rank;
		lastGrad = it->first;
	  }
	  assert(sg[j].size()==N);
	}

	for (int i = 0; i < M; ++i){
	  int si;
	  cin >> si;
	  if(sg[0].find(si) == sg[0].end()){
		cout << "N/A" << endl;
		continue;
	  }
	  int p=0,t=N+1;
	  for(int j = 0; j < 4; ++j){
		map<int,int>::const_iterator it = sg[j].find(si);
		assert(it!=sg[j].end());
		if(it->second<t){
		  p = j;
		  t = it->second;
		}
	  }
	  assert(t>=1);
	  assert(t<=N);
	  cout << t << " " << dic[p] << endl;
	}
  }
  return 0;
}
