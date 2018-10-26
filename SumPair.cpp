// Count pairs with given sum

#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int arr[] = {1, 5, -2, 7, 2, 12, 9, 0, 5 };
    int sum;
    cin>>sum;
    
    int pairs = getPair1(arr, 9, sum);
    cout<<pairs<<endl;
    return 0;
}
