

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

class Solution {
    public void setZeroes(int[][] matrix) {
        
        int col0=1 , row = matrix.length , col = matrix[0].length;
        
        for(int i=0; i < row; i++){
        if(matrix[i][0] == 0) col0 =0;
        for(int j = 1 ; j< col; j++)
            if(matrix[i][j] ==0)
                matrix[i][0]= matrix[0][j]= 0;
    }
    
      for(int i=row-1; i>=0; i--){
        for(int j = col-1; j>0; j--)
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
          if(col0==0) matrix[i][0] =0;
      }
                
        

        
        
    }
}