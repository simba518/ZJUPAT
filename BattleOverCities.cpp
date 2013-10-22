#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int N,M,K;
  while((cin >> N >> M >> K)){

	vector<vector<int> > cmap(N+1);
	int a,b;
	for (int i = 0; i < M; ++i){
	  cin >> a >> b;
	  cmap[a].push_back(b);
	  cmap[b].push_back(a);
	}
	
	int occupied;
	vector<bool> visited(N+1,false);
	for (int i = 0; i < K; ++i){

	  cin >> occupied;
	  for (int i = 1; i <= N; ++i)
		visited[i] = false;
	  visited[occupied] = true;

	  int c = 1;
	  for (; c <= N; ++c){
		if(!visited[c])
		  break;
	  }
	  if(c == N+1){
		cout<< 0 << endl;
		continue;
	  }

	  queue<int> toVisit;
	  toVisit.push(c);
	  visited[c] = true;
	  set<int> unVisted;
	  for (int i = 1; i <= N; ++i){
		if(i != occupied && i != c)
		  unVisted.insert(i);
	  }

	  int ways = 0;
	  while(!toVisit.empty()){

		const int c0 = toVisit.front();
		toVisit.pop();
		for (int j = 0; j < cmap[c0].size(); ++j){
		  const int c = cmap[c0][j];
		  if(!visited[c]){
			toVisit.push(c);
			visited[c] = true;
			unVisted.erase(c);
		  }
		}
		if(toVisit.empty() && !unVisted.empty()){
		  toVisit.push(*(unVisted.begin()));
		  unVisted.erase(unVisted.begin());
		  ways ++;
		}
	  }
	  cout << ways << endl;
	}
  }
  return 0;
}
