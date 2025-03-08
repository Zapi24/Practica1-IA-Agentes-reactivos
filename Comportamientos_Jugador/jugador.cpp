#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include<queue>
//#include "jugador.hpp"
using namespace std;

void PonerTerrenoEnMatriz(const vector<unsigned char> & terreno, const State & st, vector<vector<unsigned char>> & matriz, Sensores sensores){

    //Actualmente solo pone la casilla en la que se encuentra el agente, pero sabiendo su situación y orientación,
    //podemos desvelar todo lo que este ve

    matriz[st.fil][st.col] = terreno [0];
    
    int var1, var2, var3, var4, var5, var6;    //Depende de la orientación, tendrán unos valores u otros

    switch(st.brujula){
   	 case norte: case oeste: case noreste: case noroeste:

   		 var1 = -1; var2 = -2; var3 = -3; var4 = 1; var5 = 2; var6 = 3;
   	 break;

   	 case sur: case este: case suroeste: case sureste:

   		 var1 = 1; var2 = 2; var3 = 3; var4 = -1; var5 = -2; var6 = -3;
   	 break;
   	 
    }
    //Realizamos las asignaciones
    if(st.brujula == norte  || st.brujula == sur){

   	 matriz[st.fil + var1][st.col + var1] = terreno[1];
   	 matriz[st.fil + var1][st.col] = terreno[2];
   	 matriz[st.fil + var1][st.col + var4] = terreno[3];

   	 matriz[st.fil + var2][st.col + var2] = terreno[4];
   	 matriz[st.fil + var2][st.col + var1] = terreno[5];
   	 if(sensores.nivel != 3) matriz[st.fil + var2][st.col] = terreno[6];
   	 matriz[st.fil + var2][st.col + var4] = terreno[7];
   	 matriz[st.fil + var2][st.col + var5] = terreno[8];

   	 matriz[st.fil + var3][st.col + var3] = terreno[9];
   	 matriz[st.fil + var3][st.col + var2] = terreno[10];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col + var1] = terreno[11];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col] = terreno[12];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col + var4] = terreno[13];
   	 matriz[st.fil + var3][st.col + var5] = terreno[14];
   	 matriz[st.fil + var3][st.col + var6] = terreno[15];
    }
    else if(st.brujula == oeste || st.brujula == este){
   	 
   	 matriz[st.fil + var4][st.col + var1] = terreno[1];
   	 matriz[st.fil][st.col + var1] = terreno[2];
   	 matriz[st.fil + var1][st.col + var1] = terreno[3];

   	 matriz[st.fil + var5][st.col + var2] = terreno[4];
   	 matriz[st.fil + var4][st.col + var2] = terreno[5];
   	 if(sensores.nivel != 3) matriz[st.fil][st.col + var2] = terreno[6];
   	 matriz[st.fil + var1][st.col + var2] = terreno[7];
   	 matriz[st.fil + var2][st.col + var2] = terreno[8];

   	 matriz[st.fil + var6][st.col + var3] = terreno[9];
   	 matriz[st.fil + var5][st.col + var3] = terreno[10];
   	 if(sensores.nivel != 3) matriz[st.fil + var4][st.col + var3] = terreno[11];
   	 if(sensores.nivel != 3) matriz[st.fil][st.col + var3] = terreno[12];
   	 if(sensores.nivel != 3) matriz[st.fil + var1][st.col + var3] = terreno[13];
   	 matriz[st.fil + var2][st.col + var3] = terreno[14];
   	 matriz[st.fil + var3][st.col + var3] = terreno[15];
    }
    else if(st.brujula == noreste || st.brujula == suroeste){

   	 matriz[st.fil + var1][st.col] = terreno[1];
   	 matriz[st.fil + var1][st.col + var4] = terreno[2];
   	 matriz[st.fil][st.col + var4] = terreno[3];

   	 matriz[st.fil + var2][st.col] = terreno[4];
   	 matriz[st.fil + var2][st.col + var4] = terreno[5];
   	 if(sensores.nivel != 3) matriz[st.fil + var2][st.col + var5] = terreno[6];
   	 matriz[st.fil + var1][st.col + var5] = terreno[7];
   	 matriz[st.fil][st.col + var5] = terreno[8];

   	 matriz[st.fil + var3][st.col] = terreno[9];
   	 matriz[st.fil + var3][st.col + var4] = terreno[10];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col + var5] = terreno[11];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col + var6] = terreno[12];
   	 if(sensores.nivel != 3) matriz[st.fil + var2][st.col + var6] = terreno[13];
   	 matriz[st.fil + var1][st.col + var6] = terreno[14];
   	 matriz[st.fil][st.col + var6] = terreno[15];
    }    
    else if(st.brujula == noroeste || st.brujula == sureste){

   	 matriz[st.fil][st.col + var1 ] = terreno[1];
   	 matriz[st.fil + var1][st.col + var1] = terreno[2];
   	 matriz[st.fil + var1 ][st.col] = terreno[3];

   	 matriz[st.fil][st.col + var2] = terreno[4];
   	 matriz[st.fil + var1][st.col + var2] = terreno[5];
   	 if(sensores.nivel != 3) matriz[st.fil + var2][st.col + var2] = terreno[6];
   	 matriz[st.fil + var2][st.col + var1] = terreno[7];
   	 matriz[st.fil + var2][st.col] = terreno[8];

   	 matriz[st.fil][st.col + var3] = terreno[9];
   	 matriz[st.fil + var1][st.col + var3] = terreno[10];
   	 if(sensores.nivel != 3) matriz[st.fil + var2][st.col + var3] = terreno[11];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col + var3] = terreno[12];
   	 if(sensores.nivel != 3) matriz[st.fil + var3][st.col + var2] = terreno[13];
   	 matriz[st.fil + var3][st.col + var1] = terreno[14];
   	 matriz[st.fil + var3][st.col] = terreno[15];
    }
}
Action ComportamientoJugador::think(Sensores sensores)
{

    Action accion = actIDLE;
    int a;    //Para almacenar la posicion entera del enum

    //Actualización de las variables de estado
    switch(last_action){

   	 case actWALK:
   		 // Actualización en caso de avanzar
         if(!sensores.colision){
            switch(current_state.brujula){    //enum Orientacion {norte, noreste, este, sureste, sur, suroeste, oeste, noroeste};
                
                case norte:    current_state.fil--;    break;
                case noreste: current_state.fil--; current_state.col++; break;
                case este: current_state.col++;   	 break;
                case sureste: current_state.fil++; current_state.col++; break;
                case sur: current_state.fil++;   	 break;
                case suroeste: current_state.fil++; current_state.col--; break;
                case oeste: current_state.col--;    break;
                case noroeste: current_state.fil--; current_state.col--; break; 
            }
            break;
         }
   	 case actRUN:
   		 // Actualización en caso de correr
   		 break;
   	 case actTURN_SR:
   		 //Actualización en caso de girar 45º a la derecha
   		 a = current_state.brujula;
   		 a = (a + 1) % 8; // Incrementar la orientación en 1 y aplicar módulo 8 para mantenerla dentro del rango [0, 7]
   		 current_state.brujula = static_cast<Orientacion>(a);
   		 break;
   	 case actTURN_L:
   		 // Actualizacion en caso de girar 90º a la izquierda
   		 a = current_state.brujula;
   		 a = (a + 6) % 8; // Decrementar la orientación en 1 (sumar 6 es equivalente a restar 2, pero maneja adecuadamente el caso de que 'a' sea 0)
   		 current_state.brujula = static_cast<Orientacion>(a);
   		 break;
    }

	if(sensores.reset){

		desorientado();
        reiniciarMapa();    
	}

    if(precipicios){    //Para que se descubran los precipicios al empezar
        precipicios = false;

        for (int i = 0; i < mapaResultado.size(); ++i) {
            for (int j = 0; j < mapaResultado.size(); ++j) {
                if (i < 3 || j < 3 || i >= mapaResultado.size() - 3 || j >= mapaResultado.size() - 3) {
                mapaResultado[i][j] = 'P';
                }
            }
        }
    }

    if(sensores.terreno[0] == 'G' && !bien_situado){    //Podemos saber donde nos encontramos

        if(sensores.nivel == 1 || sensores.nivel == 2)
            PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaCopiado,sensores);    //Que copie tb la casilla de posicionamiento
        
        //Obtenemos posiciones de las casillas de posicionamiento en el mapaCopiado
        int posx = current_state.fil;
        int posy = current_state.col;

        current_state.fil = sensores.posF;
        current_state.col= sensores.posC;
        current_state.brujula = sensores.sentido;
        bien_situado = true;

        if(sensores.nivel == 1 || sensores.nivel == 2){
            int dif1 = (posx - current_state.fil);
            int dif2 = (posy - current_state.col);

            // Copiar el área del mapaCopiado al mapaResultado
            for (int i = 0; i < 300; ++i) {
                for (int j = 0; j < 300; ++j) {
                    if(mapaCopiado[i][j] != '?' && mapaResultado[i-dif1][j-dif2] == '?'){

                       mapaResultado[i-dif1][j-dif2] =  mapaCopiado[i][j];
                    }
                }
            }
        }
    }

    if(bien_situado){    //Marcamos la raiz nuestra localización

   	 PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado,sensores);
     mapaBool[current_state.fil][current_state.col] = true;

        for(int i = current_state.fil - 2; i < current_state.fil + 2;i++){
            for(int j = current_state.col -2 ; j < current_state.col + 2 ; j++){
                if((i != current_state.fil || j != current_state.col) && (mapaResultado[i][j] == 'P'|| mapaResultado[i][j] == 'M')){

                    mapaBool[i][j] = true;  //Para que no intente caminar sobre precipicios o muros
                }
            }
        }
    }
    else if(sensores.nivel == 1 || sensores.nivel == 2){   //Si no estamos situados que vaya copiando 

        PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaCopiado,sensores);
    }

	//Ponemos los boleanos del bikini o las zapatillas a true si los encontramos 

	if(sensores.terreno[0] ==  'K'){

		bikini = true;
	}

	if (sensores.terreno[0] == 'D'){

		zapatillas = true;
	}

    //DECIDIR LA SIGUIENTE ACCION
    if(!bien_situado && buscoPosicionarme(sensores.terreno) && !obstaculoDelante(sensores.terreno)){	//Si no se donde estoy, y encuentro una casilla de ubicación, que vaya a por ella

		accion = obtenerPosicion(sensores);
	}
	else if(!zapatillas && buscoZapatillas(sensores.terreno) && !obstaculoDelante(sensores.terreno)){	//Si no tengo zapatillas, y las veo, que vaya a por ellas

		accion = obtenerRopa(sensores);
	}
	else if(!bikini && buscoBikini(sensores.terreno) && !obstaculoDelante(sensores.terreno)){

		accion = obtenerRopa(sensores);
	}
    else if(buscoBateria(sensores.terreno) && !obstaculoDelante(sensores.terreno) && sensores.bateria <=2500){

		accion = obtenerBateria(sensores);
	}
	else if(buscoPuerta(sensores.terreno) && !obstaculoDelante(sensores.terreno)){

		accion = entrarPuerta(sensores);
	}
    else if(continuarPrecipicios(sensores.terreno) && !obstaculoDelante(sensores.terreno) && !bien_situado){

        accion = actWALK;
    }
	/*else if(((buscoAgua(sensores.terreno) && !bikini) || (buscoBosque(sensores.terreno)) && !zapatillas) &&
	 !obstaculoDelante(sensores.terreno) && buscoPrecipicios(sensores.terreno)){

		tirarme_precipicio = true;	//Probablemente estamos encerrados
		accion = tirarmePrecipicios(sensores);
	}*/
	/*else if(buscoPuertaPrecipicio(sensores.terreno)){

		accion = entrarPuertaPrecipicio(sensores);
	}*/
    /*else if(((!bikini && sensores.terreno[0] == 'A') && (!zapatillas && sensores.terreno[0] == 'B')) 
    && !obstaculoDelante(sensores.terreno) && buscoSalida(sensores.terreno)){

        accion = escaparAguaBosque(sensores);   //No deberia pasar mucho tiempo sobre agua o bosque sin zapatillas o bikini
    }*/
	else if(sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' || sensores.terreno[2] == 'K' 
        || sensores.terreno[2] == 'D' || sensores.terreno[2] == 'X' ||
	   (sensores.terreno[2] == 'A' && (bikini || buscoAgua(sensores.terreno))) || (sensores.terreno[2] == 'B' && (zapatillas || buscoBosque(sensores.terreno))) 
	   && sensores.agentes[2] == '_'){

        if(bien_situado){

            accion = recorrerNuevos(sensores);
        }
        else{

            accion = actWALK;
        }

	}else if(!girar_derecha){


    	accion = actTURN_L;
    	girar_derecha = (rand()%2 == 0);    //Puede ser que el prox giro sea a la izq o a la der
    }else{

    	accion = actTURN_SR;
    	girar_derecha = (rand()%2 == 0);
   }

   if(accion == actWALK){

    n_giros = 0;    //Lleva 0 giros consecutivos
   }

   //Recordar la ultima accion
   last_action = accion;
   return accion;
}


