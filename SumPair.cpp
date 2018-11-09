// Count pairs with given sum

#include <bits/stdc++.h>

using namespace std;

//TC: O(n^2)
//SC: O(1)
int getPair1(int *arr, int size, int k)
{
    int count = 0;
    for(int i =0; i< size; i++)
    {
        for(int j = i+1; j< size-1; j++)
        {
            if(arr[i] + arr[j] == k) 
            {
                cout<<arr[i]<<" "<<arr[j]<<endl;
                count++;
            }
        }
    }
    return count;
}


void swap(int *arr, int l, int r)
{
    int temp = *(arr+l);
    *(arr+l) = *(arr+r);
    *(arr+r) = temp;
}

// TC: O(logn)
// SC: O(1)
int partition(int *arr, int low, int high)
{
    int mid = low+(high-low)/2;
    int pivot = arr[mid];
    
    while(low<high)
    {
        while( arr[low] < pivot)
        {
             low++;
        }
        
        while(pivot <= arr[high])
        {
            high--;
        }
        
        //swapping
        if(low<high)
        {
            swap(arr, low, high);
        }        
    }   
    return low;
}


void quickSort(int *arr, int low, int high)
{
    if(low < high) 
    {
        int mid = partition(arr, low, high);
        quickSort(arr, 0, mid-1);
        quickSort(arr, mid+1, high);
    }
}


int getPair2(int *arr, int size, int sum)
{
    quickSort(arr, 0, size-1); // O(n*log(n))
    int i= 0, j=size-1;
    int pairs = 0;
    
    while(i<j)//O(n)
    {
        if(arr[i] + arr[j] == sum) { pairs++; i++; j--;}
        else if(arr[i] + arr[j] > sum) j--;
        else if(arr[i] + arr[j] < sum) i++;
    }
    return pairs;
}

int main()
{
    int arr[] = {1, 5, -2, 7, 2, 12, 9, 0, -5 };
    
    int sum=9;
    cin>>sum;
    
    int pairs = getPair2(arr, 9, sum);
    
    cout<<pairs<<endl;
    return 0;
}