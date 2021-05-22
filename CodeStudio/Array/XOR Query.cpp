/* 
             Name - Rindhe Sushil Samadhan
             IIT Guwahati
             
*/



/*


Assume you initially have an empty array say ‘ARR’.
You need to return the updated array provided that some ‘Q’ number of queries were performed on this array.
The queries are of two types:
1. 1 ‘VAL’, for this type of query, you need to insert the integer 'VAL' to the end of the array.
2. 2 ‘VAL’, for this type of query, you need to take the bitwise XOR of all the elements of the array with 'VAL' i.e each element of the array ‘ARR’ will be updated as ‘ARR[i]’ = ‘ARR[i]’ ^ ‘VAL’ ( ^ denotes the bitwise XOR operation).
Note:
1) Bitwise XOR operation takes two numbers and performs XOR operation on every bit of those two numbers. For example, consider two numbers 2 and 3 their bitwise XOR will be 1. Because the binary representation of 2 is '10' and the binary representation of 3 is '11'. And XOR of '10' and '11' will be '01'(because XOR evaluates to 0 if the corresponding bits are the same in both the operands, otherwise it evaluates to 1), which is equal to 1.

2) The first query will always be a type 1 query.

3) Note that the ith query should be performed on the array obtained after performing (i-1)th query on the array and so on i.e the changes of each query are updated on the original array itself.
Input Format:
The first line contains an integer ‘T’ which represents the number of test cases.

The first line of each test case contains an integer ‘Q’ denoting the number of queries. 

Then each of the ‘Q’ lines contains two space-separated integers denoting the query to be performed.
Output Format:
For each test case, return the updated array after processing all the queries.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints:
1 <= T <= 10
1 <= Q <= 10^5
1 <= Val <= 10^9

Time Limit: 1sec
Sample Input 1:
2
2
1 3
2 2
3
1 2
2 3
2 1
Sample Output 1:
1
0
Explanation For Sample Input 1:
For the first test case:
After the first query, 3 will be pushed into the array, so the array will be {3}, then after processing the second query the array will be changed to {3^2} i.e. {1}. So the output array will be {1}.

For the second test case:
After the first query, 2 will be pushed into the array, so the array will be {2}, then after processing the second query the array will be changed to {2^3} i.e. {1}, further the array is modified as {1^1} i.e {0}, after processing the third query. So the output array will be {0}.
Sample Input 2:
2
3 
1 2 
1 3
2 4
3
1 4
1 5
2 1
Sample Output 2:
6 7
5 4
Explanation For Sample Input 2:
For the first test case:
After the first query, 2 will be pushed into the array, so the array will be {2}. Then after processing the second query 3 will be pushed into the array, so the array will be {2, 3}. Then after processing the third query the array will be changed to {2^4, 3^4} i.e. {6, 7}. So the output array will be {6, 7}.

For the second test case:
After the first query, 4 will be pushed into the array, so the array will be {4}. Then after processing the second query 5 will be pushed into the array, so the array will be {4, 5}. Then after processing the third query the array will be changed to {4^1, 5^1} i.e. {5, 4}. So the output array will be {5, 4}.


*/





// Time Complexity - O(Q)
// Space Complexity - O(1)

vector<int> xorQuery(vector<vector<int>> &queries)
{
    vector<int> answer;
    int flag = 0;
    
    for(int i=0;i<queries.size();i++){
        if(queries[i][0]==1){
            answer.push_back(queries[i][1]^flag);
        }
        else{
            flag ^= queries[i][1];
        }
    }
    
    for(int i=0;i<answer.size();i++){
        answer[i] ^= flag;
    }
    return answer;
}
