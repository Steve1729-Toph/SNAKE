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