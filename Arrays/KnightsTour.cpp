/*
	Solution to classic backtracking problem
	solved using elementary arrays
*/

#include <stdio.h>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;
 
void answer(int grid[][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int x, int y, int x1, int y1, int grid[][8])
{
    //cout << "yolo";
    int x2=x+x1;
    int y2=y+y1;
    if(x2>=0 && y2>=0 && grid[x2][y2]==-1 && x2<=7 && y2<=7)
        return true;
    return false;
}

bool permute(int grid[][8], int x, int y, int count)
{
    
    if(count>=64)
        return true;
    int x1[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int y1[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    
    for(int i=0; i<8; i++)
    {
        if(isSafe(x,y,x1[i],y1[i],grid))
        {
            //cout << "fdg" << endl;
            grid[x+x1[i]][y+y1[i]]=count;
            //answer(grid);
            
            if(permute(grid,x+x1[i],y+y1[i],count+1))
                return true;
            grid[x+x1[i]][y+y1[i]]=-1;
            
        }
    }
    return false;
}
 
void solve()
{
    int grid[8][8];
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            grid[i][j]=-1;
    grid[0][0]=0;
    permute(grid,0,0,1);
    answer(grid);
} 
 
int main()
{
    solve();
    return 0;
}