int ComportamientoJugador::interact(Action accion, int valor)
{
   return false;
}


void ComportamientoJugador::desorientado(){

   current_state.fil = 99;
   current_state.col = 99;
   current_state.brujula = norte;      //Su orientación inicial es el norte
   last_action =  actIDLE;             //Comodin, no hace nada
   girar_derecha = true; 
   bien_situado = false;
   zapatillas = false;
   bikini = false;
   tirarme_precipicio = false; // Es posible que me haya tirado de un pricipicio para escapar de estar encerrado
}

bool ComportamientoJugador::buscoZapatillas(vector< unsigned char> terreno){
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'D'){  //Tenemos en nuestra visión una casilla de posicionamiento


           return true;
       }
   }


   return false;
}

bool ComportamientoJugador::buscoBikini(vector< unsigned char> terreno){
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'K'){  //Tenemos en nuestra visión una casilla de posicionamiento

           return true;
       }
   }

   return false;
}


Action  ComportamientoJugador::obtenerRopa(Sensores sensores){
   Action accion = actIDLE;

   if (sensores.terreno[1] == 'K' || sensores.terreno[1] == 'D' ||
       sensores.terreno[4] == 'K' || sensores.terreno[4] == 'D' ||
       sensores.terreno[9] == 'K' || sensores.terreno[9] == 'D') {
  
       accion = actTURN_L;
       }
else if (sensores.terreno[2] == 'K' || sensores.terreno[2] == 'D' ||
        sensores.terreno[5] == 'K' || sensores.terreno[5] == 'D' ||
        sensores.terreno[6] == 'K' || sensores.terreno[6] == 'D' ||
        sensores.terreno[7] == 'K' || sensores.terreno[7] == 'D' ||
        sensores.terreno[10] == 'K' || sensores.terreno[10] == 'D' ||
        sensores.terreno[11] == 'K' || sensores.terreno[11] == 'D' ||
        sensores.terreno[12] == 'K' || sensores.terreno[12] == 'D' ||
        sensores.terreno[13] == 'K' || sensores.terreno[13] == 'D' ||
        sensores.terreno[14] == 'K' || sensores.terreno[14] == 'D') {
  
       accion = actWALK;
       }
else if (sensores.terreno[3] == 'K' || sensores.terreno[3] == 'D' ||
        sensores.terreno[8] == 'K' || sensores.terreno[8] == 'D' ||
        sensores.terreno[15] == 'K' || sensores.terreno[15] == 'D') {


       accion = actTURN_SR;
}

   last_action = accion;
   return accion; 
}

