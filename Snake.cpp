#include <iostream>
#include "Source_Snake.hpp"
#include <time.h>

using namespace std;
#define MAX 100
//========================================================================================================================
//bien toan cuc
long long score = 0;
long long record = 0;
int color ;
//========================================================================================================================
//cac phan cua snake
struct Node{ //toa do cua snake
    int x,y;
};

struct SNAKE{//snake
    Node a[100]; 
    int len;//do dai snake
};
//========================================================================================================================
//prototype
void Draw_Wall_tren();//ve tuong tren
void Draw_Wall_duoi();//ve tuong duoi
void Draw_Wall_trai();//ve tuong trai
void Draw_Wall_phai();//ve tuong phai
void Draw_Wall();//ve ra cai tuong
void Init(SNAKE& snake);//khoi tao snake
void Draw_Snake(SNAKE& snake);//ve snake
void Run(SNAKE& snake, int dir);//snake di chuyen
void Draw_Food(int& res_X, int& res_Y);//ve thuc an
bool check_Snake(SNAKE& snake, int res_X, int res_Y);//kiem tra ran co cham tuong khong
void Xu_Ly(SNAKE& snake, int& res_X, int& res_Y);//xu ly snake an thuc an
void Create_Food(SNAKE& snake, int& res_X, int& res_Y);//khoi tao thuc an
void play(SNAKE& snake, char& ch, int& dir, int& res_X, int& res_Y);// ham nay chua toan bo chuc nang cua game
bool Game_Over(SNAKE snake);//kiem tra tro choi ket thuc
bool check_touch(SNAKE& snake, int& res_X, int& res_Y);//kiem tra snake co cham vao thuc an hay ko
bool check_touch_snake(SNAKE& snake);//kiem tra snake co cham vao than snake ko
void GAMEOVER();//in background gameover
void SNAKE_HINT_1();//in background di chuyen bang A W S D
void SNAKE_HINT_2();//in background di chuyen bang mui ten
void SNAKE_GAME();//in background snake game
void MENU_SNAKE(int&);//lua chon trong menu tro choi
void INIT_MENU();//khoi tao menu
void menu1();//>> starts <<
void menu2();//>> guide <<
void menu3();//>> setting <<
void menu4();//>> exit <<
void delete_MENU_up(int);//xoa >> << TH di len
void delete_MENU_down(int);//xoa >> << TH di xuong
void LOADING();//giao dien loanding
void GUIDE();//giao dien guide
char SETTING();//giao dien setting
void Arrow(char&, int&);//lua chon nut mui ten de di chuyen
void ASDW(char&, int&);//lua chon A S D W de di chuyen
void Up_score();//diem va ky luc
//========================================================================================================================
int main(){

    SNAKE snake;

    int dir = 0;

    int res_X = -1, res_Y = -1;

    char ch;

    srand(time(NULL));

    play(snake, ch, dir, res_X, res_Y);

    return 0;
}
//========================================================================================================================
void Draw_Wall_tren(){
    int x = 50, y = 5;
    while(x < 151){
        gotoxy(x,y);
        printf("%c",219);
        printf("%c",219);
        x+=2;
    }
}
void Draw_Wall_duoi(){
    int x = 50, y = 35;
    while(x < 151){
        gotoxy(x,y);
        printf("%c",219);
        printf("%c",219);
        x+=2;
    }
}
void Draw_Wall_trai(){
    int x = 50, y = 5;
    while(y < 35){
        gotoxy(x,y);
        printf("%c",219);
        printf("%c",219);
        y++;
    }
}
void Draw_Wall_phai(){
    int x = 151, y = 5;
    while(y <= 35){
        gotoxy(x,y);
        printf("%c",219);
        printf("%c",219);
        y++;
    }
}
void Init(SNAKE& snake){
    snake.len = 4;
    int x = 75, y = 20;
    for(int i = 0; i < snake.len; ++i){
        snake.a[i].x = x;
        snake.a[i].y = y;
        x--;
    }
}
void Draw_Wall(){
    SetColor(7);
    Draw_Wall_tren();
    Draw_Wall_duoi();
    Draw_Wall_trai();
    Draw_Wall_phai();
}
void play(SNAKE& snake, char& ch, int& dir, int& res_X, int& res_Y){
    int check = 1;
    SetColor(4);
    SNAKE_GAME();
    char p = 50;
    char h;
    SetColor(1);
    while(true){
        
        char c = 97;
        MENU_SNAKE(check);
        if(kbhit()) ch = getch();
        if(ch == -32){
            ch = getch();
            if(ch == 72){
                check += -1;//len
                if(check <= 0) check = 4;
                delete_MENU_up(check);
            }else if(ch == 80){
                check += 1;//xuong
                if(check >= 5) check = 1;
                delete_MENU_down(check);
            }
        }else if(ch == 32 && check == 2) {
            system("cls");
            GUIDE();
            
            while(c != 98){
                if(kbhit()) c = getch();
                Sleep(1);
            }

            system("cls");
            ch = 30;
            SNAKE_GAME();
        }else if(ch == 32 && check == 3){
            system("cls");
            char t = p;
            p = SETTING();
            
            while(p != 98 && p != 49 && p != 50){
                if(kbhit()) p = getch();
                Sleep(1);
            }

            if(p == 98) p = t;

            system("cls");
            ch = 30;
            SNAKE_GAME();
        }else if (ch == 32 && check == 4){
            return;
        }else if (ch == 32 && check == 1){
            break;
        }
        Sleep(100);
    }

    system("cls");
    LOADING();
    system("cls");
    Draw_Wall();

    if(p == 50)
        SNAKE_HINT_1();
    else 
        SNAKE_HINT_2();

    Init(snake);

    Create_Food(snake, res_X, res_Y);

    Draw_Food(res_X, res_Y);

    Sleep(3000);
    
    while(true){

        gotoxy(snake.a[snake.len].x, snake.a[snake.len].y);
        printf(" ");
        if(!Game_Over(snake)) Draw_Snake(snake);
        if(kbhit()) ch = getch();
        if (p == 50){
            Arrow(ch, dir);
        
        }else{
            ASDW(ch, dir);
        }

        if(record <= score) record = score;

        Up_score();
        SetColor(color);
        
        if(Game_Over(snake)){
            Sleep(3000);
            system("cls");
            GAMEOVER();
            h = getch();
            if(h == 32){
                score = 0;
                system("cls");
                LOADING();
                system("cls");
                Draw_Wall();
                if(p == 50)
                    SNAKE_HINT_1();
                else 
                    SNAKE_HINT_2();
                Init(snake);

                Create_Food(snake, res_X, res_Y);
                Draw_Food(res_X, res_Y);
                dir = 0;
                Sleep(3000);
            }else break;
        }

        Xu_Ly(snake, res_X, res_Y);

        Run(snake, dir);

        if(dir == 1 || dir == 3) Sleep(150);
        else Sleep(100);
    }

}
void Draw_Snake(SNAKE& snake){
    int i;
    for(i = 0; i < snake.len; ++i){
        gotoxy(snake.a[i].x, snake.a[i].y);
        (i == 0) ? printf("%c",254):printf("%c",219);
    }
}
void Run(SNAKE& snake, int dir){
    for (int i = snake.len; i > 0; --i){
        snake.a[i].x = snake.a[i-1].x;
        snake.a[i].y = snake.a[i-1].y;
    }
    switch (dir)
    {
    case 0://huong ben phai = 0
        snake.a[0].x = snake.a[0].x + 1;
        break;
    case 1://huong di xuong = 1
        snake.a[0].y = snake.a[0].y + 1;
        break;
    case 2://huong ben trai = 2
        snake.a[0].x = snake.a[0].x - 1;
        break;
    case 3://huong di len = 3
        snake.a[0].y = snake.a[0].y - 1;
        break;
    }
}
bool check_touch(SNAKE& snake, int& res_X, int& res_Y){
    for(int i = 0; i < snake.len; ++i){
        if(res_X == snake.a[i].x && res_Y == snake.a[i].y)
            return true;
    }
    return false;
}
void Create_Food(SNAKE& snake,int& res_X, int& res_Y){
    color = rand() % (15 - 1) + 1;
    SetColor(color);
    do{
        res_X = rand() % (150 - 52 + 1) + 52;
        res_Y = rand() % (24 - 6 + 1) + 6;
    }while(check_touch(snake, res_X, res_Y)); 
}
void Draw_Food(int& res_X, int& res_Y){
    gotoxy(res_X, res_Y);
    printf("%c", 254);
} 
bool check_Snake(SNAKE& snake, int res_X, int res_Y){
    return (res_X == snake.a[0].x) && (res_Y == snake.a[0].y);
}
void Xu_Ly(SNAKE& snake, int& res_X, int& res_Y){
    if(check_Snake(snake, res_X, res_Y)){
        SetColor(color);
        snake.len++;
        score += 10;
        Create_Food(snake, res_X, res_Y);
        Draw_Food(res_X, res_Y);
    }
}
bool Game_Over(SNAKE snake){
    if (snake.a[0].x == 51 || snake.a[0].x == 151 || snake.a[0].y == 5 || snake.a[0].y == 35)
        return true;
    return check_touch_snake(snake); 
}
bool check_touch_snake(SNAKE& snake){
    for(int i = 1; i <= snake.len; ++i){
        if(snake.a[i].x == snake.a[0].x && snake.a[i].y == snake.a[0].y)
            return true;
    }
    return false;
}
void GAMEOVER(){
    SetColor(6);
    gotoxy(50,5);
    cout << "#####   ###     #   #   #####  ##### ##    ## ##### ######"; 
    gotoxy(50,6);
    cout << "## __  #   #   ### ###  ##__   #   #  ##  ##  ##___ ##__##";
    gotoxy(50,7);
    cout << "##  #  #####   #  #  #  ##     #   #   #  #   ##    ##  ##";
    gotoxy(50,8);
    cout << "##### ##   ## ##     ## #####  #####    ##    ##### ##   ##";
    gotoxy(65,12);
    SetColor(9);
    cout << "SCORE      : " << score;
    gotoxy(65,13);
    cout << "RECORD     : " << record;
    gotoxy(65,14);
    cout << "PLAY AGAIN : press the space";
    gotoxy(65,15);
    cout << "EXIT       : press E";
}
void SNAKE_HINT_1(){
    SetColor(11);
    gotoxy(10,6);
    cout << "// |\\ ||   //\\   ||// ||||||";
    gotoxy(10,7);
    cout << "\\\\ ||\\||  //-\\\\  |\\/  ||--";
    gotoxy(10,8);
    cout << "// || \\| //   \\\\ ||\\\\ ||||||";
    gotoxy(5,9);
    cout << "======================================";
    gotoxy(5,10);
    cout << "======================================";
    gotoxy(18,12);
    cout << "DECORD : " << record;
    gotoxy(18,14);
    cout << "SCORE  : " << score;
    gotoxy(5,16);
    cout << "======================================";
    gotoxy(5,17);
    cout << "======================================";
    gotoxy(19,19);
    cout << "PLAY";
    gotoxy(13,20);
    cout << "Arrow up    : go up";
    gotoxy(13,21);
    cout << "Arrow down  : go down";
    gotoxy(13,22);
    cout << "Arrow left  : go left";
    gotoxy(13,23);
    cout << "Arrow right : go right";
}
void SNAKE_HINT_2(){
    SetColor(11);
    gotoxy(10,6);
    cout << "// |\\ ||   //\\   ||// ||||||";
    gotoxy(10,7);
    cout << "\\\\ ||\\||  //-\\\\  |\\/  ||--";
    gotoxy(10,8);
    cout << "// || \\| //   \\\\ ||\\\\ ||||||";
    gotoxy(5,9);
    cout << "======================================";
    gotoxy(5,10);
    cout << "======================================";
    gotoxy(18,12);
    cout << "DECORD : " << record;
    gotoxy(18,14);
    cout << "SCORE  : " << score;
    gotoxy(5,16);
    cout << "======================================";
    gotoxy(5,17);
    cout << "======================================";
    gotoxy(19,19);
    cout << "PLAY";
    gotoxy(13,20);
    cout << "W    : go up";
    gotoxy(13,21);
    cout << "S    : go down";
    gotoxy(13,22);
    cout << "A    : go left";
    gotoxy(13,23);
    cout << "D    : go right";
}
void SNAKE_GAME(){
    SetColor(4);
    gotoxy(50,5);
    cout << "$$$$ $$  $$   $$$   $$  $$ $$$$$   $$$$$   $$$     $   $   $$$$$";
    gotoxy(50,6);
    cout << "$$\\  $$$ $$  $   $  $$$$$  $$__    $$ __  $   $   $$$ $$$  $$__";
    gotoxy(50,7);
    cout << "  $$ $$ $$$  $$$$$  $$ $$  $$      $$  $  $$$$$   $  $  $  $$   ";
    gotoxy(50,8);
    cout << "$$$/ $$  $$ $$   $$ $$  $$ $$$$$   $$$$$ $$   $$ $$     $$ $$$$$";
    int j = 1; 
    for(int i = 0; i < 45; ++i){
        gotoxy(60+i,10);
        SetColor(j);
        printf("%c", 223);
        gotoxy(60+i,17);
        printf("%c", 223);
        j++;
        if(j == 15) j -= 14;
        Sleep(50);
    }
    INIT_MENU();
    gotoxy(63, 18);
    cout << "Open full screen for the best experience!";
}
void menu1(){
    SetColor(11);
    gotoxy(77,12);
    cout << ">> ";
    gotoxy(86,12);
    cout << " <<";
}
void menu2(){
    SetColor(10);
    gotoxy(77,13);
    cout << ">> ";
    gotoxy(85,13);
    cout << " <<";

}
void menu3(){
    SetColor(9);
    gotoxy(77,14);
    cout << ">> ";
    gotoxy(87,14);
    cout << " <<";
}
void menu4(){
    SetColor(8);
    gotoxy(77,15);
    cout << ">> ";
    gotoxy(84,15);
    cout << " <<";
}
void INIT_MENU(){
    SetColor(6);
    gotoxy(80,12);
    cout << "STARTS";
    gotoxy(80,13);
    cout << "GUIDE";
    gotoxy(80,14);
    cout << "SETTING";
    gotoxy(80,15);
    cout << "EXIT";
}
void MENU_SNAKE(int& check){
    if (check == 1) menu1();
    else if (check == 2) menu2();
    else if (check == 3) menu3();
    else if (check == 4) menu4();
}
void delete_MENU_down(int check){
    if(check == 1) {
        //vi tri 4
        gotoxy(77,15);
        printf("   ");
        gotoxy(84,15);
        printf("   ");
    }
    else if(check == 2){
        //vi tri 1
        gotoxy(77,12);
        printf("   ");
        gotoxy(86,12);
        printf("   ");    
    }
    else if(check == 3){
        //vitri 2
        gotoxy(77,13);
        printf("   ");
        gotoxy(85,13);
        printf("   ");    
    }
    else if(check == 4){
        //vi tri 3
        gotoxy(77,14);
        printf("   ");
        gotoxy(87,14);
        printf("   ");    
    }
}
void delete_MENU_up(int check){
    if(check == 3) {
        //vi tri 4
        gotoxy(77,15);
        printf("   ");
        gotoxy(84,15);
        printf("   ");
    }
    else if(check == 4){
        //vi tri 1
        gotoxy(77,12);
        printf("   ");
        gotoxy(86,12);
        printf("   ");    
    }
    else if(check == 1){
        //vitri 2
        gotoxy(77,13);
        printf("   ");
        gotoxy(85,13);
        printf("   ");    
    }
    else if(check == 2){
        //vi tri 3
        gotoxy(77,14);
        printf("   ");
        gotoxy(87,14);
        printf("   ");    
    }
}
void LOADING(){
    gotoxy(50,5);
    cout << "$$$$ $$  $$   $$$   $$  $$ $$$$$   $$$$$   $$$     $   $   $$$$$";
    gotoxy(50,6);
    cout << "$$\\  $$$ $$  $   $  $$$$$  $$__    $$ __  $   $   $$$ $$$  $$__";
    gotoxy(50,7);
    cout << "  $$ $$ $$$  $$$$$  $$ $$  $$      $$  $  $$$$$   $  $  $  $$   ";
    gotoxy(50,8);
    cout << "$$$/ $$  $$ $$   $$ $$  $$ $$$$$   $$$$$ $$   $$ $$     $$ $$$$$";
    int j = 1; 
    gotoxy(75,11);
    cout << "Loading...";
    for(int i = 0; i < 45; ++i){
        gotoxy(60+i,10);
        SetColor(j);
        printf("%c", 223);
        gotoxy(60+i,12);
        printf("%c", 223);
        j++;
        if(j == 15) j -= 14;
        Sleep(70);
    }
}
void GUIDE(){
    int j = 1; 
    for(int i = 0; i < 61; ++i){
        gotoxy(60+i,10);
        SetColor(j);
        printf("%c", 223);
        gotoxy(60+i,13);
        printf("%c", 223);
        j++;
        if(j == 15) j -= 14;
    }
    gotoxy(65,11);
    cout << "Use the arrow keys (or A, W, S, D in settings)";
    gotoxy(60,12);
    cout << " to move the snake to eat the bait and reach a record score.";
    gotoxy(60,14);
    cout << "Press B to Back.";
}
char SETTING(){
    int j = 1; 
    for(int i = 0; i < 61; ++i){
        gotoxy(60+i,10);
        SetColor(j);
        printf("%c", 223);
        gotoxy(60+i,13);
        printf("%c", 223);
        j++;
        if(j == 15) j -= 14;
    }
    gotoxy(75,11);
    cout << "1. Using A, W, S and D to move";
    gotoxy(68,12);
    cout << "2. Using Arrow left, right, up, down to move"; 
    gotoxy(60,14);
    cout << "Press B to Back";
    char c;
    if(kbhit()) c = getch();
    return c;
}
void Arrow(char& ch, int& dir){
            if(ch == -32){
                ch = getch();
                if(ch == 72 && dir != 1){
                    dir = 3;//len
                }else if(ch == 80 && dir != 3){
                    dir = 1;//xuong
                }else if(ch == 77 && dir != 2){
                    dir = 0;//phai
                }else if(ch == 75 && dir != 0){
                    dir = 2;//trai
                }
            }
}
void ASDW(char& ch, int& dir){
                if(ch == 119 && dir != 1){
                    dir = 3;//len
                }else if(ch == 115 && dir != 3){
                    dir = 1;//xuong
                }else if(ch == 100 && dir != 2){
                    dir = 0;//phai
                }else if(ch == 97 && dir != 0){
                    dir = 2;//trai
                }
}
void Up_score(){
        SetColor(7);
        gotoxy(18,12);
        cout << "DECORD : " << record;
        gotoxy(18,14);
        cout << "SCORE  : " << score;
        gotoxy(5,16);
}