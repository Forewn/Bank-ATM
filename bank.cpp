//codigo de un cajero automatico

//librerias
#include<iostream>
#include<cctype>
#include<conio.h>
#include<windows.h>

using namespace std;

//esta es la comision que se cobra por cada transaccion
#define BANK 0.015

//esta es una funcion que nos sirve para ordenar las cosas en la pantalla
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);	  
}

//aca se listan todas las funciones excepto la principal
void checkBalance(float balance);
float depositBalance(float balance, bool *pHaveMoney);
float withdrawBalance(float balance, bool haveMoney);
void drawSquare(int xleft, int xright, int yup, int ydown);


//funcion principal
int main(){

    //tamano de pantalla y cositas, no mires esto
    HWND console = GetConsoleWindow(), hwnd = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 594, 500, TRUE);
    HMENU hMenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
    EnableMenuItem(hMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_GRAYED);

    //seccion de incializacion
    bool stop, haveMoney = false;
    int choice;
    float balance = 0.00, aux;


    //bienvenida
    system("cls");
    system("color 1f");
    gotoxy(20, 3); cout<<"*********************************";
    gotoxy(20,4); cout<<"Bienvenido al sistema de cajero!!";
    gotoxy(20,5); cout<<"*********************************";
    Sleep(2000);

    //bucle que mantiene el programa en marcha
    do
    {
        //opciones
        gotoxy(20, 9); cout<<"Seleccione una opcion:";
        //Boton superior izquierdo
        drawSquare(0, 5, 12, 14);
        //Boton superior derecho
        drawSquare(63, 69, 12, 14);
        //Boton inferior izquierdo
        drawSquare(0, 5, 17, 19);
        //Boton inferior derecho
        drawSquare(63, 69, 17, 19);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
        gotoxy(6, 13); cout<<"1.Revisar balance";
        gotoxy(6, 18); cout<<"2.Depositar";
        gotoxy(54, 13); cout<<"3.Retirar";
        gotoxy(56, 18); cout<<"4.Salir";
        gotoxy(25, 20); cout<<">>";
        choice = getche();
        system("cls");


        //dependiendo de cada opcion va a ejecutar una funcion distinta (las funciones las ves al final del codigo)
        switch (choice)
        {
        
            //funcion ver balance
            case '1':
                checkBalance(balance);
                stop = false;
                break;
            //funcion depositar balance
            case '2':
                balance = depositBalance(balance, &haveMoney);
                break;
            //funcion retirar balance
            case '3':
                balance = withdrawBalance(balance, haveMoney);
                break;
            //salir
            default:
                stop = true;
                break;
        }
        //el ciclo no se va a romper mientras que stop sea false
    } while (!stop);

    return 0;
}

void checkBalance(float balance){
    //Imprime balance
    gotoxy(20, 6); cout<<"Balance: "<<balance;
    //espera 6 segundos para borrar el mensaje
    for(int i = 6; i >= 1; i--){
        gotoxy(12, 8); cout<<"Este mensaje desaparecera en "<<i<<"s";
        Sleep(1000);
    }
    system("cls");
}

float depositBalance(float balance, bool *pHaveMoney){
    int choice = 0;
    float aux;

    //opciones de retiro
    gotoxy(20, 6); cout<<"Balance: "<<balance;
    gotoxy(20, 8); cout<<"Monto: ";
    gotoxy(0, 12); cout<<"1.20";
    gotoxy(0, 14); cout<<"2.50";
    gotoxy(45, 12); cout<<"3.100";
    gotoxy(45, 14); cout<<"4.otro";
    gotoxy(25, 16); cout<<">>";
    choice = getche();

    switch (choice){

        case '1':
            balance += 20 - 20*BANK;
            *pHaveMoney = true;
            break;

        case '2':
            balance += 50 - 50*BANK;

            break;

        case '3':
            balance += 100 - 100*BANK;
            *pHaveMoney = true;
            break;
        //en caso de ser otro monto debe especificar un monto a depositar
        case '4':
        //bucle que repite hasta que el usuario ingrese un monto correcto
            do{
                gotoxy(25, 16); cout<<"Monto: ";
                fflush(stdin);
                cin>>aux;
                //aca verificamos que sea un numero mayor que 0
                if(aux <= 0){
                    gotoxy(25, 18); cout<<"Ingrese un monto valido!!";
                }
            }
            //si no es mayor a 0 repite el proceso
            while(aux <= 0);

            //calculamos y restamos comision    
            balance += aux - aux*BANK;
            gotoxy(25, 17); cout<<"Comision: "<<aux*BANK;
            gotoxy(25, 18); cout<<"                             ";
            Sleep(2000);
            *pHaveMoney = true;
            break;
        //si el usuario no ingresa ninguna de las 4 opciones sale este mensaje
        default:
            cout<<"Ingrese una opcion valida";
            Sleep(2000);
            break;
    }
    //borrar pantalla
    system("cls");

    return balance;
}

float withdrawBalance(float balance, bool haveMoney){
    int choice = 0;
    float aux;
    //opciones
    if(!haveMoney){
        cout<<"No tiene dinero en su cuenta!!";
    }
    else{
        gotoxy(20, 6); cout<<"Balance: "<<balance;
        gotoxy(20, 8); cout<<"Monto: ";
        gotoxy(0, 12); cout<<"1.20";
        gotoxy(0, 14); cout<<"2.50";
        gotoxy(45, 12); cout<<"3.100";
        gotoxy(45, 14); cout<<"4.otro";
        gotoxy(25, 16); cout<<">>";
        choice = getche();

        switch(choice){
            case '1':
                if(balance < 20 + 20*BANK){
                    gotoxy(25, 18); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 20 + 20*BANK;
                    gotoxy(25, 17); cout<<"Comision: "<<20*BANK;
                    gotoxy(25, 18); cout<<"                             ";
                }
                break;
            case '2':
                if(balance < (50 + 50*BANK) ){
                    gotoxy(25, 18); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 50 + 50*BANK;
                    gotoxy(25, 17); cout<<"Comision: "<<50*BANK;
                    gotoxy(25, 18); cout<<"                             ";
                }
                break;
            case '3':
                if(balance < 100 + 100*BANK){
                    gotoxy(25, 18); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 100 + 100*BANK;
                    gotoxy(25, 17); cout<<"Comision: "<<100*BANK;
                    gotoxy(25, 18); cout<<"                             ";
                }
                break;

        //igual, cuando es otro monto hay que saber que monto y verificar que sea correcto
            case '4':
                gotoxy(25, 16); cout<<"Monto: ";
                //ciclo para verificar
                do{
                    cin>>aux;
                    //si el monto es mayor que el dinero que tienes da error
                    if(aux + aux*BANK >= balance){
                        gotoxy(25, 18); cout<<"Ingrese un monto valido!!";
                    }
                }
                //esto se repite hasta que se ingrese un monto correcto
                while(aux<=0);
                balance -= aux + aux*BANK;
                gotoxy(25, 17); cout<<"Comision: "<<aux*BANK;
                gotoxy(25, 18); cout<<"                             ";
                break;
            }
        }
  
    //calculo de comision
    Sleep(2000);

    return balance;
}

void drawSquare(int xleft, int xright, int yup, int ydown){
    for (int i = yup; i <= ydown; i++) {
        for (int j = xleft; j <= xright; j++) {
            if (i == yup || i == ydown || j == xleft || j == xright) {
                gotoxy(j, i);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
                cout << " ";
            } 
            else {
                gotoxy(j, i);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
                cout << " ";
                }
            }
        }
}
