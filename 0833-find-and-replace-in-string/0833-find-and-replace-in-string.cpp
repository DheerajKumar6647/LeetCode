class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<int>order(n);
        for(int i=0; i<n; i++){
            order[i] = i;
        }
        string original = s;
        sort(order.begin() , order.end() ,[&](int a , int b){
            return (indices[a] > indices[b]);
        });

        for(int i : order){
            int size = sources[i].size();
            if(original.substr(indices[i] , size) == sources[i]){
                s.replace(indices[i] , size , targets[i]);
                
            }
        }
        return s;
    }
};