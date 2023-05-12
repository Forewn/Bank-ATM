//Jhosmar Suarez
//codigo de un cajero automatico

//debug with gdb.exe

//librerias
#include<iostream>
#include<cctype>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

//esta es la comision que se cobra por cada transaccion
#define BANK 0.015
//max de usuarios concurrentes
#define MAX 20

typedef struct{
    float Balance;
    bool haveMoney;
}accountData;

typedef struct{
    accountData aData;
    string name, password, cardNumber, id, surname;
}userData[MAX];

typedef struct{
    int registeredUsers = 0, dpUsers, WdUsers, ChUsers;
    float Comision = 0;
}bankStats;

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
float loggedIn(userData user[], int index);
void signUp(int registeredUsers, userData user[]);
int signIn(int registeredUsers, userData user[]);
bool checkCardNumber(string cardNumber);
int getDigit(const int number);
int sumOddDigits(const string cardNumber);
int sumEvenDigits(const string cardNumber);
void usersList(int registeredUsers, userData user[MAX]);
void printStats(bankStats bank);


//funcion principal
int main(){
    //tamano de pantalla y cositas, no mires esto
    HWND console = GetConsoleWindow(), hwnd = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 665, 500, TRUE);
    HMENU hMenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
    EnableMenuItem(hMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_GRAYED);

    //bienvenida
    system("cls");
    system("color 1f");
    gotoxy(23, 3); cout<<"*********************************";
    gotoxy(23,4); cout<<"Bienvenido al sistema de cajero!!";
    gotoxy(23,5); cout<<"*********************************";
    Sleep(2000);

    //Seccion de inicializacion
    userData user[MAX];
    bankStats bank;
    int choice, registeredUsers = 0;
    char select;
    bool stop = false;
    float comision = 0;

    //bucle que mantiene tooodo el programa corriendo
    do{
        //opciones
        gotoxy(28, 9); cout<<"Seleccione una opcion:";
        doSquare();
        gotoxy(6, 13); cout<<"1.Registrarse";
        gotoxy(6, 18); cout<<"2.Iniciar Sesion";
        gotoxy(56, 13); cout<<"3.Lista usuarios";
        gotoxy(65, 18); cout<<"4.Salir";
        gotoxy(38, 20); cout<<">>";
        choice = getche();
        system("cls");
        

        switch(choice)
        {
            case '1':
                registeredUsers = signIn(registeredUsers, user);
                break;
            case '2':
                if(registeredUsers > 0){
                    signUp(registeredUsers, user);
                }
                else{
                    cout<<"Nadie ha sido registrado aun!!";
                }
                
                break;
            case '3':
                usersList(registeredUsers, user);
                break;
            case '4':
                stop = true;
                break;
            case '0':
                bank.registeredUsers = registeredUsers;
                bank.Comision = comision;
                printStats(bank);
                break;
            default:
                gotoxy(30,10); cout<<"Ingrese una opcion valida!";
                Sleep(500);
                system("cls");
                break;
        }
        if(!stop){
            cout<<"\n\nDesea realizar otra transaccion? (s/n): ";
            select = toupper(getch());
            system("cls");
        }
        else{
            select = 'N';
        }
        
     }
    while(select != 'N');
    return 0;
}

