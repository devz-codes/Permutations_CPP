#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> permutations(vector<int> v,int len){
  vector<vector<int>> result={};
  if(len==2){
  	result={{v[0],v[1]},{v[1],v[0]}};
  }
  else{
    int num=v[len-1];
    for(vector<int> i:permutations(v,len-1)){
      for(int j=0;j<len;j++){
        vector<int> dummy=i;
        dummy.insert(dummy.begin()+j,num);
        result.push_back(dummy);
      }
    }
  }
  return result;
}

int main(){
  vector<int> num={1,2,3,4,5,6,7};
  vector<vector<int>> perm=permutations(num,7);
  for(vector<int> j:perm){
    for(int i:j){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  cout<<perm.size();
}
