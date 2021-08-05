#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9] =
    { { 0, 2, 0, 0, 0, 0, 0, 0, 0 },    
      { 0, 0, 0, 6, 0, 0, 0, 0, 3 },    
      { 0, 7, 4, 0, 8, 0, 0, 0, 0 },    
      { 0, 0, 0, 0, 0, 3, 0, 0, 2 },    
      { 0, 8, 0, 0, 4, 0, 0, 1, 0 },    
      { 6, 0, 0, 5, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 1, 0, 7, 8, 0 },
      { 5, 0, 0, 0, 0, 9, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 4, 0 } };

int solve(int i, int j){
    // stop condition
    if((i == 9) && (j == 0)){
        for(int ii = 0; ii < 9; ii++){
            for(int jj = 0; jj < 9; jj++){
                printf("%2d", sudoku[ii][jj]);
            }
            printf("\n");
        }
        return 1;
    }

    if(sudoku[i][j] != 0){
        if(j == 8){
            // jump to next row of sudoku[][]
            i = i + 1;
            j = 0;
        }else{
            // jump to next cell in the same row of sudoku[][]
            //i = i;
            j = j + 1;
        }
        solve(i, j);
    }else{
        for(int n = 1; n <= 9; n++){
            int found = 0;

            for(int ii = 0; ii < 9; ii++){
                found = found || (sudoku[ii][j] == n);
            }

            for(int jj = 0; jj < 9; jj++){
                found = found || (sudoku[i][jj] == n);
            }

            for(int ii = 0; ii < 3; ii++){
                for(int jj = 0; jj < 3; jj++){
                    found = found || (sudoku[(i / 3) * 3 + ii][(j / 3) * 3 + jj] == n);
                }
            }

            if(!found){
                // now, n is a valid value for cell [i][j]
                sudoku[i][j] = n;

                if(solve((j == 8) ? i + 1 : i, (j == 8) ? 0 : j + 1) != 0){
                    return 1;
                }

                sudoku[i][j] = 0;
            }
        }
    }
    return 0;
}

int main(){
    solve(0, 0);
    return 0;
}