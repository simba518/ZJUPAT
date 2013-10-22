#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

typedef long long int LINT;

LINT digit(const char c){
  if(c>='0'&&c<='9')
	return c-'0';
  return c-'a'+10;
}

LINT num(const string &s,LINT r){

  LINT a = 0, d = 1;
  for (int i = 0; i < s.size(); ++i){
	a += digit(s[s.size()-i-1])*d;
    d = d*r;
  }
  return a;
}

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  string a,b;
  while( !(cin>>a).eof()){
  	cin >> b;
  	int i=1,d=1;
  	cin>>i>>d;
  	if(i==2)
  	  swap(a,b);
	const LINT av = num(a,d);
	LINT r = digit(b[0])+1;
	for (int i = 0; i < b.size(); ++i)
	  if(digit(b[i])+1>r)
		r = digit(b[i])+1;
	if(b.size()>1&&num(b,r)!=0){

	  LINT minR = r, maxR = r;
	  while(true){
		const LINT bv = num(b,maxR);
		if(av == bv){
		  minR = maxR;
		  break;
		}else if(av > bv){
		  minR = maxR;
		  maxR = maxR*2;
		}else{
		  break;
		}
	  }
	  while(true){
		r = (maxR+minR)/2;
		const LINT bv = num(b,r);
		if(bv == av){
		  cout << r << endl;
		  break;
		}else if(minR >= maxR){
		  cout << "Impossible" << endl;
		  break;
		}else if(bv < av){
		  minR = r+1;
		}else{
		  maxR = r-1;
		}
	  }
	}else{
	  if(num(b,r) == av){
		cout << r << endl;		
	  }else{
		cout << "Impossible" << endl;
	  }
	}
  }
  return 0;
}
