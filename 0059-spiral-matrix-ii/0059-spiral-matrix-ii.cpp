class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> arr(n, vector<int>(n));

        int up = 0, dn = n-1, lt = 0, rt = n-1;

        while (up <= dn && lt <= rt) {

            for(int j=lt; j<=rt; j++){
                arr[up][j] = num++;
                
            }
            up++;
            for(int i=up; i<=dn; i++){
                arr[i][rt] = num++;
            }
            rt--;

            for(int j=rt; j>=lt; j--){
                arr[dn][j] = num++;
            }
            dn--;

            for(int i=dn; i>=up; i--){
                arr[i][lt] = num++;
            }
            lt++;
        }

        return arr;
    }
};