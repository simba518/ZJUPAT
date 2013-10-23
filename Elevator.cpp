#include <stdio.h>

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int N;
  while(scanf("%d",&N)!=EOF){
	int F = 0, S = 0, cost = 0;
	for (int i = 1; i <= N; ++i){
	  scanf("%d",&S);
	  if (F > S)
		cost += (4*(F-S)+5);
	  else
		cost += (6*(S-F)+5);
	  F = S;
	}
	printf("%d\n",cost);
  }
  return 0;
}
