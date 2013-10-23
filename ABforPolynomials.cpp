#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

  freopen("in.txt","r,",stdin);
  int len;
  while(!(cin>>len).eof()){
	
	double N[1010] = {0.0f};
	for (int i = 0; i < len; ++i){
	  double k,v;  cin >> k >> v;
	  N[(int)k] = v;
	}
	cin >> len;
	for (int i = 0; i < len; ++i){
	  double k,v;  cin >> k >> v;
	  N[(int)k] += v;
	}
	int c = 0;
	for (int i = 0; i < 1010; ++i){
	  if (N[i] != 0)
		c ++;
	}
	if(c == 0){
	  printf ("%d",c);
	  continue;
	}
	printf("%d ",c);
	int j = 0;
	for (int i = 1001; i>=0; --i){
	  if (N[i] != 0){
		printf("%d %.1f",i,N[i]);
		j++;
		if(j < c)  printf(" ");
	  }
	}
	printf("\n");
  }
  return 0;
}
