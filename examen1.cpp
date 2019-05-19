//intento de examen 1 programacion 3
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

//no objects
//prototipos
bool tomar_correcta(char**matriz,int x,int y,char pieza);
//menu repetitivo
int main(){
    char opcion;
    int x;
    int y;
    do{
    
    cout<<"\nseleccione una opcion\n\n1.op1\ns.salir\n?:";
    cin>>opcion;

    switch(opcion){
        case '1':
            //suponemos tener datos
            x=0;
            y=0;

            //primer turno
            while(!tomar_correcta(matriz,x,y,'n')){//mientras no tomemos una pieza correcta para el turno
                //continuamos pidiendo que se tome una pieza correcta
                cout<<"no se ha tomado una pieza correta intente de nuevo";
                tomar_correcta(matriz,x,y,'n');
            }



            break;
        case 's':
            cout<<"hasta luego\n";
            break;
        default:cout<<"no ingreso una opcion corrrecta intente de nuevo";
    }

    
    }while(opcion!='s');
    return 0;
}


//funcion que selecciona una pieza
bool tomar_correcta(char**matriz,int x,int y,char pieza){
    return matriz[x][y]==pieza;

}
