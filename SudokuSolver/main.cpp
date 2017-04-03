#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define sc(x) scanf("%d",&x)
#define p     printf
#define pr(x) p("%2d",x)
#define pl(x) p("%s",x)
#define sp()  p(" ")
#define nl()  p("\n")
#define ise(i,s,e) for(int i=s;i<e;i++)
#define iseo(i,s,e,o) for(int i=s;i<e;i+=o)
#define esi(i,s,e) for(int i=e-1;i>=s;i--)
#define sz(x) (int)(x.size())
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int,int>



#define zero 0
#define N 9

int gridarray[N][N]={{4,0,0,0,0,0,8,0,5},
                     {0,3,0,0,0,0,0,0,0},
                     {0,0,0,7,0,0,0,0,0},
                     {0,2,0,0,0,0,0,6,0},
                     {0,0,0,0,8,0,4,0,0},
                     {0,0,0,0,1,0,0,0,0},
                     {0,0,0,6,0,3,0,7,0},
                     {5,0,0,2,0,0,0,0,0},
                     {1,0,4,0,0,0,0,0,0}};

string num        = "123456789";
string MainGrid   = " 4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......";
string AnswerGrid = " 438796215659132478271458693815219367713564829926873154194325786362987541587641932";

//vector<vector<int>> vvi;
// Row separation
string R1(string grid){string s="";ise(i, 1,10)s=s+grid[i];return s;}
string R2(string grid){string s="";ise(i,10,19)s=s+grid[i];return s;}
string R3(string grid){string s="";ise(i,19,28)s=s+grid[i];return s;}
string R4(string grid){string s="";ise(i,28,37)s=s+grid[i];return s;}
string R5(string grid){string s="";ise(i,37,46)s=s+grid[i];return s;}
string R6(string grid){string s="";ise(i,46,55)s=s+grid[i];return s;}
string R7(string grid){string s="";ise(i,55,64)s=s+grid[i];return s;}
string R8(string grid){string s="";ise(i,64,73)s=s+grid[i];return s;}
string R9(string grid){string s="";ise(i,73,82)s=s+grid[i];return s;}
// Column separation
string C1(string grid){string s="";iseo(i,1,82,9)s=s+grid[i];return s;}
string C2(string grid){string s="";iseo(i,2,82,9)s=s+grid[i];return s;}
string C3(string grid){string s="";iseo(i,3,82,9)s=s+grid[i];return s;}
string C4(string grid){string s="";iseo(i,4,82,9)s=s+grid[i];return s;}
string C5(string grid){string s="";iseo(i,5,82,9)s=s+grid[i];return s;}
string C6(string grid){string s="";iseo(i,6,82,9)s=s+grid[i];return s;}
string C7(string grid){string s="";iseo(i,7,82,9)s=s+grid[i];return s;}
string C8(string grid){string s="";iseo(i,8,82,9)s=s+grid[i];return s;}
string C9(string grid){string s="";iseo(i,9,82,9)s=s+grid[i];return s;}
// Square separation
string S1(string grid){int c=0;string s="";ise(i, 1,28){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S2(string grid){int c=0;string s="";ise(i, 4,28){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S3(string grid){int c=0;string s="";ise(i, 7,28){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S4(string grid){int c=0;string s="";ise(i,28,55){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S5(string grid){int c=0;string s="";ise(i,31,55){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S6(string grid){int c=0;string s="";ise(i,34,55){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S7(string grid){int c=0;string s="";ise(i,55,82){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S8(string grid){int c=0;string s="";ise(i,58,82){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}
string S9(string grid){int c=0;string s="";ise(i,61,82){s=s+grid[i];c+=1;if(c==3){i+=6;c=0;}}return s;}


void showGrid(int gridarray[N][N]){
    ise(r,0,9)ise(c,0,9)pr(gridarray[r][c]);nl();
}
/*
void showGrid(string grid){

    ise(i,1,82){
        cout << grid[i] <<" ";
        if(i==27 or i==54){cout << endl ; cout<<"------+-------+------"<< endl ; continue;}
        if(i%9==0){cout << endl ;continue;}
        if(i%3==0)cout << "| " ;
    }
    cout << S1(grid)<< " "  ;
}
*/
// convert string to number grid
// assign 0 where use dot(.)
vi vec_s2i(string grid){
    vi v;
    int a=sz(grid);
    ise(i,0,a){
        if(grid[i]=='.')v.pb(0);
        else v.pb(grid[i]-'0');
    }
    return v;
}




bool emptySpace(int grid[N][N], int &r, int &c);
bool noRepeat(int grid[N][N], int r, int c, int n);
bool SolveSudoku(int grid[N][N])
{
    int r, c;
    if (!emptySpace(grid, r, c))
       return 1;
    for (int n = 1; n <= 9; n++)
    {
        if (noRepeat(grid, r, c, n))
        {
            grid[r][c] = n;
            if (SolveSudoku(grid))
                return 1;
            grid[r][c] = zero;
        }
    }
    return 0;
}
bool emptySpace(int grid[N][N], int &r, int &c)
{
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (grid[r][c] == zero)
                return 1;
    return 0;
}

bool isInRow(int grid[N][N], int r, int n)
{
    ise(c,0,N)
        if (grid[r][c] == n)
            return 1;
    return 0;
}
bool isInCol(int grid[N][N], int c, int n)
{
    ise(r,0,N)
        if (grid[r][c] == n)
            return 1;
    return 0;
}

bool isInSquare(int grid[N][N], int sr, int sc, int n)
{
    ise(r,0,3)
        ise(c,0,3)
            if (grid[r+sr][c+sc] == n)
                return 1;
    return 0;
}

bool noRepeat(int grid[N][N], int r, int c, int n)
{
    return !isInRow(grid, r, n) &&
           !isInCol(grid, c, n) &&
           !isInSquare(grid, r - r%3 , c - c%3, n);
}

void ShowGrid(int grid[N][N])
{
    ise(r,0,N)
    {
        ise(c,0,N)
             pr(grid[r][c]);
        nl();
    }
}


int main1()
{
    //MainGrid=" "+MainGrid;
    //AnswerGrid=" " +AnswerGrid;
    //showGrid(MainGrid);
    //showGrid(AnswerGrid);

    //vi v=vec_s2i(S1(AnswerGrid));
    //int si=sz(v);
    //ise(i,0,si)cout  <<v[i]<<" " ;
    //int gridvalue[N][N]=

    //if(solvableSudoku(gridarray))
    showGrid(gridarray);
        //return 0;
    //else cout << "No solution exits!" ;
}





int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    //int grid1[N][N] ={{4, 3, 8, 7, 9, 6, 2, 1, 5},{6, 5, 9, 1, 3, 2, 4, 7, 8}{2, 7, 1, 4, 5, 8, 6, 9, 3},                      {815219367713564829926873154194325786362987541587641932}}
    if (SolveSudoku(grid) == 1)
          ShowGrid(grid);
    else
         pl("No solution");

    return 0;
}
