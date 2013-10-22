#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  int N;
  while ( !(cin>>N).eof() ){
	map<string,string> in,out;
	for (int i = 0; i < N; ++i){
	  string is,os,id;
	  cin >> id >> is >> os;
	  in[is] = id;
	  out[os] = id;
	}
	if(in.size()>0)
	  cout << in.begin()->second << " " << out.rbegin()->second << endl;
  }
  return 0;
}
