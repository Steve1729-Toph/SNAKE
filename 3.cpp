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