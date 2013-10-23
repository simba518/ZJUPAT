#include <stdio.h>
#include <assert.h>

#define INF 1000000000

template <class T, int N>
void Dijkstra(const T G[N][N], T D[N], const int v0){
  
  for (int i = 0; i < N; ++i)
    D[i] = G[v0][i];
  bool used[100] = {false};
  used[v0] = true;
  for (int numS = 1; numS < N; ++numS){
	int nextV = -1;
	T min = INF;
	for (int v = 0; v < N; ++v)
	  if(used[v])
		for (int i = 0; i < N; ++i)
		  if(!used[i])
			if(D[v]+G[v][i] <= min){
			  nextV = i;
			  min = D[v]+G[v][i];
			}
	assert(nextV>=0);
	assert(nextV<N);
	used[nextV] = true;
	D[nextV] = min;
  }
}

int main(int argc, char *argv[]){

  double G[100][100];
  double D[100];
  for (int i = 0; i < 100; ++i){
	for (int j = 0; j < 100; ++j){
	  G[i][j] = (i==j)?0:INF;
	}
  }

  G[1][2]=2,G[1][4]=20,G[2][5]=1;
  G[3][1]=3,G[4][3]=8,G[4][6]=6;
  G[4][7]=4,G[5][3]=7,G[5][8]=3;
  G[6][3]=1,G[7][8]=1,G[8][6]=2;
  G[8][10]=2,G[9][7]=2,G[10][9]=1;

  Dijkstra<double,100>(G,D,1);
  for (int i = 1; i < 10; ++i){
    printf("%.f ",D[i]);
  }
  printf("\n");
  return 0;
}
