#include <iostream>
#include <vector>

using namespace std;

// Find the lucky number in the matrix where 
// it is the min in that row
// it is the max in that column

vector<int> FindLuckyNum(vector<vector<int> > M){
    // m is the row number and n is the column
    int m = M.size();
    int n = M[0].size();

    vector<int> ans; // to store the ans
    
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            // use [i][j] to represent each element whether they are min or max
            // 
            // default set each element to be true
            bool isMin=true, isMax=true;
            for(int k=0;k<n;k++){
                if(M[i][k]<M[i][j]){
                    isMin = false;
                    break;
                }
            }
            // if not the isMin just find the next element
            if(!isMin){
                continue;
            }

            for(int k=0; k<m;k++){
                if(M[k][j]>M[i][j]){
                    isMax = false;
                    break;
                }
            }

            if(isMax){
                ans.push_back(M[i][j]);
            }
        }
    }
    
    return ans;
}