bool ComportamientoJugador::buscoPosicionarme(vector< unsigned char> terreno){
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'G'){  //Tenemos en nuestra visión una casilla de posicionamiento


           return true;
       }
   }

   return false;
}

Action ComportamientoJugador::obtenerPosicion(Sensores sensores){
   Action accion = actIDLE;

   if(sensores.terreno[0] == 'G'){    //Verificamos si nos encontramos ya, y expecificamos si nos h
   
    current_state.fil = sensores.posF;
    current_state.col= sensores.posC;
    current_state.brujula = sensores.sentido;
    bien_situado = true;
   }
   else if (sensores.terreno[1] == 'G' || sensores.terreno[4] == 'G' || sensores.terreno[9] == 'G' ) {
  
       accion = actTURN_L;
   }
   else if (sensores.terreno[2] == 'G' || sensores.terreno[5] == 'G' || sensores.terreno[6] == 'G' ||
        sensores.terreno[7] == 'G' || sensores.terreno[10] == 'G' || sensores.terreno[11] == 'G' ||
        sensores.terreno[12] == 'G' || sensores.terreno[13] == 'G' || sensores.terreno[14] == 'G' ) {
  
       accion = actWALK;
   }
   else if (sensores.terreno[3] == 'G' || sensores.terreno[8] == 'G' || sensores.terreno[15] == 'G') {


       accion = actTURN_SR;
   }

   last_action = accion;

   return accion;
}

