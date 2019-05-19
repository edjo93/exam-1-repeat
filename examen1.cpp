//intento de examen 1 programacion 3
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

//no objects
//prototipos
bool tomar_correcta(char**,int,int,char);
char** provisionar_matriz(int);
void imprimir_matriz(char**,int);
void liberar_matriz(char**,int);
void crear_tablero(char**,int );
void mover(char**matriz,int xi,int yi,int xf,int yf,char pieza);
//menu repetitivo
int main(){
    char opcion;
    int x;
    int y;
    int size=11;
    char** matriz=NULL;
    do{
    
    cout<<"\nseleccione una opcion\n\n1.op1\ns.salir\n?:";
    cin>>opcion;

    switch(opcion){
        case '1':
            
            //obtenemos una matriz char
            matriz=provisionar_matriz(size);
            //creamos el tablero
            crear_tablero(matriz,size);
            //mostramos el tablero
            imprimir_matriz(matriz,size);
            cout<<"ingrese x:";
            cin>>x;
            cout<<"ingrese y:";
            cin>>y;
            
            //primer turno
            while(!tomar_correcta(matriz,x,y,'n')){//mientras no tomemos una pieza correcta para el turno
                //continuamos pidiendo que se tome una pieza correcta
                cout<<"\nno se ha tomado una pieza correta intente de nuevo\n";
                cout<<"ingrese x:";
                cin>>x;
                cout<<"ingrese y:";
                cin>>y;
                tomar_correcta(matriz,x,y,'n');
            }
            imprimir_matriz(matriz,size);
            int xf;
            int yf;
            cout<<"ingrese xf:";
            cin>>xf;
            cout<<"ingrese yf:";
            cin>>yf;
            mover(matriz,x,y,xf,yf,'n');
            imprimir_matriz(matriz,size);

            //liberamos la matriz
            liberar_matriz(matriz,size);


            break;
        case 's':
            cout<<"hasta luego\n";
            break;
        default:cout<<"\nno ingreso una opcion corrrecta intente de nuevo";
    }

    
    }while(opcion!='s');
    return 0;
}


//funcion que selecciona una pieza
bool tomar_correcta(char**matriz,int x,int y,char pieza){
    return matriz[x][y]==pieza;

}
char** provisionar_matriz(int size){
	char**matriz=NULL;

	matriz=new char*[size];//reservando memoria lara las filas

	for(int i=0;i<size;i++){
		matriz[i]=new char[size];//reservando memoria para las columnas
	}

	return matriz;
}
void imprimir_matriz(char** matriz,int size){
	cout<<endl;
    for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
}
void liberar_matriz(char** matriz,int size){
	for(int i=0;i<size;i++){
		if(matriz[i]!=NULL){
			delete[] matriz[i];
			matriz[i]=NULL;

		}
	}	
	


	if(matriz!=NULL){
		delete[] matriz;
		matriz=NULL;
	}
}

void crear_tablero(char**matriz,int size){
    //se crea una matriz de 11*11
       
	//llenar con espacios vacios
        
    for(int x=0;x<size;x++){
            for(int y=0;y<size;y++){
                    matriz[x][y]=' ';
                    
            }
            
    }
    
    //recorremos la matriz y vamos a ir poniendo piezas segun sea el caso
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            if(y==0||y==size-1){
                matriz[size/2][y]='n';
                matriz[(size/2)+1][y]='n';
                matriz[(size/2)-1][y]='n';
            }
                    
            if(x==0||x==size-1){
                matriz[x][size/2]='n';
                matriz[x][(size/2)+1]='n';
                matriz[x][(size/2)-1]='n';
            }
        
            if(y==1||y==size-2){
                //matriz[size/2][y]='n';
                matriz[(size/2)+1][y]='n';
                matriz[(size/2)-1][y]='n';
            }
                    
            if(x==1||x==size-2){
                //matriz[x][size/2]='n';
                matriz[x][(size/2)+1]='n';
                matriz[x][(size/2)-1]='n';
            }
        
            if(y==2||y==size-3){
                matriz[size/2][y]='n';
                //matriz[(size/2)+1][y]='n';
                //matriz[(size/2)-1][y]='n';
            }
                    
            if(x==2||x==size-3){
                matriz[x][size/2]='n';
                //matriz[x][(size/2)+1]='n';
                //matriz[x][(size/2)-1]='n';
            }
        
            if(y==3||y==size-4){
                matriz[size/2][y]='b';
                //matriz[(size/2)+1][y]='n';
                //matriz[(size/2)-1][y]='n';
            }
                    
            if(x==3||x==size-4){
                matriz[x][size/2]='b';
                //matriz[x][(size/2)+1]='n';
                //matriz[x][(size/2)-1]='n';
            }
        
            if(y==4||y==size-5){
                matriz[size/2][y]='b';
                matriz[(size/2)+1][y]='b';
                matriz[(size/2)-1][y]='b';
            }
                    
            if(x==4||x==size-5){
                matriz[x][size/2]='b';
                matriz[x][(size/2)+1]='b';
                matriz[x][(size/2)-1]='b';
            }
        
            if(x==size/2&&y==size/2){
                matriz[x][y]='w';
            }
        
            //marcar las ezquinas
        
            if(x==0&&y==0){
                matriz[x][y]='x';
                        
            }
            
            if(x==0&&y==size-1){
                matriz[x][y]='x';
                    
            }
            if(x==size-1&&y==0){
                matriz[x][y]='x';
                    
            }
            if(x==size-1&&y==size-1){
                matriz[x][y]='x';
                    
            }
                        
        }
                
    }
        
}

void mover(char**matriz,int xi,int yi,int xf,int yf,char pieza){
    if (xi==xf){//el movimiento sera en la fila
        matriz[xi][yi]=' ';//la pieza se movio de ese sitio
        matriz[xf][yf]=pieza;//la pieza se movio a este sitio
    }else{
        if (yi==yf){//el movimiento sera en la columna
        matriz[xi][yi]=' ';//la pieza se movio de ese sitio
        matriz[xf][yf]=pieza;//la pieza se movio a este sitio
        }else{
            cout<<"\nel movimiento debe ser como el de la torre en ajedrez intente de nuevo";
        }
    }
    


}