int signIn(int registeredUsers, userData user[]){
    string aux;
    bool error = false;
    cout<<"Nombre: ";
    cin>>user[registeredUsers]->name;
    //funcion para convertir un string en mayusculas
    transform(user[registeredUsers]->name.begin(), user[registeredUsers]->name.end(), user[registeredUsers]->name.begin(), ::toupper);
    cout<<"Apellido: ";
    cin>>user[registeredUsers]->surname;
    transform(user[registeredUsers]->surname.begin(), user[registeredUsers]->surname.end(), user[registeredUsers]->surname.begin(), ::toupper);
    cout<<"Cedula: ";
    cin>>user[registeredUsers]->id;
    cout<<"Numero de tarjeta (Sin espacios): ";
    cin>>user[registeredUsers]->cardNumber;
    if((checkCardNumber(user[registeredUsers]->cardNumber) == true) && user[registeredUsers]->cardNumber != "0"){
        cout<<"Numero Valido"<<endl;
        cout<<"Contrasena (4 digitos): ";
        cin>>user[registeredUsers]->password;
        if(user[registeredUsers]->password.length() == 4){
            for(int i = 0; i < 4; i++){
                if(!isdigit(user[registeredUsers]->password.at(i))){
                    error = true;
                }
            
            }
            if(!error){
                cout<<"Verificar contrasena: ";
                cin>>aux;
                if(!user[registeredUsers]->password.compare(aux)){
                    cout<<"\nRegistro efectuado exitosamente";
                    registeredUsers++;
                }
                else{
                    cout<<"\ncontrasena incorrecta";
                    //password[registeredUsers] == 0;
                    user[registeredUsers]->cardNumber = " ";
                    user[registeredUsers]->name = " ";
                    user[registeredUsers]->surname = " ";
                    user[registeredUsers]->id = " ";
                }
            }
            else{
                cout<<"\nLa contrasena solo puede contener digitos numericos";
                //password[registeredUsers] == 0;
                user[registeredUsers]->cardNumber = " ";
                user[registeredUsers]->name = " ";
                user[registeredUsers]->surname = " ";
                user[registeredUsers]->id = " ";
            }
            
        }
        else if(user[registeredUsers]->password.length() < 4){
            cout<<"\nDemasiado corta!!";
            //password[registeredUsers] == 0;
            user[registeredUsers]->cardNumber = " ";
            user[registeredUsers]->name = " ";
            user[registeredUsers]->surname = " ";
            user[registeredUsers]->id = " ";
        }
        else if(user[registeredUsers]->password.length() > 4){
            cout<<"\ndemasiado larga!!";
            //password[registeredUsers] == 0;
            user[registeredUsers]->cardNumber = " ";
            user[registeredUsers]->name = " ";
            user[registeredUsers]->surname = " ";
            user[registeredUsers]->id = " ";
        }
    }
    else{
        cout<<"Numero invalido";
        //password[registeredUsers] == 0;
        user[registeredUsers]->cardNumber = " ";
        user[registeredUsers]->name = " ";
        user[registeredUsers]->surname = " ";
        user[registeredUsers]->id = " ";
    }
    

    return registeredUsers;
}

void signUp(int registeredUsers, userData user[]){

    string auxcard, auxpass = "0";
    bool correct = false;
    int index = 0;

    cout<<"Numero de tarjeta (sin espacios): ";
    cin>>auxcard;
    if(!auxcard.compare("0")){
        cout<<"Numero invalido!";
        Sleep(1000);
        correct = false;
    }
    else{
        for(int i = 0; i < registeredUsers; i++){
            if(auxcard.compare(user[i]->cardNumber) == 0){
                index = i;
                correct = true;
            }
            else if(correct != true && (auxcard.compare(user[i]->cardNumber))){
                correct = false;
            }
        }
    string aux2 = user[index]->password;
    if(correct){
        cout<<"Contrasena: ";
        cin>>auxpass;
        if(!auxpass.compare(aux2)){
            if(auxpass.compare("0")){
                cout<<"Ingreso exitoso!";
                Sleep(1000);
                system("cls");
                user[index]->aData.Balance = loggedIn(user, index);
                }
                else{
                    cout<<"Contrasena incorrecta!";
                    Sleep(1000);
                }
            }
            else{
            cout<<"Contrasena incorrecta!";
            Sleep(1000);
            }
        }
    else{
        cout<<"Ese numero no se encuentra registrado!";
        Sleep(1000);
        
        }
    }

    
}