bool ComportamientoJugador::buscoBateria(vector< unsigned char> terreno){
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'X'){  //Tenemos en nuestra visión una casilla para recargar bateria

           return true;
       }
   }

   return false;
}


Action ComportamientoJugador::obtenerBateria(Sensores sensores){
   Action accion = actIDLE;

   if (sensores.terreno[1] == 'X' || sensores.terreno[4] == 'X' || sensores.terreno[9] == 'X' ) {
  
       accion = actTURN_L;
   }
   else if (sensores.terreno[2] == 'X' || sensores.terreno[5] == 'X' || sensores.terreno[6] == 'X' ||
        sensores.terreno[7] == 'X' || sensores.terreno[10] == 'X' || sensores.terreno[11] == 'X' ||
        sensores.terreno[12] == 'X' || sensores.terreno[13] == 'X' || sensores.terreno[14] == 'X' ) {
  
       accion = actWALK;
   }
   else if (sensores.terreno[3] == 'X' || sensores.terreno[8] == 'X' || sensores.terreno[15] == 'X') {

       accion = actTURN_SR;
   }


   last_action = accion;
   return accion;
}


bool ComportamientoJugador::buscoPuerta(vector< unsigned char> terreno){    //ARREGLAR

   if ((terreno[3] == 'M' && terreno[7] == 'M' && terreno[13] == 'M' &&
       (terreno[8] == 'S' || terreno[8] == 'T') && (terreno[14] == 'S' || terreno[14] == 'T')) ||

       ((terreno[1] == 'S' || terreno[1] == 'T') && terreno[5] == 'M' && terreno[11] == 'M' &&
       (terreno[4] == 'S' || terreno[4] == 'T') && (terreno[10] == 'S' || terreno[10] == 'T')) ||

       (recuerdo_puerta_izq && terreno[1] == 'M' && terreno[5] == 'M' && (terreno[4] == 'S' || terreno[4] == 'T')) ||

       (terreno[2] != 'M' && terreno[1] == 'M' && terreno[3] == 'M') ||
       (terreno[6] != 'M'  && terreno[5] == 'M' && terreno[7] == 'M') ||
       (terreno[12] != 'M' && terreno[11] == 'M' && terreno[13] == 'M') ||
       (terreno[5] != 'M' && terreno[4] == 'M' && terreno[6] == 'M') ||
       (terreno[7] != 'M' && terreno[6] == 'M' && terreno[8] == 'M') ||
       (terreno[10] != 'M' && terreno[9] == 'M' && terreno[11] == 'M') ||
       (terreno[11] != 'M' && terreno[10] == 'M' && terreno[12] == 'M') ||
       (terreno[13] != 'M' && terreno[12] == 'M' && terreno[14] == 'M') ||
       (terreno[14] != 'M' && terreno[13] == 'M' && terreno[15] == 'M') || 
       
       (terreno[1] != 'M' && terreno[2] == 'M' && terreno[3] == 'M') ||
       (terreno[4] != 'M' && terreno[5] == 'M' && terreno[6] == 'M') ||
       (terreno[9] != 'M' && terreno[10] == 'M' && terreno[11] == 'M') ||

        (terreno[3] != 'M' && terreno[1] == 'M' && terreno[2] == 'M') ||
        (terreno[8] != 'M' && terreno[6] == 'M' && terreno[7] == 'M') ||
        (terreno[15] != 'M' && terreno[13] == 'M' && terreno[14] == 'M')){

        return true;
    }

   return false;
}


