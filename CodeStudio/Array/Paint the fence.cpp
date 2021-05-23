/*
                Name - Rindhe Sushil Samadhan
                IIT Guwahati
                
*/






//Brutforce approach
// Calculate for each pair the maximum no. of sections painted if that pair is not considered.

// Time Complexity - O(N* (Q^3))
// Space Complexity - O(1);


int findCount(vector<int> &arr, int left, int right){
    int count = 0;
    int n = arr.size();
    
    for(int i=left; i<=right; i++){
        if(arr[i] == 1){
            continue;
        }
        else{
            arr[i] += 1;
            count += 1;
        }
    }
    return count;
}
int paintTheFence(vector<vector<int>>& ranges, int n, int q){
   
    int maxCount = 0;
    for(int i = 0; i < ranges.size(); i++){
        
        for(int j = i + 1; j < ranges.size(); j++){
            
            int count = 0;
            vector<int> arr(n, 0);
            
            for(int k = 0; k < ranges.size(); k++){
                if(k==i){
                    continue;
                }
                if(k==j){
                    continue;
                }
                else{
                    count += findCount(arr, ranges[k][0] - 1, ranges[k][1] - 1);
                }
            }
            maxCount = max(count, maxCount);
            
        }
    }
    return maxCount;
}
