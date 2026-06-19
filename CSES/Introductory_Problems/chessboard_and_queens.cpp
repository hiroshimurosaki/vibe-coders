#include <bits/stdc++.h>

using namespace std;

bool verify(int x, int y, vector<vector<char>> board){
    
    // Linha
    for(int i=0;i<8;i++) if(board[x][i] == 'q' && i!=y) return false;
    
    // Coluna
    for(int i=0;i<8;i++) if(board[i][y] == 'q' && i!=x) return false;

    // Diagonal Sup Esq
    for(int i=x-1,j=y-1; i>=0 && j>=0; i--,j--) if(board[i][j] == 'q') return false;
    
    // Diagonal Sup Dir
    for(int i=x-1,j=y+1; i>=0 && j<8; i--,j++) if(board[i][j] == 'q') return false;

    // Diagonal Inf Esq
    for(int i=x+1,j=y-1; i<8 && j>=0; i++,j--) if(board[i][j] == 'q') return false;

    // Diagonal Inf Dir
    for(int i=x+1,j=y+1; i<8 && j<8; i++,j++) if(board[i][j] == 'q') return false;

    return true;
}

int ans=0;
void recursion(int x, int y, vector<vector<char>> & board){

    if(y==8){
        ans++;
        return;
    }
    if(x == 8) return;
    if(board[x][y] == '*' || !verify(x,y,board)) recursion(x+1,y,board);
    else {
        board[x][y] = 'q';
        
        recursion(0, y+1, board);
        
        board[x][y] = '.';
    
        recursion(x+1,y,board);
    }

}

int main() {

    vector<vector<char>> board(8, vector<char>(8));

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> board[i][j];
        }
    }

    recursion(0,0,board);

    cout << ans << endl;

    return 0;

}