Action ComportamientoJugador::entrarPuerta(Sensores sensores){
   Action accion = actIDLE;


   //Tengo una pared de muros a mi derecha, la sigo
   if(sensores.terreno[7] == 'M' && sensores.terreno[7] == 'M' && sensores.terreno[13] == 'M'){

        accion = actWALK;
   }
   //Probablemente tenga una puerta a mi derecha
   else if(sensores.terreno[3] == 'M' && sensores.terreno[7] == 'M' && sensores.terreno[13] == 'M' &&
       (sensores.terreno[8] == 'S' || sensores.terreno[8] == 'T') && (sensores.terreno[14] == 'S' || sensores.terreno[14] == 'T')){

           accion = actTURN_SR;
   }
   //Probablemente tenga una puerta a mi izquierda
   else if((sensores.terreno[1] == 'S' || sensores.terreno[1] == 'T') && sensores.terreno[5] == 'M' && sensores.terreno[11] == 'M' &&
   (sensores.terreno[4] == 'S' || sensores.terreno[4] == 'T') && (sensores.terreno[10] == 'S' || sensores.terreno[10] == 'T')){


       recuerdo_puerta_izq = true;
       accion = actWALK;
   }
   //Recuerdo que tengo una puerta a mi izquierda y giro para atravesarla
   else if(recuerdo_puerta_izq && sensores.terreno[1] == 'M' && sensores.terreno[5] == 'M' && (sensores.terreno[4] == 'S' || sensores.terreno[4] == 'T')){


       recuerdo_puerta_izq = false;
       accion = actTURN_L;
   }
   //Tengo una puerta delante
   else if((sensores.terreno[2] != 'M' && sensores.terreno[1] == 'M' && sensores.terreno[3] == 'M') ||
			(sensores.terreno[6] != 'M'  && sensores.terreno[5] == 'M' && sensores.terreno[7] == 'M') ||
			(sensores.terreno[12] != 'M' && sensores.terreno[11] == 'M' && sensores.terreno[13] == 'M') ||
            (sensores.terreno[5] != 'M' && sensores.terreno[4] == 'M' && sensores.terreno[6] == 'M') ||
            (sensores.terreno[7] != 'M' && sensores.terreno[6] == 'M' && sensores.terreno[8] == 'M') ||
            (sensores.terreno[10] != 'M' && sensores.terreno[9] == 'M' && sensores.terreno[11] == 'M') ||
            (sensores.terreno[11] != 'M' && sensores.terreno[10] == 'M' && sensores.terreno[12] == 'M') ||
            (sensores.terreno[13] != 'M' && sensores.terreno[12] == 'M' && sensores.terreno[14] == 'M') ||
            (sensores.terreno[14] != 'M' && sensores.terreno[13] == 'M' && sensores.terreno[15] == 'M')){

		accion = actWALK;
	}
    else if((sensores.terreno[1] != 'M' && sensores.terreno[2] == 'M' && sensores.terreno[3] == 'M') ||
            (sensores.terreno[4] != 'M' && sensores.terreno[5] == 'M' && sensores.terreno[6] == 'M') ||
            (sensores.terreno[9] != 'M' && sensores.terreno[10] == 'M' && sensores.terreno[11] == 'M')){

        accion = actTURN_L;
    }
    else if((sensores.terreno[3] != 'M' && sensores.terreno[1] == 'M' && sensores.terreno[2] == 'M') ||
            (sensores.terreno[8] != 'M' && sensores.terreno[6] == 'M' && sensores.terreno[7] == 'M') ||
            (sensores.terreno[15] != 'M' && sensores.terreno[13] == 'M' && sensores.terreno[14] == 'M') ){

        accion = actTURN_SR;
    }
    
  
   last_action = accion;
   return accion;
}

