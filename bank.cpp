//Jhosmar Suarez
//codigo de un cajero automatico

//debug with g++.exe

//librerias
#include<iostream>
#include<cctype>
#include<conio.h>
#include<windows.h>

using namespace std;

//esta es la comision que se cobra por cada transaccion
#define BANK 0.015
//max de usuarios concurrentes
#define MAX 20

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
void doSquare();
float loggedIn(float Balance[MAX], int index);
void signUp(string cardNumber[MAX], int password[MAX], int registeredUsers, float Balance[MAX]);
int signIn(string cardNumber[MAX], int password[MAX], int registeredUsers, string name[MAX], string id[MAX], string surname[MAX]);
bool checkCardNumber(string cardNumber);
int getDigit(const int number);
int sumOddDigits(const string cardNumber);
int sumEvenDigits(const string cardNumber);
void usersList(string cardNumber[MAX], int password[MAX], string name[MAX], string id[MAX], int registeredUsers, string surname[MAX]);

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

    //bienvenida
    system("cls");
    system("color 1f");
    gotoxy(20, 3); cout<<"*********************************";
    gotoxy(20,4); cout<<"Bienvenido al sistema de cajero!!";
    gotoxy(20,5); cout<<"*********************************";
    Sleep(2000);

    //Seccion de inicializacion
    int choice, stop = false, password[MAX], registeredUsers = 0;
    string cardNumber[MAX], name[MAX], id[MAX], surname[MAX];
    char select;
    float Balance[MAX];

    //Bucle para que todos los balances del vector se inicialicen en 0
    for(int i = 0; i < MAX; i++){
        Balance[i] = 0.00;
    }

    //bucle que mantiene tooodo el programa corriendo
    do{
        //opciones
        gotoxy(26, 9); cout<<"Seleccione una opcion:";
        doSquare();
        gotoxy(6, 13); cout<<"1.Registrarse";
        gotoxy(6, 18); cout<<"2.Iniciar Sesion";
        gotoxy(47, 13); cout<<"3.Lista usuarios";
        gotoxy(56, 18); cout<<"4.Salir";
        gotoxy(36, 20); cout<<">>";
        choice = getche();
        system("cls");
        

        switch(choice)
        {
            case '1':
                registeredUsers = signIn(cardNumber, password, registeredUsers, name, id, surname);
                break;
            case '2':
                signUp(cardNumber, password, registeredUsers, Balance);
                break;
            case '3':
                usersList(cardNumber, password, name, id, registeredUsers, surname);
                break;
            default:
                stop = true;
                break;
        }
        if(!stop){
            cout<<"\nDesea realizar otra transaccion? (s/n): ";
            select = toupper(getch());
        }
        else{
            select = 'N';
        }
        
     }
    while(select != 'N');
    return 0;
}

int signIn(string cardNumber[MAX], int password[MAX], int registeredUsers, string name[MAX], string id[MAX], string surname[MAX]){

    int aux;
    
    cout<<"Nombre: ";
    cin>>name[registeredUsers];
    cout<<"Apellido: ";
    cin>>surname[registeredUsers];
    cout<<"Cedula: ";
    cin>>id[registeredUsers];
    cout<<"Numero de tarjeta (Sin espacios): ";
    cin>>cardNumber[registeredUsers];
    if(checkCardNumber(cardNumber[registeredUsers]) == true){
        cout<<"Valid"<<endl;
        cout<<"Contrasena (4 digitos): ";
        cin>>password[registeredUsers];
        cout<<"Verificar contrasena: ";
        cin>>aux;
        if(password[registeredUsers] == aux){
            cout<<"\nRegistro efectuado exitosamente";
            registeredUsers++;
        }
        else{
            cout<<"\ncontrasena incorrecta";
            password[registeredUsers] == 0;
            cardNumber[registeredUsers] = " ";
            name[registeredUsers] = " ";
            surname[registeredUsers] = " ";
            id[registeredUsers] = " ";
        }
    }
    else{
        cout<<"Not valid";
        password[registeredUsers] == 0;
        cardNumber[registeredUsers] = " ";
        name[registeredUsers] = " ";
        surname[registeredUsers] = " ";
        id[registeredUsers] = " ";
    }
    

    return registeredUsers;
}

void signUp(string cardNumber[MAX], int password[MAX], int registeredUsers, float Balance[MAX]){

    string auxcard;
    bool correct = false;
    int index, auxpass;

    cout<<"Numero de tarjeta (sin espacios): ";
    cin>>auxcard;
    for(int i = 0; i <= registeredUsers; i++){
        if(auxcard.compare(cardNumber[i])){
            index = i-1;
            correct = true;
        }
    }
    if(correct){
        cout<<"Contrasena: ";
        cin>>auxpass;
        if(auxpass == password[index]){
            cout<<"Ingreso exitoso!";
            Sleep(1000);
            system("cls");
            Balance[index] = loggedIn(Balance, index);
        }
        else{
            cout<<"Contrasena incorrecta!";
            Sleep(1000);
        }
    }
    else{
        cout<<"Numero incorrecto!";
        Sleep(1000);
    }
}

