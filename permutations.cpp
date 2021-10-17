#include<iostream>
#include<vector>
using namespace std;

int factorial(int num){
  return num==0 ? 1: num*factorial(num-1);
}

void swap(int &i,int &j){
  int c=i;
  i=j;
  j=c;
}


vector<vector<int>> permutation(vector<int> v){
  vector<vector<int>> result={};
  int len=v.size();

  for(int i=0;i<factorial(len)/len;i++){
    if(i%2==0){
      for(int j=len-1;j>=1;j--){
        swap(v[j],v[j-1]);
        result.push_back(v);
      }
      swap(v[len-1],v[len-2]);
      result.push_back(v);
    }
    else{
      for(int j=0;j<len-1;j++){
        swap(v[j],v[j+1]);
        result.push_back(v);
      }
      swap(v[0],v[1]);
      result.push_back(v);
    }
  }
  return result;
}

int main(){
  vector<int> num={1,2,3,4,5,6};
  vector<vector<int>> p=permutation(num);
  cout<<p.size();
}