bool ComportamientoJugador::buscoAgua(vector< unsigned char> terreno){
   int contador = 0;
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'A'){ 


           contador ++;
       }
   }


   return contador>=6; //Es probable que nos encontremos rodeados de agua, asi que deberiamos escapar
}

bool ComportamientoJugador::buscoBosque(vector< unsigned char> terreno){
   int contador = 0;
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'B'){ 


           contador ++;
       }
   }

   return contador>=6; //Es probable que nos encontremos rodeados de bosque, asi que deberiamos escapar
}


bool ComportamientoJugador::obstaculoDelante(vector <unsigned char> terreno){
   if(terreno[2]=='P' || terreno[2]=='M'){

       return true;
   }
  
   return false;
}

bool ComportamientoJugador::buscoPrecipicios(vector< unsigned char> terreno){	//NO SE UTILIZAN, FUTURA IMPLEMENTACIÓN
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'P'){  //Tenemos en nuestra visión una casilla de precipicio


           return true;
       }
   }


   return false;
}

Action ComportamientoJugador::tirarmePrecipicios(Sensores sensores){
   Action accion = actIDLE;


   if (sensores.terreno[1] == 'P' || sensores.terreno[4] == 'P' || sensores.terreno[9] == 'P' ) {
  
       accion = actTURN_L;
   }
   else if (sensores.terreno[2] == 'P' || sensores.terreno[5] == 'P' || sensores.terreno[6] == 'P' ||
        sensores.terreno[7] == 'P' || sensores.terreno[10] == 'P' || sensores.terreno[11] == 'P' ||
        sensores.terreno[12] == 'P' || sensores.terreno[13] == 'P' || sensores.terreno[14] == 'P' ) {
  
       accion = actWALK;
   }
   else if (sensores.terreno[3] == 'P' || sensores.terreno[8] == 'P' || sensores.terreno[15] == 'P') {


       accion = actTURN_SR;
   }

   last_action = accion;
   return accion;
}

