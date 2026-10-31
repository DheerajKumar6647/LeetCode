class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double>ans;
        priority_queue<int>pqMax;
        priority_queue<int , vector<int>  , greater<int>>pqMin;
        int x = 0 , y = 0;

        // Making window

        for(int i=0; i<k; i++){
            if(pqMax.empty() || nums[i] <= pqMax.top()){
                pqMax.push(nums[i]);
                x++;
            }
            else {
                pqMin.push(nums[i]);
                y++;
            }
            if(x-y > 1){
                pqMin.push(pqMax.top());
                pqMax.pop();
                x--;
                y++;
            }
            else if(y-x > 1){
                pqMax.push(pqMin.top());
                pqMin.pop();
                x++;
                y--; 
            }
        }
        if(k%2 == 0){
            ans.push_back((1LL*pqMax.top() + pqMin.top())/2.0);
        }
        else{
            if(x>y) ans.push_back(pqMax.top());
            else ans.push_back(pqMin.top());
        }
        
        unordered_map<int , int>mp;

        for(int i=k; i<n; i++){
// Handle going elements

            int idx = i-k;

            mp[nums[idx]]++;
            if(nums[idx] <= pqMax.top()){
                x--;
            }
            else y--;
 // Cleaning elements of mp

            while(!mp.empty() && mp.count(pqMax.top())){
                mp[pqMax.top()]--;
                if(mp[pqMax.top()] == 0) mp.erase(pqMax.top());
                pqMax.pop();

            }
            while(!mp.empty() && mp.count(pqMin.top())){
                mp[pqMin.top()]--;
                if(mp[pqMin.top()] == 0) mp.erase(pqMin.top());
                pqMin.pop();
            }
//Insert elements
            if(nums[i] <= pqMax.top()){
                pqMax.push(nums[i]);
                x++;
            }
            else {
                pqMin.push(nums[i]);
                y++;
            }



//Size handling
            if(x-y > 1){
                pqMin.push(pqMax.top());
                pqMax.pop();
                x--;
                y++;
            }
            else if(y-x > 1){
                pqMax.push(pqMin.top());
                pqMin.pop();
                x++;
                y--; 
            }

            while(!mp.empty() && mp.count(pqMax.top())){
                mp[pqMax.top()]--;
                if(mp[pqMax.top()] == 0) mp.erase(pqMax.top());
                pqMax.pop();

            }
            while(!mp.empty() && mp.count(pqMin.top())){
                mp[pqMin.top()]--;
                if(mp[pqMin.top()] == 0) mp.erase(pqMin.top());
                pqMin.pop();
            }
            
//finding Meadian
            if(k%2 == 0){
            ans.push_back((1LL*pqMax.top() + pqMin.top())/2.0);
            }
            else{
                if(x>y) ans.push_back(pqMax.top());
                else ans.push_back(pqMin.top());
            }
        }
        return ans;
    }
};