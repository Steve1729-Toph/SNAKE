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