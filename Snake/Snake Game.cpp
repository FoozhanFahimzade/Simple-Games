#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int sizen = 30, sizem = 80, arr[100][4], len = 1;
char g[1000][100], lastm = 'r',fi = rand()% (sizen-2) + 1, fj = rand()% (sizem-2) + 1;
class Ground{
  public:
  void set(int n, int m);
  void print(int n, int m);
};
class Snake{
  public:
  void moves();
  void movep(char a);
  void setm();
  void increase();
  bool validpress(char a);
  bool lose();
  bool lose2();
  bool win();
};
class Food{
    public:
    void showf();
    void hidef();
    void newf();
    bool touchf();
};

int main(){
    Ground ground;
    Snake snake;
    Food food;
    arr[0][0] = 1;
    arr[0][1] = 1;
    ground.set(sizen, sizem);
    snake.setm();
    food.showf();
    ground.print(sizen, sizem);
    bool flag = true, flag2 = false;
    char p;
    int times = 70;
    while(flag){
        
        ground.set(sizen,sizem);
        food.showf();
        if(kbhit()){
        p = getch();
        //cin >> p;
        
        }

        snake.movep(p);
        snake.moves();
        
        if(snake.lose() or snake.lose2() or snake.win()){
            flag = false;
        }
        if(food.touchf()){
        food.newf();
        snake.increase();
        len++;
        times --;
        }
        cout << endl;
        snake.setm();
        ground.print(sizen,sizem);
        Sleep(times);
        system("cls");
    }
    return 0;
}

void Ground::set(int n, int m){
    for(int i = 1; i  < n-1; i ++){
        g[i][0] = '*';
        g[i][m-1] = '*';
        for(int j = 1; j < m-1; j ++){
            g[i][j] = ' ';
        }
    }
    for(int i = 0; i < m; i ++){
        g[0][i] = '*';
        g[n-1][i] = '*';
    }
}

void Ground::print(int n, int m){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cout << g[i][j];
        }
        cout << endl;
    }
}
bool Snake::validpress(char a){
    if(lastm == 'r' or lastm == 'l'){
        if(a == 'u' or a == 'd'){
            return true;
        }
        else{
            cout << "Invalid press";
            return false;
        }
    }
    else{
        if(a == 'l' or a == 'r'){
            return true;
        }
        else{
            cout << "Invalid press";
            return false;
        }
    }
}
void Snake::movep(char a){
        if(a == 'w'){
            lastm = 'u';
        }
        if(a == 's'){
            lastm = 'd';
        }
        if(a == 'd'){
            lastm = 'r';
        }
        if(a == 'a'){
            lastm = 'l';
        }
}
void Snake::moves(){
    int x = arr[0][0], y = arr[0][1];
    for(int i = 1; i < len; i ++){
        int x2 = arr[i][0], y2 = arr[i][1];
        arr[i][0] = x;
        arr[i][1] = y;
        x = x2;
        y = y2;
    }
    if(lastm == 'r'){
        arr[0][1] ++;
    }
    if(lastm == 'l'){
        arr[0][1] --;
    }
    if(lastm == 'd'){
        arr[0][0] ++;
    }
    if(lastm == 'u'){
        arr[0][0] --;
    }
}
void Snake::setm(){
    for(int i = 1; i < len; i ++){
        g[arr[i][0]][arr[i][1]] = '0';
    }
    g[arr[0][0]][arr[0][1]] = '@';
}
void Snake::increase(){
    arr[len][0] = arr[len-1][0];
    arr[len][1] = arr[len-1][1];
}
bool Snake::lose(){
    for(int i = 0; i < len; i ++){
       if( g[arr[i][0]][arr[i][1]] == '*'){
           cout << "lost";
           return true;
       }
    }
    
    return false;
}
bool Snake::lose2(){
    for(int i = 0; i < len; i ++){
        for(int j = 0;  j < len; j ++){
            if(i!=j and arr[i][0] ==arr[j][0] and arr[i][1] == arr[j][1]){
                cout << "lost";
                return true;
            }
        }
    }
    return false;
}
bool Snake::win(){
    if(len == 60){
        return true;
    }
    return false;
}
void Food::showf(){
    g[fi][fj] = '$';
}
void Food::hidef(){
    g[fi][fj] = ' ';
}
void Food::newf(){
    fi = rand()% (sizen-3) + 1;
    fj = rand()% (sizem-3) + 1;
}


bool Food::touchf(){
    if(g[arr[0][0]][arr[0][1]] == '$'){
            g[fi][fj] = ' ';
            return true;
        }
    return false;
}