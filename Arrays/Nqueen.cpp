/*
	Solution to classic backtracking problem
	solved using elementary arrays
*/

#include <stdio.h>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

bool check(int row, int col, int board[][50], int n)
{
    //check left straight line
    for(int i=0; i<col; i++)
        if(board[row][i])
            return false;
    //check diagnols
    for(int i=row, j=col; i>=0 && j>=0; i--,j-- )
        if(board[i][j])
            return false;
    for(int i=row, j=col; i<n && j>=0; i++,j-- )
        if(board[i][j])
            return false;
            
    return true;
}

bool permute(int board[][50], int col, int n)
{
    if(col>=n)
        return true;
        
    for(int i=0; i<n; i++)
    {
        if(check(i,col,board,n))
        {
            board[i][col]=1;
            //Check if answer lies in the next permutation
            if(permute(board,col+1,n))
                return true;
                
            //Couldn't find solution in next col. So zero previous one!
            board[i][col]=0;
            
        }
    }
    return false;
}

void printAnswer(int board[][50], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << board[i][j];
        cout << endl;
    }
}

void solve(int n)
{
    //retains the board after permute to display
    int board[n][50]={0};
    permute(board,0,n);
    printAnswer(board,n);
}



int main()
{
    cout << "No of queens to fit: ";
    int n;
    cin >> n;
    solve(n);
    return 0;
}
