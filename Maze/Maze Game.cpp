#include <bits/stdc++.h>
using namespace std;
string cellarr[1020][1020];
int ln = 0, lm = 0;
int x = rand()% 10 + 3;
int y = rand()% 10 + 3;
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
class Cell{
    public:
    void set(int a, int b);
    void setbomb(int n, int m, int t);
    void setdivar(int n, int m, int t);
    void pcell(int a, int b, int li, int lj);
    void Clear(){
    cin.clear();
    system("cls");
    string IgnoreLine;
    getline(cin,IgnoreLine);
    }
    
};
class Maze{
  public:
  void movep(int li, int lj);
  bool wincheck(int li, int lj);
  bool losecheck(int li, int lj);
};
int main()
{
    int b = rand()% (x*y/3);
    int d = rand()% (x*y/3);
    Cell cell;
    cell.set(x, y);
    cell.setbomb(x, y, b);
    cell.setdivar(x, y, d);
    cell.pcell(x,y, ln, lm);
    Maze maze;
    while(!maze.wincheck(ln, lm) and !maze.losecheck(ln, lm)){
        maze.movep(ln, lm);
        cell.Clear();
        cell.pcell(x, y, ln, lm);
        
    }
    
    return 0;
}
void Cell::pcell(int a, int b, int li, int lj){
    for(int i = 0; i < a; i ++){
        for(int j = 0; j < b; j ++){
            if(i == li and j == lj)
            cout << "[.]";
            else
            cout << cellarr[i][j];
        }
        cout << endl;
    }
}

void Cell::set(int a, int b){
    for(int i = 0; i < a; i ++){
        for(int j = 0; j < b; j ++){
            cellarr[i][j] = "[ ]";
        }
    }
}

void Cell::setbomb(int n, int m, int t){
    int a, b;
    for(int i = 0; i < t; i ++){
        do{
            a = rand()% n + 1;
            b = rand()% m + 1;
        }while (cellarr[a][b] == "[B]" or cellarr[a][b] == "[#]" );
        cellarr[a][b] = "[B]";
    }
}

void Cell::setdivar(int n, int m, int t){
    int a, b;
    for(int i = 0; i < t; i ++){
        do {
            a = rand()% n + 1;
            b = rand()% m + 1;
        }while (cellarr[a][b] == "[B]" or cellarr[a][b] == "[#]" );
        cellarr[a][b] = "[#]";
    }
}

void Maze::movep(int li, int lj){
    char a;
    cin >> a;
    switch (a) {
        case UP:
            if(li-1 > 0 and cellarr[li-1][lj] != "[#]"){
               li --; 
                ln = li;
                lm = lj;
            }
            else{
                cout << "Harekat na motabar ast." << endl;
            }

        break ;
        case DOWN:
            if(li+1 < x and cellarr[li+1][lj] != "[#]"){
               li ++; 
                ln = li;
                lm = lj;
            }
            else{
                cout << "Harekat na motabar ast." << endl;
            }
        break;
        case LEFT:
            if(lj-1 > 0 and cellarr[li][lj-1] != "[#]"){
               lj --;
               ln = li;
                lm = lj;
            }
            else{
                cout << "Harekat na motabar ast." << endl;
            }
        break;
        case RIGHT:
            if(lj+1 < y and cellarr[li][lj+1] != "[#]"){
               lj ++; 
               ln = li;
                lm = lj;
            }
            else{
                cout << "Harekat na motabar ast."<< endl;
            }
        break;
    }
}

bool Maze::wincheck(int li, int lj){
    if(li == x-1 and lj == y-1){
        cout << "YOU WON!";
        return true;
    }
    return false;
}
bool Maze::losecheck(int li, int lj){
    if(cellarr[li][lj] == "[B]"){
        cout << "YOU LOST!";
        return true;
    }
    return false;
}
