

#include <iostream>
using namespace std;
// Time Complexity - O(2^N)
int fibonacci(int n){
    if(n==0 || n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

// Time Complexity - O(N)
int fib2(int n, int*arr){
    if(n==0 || n==1){
        return 1;
    }
    if(arr[n] > 0){
        return arr[n];
    }

    int output = fib2(n-1,arr) + fib2(n-2,arr);
    arr[n] = output;
    return arr[n];
}

int main() {

	int n;
	cin >> n;
	int *arr = new int[n]();
	cout<<fib2(n,arr)<<endl;
	delete[] arr;
	return 0;
}
