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
bool gano_rey(char**matriz,int size);
bool ganan_moskovitas(char**matriz,int size);
void captura_guardianes(char**,int);
void colocar_x(char**matriz,int size);
//menu repetitivo
int main(){
    char opcion;
    int x;
    int y;
    int size=11;
    char** matriz=NULL;
    char sueco;//leemos si se movera el rey o una pieza comun
    int xf;
    int yf;
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
            cout<<"tablero listo";
            
            
            
            while(!gano_rey(matriz,size)&&!ganan_moskovitas(matriz,size)){//mientras no gane el rey ni tampoco los moskovitas el juego continua
                cout<<"\njuegan moskovitas"<<endl;
                //primer turno
                imprimir_matriz(matriz,size);
                cout<<"ingrese xi:";
                cin>>x;
                cout<<"ingrese yi:";
                cin>>y;
                while(!tomar_correcta(matriz,x,y,'n')){//mientras no tomemos una pieza correcta para el turno
                    //continuamos pidiendo que se tome una pieza correcta
                    cout<<"\nno se ha tomado una pieza correcta intente de nuevo\n";
                    imprimir_matriz(matriz,size);
                    cout<<"ingrese x:";
                    cin>>x;
                    cout<<"ingrese y:";
                    cin>>y;
                    tomar_correcta(matriz,x,y,'n');
                }
                cout<<"ingrese xf:";
                cin>>xf;
                cout<<"ingrese yf:";
                cin>>yf;
                
                //los moskovitas se mueven
                mover(matriz,x,y,xf,yf,'n');
                imprimir_matriz(matriz,size);
                //se verifica si el rey gano
                captura_guardianes(matriz,size);
                colocar_x(matriz,size);
                gano_rey(matriz,size);
                ganan_moskovitas(matriz,size);
                
                

                if(!gano_rey(matriz,size)&&!ganan_moskovitas(matriz,size)){//si el rey no ha ganado la siguiente jugada continua y tampoco los moskovitas
                    cout<<"\nturno de los suecos\nw-mover rey\nb-pieza comun\n?:";
                    cin>>sueco;
                    while(sueco!='w'&&sueco!='b'){//mientras no se elija correctamente una pieza comun o un rey continuamos pidiendo la pieza
                        cout<<"\nturno de los suecos\nr-mover rey\nc-pieza comun\n?:";
                        cin>>sueco;

                    }
                    cout<<"ingrese x:";
                    cin>>x;
                    cout<<"ingrese y:";
                    cin>>y;
                    //segundo turno
                    while(!tomar_correcta(matriz,x,y,sueco)){//mientras no tomemos una pieza correcta para el turno
                        //continuamos pidiendo que se tome una pieza correcta
                        cout<<"\nno se ha tomado una pieza correcta intente de nuevo\n";
                        imprimir_matriz(matriz,size);
                        cout<<"ingrese x:";
                        cin>>x;
                        cout<<"ingrese y:";
                        cin>>y;
                        tomar_correcta(matriz,x,y,sueco);
                    }
                    imprimir_matriz(matriz,size);
                    
                    cout<<"ingrese xf:";
                    cin>>xf;
                    cout<<"ingrese yf:";
                    cin>>yf;
                    //los moskovitas se mueven
                    mover(matriz,x,y,xf,yf,sueco);
                    imprimir_matriz(matriz,size);
                    captura_guardianes(matriz,size);
                    colocar_x(matriz,size);
                    gano_rey(matriz,size);
                    ganan_moskovitas(matriz,size);

                }
                

            }


            


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
    bool haypieza=false;
    bool es_x=false;
    if(pieza!='w'){//juegan las piezas comunes
        
        if (xi==xf){//el movimiento sera en la fila
            //validamos que no se pueda saltar piezas
            if(yi<yf){
                for(int i=yi+1;i<=yf;i++){
                    if(matriz[xi][i]!=' '&&matriz[xi][i]!='x'){
                        haypieza=true;
                    }

                }
            }else{
                for(int i=yi-1;i>=yf;i--){
                    if(matriz[xi][i]!=' '&&matriz[xi][i]!='x'){
                        haypieza=true;
                    }

                }
            }
            

            if(!haypieza){//el movimiento se puede hacer si no hay pieza en el camino
                //la casilla destino es x
                if(matriz[xf][yf]=='x'){
                    es_x=true;
                }



                if(!es_x){//no es x la casilla destino
                    matriz[xi][yi]=' ';//la pieza se movio de ese sitio
                    matriz[xf][yf]=pieza;//la pieza se movio a este sitio

                }else{  
                    cout<<"\nlas piezas comunes no pueden tocar la casilla x";

                }
                
                
            }else{

                cout<<"\nno se puede saltar sobre piezas intente de nuevo";
            }
        
        
        }else{
            if (yi==yf){//el movimiento sera en la columna
                if(xi<xf){
                    for(int i=xi+1;i<=xf;i++){
                        if(matriz[i][yi]!=' '&&matriz[i][yi]!='x'){
                            haypieza=true;
                        }

                    }
                }else{
                    for(int i=xi-1;i>=xf;i--){
                        if(matriz[i][yi]!=' '&&matriz[i][yi]!='x'){
                            haypieza=true;
                        }

                    }
                }
                
                
                if(!haypieza){//el movimiento se puede hacer si no hay pieza en el camino
                    //la casilla destino es x
                    if(matriz[xf][yf]=='x'){
                        es_x=true;
                    }

                    if(!es_x){//no es x la casilla destino
                        matriz[xi][yi]=' ';//la pieza se movio de ese sitio
                        matriz[xf][yf]=pieza;//la pieza se movio a este sitio

                    }else{  
                        cout<<"\nlas piezas comunes no pueden tocar la casilla x";

                    }
                }else{

                    cout<<"\nno se puede saltar sobre piezas intente de nuevo";
                }
            
            }else{
                cout<<"\nel movimiento debe ser como el de la torre en ajedrez intente de nuevo";
            }

        }

    }else{//mismo movimiento con diferente restriccion
        if (xi==xf){//el movimiento sera en la fila
            //validamos que no se pueda saltar piezas
            if(yi<yf){
                for(int i=yi+1;i<=yf;i++){
                    if(matriz[xi][i]!=' '&&matriz[xi][i]!='x'){
                        haypieza=true;
                    }

                }
            }else{
                for(int i=yi-1;i>=yf;i--){
                    if(matriz[xi][i]!=' '&&matriz[xi][i]!='x'){
                        haypieza=true;
                    }

                }
            }


            if(!haypieza){//el movimiento se puede hacer si no hay pieza en el camino
                matriz[xi][yi]=' ';//la pieza se movio de ese sitio
                matriz[xf][yf]=pieza;//la pieza se movio a este sitio
            }else{

                cout<<"\nno se puede saltar sobre piezas intente de nuevo";
            }

        
        }else{
            if (yi==yf){//el movimiento sera en la columna
                if(xi<xf){
                    for(int i=xi+1;i<=xf;i++){
                        if(matriz[i][yi]!=' '&&matriz[i][yi]!='x'){
                            haypieza=true;
                        }

                    }
                }else{
                    for(int i=xi-1;i>=xf;i--){
                        if(matriz[i][yi]!=' '&&matriz[i][yi]!='x'){
                            haypieza=true;
                        }

                    }
                }


                if(!haypieza){//el movimiento se puede hacer si no hay pieza en el camino
                    matriz[xi][yi]=' ';//la pieza se movio de ese sitio
                    matriz[xf][yf]=pieza;//la pieza se movio a este sitio    
                }else{

                    cout<<"\nno se puede saltar sobre piezas intente de nuevo";
                }
            
            }else{
                cout<<"\nel movimiento debe ser como el de la torre en ajedrez intente de nuevo";
            }

        }

    }

    
    


}

