class Solution {
public:
    
    void change(int **matrix, int ri, int ci, int m, int n){
        for(int j=0;j<n;j++){
            matrix[ri][j]+=1;
        }
        for(int i=0;i<m;i++){
            matrix[i][ci]+=1;
        }
    }
    
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int **matrix = new int*[m];
        for(int i=0;i<m;i++){
            matrix[i] = new int[n];
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
        for(int x=0;x<indices.size();x++){
            change(matrix, indices[x][0], indices[x][1], m, n);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]%2!=0){
                    count+=1;
                }
            }
        }
        return count;
    }
};