float loggedIn(float Balance[MAX], int index){
    //seccion de incializacion
    bool stop, haveMoney = false;
    int choice;
    float balance = Balance[index], aux;

     do
    {
        //opciones
        gotoxy(26, 9); cout<<"Seleccione una opcion:";
        doSquare();
        gotoxy(6, 13); cout<<"1.Revisar balance";
        gotoxy(6, 18); cout<<"2.Depositar";
        gotoxy(54, 13); cout<<"3.Retirar";
        gotoxy(56, 18); cout<<"4.Salir";
        gotoxy(36, 20); cout<<">>";
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
    return balance;
}

bool checkCardNumber(string cardNumber){
    string Mariano;
    int result = 0;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    return(result % 10 == 0)? true : false;
    
}

//imprime tabla de usuarios
void usersList(string cardNumber[MAX], int password[MAX], string name[MAX], string id[MAX], int registeredUsers, string surname[MAX]){
    system("cls");
    gotoxy(23, 1); cout<<"Listado de usuarios";
    gotoxy(0, 3); cout<<"#";
    gotoxy(3, 3); cout<<"Nombre";
    gotoxy(13,3); cout<<"Apellido";
    gotoxy(25, 3); cout<<"Numero de tarjeta";
    gotoxy(44, 3); cout<<"Cedula";
    gotoxy(54, 3); cout<<"Contrasena";
    for(int i = 0; i<registeredUsers; i++){
        gotoxy(0, i+4); cout<<i+1;
        gotoxy(3,i+4); cout<<name[i];
        gotoxy(13, i+4); cout<<surname[i];
        gotoxy(25, i+4); cout<<cardNumber[i];
        gotoxy(44, i+4); cout<<id[i];
        gotoxy(54, i+4); cout<<password[i];
    }
}

int getDigit(const int number){

    return number % 10 + (number / 10 % 10);
}
int sumOddDigits(const string cardNumber){

    int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i-=2){
        sum += cardNumber[i] - '0';
    }

    return sum;
}
int sumEvenDigits(const string cardNumber){

    int sum = 0;

    for(int i = cardNumber.size() - 2; i >= 0; i-=2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
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
    gotoxy(30, 6); cout<<"Balance: "<<balance;
    gotoxy(34, 8); cout<<"Monto: ";
    doSquare();
    gotoxy(6, 13); cout<<"1.20";
    gotoxy(6, 18); cout<<"2.50";
    gotoxy(58, 13); cout<<"3.100";
    gotoxy(57, 18); cout<<"4.otro";
    gotoxy(36, 20); cout<<">>";
    choice = getche();

    switch (choice){

        case '1':
            balance += 20 - 20*BANK;
            *pHaveMoney = true;
            aux = 20;
            break;

        case '2':
            balance += 50 - 50*BANK;
            *pHaveMoney = true;
            aux = 50;
            break;

        case '3':
            balance += 100 - 100*BANK;
            *pHaveMoney = true;
            aux = 100;
            break;
        //en caso de ser otro monto debe especificar un monto a depositar
        case '4':
        //bucle que repite hasta que el usuario ingrese un monto correcto
            do{
                gotoxy(25, 20); cout<<"Monto: ";
                fflush(stdin);
                cin>>aux;
                //aca verificamos que sea un numero mayor que 0
                if(aux <= 0){
                    gotoxy(25, 22); cout<<"Ingrese un monto valido!!";
                }
            }
            //si no es mayor a 0 repite el proceso
            while(aux <= 0);

            //calculamos y restamos comision    
            balance += aux - aux*BANK;
            *pHaveMoney = true;
            break;
        //si el usuario no ingresa ninguna de las 4 opciones sale este mensaje
        default:
            cout<<"Ingrese una opcion valida";
            break;
    }
    gotoxy(25, 21); cout<<"Comision: "<<aux*BANK;
    gotoxy(25, 22); cout<<"                             ";
    Sleep(2000);
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
        gotoxy(30, 6); cout<<"Balance: "<<balance;
        gotoxy(34, 8); cout<<"Monto: ";
        doSquare();
        gotoxy(6, 13); cout<<"1.20";
        gotoxy(6, 18); cout<<"2.50";
        gotoxy(58, 13); cout<<"3.100";
        gotoxy(57, 18); cout<<"4.otro";
        gotoxy(36, 20); cout<<">>";
        choice = getche();

        switch(choice){
            case '1':
                if(balance < 20 + 20*BANK){
                    gotoxy(30, 22); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 20 + 20*BANK;
                    gotoxy(30, 21); cout<<"Comision: "<<20*BANK;
                    gotoxy(30, 22); cout<<"                             ";
                }
                break;
            case '2':
                if(balance < (50 + 50*BANK) ){
                    gotoxy(30, 22); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 50 + 50*BANK;
                    gotoxy(30, 21); cout<<"Comision: "<<50*BANK;
                    gotoxy(30, 22); cout<<"                             ";
                }
                break;
            case '3':
                if(balance < 100 + 100*BANK){
                    gotoxy(30, 22); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 100 + 100*BANK;
                    gotoxy(30, 21); cout<<"Comision: "<<100*BANK;
                    gotoxy(30, 22); cout<<"                             ";
                }
                break;

        //igual, cuando es otro monto hay que saber que monto y verificar que sea correcto
            case '4':
                gotoxy(30, 21); cout<<"Monto: ";
                //ciclo para verificar
                do{
                    cin>>aux;
                    //si el monto es mayor que el dinero que tienes da error
                    if(aux + aux*BANK >= balance){
                        gotoxy(30, 23); cout<<"Ingrese un monto valido!!";
                    }
                }
                //esto se repite hasta que se ingrese un monto correcto
                while(aux<=0);
                balance -= aux + aux*BANK;
                gotoxy(30, 22); cout<<"Comision: "<<aux*BANK;
                gotoxy(30, 23); cout<<"                             ";
                break;
            }
        }
  
    //calculo de comision
    Sleep(2000);
    system("cls");

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

void doSquare(){
    //Boton superior izquierdo
    drawSquare(0, 5, 12, 14);
    //Boton superior derecho
    drawSquare(63, 69, 12, 14);
    //Boton inferior izquierdo
    drawSquare(0, 5, 17, 19);
    //Boton inferior derecho
    drawSquare(63, 69, 17, 19);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

}
