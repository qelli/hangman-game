#include <allegro.h>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <iostream>

BITMAP* letraA;
BITMAP* letraB;
BITMAP* letraC;
BITMAP* letraD;
BITMAP* letraE;
BITMAP* letraF;
BITMAP* letraG;
BITMAP* letraH;
BITMAP* letraI;
BITMAP* letraJ;
BITMAP* letraK;
BITMAP* letraL;
BITMAP* letraM;
BITMAP* letraN;
BITMAP* letraO;
BITMAP* letraP;
BITMAP* letraQ;
BITMAP* letraR;
BITMAP* letraS;
BITMAP* letraT;
BITMAP* letraU;
BITMAP* letraV;
BITMAP* letraW;
BITMAP* letraX;
BITMAP* letraY;
BITMAP* letraZ;
BITMAP* used;
BITMAP* notfound;
BITMAP* ganar;
BITMAP* perder;
BITMAP* ahorcado1;
BITMAP* ahorcado2;
BITMAP* ahorcado3;
BITMAP* ahorcado4;
BITMAP* ahorcado5;
BITMAP* ahorcado6;
BITMAP* ahorcado7;
BITMAP* buffer;

int totalLetras=25;
bool letrasUsadas[25];
bool fin=false;
int status=0;
int intentos=6;
const char letras[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int palabras_secretas[6][15]={
    {8,2,14,2,0,2,14,11,0}, //cocacola
    {8,0,6,20,0,2,0,19,4},//aguacate
    {8,15,0,13,19,0,11,14,13},//pantalon
    {7,0,1,0,13,8,2,14},//abanico
    {11,2,14,12,15,20,19,0,3,14,17,0},//computadora
    {6,2,14,1,8,9,0} //cobija
    };
bool palabras_secretas_usadas[6][15]={
     {8},
     {8},
     {8},
     {7},
     {11},
     {6}
     };
    
int palabra;
std::string cadena="A";

int topX=840;
int bottomX=topX-120;

void configurarJuego();
void mostrarLetras();
int leerLetra();
void mostrarPalabraSecreta();
void progreso(int);
bool palabraSecretaCompleta();
void ahorcado();
void fin_juego();

int main() 
{	
	allegro_init();
	configurarJuego();
	while(!key[KEY_ESC] && fin!=true){
        clear(buffer);
        progreso(leerLetra());
        mostrarPalabraSecreta();
        mostrarLetras();
        blit(buffer, screen, 0,0,0,0,1800,980);
        rest(50);
    }
    fin_juego();
	
	return 0;
}
END_OF_MAIN();


void configurarJuego(){
    
    install_keyboard(); 
    set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1800, 980, 0, 0);  
	
	for(int cont=0; cont<totalLetras; cont++){
        letrasUsadas[cont]=false;
    }
    
    for(int cont=0; cont<6; cont++){
        for(int cont2=0; cont2<palabras_secretas_usadas[cont][0]; cont2++){
            palabras_secretas_usadas[cont][cont2+1]=false;
        }
    }
    
    srand((unsigned)time(0));
    palabra=rand()%6;
    
    letraA = load_bitmap("letras/a.bmp",NULL);
    letraB = load_bitmap("letras/b.bmp",NULL);
    letraC = load_bitmap("letras/c.bmp",NULL);
    letraD = load_bitmap("letras/d.bmp",NULL);
    letraE = load_bitmap("letras/e.bmp",NULL);
    letraF = load_bitmap("letras/f.bmp",NULL);
    letraG = load_bitmap("letras/g.bmp",NULL);
    letraH = load_bitmap("letras/h.bmp",NULL);
    letraI = load_bitmap("letras/i.bmp",NULL);
    letraJ = load_bitmap("letras/j.bmp",NULL);
    letraK = load_bitmap("letras/k.bmp",NULL);
    letraL = load_bitmap("letras/l.bmp",NULL);
    letraM = load_bitmap("letras/m.bmp",NULL);
    letraN = load_bitmap("letras/n.bmp",NULL);
    letraO = load_bitmap("letras/o.bmp",NULL);
    letraP = load_bitmap("letras/p.bmp",NULL);
    letraQ = load_bitmap("letras/q.bmp",NULL);
    letraR = load_bitmap("letras/r.bmp",NULL);
    letraS = load_bitmap("letras/s.bmp",NULL);
    letraT = load_bitmap("letras/t.bmp",NULL);
    letraU = load_bitmap("letras/u.bmp",NULL);
    letraV = load_bitmap("letras/v.bmp",NULL);
    letraW = load_bitmap("letras/w.bmp",NULL);
    letraX = load_bitmap("letras/x.bmp",NULL);
    letraY = load_bitmap("letras/y.bmp",NULL);
    letraZ = load_bitmap("letras/z.bmp",NULL);
    used = load_bitmap("letras/used.bmp",NULL);
    notfound = load_bitmap("letras/notfound.bmp",NULL);
    ganar = load_bitmap("progreso/ganar.bmp",NULL);
    perder = load_bitmap("progreso/perdido.bmp",NULL);
    ahorcado1 = load_bitmap("progreso/0.bmp",NULL);
    ahorcado2 = load_bitmap("progreso/1.bmp",NULL);
    ahorcado3 = load_bitmap("progreso/2.bmp",NULL);
    ahorcado4 = load_bitmap("progreso/3.bmp",NULL);
    ahorcado5 = load_bitmap("progreso/4.bmp",NULL);
    ahorcado6 = load_bitmap("progreso/5.bmp",NULL);
    ahorcado7 = load_bitmap("progreso/6.bmp",NULL);
    buffer = create_bitmap(1800,980);
    
}


