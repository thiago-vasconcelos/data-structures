#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &in, int begin, int mid, int end){
  vector<int>ans;
  int i=begin, j=mid+1;
  while(i<=mid && j<=end) {
    if(in[i] > in[j]) {
      ans.push_back(in[j++]);
    } else {
      ans.push_back(in[i++]);
    }
  }
  while(i<=mid) ans.push_back(in[i++]);
  while(j<=end) ans.push_back(in[j++]);
  for(int i=begin; i<=end;i++) in[i] = ans[i-begin];
}

void mergeSort(vector<int> &in, int begin, int end) {
  if(begin < end) {
    int mid = (begin + end)/2;
    mergeSort(in, begin, mid);
    mergeSort(in, mid + 1, end);
    return merge(in, begin, mid, end);
  }
}

void mergeSort(vector<int> &in) {
  mergeSort(in, 0, in.size() - 1);
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
