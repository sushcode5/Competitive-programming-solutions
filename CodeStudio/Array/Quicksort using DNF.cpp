/*         
                 Name - Rindhe Sushil Samadhan
                 IIT Guwahati
                
*/


/*


Quicksort using the Dutch national flag algorithm.


Problem Statement
You are given an array/list of integers. You are supposed to sort the array in non-decreasing order by applying Quicksort using the Dutch national flag algorithm.
The Dutch National Flag algorithm is used to sort an array/list consisting of only three distinct elements in one iteration by placing all occurrences of the smallest element at the beginning of the array and all occurrences of the biggest element at the end of the array.
Input Format:
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

The second line of each test case contains ‘N’ single space-separated integers denoting the elements of the array/list.
Output Format:
For each test case, print in a new line the elements of the given array/list in non-decreasing order.
Note:
You don’t need to print anything; It has already been taken care of.
Constraints:
1 <= T <= 5
1 <= N <= 10^5
-10^9 <= ARR[i] <= 10^9

Where ‘T’ denotes the number of test cases, ‘N’ denotes the number of elements in the array and ARR[i] denotes the elements of the array.

Time Limit: 1 sec
Sample Input 1 :
2
5
4 2 1 4 2
5
5 2 7 3 5
Sample Output 1:
1 2 2 4 4
2 3 5 5 7
Explanation Of Sample Input 1:
In the first test case, after arranging elements of the given array/list in non-decreasing order, we get {1,2,2,4,4}.

In the second test case, after arranging elements of the given array/list in non-decreasing order, we get {2,3,5,5,7}.
Sample Input 2:
2
3
3 5 4
4
4 4 2 4
Sample Output 2:
3 4 5
2 4 4 4
Explanation Of Sample Input 2:
In the first test case, after arranging elements of the given array/list in non-decreasing order, we get {3,4,5}.
In the second test case, after arranging elements of the given array/list in non-decreasing order, we get {2,4,4,4}.








*/

// Time Complexity - O(NlogN)
// Space Complexity - O(logN)



void partition(vector<int>&arr, int si, int ei,int &low, int &mid){
    int pivot = arr[si];
    
    //high is taken for elements higher than pivot
    int high = ei;
    
    while(mid<=high){
        if(arr[mid]<pivot){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]>pivot){
            swap(arr[mid],arr[high]);
            high--;
        }
        else{
            mid++;
        }
    }
}
void quickSort(vector<int>&arr, int si, int ei){
    if(si>=ei){
        return;
    }
    if(si+1==ei){
        if(arr[si]>arr[ei]){
            swap(arr[si],arr[ei]);
            return;
        }
    }
    //low is taken for elements lower than pivot
    int low = si;
    
    //mid is taken for elements equal than pivot
    int mid = si;
    partition(arr,si,ei,low,mid);
    
    quickSort(arr,si,low-1);
    quickSort(arr,mid,ei);
}
vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr)
{
    int n = arr.size();
    quickSort(arr,0,n-1);
    return arr;
}
