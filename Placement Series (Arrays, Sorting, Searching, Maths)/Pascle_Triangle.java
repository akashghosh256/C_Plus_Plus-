Normal Pascle Triangle

      1                                            1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
 1 5 10 10 5 1


public class vibe{

   static int fact(int n){
        if(n==0)
        return 1;
    return n * fact(n-1);
    }

    public static void main(String[] args) {
        int i,j,n=5;

        for( i=0; i<=n; i++){
            for(j=0; j<n-i; j++){
                System.out.print(" ");
            }
            for(int k =0 ; k<=i; k++){
                System.out.print(" "+fact(i)/(fact(i-k)*fact(k)));

            }
            System.out.println();
        }
       
    }

}

OUTPUT: 
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
 1 5 10 10 5 1




STRIVER // LEETCODE


import java.util.*;   

class Solution {
    public List<List<Integer>> generate(int numRows) {
        
List<List<Integer >> res = new ArrayList<List<Integer >>();


List<Integer>row,pre=null;
for(int i=0;i<numRows;++i){
    row=new ArrayList<Integer>();
    for(int j=0;j<=i;++j)
        if(j==0 || j==i)
            row.add(1);
        else
         row.add(pre.get(j-1)+pre.get(j));
      pre=row;
      System.out.println("current "+i+" row/pre value "+pre);
res.add(row);
    
}
return res;
}
                        
}

public class fire{

    public static void main(String[] args) {
        Solution s =new Solution();
     
      System.out.println( "\n Final Pascle Triangle is : \n"+ s.generate(5));
        // leetcode type output : [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    }
}



