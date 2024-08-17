#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> left,vector<int> right){
    int m = left.size();
    int n = right.size();
    vector<int> result(m+n,0);
    int i=0,j=0,k=0;
    while(i < m && j < n){
        if(left[i] <= right[j]){
            result[k++] = left[i++];
        }
        else result[k++] = right[j++];

    }
    while(i < m) result[k++] = left[i++];
    while(j < n) result[k++] = right[j++];

    return result;
}
vector<int> helper(vector<int> arr,int start,int end){
    if (start == end) return arr;
    int mid = (start + end) / 2;
    vector<int> left(arr.begin(),arr.begin()+mid+1);
    vector<int> right(arr.begin()+mid+1,arr.end());
    left = helper(left, 0, left.size()-1);
    right = helper(right,0,right.size()-1);
    return merge(left, right);
}
void mergeSort(vector<int> arr){
    vector<int> result = helper(arr,0,arr.size()-1);
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
}

int main(){
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(12);
    arr.push_back(82);
    arr.push_back(0);
    arr.push_back(76);
    arr.push_back(34);
    arr.push_back(23);
    arr.push_back(84);
    arr.push_back(21);
    
    mergeSort(arr);

}