void mostrarLetra(int letra, int x, int y){
    switch(letra){
        case 0:
            draw_sprite(buffer, letraA, x, y);
        break;
        
        case 1:
            draw_sprite(buffer, letraB, x, y);
        break;
        
        case 2:
            draw_sprite(buffer, letraC, x, y);
        break;
        
        case 3:
            draw_sprite(buffer, letraD, x, y);
        break;
        
        case 4:
            draw_sprite(buffer, letraE, x, y);
        break;
        
        case 5:
            draw_sprite(buffer, letraF, x, y);
        break;
        
        case 6:
            draw_sprite(buffer, letraG, x, y);
        break;
        
        case 7:
            draw_sprite(buffer, letraH, x, y);
        break;
        
        case 8:
            draw_sprite(buffer, letraI, x, y);
        break;
        
        case 9:
            draw_sprite(buffer, letraJ, x, y);
        break;
        
        case 10:
            draw_sprite(buffer, letraK, x, y);
        break;
        
        case 11:
            draw_sprite(buffer, letraL, x, y);
        break;
        
        case 12:
            draw_sprite(buffer, letraM, x, y);
        break;
        
        case 13:
            draw_sprite(buffer, letraN, x, y);
        break;
        
        case 14:
            draw_sprite(buffer, letraO, x, y);
        break;
        
        case 15:
            draw_sprite(buffer, letraP, x, y);
        break;
        
        case 16:
            draw_sprite(buffer, letraQ, x, y);
        break;
        
        case 17:
            draw_sprite(buffer, letraR, x, y);
        break;
        
        case 18:
            draw_sprite(buffer, letraS, x, y);
        break;
        
        case 19:
            draw_sprite(buffer, letraT, x, y);
        break;
        
        case 20:
            draw_sprite(buffer, letraU, x, y);
        break;
        
        case 21:
            draw_sprite(buffer, letraV, x, y);
        break;
        
        case 22:
            draw_sprite(buffer, letraW, x, y);
        break;
        
        case 23:
            draw_sprite(buffer, letraX, x, y);
        break;
        
        case 24:
            draw_sprite(buffer, letraY, x, y);
        break;
        
        case 25:
            draw_sprite(buffer, letraZ, x, y);
        break;     
   
        
        
           
    }   
}








int leerLetra(){
    if(key[KEY_A]){
        letrasUsadas[0]=true; 
        return 0;  
    }     
    if(key[KEY_B]){
        letrasUsadas[1]=true;  
        return 1; 
    }    
    if(key[KEY_C]){
        letrasUsadas[2]=true;   
        return 2;
    }    
    if(key[KEY_D]){
        letrasUsadas[3]=true;   
        return 3;
    }    
    if(key[KEY_E]){
        letrasUsadas[4]=true;   
        return 4;
    }    
    if(key[KEY_F]){
        letrasUsadas[5]=true;   
        return 5;
    }    
    if(key[KEY_G]){
        letrasUsadas[6]=true;   
        return 6;
    }    
    if(key[KEY_H]){
        letrasUsadas[7]=true;   
        return 7;
    }    
    if(key[KEY_I]){
        letrasUsadas[8]=true;   
        return 8;
    }    
    if(key[KEY_J]){
        letrasUsadas[9]=true;   
        return 9;
    }    
    if(key[KEY_K]){
        letrasUsadas[10]=true;   
        return 10;
    }    
    if(key[KEY_L]){
        letrasUsadas[11]=true;   
        return 11;
    }    
    if(key[KEY_M]){
        letrasUsadas[12]=true;   
        return 12;
    }    
    if(key[KEY_N]){
        letrasUsadas[13]=true;   
        return 13;
    }    
    if(key[KEY_O]){
        letrasUsadas[14]=true;   
        return 14;
    }    
    if(key[KEY_P]){
        letrasUsadas[15]=true;   
        return 15;
    }    
    if(key[KEY_Q]){
        letrasUsadas[16]=true;   
        return 16;
    }    
    if(key[KEY_R]){
        letrasUsadas[17]=true;   
        return 17;
    }    
    if(key[KEY_S]){
        letrasUsadas[18]=true;   
        return 18;
    }    
    if(key[KEY_T]){
        letrasUsadas[19]=true;   
        return 19;
    }    
    if(key[KEY_U]){
        letrasUsadas[20]=true;   
        return 20;
    }    
    if(key[KEY_V]){
        letrasUsadas[21]=true;   
        return 21;
    }    
    if(key[KEY_W]){
        letrasUsadas[22]=true;   
        return 22;
    }    
    if(key[KEY_X]){
        letrasUsadas[23]=true;   
        return 23;
    }    
    if(key[KEY_Y]){
        letrasUsadas[24]=true;   
        return 24;
    }    
    if(key[KEY_Z]){
        letrasUsadas[25]=true;   
        return 25;
    }      
    
    return 99;
}






