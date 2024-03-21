#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col,vector<vector<int> > &board, int val){
    
    for(int i=0;i<board.size();i++){
        //row check
        if(board[row][i]==val){
            return false;
        }
        // col check
        if(board[i][col]==val){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }

    }
    return true;
}

bool Solve(vector<vector<int> > &board){

    int n=board.size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;

                       if(Solve(board)){

                        // if(isFurtherSolPossible){
                            return true;
                        }
                        else{
                            // backtracking
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSudoku(vector<vector<int> > &board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    vector<vector<int> > board(9,vector<int>(9,0));

    // insert value
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            // cout<<"enter the element at row "<<i<<" col "<<j<<" ";
            cin>>board[i][j];
        }
    }
//    vector<vector<int> > grid=Solve(board)

    if(Solve(board)){
        cout<<"sudoko is solved "<<endl;
        cout<<endl;
        printSudoku(board);
    }
    else{
        cout<<"sudoko is not solved "<<endl;    
    }
}

// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0