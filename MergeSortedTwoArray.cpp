#include <bits/stdc++.h>

using namespace std;

//TC: O(size1+size2)
//SC: O(1)
void mergeTwoSortedArrays1(int *arr1, int size1, int *arr2, int size2, int *arr3)
{   
   
    int i=0, j=0, k=0;
    while(i<size1 && j<size2)
    {
        if( *(arr1+i) < *(arr2+j) ) *(arr3+k++) = *(arr1 + i++);
        else *(arr3+k++) = *(arr2+j++);
    }
    
    while(i<size1) *(arr3+k++) = *(arr1+i++);
    
    while(j<size2) *(arr3+k++) = *(arr2+j++); 
}


int main()
{
    int arr1[] = {2, 3, 6, 7};
    int arr2[] = {1, 4, 5, 8};
    int arr3[8];
    
    mergeTwoSortedArrays1(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int), arr3);
     
    int i = 0;
    while(i<8) cout<<*(arr3+i++)<<"\t";
  
    return 0;
}