bool ComportamientoJugador::buscoPuertaPrecipicio(vector< unsigned char> terreno){

	if(((terreno[3] == 'S' || terreno[3] == 'T') && terreno[7] == 'P' && terreno[13] == 'P')){

		return true;
	}
	return false;
}

bool ComportamientoJugador::continuarPrecipicios(vector< unsigned char> terreno){

    if(terreno[7] == 'P' && terreno[3] == 'P'){

		return true;
	}
	return false;
}

Action ComportamientoJugador::entrarPuertaPrecipicio(Sensores sensores){
	Action accion = actIDLE;

	//Tengo la puerta a mi derecha y la puedo atravesar
	if(((sensores.terreno[3] == 'S' || sensores.terreno[3] == 'T') && sensores.terreno[7] == 'P' && sensores.terreno[13] == 'P')){

		accion = actTURN_SR;	//Me meto por la puerta
	}
	last_action = accion;
   	return accion;
}

bool ComportamientoJugador::buscoSalida(vector< unsigned char> terreno){
   for(int i = 1; i < 16 ; i++){
       if(terreno[i] == 'S' || terreno[i] == 'T'){  

           return true;
       }
   }

   return false;
}

Action ComportamientoJugador::escaparAguaBosque(Sensores sensores){
     Action accion = actIDLE;


    if (sensores.terreno[1] == 'S' || sensores.terreno[1] == 'T' ||
       sensores.terreno[4] == 'S' || sensores.terreno[4] == 'T' ||
       sensores.terreno[9] == 'S' || sensores.terreno[9] == 'T') {
  
       accion = actTURN_L;
       }
    else if (sensores.terreno[2] == 'S' || sensores.terreno[2] == 'T' ||
            sensores.terreno[5] == 'S' || sensores.terreno[5] == 'T' ||
            sensores.terreno[6] == 'S' || sensores.terreno[6] == 'T' ||
            sensores.terreno[7] == 'S' || sensores.terreno[7] == 'T' ||
            sensores.terreno[10] == 'S' || sensores.terreno[10] == 'T' ||
            sensores.terreno[11] == 'S' || sensores.terreno[11] == 'T' ||
            sensores.terreno[12] == 'S' || sensores.terreno[12] == 'T' ||
            sensores.terreno[13] == 'S' || sensores.terreno[13] == 'T' ||
            sensores.terreno[14] == 'S' || sensores.terreno[14] == 'T') {
  
       accion = actWALK;
       }
    else if (sensores.terreno[3] == 'S' || sensores.terreno[3] == 'T' ||
            sensores.terreno[8] == 'S' || sensores.terreno[8] == 'T' ||
            sensores.terreno[15] == 'S' || sensores.terreno[15] == 'T') {

       accion = actTURN_SR;
}


   last_action = accion;
   return accion; 
}

