class Solution {
public:
    int islandPerimeter(vector<vector<int>>& a) {
        if(a.size()==0 || a[0].size()==0) return 0;
        
        int c=0;
        int row=a.size(), col=a[0].size();
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
             
                if(a[i][j]) {
                    //counting all tops (T)
                    if(i>=0) {
                        if(i>0 && !a[i-1][j])   c++;//for all non-border elements
                        else if(i==0 && (j==0 || j==col-1)) c++;//for TL & TR corner (border)  
                        else if(i==0 /*&& (j>0 && j<col-1)*/)   c++;//for T non-corner (border)
                    }
                    
                    //counting all bottoms (B)
                    if(i<=row-1) {
                        if(i<row-1 && !a[i+1][j])   c++;//for all non-border elements
                        else if(i==row-1 && (j==0 || j==col-1)) c++;//for BL&BR corner (border) 
                        else if(i==row-1 /*&& (j>0 && j<col-1)*/)c++;//for B non-corner(border) 
                    }
                    //counting all lefts (L)
                    if(j>=0) {
                        if(j>0 && !a[i][j-1])   c++;//for all non-border elements
                        else if(j==0 && (i==0 || j==row-1)) c++;//for LT & LB corner (border) 
                        else if(j==0 /*&& (i>0 && j<row-1)*/)   c++;//for L non-corner (border)
                    }
                    //counting all Rights (R)
                    if(j<=col-1) {
                        if(j<col-1 && !a[i][j+1])   c++;//for all non-border elements
                        else if(j==col-1 && (i==0 || i==row-1)) c++;//for RT&RB corner (border) 
                        else if(j==col-1 /*&& (i>0 && i<row-1)*/)c++;//for R non-corner(border) 
                    }
                    
                }
