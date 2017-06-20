#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &in, int begin, int mid, int end) {
  vector<int> aux;
  int i = begin;
  int j = mid + 1;
  while(i<=mid && j<=end) {
    if(in[i]<in[j]){
      aux.push_back(in[i]);
      i++;
    } else {
      aux.push_back(in[j]);
      j++;
    }
  }
  while(i<=mid) aux.push_back(in[i++]);
  while(j<=end) aux.push_back(in[j++]);
  for(int i=begin; i<=end;i++) in[i] = aux[i-begin];
}

void mergeSort(vector<int> &in) {
  for(int currentSize=1; currentSize<in.size(); currentSize*=2) {
    for(int begin=0;begin<in.size()-1;begin+=currentSize*2) {
      int mid = (2 * begin + 2 * currentSize - 1) / 2;
      int end = min(begin + 2*currentSize - 1, (int)in.size() - 1);
      merge(in, begin, mid, end);
    }
  }
}

int main() {
  vector<int> vec;
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(2);
  vec.push_back(4);
  vec.push_back(1);
  vec.push_back(8);
  mergeSort(vec);
  for(int i=0; i<vec.size();i++) {
    cout<<vec[i]<<endl;
  }
  return 0;
}
