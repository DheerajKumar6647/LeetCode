class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int m = sandwiches.size();
        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }
        int j = 0;
        int count = 0 ;
        while(!q.empty() && count!=q.size()){

            if(q.front() == sandwiches[j]){
                count = 0;
                q.pop();
                j++;
            }
            else{
                int temp = q.front();
                q.pop();
                q.push(temp);
                count++;

            }
        }
        return q.size();
    }
};