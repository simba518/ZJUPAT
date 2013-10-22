#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

  freopen("in.txt","r",stdin);
  const char *dic[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
  string N;
  while(!(cin>>N).eof()){
  	int sum = 0;
  	for (int i = 0; i < N.size(); ++i)
  	  sum += N[i]-'0';
  	if (sum == 0){
  	  cout << dic[0] << endl;
  	  continue;
  	}
  	vector<int> digit;
  	int D = 1;
  	while(D<=sum){
  	  digit.push_back(sum%(D*10)/D);
  	  D *= 10;
  	}
  	for (int i = 0; i < digit.size(); ++i){
  	  cout << dic[digit[digit.size()-i-1]];
  	  if (i != digit.size()-1)
  		cout << " ";
  	}
  	cout << endl;
  }
  return 0;
}
