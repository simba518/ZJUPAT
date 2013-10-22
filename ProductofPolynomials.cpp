#include <stdio.h>

int main(int argc, char *argv[]){
  
  freopen("in.txt","r",stdin);
  int n1,n2,p;
  while (scanf("%d",&n1) != EOF){
	double x[1001] = {0.0f};
	for (int i = 0; i < n1; ++i){
	  scanf("%d",&p);
	  scanf("%lf",&x[p]);
	}
	scanf("%d",&n2);
	double s[1001+1001] = {0.0f};
	double y;
	for (int i = 0; i < n2; ++i){
	  scanf("%d",&p);
	  scanf("%lf",&y);
	  for (int j = 0; j < 1001; ++j)
		s[p+j] += x[j]*y;
	}
	int c = 0;
	for (int i = 1001+1001-1; i>=0; --i)
	  if(s[i]!=0)
		c ++;
	printf("%d",c);
	for (int i = 1001+1001-1; i>=0; --i)
	  if(s[i]!=0)
		printf(" %d %.1f",i,s[i]);
	printf("\n");
  }
  return 0;
}