Action ComportamientoJugador::recorrerNuevos(Sensores sensores){
     Action accion = actIDLE;

    switch(current_state.brujula){    //enum Orientacion {norte, noreste, este, sureste, sur, suroeste, oeste, noroeste};

   		case norte: 
            if(!mapaBool[current_state.fil - 2][current_state.col]) accion = actWALK;
            else if(!mapaBool[current_state.fil - 1][current_state.col]) accion = actWALK;
            else if(!mapaBool[current_state.fil - 1][current_state.col + 1]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil - 1][current_state.col - 1]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK;
        break;
   		case noreste: 
            if(!mapaBool[current_state.fil - 2][current_state.col + 2]) accion = actWALK;
            else if(!mapaBool[current_state.fil - 1][current_state.col + 1]) accion = actWALK;
            else if(!mapaBool[current_state.fil][current_state.col + 1]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil - 1][current_state.col]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK;
        break;
   		case este:
            if(!mapaBool[current_state.fil][current_state.col + 2]) accion = actWALK;
            else if(!mapaBool[current_state.fil][current_state.col + 1]) accion = actWALK;
            else if(!mapaBool[current_state.fil + 1][current_state.col + 1]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil - 1][current_state.col + 1]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK; 
        break;
   		case sureste: 
            if(!mapaBool[current_state.fil + 2][current_state.col + 2]) accion = actWALK;
            else if(!mapaBool[current_state.fil + 1][current_state.col + 1]) accion = actWALK;
            else if(!mapaBool[current_state.fil + 1][current_state.col]) { accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil][current_state.col + 1]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK;
        break;
   		case sur: 
            if(!mapaBool[current_state.fil + 2][current_state.col]) accion = actWALK;
            else if(!mapaBool[current_state.fil + 1][current_state.col]) accion = actWALK;
            else if(!mapaBool[current_state.fil + 1][current_state.col - 1]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil + 1][current_state.col + 1]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK;
        break;
   		case suroeste:
            if(!mapaBool[current_state.fil + 2][current_state.col - 2]) accion = actWALK;
            else if(!mapaBool[current_state.fil + 1][current_state.col - 1]) accion = actWALK;
            else if(!mapaBool[current_state.fil][current_state.col - 1]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil + 1][current_state.col]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK; 
        break;
   		case oeste: 
            if(!mapaBool[current_state.fil][current_state.col - 2]) accion = actWALK;
            else if(!mapaBool[current_state.fil][current_state.col - 1]) accion = actWALK;
            else if(!mapaBool[current_state.fil - 1][current_state.col - 1]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil + 1][current_state.col - 1]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK;
        break;
   		case noroeste: 
            if(!mapaBool[current_state.fil - 2][current_state.col - 2]) accion = actWALK;
            else if(!mapaBool[current_state.fil - 1][current_state.col -1 ]) accion = actWALK;
            else if(!mapaBool[current_state.fil - 1][current_state.col]){ accion = actTURN_SR; n_giros++;}
            else if(!mapaBool[current_state.fil][current_state.col - 1]){ accion = actTURN_L; n_giros++;}
            else accion = actWALK;
        break;
   	}

    if(n_giros >=6){    //Se ha quedado atascado girando, por lo que no puede elegir la siguiente opcion

        accion = actWALK;
    }

   last_action = accion;
   return accion; 
}

void ComportamientoJugador::reiniciarMapa(){

    mapaCopiado.resize(300);
    for (int i = 0; i < 300; ++i) {
      mapaCopiado[i].resize(300);
      
      for (int j = 0; j < 300; ++j) {

          mapaCopiado[i][j] = '?';
      }
    }
}

/*
   // Mostrar el valor de los sensores
   cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
   switch (sensores.sentido)
   {
    case norte:      cout << " Norte\n";    break;
    case noreste: cout << " Noreste\n";    break;
    case este: cout << " Este\n";    break;
    case sureste: cout << " Sureste\n";    break;
    case sur:  cout << " Sur\n";    break;
    case suroeste:cout << " Suroeste\n";    break;
    case oeste:   cout << " Oeste\n";    break;
    case noroeste:cout << " Noroeste\n";    break;
   }
   cout << "Terreno: ";
   for (int i=0; i<sensores.terreno.size(); i++)
    cout << sensores.terreno[i];


   cout << "  Agentes: ";
   for (int i=0; i<sensores.agentes.size(); i++)
    cout << sensores.agentes[i];


   cout << "\nColision: " << sensores.colision;
   cout << "  Reset: " << sensores.reset;
   cout << "  Vida: " << sensores.vida << endl<< endl;
   */
