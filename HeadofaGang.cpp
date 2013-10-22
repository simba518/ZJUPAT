#include <stdio.h>
#include <assert.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef vector<map<string, int> > vmap;
typedef map<string, int>::iterator mapit;

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int N,K;
  while(cin>>N>>K){

	vmap gs;
	vector<int> weights;
	for (int i = 0; i < N; ++i){

	  string n1,n2;
	  int p;
	  cin >> n1 >> n2 >> p;
	  int g1 = 0;
	  for (g1; g1 < gs.size(); ++g1){
		mapit it = gs[g1].find(n1);
		if(it != gs[g1].end()){
		  it->second += p;
		  weights[g1] += p;
		  break;
		}
	  }
	  
	  int g2 = 0;
	  for (g2; g2 < gs.size(); ++g2){
		mapit it = gs[g2].find(n2);
		if(it != gs[g2].end()){
		  it->second += p;
		  if (g1 >= gs.size())
			weights[g2] += p;
		  break;
		}
	  }

	  if (gs.size() <= g1){
		if (gs.size() <= g2){
		  map<string,int> m;
		  m[n1] = p;
		  m[n2] = p;
		  gs.push_back(m);
		  weights.push_back(p);
		}else{
		  gs[g2][n1] = p;
		}
	  }else{
		if (gs.size() <= g2){
		  gs[g1][n2] = p;
		}else if(g1 != g2){
		  if (gs[g1].size() < gs[g2].size()){
			gs[g2].insert(gs[g1].begin(),gs[g1].end());
			weights[g2] += weights[g1];
			gs.erase(gs.begin()+g1);
			weights.erase(weights.begin()+g1);
		  }else{
			gs[g1].insert(gs[g2].begin(),gs[g2].end());
			gs.erase(gs.begin()+g2);
			weights.erase(weights.begin()+g2);
		  }
		}
	  }
	}

	vector<pair<string,int> > head;
	for (int i = 0; i < gs.size(); ++i){

	  // cout << weights[i] << endl;
	  if(gs[i].size() > 2 && weights[i] > K){

		string name;
		int maxh = -1;
		for (mapit it = gs[i].begin();it!=gs[i].end();++it){
		  if(it->second > maxh){
			maxh = it->second;
			name = it->first;
		  }
		}
		head.push_back(make_pair(name,gs[i].size()));
	  }
	}

	sort(head.begin(),head.end());
	cout << head.size() << endl;
	for (int i = 0; i < head.size(); ++i){
	  cout << head[i].first << " " << head[i].second << endl;
	}
  }
  return 0;
}
