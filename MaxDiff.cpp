//Given an array arr[] of integers, 
//find out the maximum difference between any two elements such that larger element appears after the smaller number.

#include <bits/stdc++.h>

using namespace std;

//TC: O(n)
//SC: O(1)
int maxDifference2(int arr[], int size)
{
    if(size<=1) return 0;
    
    int maxDiff = arr[1]-arr[0];
    int min = arr[0];
    
    for(int i = 1; i < size; i++)
    {
        if( arr[i]-min > maxDiff) maxDiff = arr[i] - min;
        if(arr[i] <  min) min = arr[i];
    }
    return maxDiff;
}

//TC: O(n^2)
//SC: O(1)
int maxDifference(int arr[], int size)
{
    if(size<=1) return 0;
    int max = arr[1] - arr[0];
    
    for(int i=0; i< size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[j]-arr[i] > max) max = arr[j]-arr[i];
        }//end-of-inner-for
    }//end-of-outer-for
    
    return max;
}


int main() {
    int arr[] = {200, 142, 311, 400, 300, 420, 500, 110, 999};
    int size = 9;
    
    cout<<maxDifference(arr, size)<<endl;
    cout<<maxDifference2(arr, size)<<endl;
    
    return 0;
}
