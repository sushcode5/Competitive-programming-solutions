/* 
           Name - Rindhe Sushil Samadhan
           IIT Guwahati
         
 */




//BrutForce approach
//Time Complexity - O(n)

pair<int, int> findFirstLastPosition(vector<int> &arr, int N, int X)
{
    int start = -1, end = -1;
	for(int i=0;i<N;i++){
        if(arr[i]==X)
        {
            if(start == -1){
                start = i;
                end = i;
            }
            else
                end = i;
        }
    }
    pair<int,int> p;
    p.first = start;
    p.second = end;
    return p;
}

//Optimal Approach
//Time complexity - O(logn)


nt BinarySearchEnd(vector<int> arr, int N, int low, int high, int X){
    if(high<low){
        return -1;
    }
    int mid = low +(high-low)/2;
    if((mid == N-1 || arr[mid+1]>arr[mid]) && arr[mid]==X){
        return mid;
    }
    if(arr[mid]>X){
        return BinarySearchEnd(arr,N,low,mid-1,X);
    }
    else {
        return BinarySearchEnd(arr,N,mid+1,high,X);
    }
}
int BinarySearchStart(vector<int> arr, int N, int low, int high, int X){
    if(high<low){
        return -1;
    }
    int mid = low +(high-low)/2;
    if( (mid==0 || arr[mid]>arr[mid-1]) && arr[mid]==X){
        return mid;
    }
    if(arr[mid]>=X){
        return BinarySearchStart(arr,N,low,mid-1,X);
    }
    else{
        return BinarySearchStart(arr,N,mid+1,high,X);
    }
}
pair<int, int> findFirstLastPosition(vector<int> &arr, int N, int X)
{
    int low = 0;
    int high = N-1;
    int start = BinarySearchStart(arr,N,low,high,X);
    int end  = BinarySearchEnd(arr,N,low,high,X);
    pair<int,int> p;
    p.first = start;
    p.second = end;
    return p;
}
