#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>&arr, int i, int j){
    int aux = arr[j];
    arr[j] = arr[i];
    arr[i] = aux;
}

int partition(vector<int>&arr, int begin, int end){
    // Pivot is first element
    int pivot = arr[begin];
    cout<<"pivot: "<<pivot<<endl;

    int i=begin, j=end;

    // while i and j dont pass
    while(i<j){
        // find and element greater than our pivot
        while(arr[i]<=pivot){
            i++;
        }
        // find an element lesser than our pivot
        while(arr[j]>pivot){
            j--;
        }
        // if i and j are not upside down (j is first than i)
        // swap values, so we have i as greater and j as lesser
        if(i<j){
            swap(arr,i,j);
        }
    }
    
    // when i and j collapse and passes each other..
    // put the pivot which is the first element in the correct position
    swap(arr, begin, j);

    // return pivot to continue next subarray
    return j;
}

void quicksort(vector<int>&arr, int begin, int end){
    if(begin>=end) return;
    int pivot = partition(arr, begin, end);

    quicksort(arr, begin, pivot-1);
    quicksort(arr, pivot+1, end);
}

int main(){
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(9);
    arr.push_back(5);

    quicksort(arr, 0, arr.size()-1);

    for(auto a:arr){
        cout<<a<<" ";
    }

    return 0;
}
