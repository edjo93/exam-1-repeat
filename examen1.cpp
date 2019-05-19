//intento de examen 1 programacion 3
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

//no objects

//menu repetitivo
int main(){
    char opcion;
    do{
    
    cout<<"\nseleccione una opcion\n\n1.op1\ns.salir\n?:";
    cin>>opcion;

    switch(opcion){
        case '1':
               
        break;
        case 's':
            cout<<"hasta luego\n";
        break;
        default:cout<<"no ingreso una opcion corrrecta intente de nuevo";
    }

    
    }while(opcion!='s');
    return 0;
}


