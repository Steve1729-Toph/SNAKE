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
void Up_score(){
        SetColor(7);
        gotoxy(18,12);
        cout << "DECORD : " << record;
        gotoxy(18,14);
        cout << "SCORE  : " << score;
        gotoxy(5,16);
}