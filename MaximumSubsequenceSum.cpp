#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int K;
  while( (scanf("%d",&K) != EOF) ){
	int D[K];
	for (int k = 0; k < K; ++k)
	  scanf("%d",&D[k]);
	int ii=0,jj=K-1,max=-1,sum=0,temp=0;
	for (int k = 0; k < K; ++k){
	  sum += D[k];
	  if(sum>max){
		max=sum;
		ii=temp;
		jj=k;
	  }
	  if(sum<0){
		sum=0;
		temp=k+1;
	  }
	}
	max = max>0? max:0;
	assert(ii<=jj);
	printf("%d %d %d\n",max,D[ii],D[jj]);
  }
  return 0;
}