float loggedIn(userData user[], int index){
    //seccion de incializacion
    bool stop;
    int choice;
    float balance = user[index]->aData.Balance , aux;

    if(user[index]->aData.Balance > 0){
        user[index]->aData.haveMoney = true;
    }
    else{
        user[index]->aData.haveMoney = false;
    }

     do
    {
        //opciones
        gotoxy(28, 9); cout<<"Seleccione una opcion:";
        doSquare();
        gotoxy(6, 13); cout<<"1.Revisar balance";
        gotoxy(6, 18); cout<<"2.Depositar";
        gotoxy(63, 13); cout<<"3.Retirar";
        gotoxy(65, 18); cout<<"4.Salir";
        gotoxy(38, 20); cout<<">>";
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
                balance = depositBalance(balance, &user[index]->aData.haveMoney);
                break;
            //funcion retirar balance
            case '3':
                balance = withdrawBalance(balance, user[index]->aData.haveMoney);
                break;
            //salir
            case '4':
                stop = true;
                break;
            default:
                gotoxy(30,10); cout<<"Ingrese una opcion valida!";
                Sleep(500);
                system("cls");
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
void usersList(int registeredUsers, userData user[MAX]){
    system("cls");
    gotoxy(23, 1); cout<<"Listado de usuarios";
    gotoxy(0, 3); cout<<"#";
    gotoxy(3, 3); cout<<"Nombre";
    gotoxy(13,3); cout<<"Apellido";
    gotoxy(25, 3); cout<<"Numero de tarjeta";
    gotoxy(46, 3); cout<<"Cedula";
    gotoxy(56, 3); cout<<"Contrasena";
    gotoxy(70, 3); cout<<"Balance";
    for(int i = 0; i<registeredUsers; i++){
        gotoxy(0, i+4); cout<<i+1;
        gotoxy(3,i+4); cout<<user[i]->name;
        gotoxy(13, i+4); cout<<user[i]->surname;
        gotoxy(25, i+4); cout<<user[i]->cardNumber;
        gotoxy(46, i+4); cout<<user[i]->id;
        gotoxy(56, i+4); cout<<user[i]->password;
        gotoxy(70, i+4); cout<<setprecision(2)<<fixed<<user[i]->aData.Balance;
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
    gotoxy(32, 6); cout<<"Balance: "<<setprecision(2)<<fixed<<balance;
    //espera 6 segundos para borrar el mensaje
    for(int i = 6; i >= 1; i--){
        gotoxy(24, 8); cout<<"Este mensaje desaparecera en "<<i<<"s";
        Sleep(1000);
    }
    system("cls");
}

float depositBalance(float balance, bool *pHaveMoney){
    bankStats bank;
    int choice = 0;
    float aux;

    //opciones de retiro
    gotoxy(32, 6); cout<<"Balance: "<<setprecision(2)<<fixed<<balance;
    gotoxy(34, 8); cout<<"Monto: ";
    doSquare();
    gotoxy(6, 13); cout<<"1.20";
    gotoxy(6, 18); cout<<"2.50";
    gotoxy(67, 13); cout<<"3.100";
    gotoxy(66, 18); cout<<"4.otro";
    gotoxy(38, 20); cout<<">>";
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
                gotoxy(32, 21); cout<<"Monto: ";
                fflush(stdin);
                cin>>aux;
                //aca verificamos que sea un numero mayor que 0
                if(aux <= 0){
                    gotoxy(28, 23); cout<<"Ingrese un monto valido!!";
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
    gotoxy(32, 22); cout<<"Comision: "<<setprecision(2)<<fixed<<aux*BANK;
    gotoxy(28, 23); cout<<"                             ";
    if(aux > 0){
        bank.Comision += aux*BANK;
    }
    Sleep(2000);
    //borrar pantalla
    system("cls");

    return balance;
}

float withdrawBalance(float balance, bool haveMoney){
    bankStats bank;
    int choice = 0;
    float aux;
    //opciones
    if(!haveMoney){
        cout<<"No tiene dinero en su cuenta!!";
    }
    else{
        gotoxy(32, 6); cout<<"Balance: "<<setprecision(2)<<fixed<<balance;
        gotoxy(34, 8); cout<<"Monto: ";
        doSquare();
        gotoxy(6, 13); cout<<"1.20";
        gotoxy(6, 18); cout<<"2.50";
        gotoxy(67, 13); cout<<"3.100";
        gotoxy(66, 18); cout<<"4.otro";
        gotoxy(38, 20); cout<<">>";
        choice = getche();

        switch(choice){
            case '1':
                if(balance < 20 + 20*BANK){
                    gotoxy(32, 22); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 20 + 20*BANK;
                    gotoxy(34, 21); cout<<"Comision: "<<setprecision(2)<<fixed<<20*BANK;
                    gotoxy(32, 22); cout<<"                             ";
                    bank.Comision += aux*BANK;
                }
                break;
            case '2':
                if(balance < (50 + 50*BANK) ){
                    gotoxy(32, 22); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 50 + 50*BANK;
                    gotoxy(34, 21); cout<<"Comision: "<<setprecision(2)<<fixed<<50*BANK;
                    gotoxy(32, 22); cout<<"                             ";
                    bank.Comision += aux*BANK;
                }
                break;
            case '3':
                if(balance < 100 + 100*BANK){
                    gotoxy(32, 22); cout<<"Fondos insuficientes!!";
                }
                else{
                    balance -= 100 + 100*BANK;
                    gotoxy(34, 21); cout<<"Comision: "<<setprecision(2)<<fixed<<100*BANK;
                    gotoxy(32, 22); cout<<"                             ";
                    bank.Comision += aux*BANK;
                }
                break;

        //igual, cuando es otro monto hay que saber que monto y verificar que sea correcto
            case '4':
                gotoxy(36, 21); cout<<"Monto: ";
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
                bank.Comision += aux*BANK;
                gotoxy(34, 22); cout<<"Comision: "<<setprecision(2)<<fixed<<aux*BANK;
                gotoxy(32, 23); cout<<"                             ";
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
    drawSquare(72, 78, 12, 14);
    //Boton inferior izquierdo
    drawSquare(0, 5, 17, 19);
    //Boton inferior derecho
    drawSquare(72, 78, 17, 19);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

}

void printStats(bankStats bank){
    system("cls");
    gotoxy(3, 3); cout<<"Usuarios registraddos";
    gotoxy(3,5); cout<<bank.registeredUsers;
    gotoxy(20,3); cout<<"Comision acumulada";
    gotoxy(20,5); cout<<bank.Comision;
}