bool gano_rey(char**matriz,int size){
    bool gano=false;//el rey no es ganador
    //el rey gana cuando llega a una x
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            //se revisan todas las esquinas
            if(matriz[0][0]=='w'){
                gano=true;

            }
            if(matriz[0][size-1]=='w'){
                gano=true;
                
            }
            if(matriz[size-1][0]=='w'){
                gano=true;
                
            }
            if(matriz[size-1][size-1]=='w'){
                gano=true;
                
            }
        }
    }
    return gano;

}

void captura_guardianes(char**matriz,int size){
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            if(matriz[x][y]=='n'){//verificamos que no hayan rodeado a un moscovita
                //evitamos salir de la matriz

                //casilla valida(columna)
                if(x-1>=0&&x+1<=size-1){
                    if(matriz[x-1][y]=='b'&&matriz[x+1][y]=='b'){
                        matriz[x][y]=' ';
                    }
                    if(matriz[x-1][y]=='w'&&matriz[x+1][y]=='b'){
                        matriz[x][y]=' ';
                    }
                    if(matriz[x-1][y]=='b'&&matriz[x+1][y]=='w'){
                        matriz[x][y]=' ';
                    }
                }

                //casilla valiada(fila)
                if(y+1<=size-1&&y-1>=0){
                    if(matriz[x][y-1]=='b'&&matriz[x][y+1]=='b'){
                        matriz[x][y]=' ';
                    }
                    if(matriz[x][y-1]=='w'&&matriz[x][y+1]=='b'){
                        matriz[x][y]=' ';
                    }
                    if(matriz[x][y-1]=='b'&&matriz[x][y+1]=='w'){
                        matriz[x][y]=' ';
                    }   
                }

            }else{//se verifica que no hayan rodeado a un sueco(exceptuando al rey)
                if(matriz[x][y]!='w'){
                    //evitamos salir de la matriz

                    //casilla valida(columna)
                    if(x-1>=0&&x+1<=size-1){
                        if(matriz[x-1][y]=='n'&&matriz[x+1][y]=='n'){
                            matriz[x][y]=' ';
                        }
                        
                    }

                    //casilla valiada(fila)
                    if(y+1<=size-1&&y-1>=0){
                        if(matriz[x][y-1]=='n'&&matriz[x][y+1]=='n'){
                            matriz[x][y]=' ';
                        }
                        
                    }    
                }
                
                   
            }
        }
    }   

}

bool ganan_moskovitas(char**matriz,int size){
    
    bool gano=false;
    //los suecos ganan cuando han rodeado al rey
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            //validamos que el rey no este rodeado

            //buscamos el rey
            if(matriz[x][y]=='w'){
                //buscamos a su alrededor

                //si todas las casillas son validas
                if(x-1>=0&&x+1<=size-1&&y+1<=size-1&&y-1>=0){
                    if(matriz[x-1][y]=='n'&&matriz[x+1][y]=='n'&&matriz[x][y-1]=='n'&&matriz[x][y+1]=='n'){
                        gano=true;//los suecos ganan
                    }
                }
            }



        }
    }

    return gano;
}

void colocar_x(char**matriz,int size){//funcion que coloca una X en el tablero cuando el rey no esta en esa posicion
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            if(matriz[size/2][size/2]!='w'){
                matriz[size/2][size/2]='x';
            }
        }
    }

}