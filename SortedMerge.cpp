/*
Given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.
Merge B into A in sorted order.
*/

#include <bits/stdc++.h>

using namespace std;

//TC: O(size1+size2)
//SC: O(1)
void sortedMerge(int *arr1, int size1, int *arr2, int size2)
{
    int i2 = size2-1; // index2 for arr2
    int i1 = size1-size2-1;// index1 for arr1
    
    
    int li = size1 - 1; // last index
    
    while(i2 >= 0)
    {
        if(li>=0&&*(arr1+i1) > *(arr2+i2)) *(arr1 + li) = *(arr1 + i1--);
        else *(arr1 + li) = *(arr2 + i2--);
        li--;
    }    
}

int main()
{
    int arr1[11] = {1, 3,4, 7, 9, 12};
    int arr2[5] = {2, 5, 6, 10, 11};
    
    sortedMerge(arr1, 11, arr2, 5);
    for(int i = 0; i<11; i++)
        cout<<arr1[i]<<"\t";
}