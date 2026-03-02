#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int st,int end){
    int idx= st-1,pivot=arr[end];
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    //after ending loop assigning pivot to correct position

    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}
//recursive function
void quickSort(vector<int>&arr,int st,int end)//using reference bec we are going to change this array reflex in main function
{
if(st<end){
 int pivIdx=  partition(arr,st,end);
    quickSort(arr,st,pivIdx-1);//left half
    quickSort(arr,pivIdx+1,end);//right half
}

}
int main(){
    vector<int> arr={5,2,6,4,1,3};
    quickSort(arr,0,arr.size()-1);//n-1as ending
for (int val:arr){
    cout<<val<<" ";
}
cout<<endl;
return 0;
}