void mostrarLetras(){
    char * writable = new char[cadena.size() + 1];

       for(int cont=0; cont<sizeof(letras); cont++){
            cadena=letras[cont];
            std::copy(cadena.begin(), cadena.end(), writable);
            writable[cadena.size()] = '\0';
            if(letrasUsadas[cont]){
                 if(cont>12){
                    draw_sprite(buffer, used, (cont-13)*126, topX);
                }else{
                    draw_sprite(buffer, used, cont*126, bottomX);
                }
            }else{
                if(cont>12){
                    mostrarLetra(cont, (cont-13)*126, topX);
                }else{
                    mostrarLetra(cont, cont*126, bottomX);
                }
        }
    }
}


void mostrarPalabraSecreta(){
    for(int cont=0; cont<palabras_secretas[palabra][0]; cont++){
        if(palabras_secretas_usadas[palabra][cont+1]){
            mostrarLetra(palabras_secretas[palabra][cont+1],cont*126,500);   
        }else{
            draw_sprite(buffer, notfound, cont*126,500);
        }
    }
}


void progreso(int letra_leida){
    bool mal=true;
        ahorcado();
        if(palabraSecretaCompleta()){
            status=2;
            fin=true;
        }else{
            if(letra_leida!=99){
               if(intentos>0){
                        for(int cont=0; cont<palabras_secretas[palabra][0]; cont++){
                            if(palabras_secretas[palabra][cont+1]==letra_leida){
                                palabras_secretas_usadas[palabra][cont+1]=true; 
                                mal=false;
                            }   
                        }
                }else{
                      status=1;
                      fin=true;   
                }
                
                if(mal){
                    intentos--;   
                }
            }
        }
}


void fin_juego(){
    switch(status){
        case 1:
            //Perdio
            draw_sprite(buffer, perder, 1200, 200);        
            blit(buffer, screen, 0,0,0,0,1800,980);    
            while(!key[KEY_ENTER]){
                rest(50);    
            }
        break;   
        
        case 2:
            //Ganado
            draw_sprite(buffer, ganar, 1200, 200);
            blit(buffer, screen, 0,0,0,0,1800,980);
            while(!key[KEY_ENTER]){
                rest(50);    
            }
        break;
    }
    
    
}


void ahorcado(){
    int x=500;
    int y=200;
    switch(intentos){
        case 0:
            draw_sprite(buffer, ahorcado7, x, y);
        break;
        
        case 1:
            draw_sprite(buffer, ahorcado6, x, y);
        break;
        
        case 2:
            draw_sprite(buffer, ahorcado5, x, y);
        break;
        
        case 3:
            draw_sprite(buffer, ahorcado4, x, y);
        break;
        
        case 4:
            draw_sprite(buffer, ahorcado3, x, y);
        break;
        
        case 5:
            draw_sprite(buffer, ahorcado2, x, y);
        break;
        
        case 6:
            draw_sprite(buffer, ahorcado1, x, y);
        break;   
    }   
}

bool palabraSecretaCompleta(){
    int encontradas=0;
    for(int count=0; count<palabras_secretas[palabra][0]; count++){
        if(palabras_secretas_usadas[palabra][count+1]){
            encontradas++;   
        }   
    }   
    if(palabras_secretas[palabra][0]==encontradas){
        return true;   
    }else{
        return false;   
    }
}
