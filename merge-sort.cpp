#include<iostream>
#include<vector>
using namespace std;
//merge function
void merge(vector<int>&arr,int st,int mid,int end){
 vector<int>temp; //temp storage
 int i=st,j=mid+1;
 while(i<=mid&&j<=end){
    if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;

    }
    else{
        temp.push_back(arr[j]);
        j++;
    }

 }  
 while(i<=mid){//remaining element of left half
    temp.push_back(arr[i]);
    i++;
 } 
 while(j<=end){//remaining element of right half
    temp.push_back(arr[j]);
    j++;
 }
 for(int idx=0;idx<temp.size();idx++){//copy to original array from temp array
 arr[idx+st]=temp[idx];
 }
}



//recursive function
void mergeSort(vector<int>&arr,int st,int end){
    if(st<end){
        int mid =st +(end-st)/2;
        mergeSort(arr,st,mid);//left half
        mergeSort(arr,mid+1,end);//right half
      merge(arr,st,mid,end);
    }
}
int main(){
    vector<int>arr={12,31,35,8,32,17};
    mergeSort(arr,0,arr.size()-1);
    for(int val:arr){
        cout<<val<<" ";

    }
    cout<<endl;
    return 0;
}