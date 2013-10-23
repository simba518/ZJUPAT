#include<stdio.h>
#include <math.h>
#include <assert.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int a,b;
  while( scanf("%d%d\n",&a,&b) != EOF ){
	int sum = a + b;
	if (sum < 0){
	  cout << "-";	
	  sum = -sum;
	}
	if (sum < 1000){
	  cout << sum << endl;
	  continue;
	}
	int v[7] = {0};
	int k = 0,D = 1;
	while(D <= sum){
	  assert(k<7);
	  v[k] = (sum%(D*10))/D;
	  k++;
	  D *= 10;
	}
	for (int i = k-1; i >=0 ; i--){
	  assert(i<7);
	  cout << v[i];
	  if(i%3 == 0 && i!= 0) cout << ",";
	}
	cout << endl;
  }
  return 0;
}
