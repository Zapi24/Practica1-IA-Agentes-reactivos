#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

struct State{

  int fil;
  int col;
  Orientacion brujula;
};

class ComportamientoJugador : public Comportamiento{

  public:
	ComportamientoJugador(unsigned int size) : Comportamiento(size){
  	// Constructor de la clase
  	// Dar el valor inicial a las variables de estado
  	current_state.fil = 99;
  	current_state.col = 99;
  	current_state.brujula = norte;  	//Su orientación inicial es el norte
    tam = size;      //tamaño del mapa 

  	last_action =  actIDLE;         	//Comodin, no hace nada
  	girar_derecha = true;  
  	bien_situado = false;
    zapatillas = false;
	  bikini = false;
    recuerdo_puerta_izq = false;
    tirarme_precipicio = false;
    precipicios = true;
    mov_aleatorio = false;
    n_giros = 0;

    mapaBool.resize(tam);
    for (int i = 0; i < tam; ++i) {
      mapaBool[i].resize(tam);
      
      for (int j = 0; j < tam; ++j) {

          mapaBool[i][j] = false;
      }
    }

    mapaCopiado.resize(300);
    for (int i = 0; i < 300; ++i) {
      mapaCopiado[i].resize(300);
      
      for (int j = 0; j < 300; ++j) {

          mapaCopiado[i][j] = '?';
      }
    }
	}

	ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
	~ComportamientoJugador(){}

	Action think(Sensores sensores);
	int interact(Action accion, int valor);

  private:
  // Declarar aquí las variables de estado
  State current_state;	//Nos permitirá recordar donde nos encontramos en cada momento
  Orientacion brujula;
  Action last_action; 	//Nos permite saber cual fue nuestra ultima acción y fundamental para actualizar nuestra info
  bool girar_derecha; 	//Para determinar de forma aleatoria, si giramos a la derecha o no
  bool bien_situado;  	//Nos dice si valor de la variable current_state refleja la posición correcta en el mapa del agente
  bool zapatillas;		//Nos dice si tenemos zapatillas o no
  bool bikini;			//Nos dice si tenemos bikini o no 
  bool recuerdo_puerta_izq; //Nos dice si tenemos a nuestra izq una puerta 
  bool tirarme_precipicio;
  bool precipicios;
  bool mov_aleatorio;
  int tam;
  int n_giros;

  vector< vector< bool> > mapaBool; //Mapa para saber por donde he pasado y por donde no
  vector< vector< unsigned char> > mapaCopiado; //Mapa para dibujar donde estoy cuando todavia no este ubicado

  //Declaramos aquí las funciones
  void desorientado();
  void reiniciarMapa();
  void obtenerPosicionCopiado(int &fila, int &columna, int& fila2, int &columna2); 
  Action obtenerRopa(Sensores sensores);
  Action obtenerPosicion(Sensores sensores);
  Action obtenerBateria(Sensores sensores);
  Action entrarPuerta(Sensores sensores);
  Action tirarmePrecipicios(Sensores sensores);
  Action entrarPuertaPrecipicio(Sensores sensores);
  Action escaparAguaBosque(Sensores sensores);
  Action recorrerNuevos(Sensores sensores);
  bool buscoPosicionarme(vector< unsigned char> terreno);
  bool buscoZapatillas(vector< unsigned char> terreno);
  bool buscoBikini(vector< unsigned char> terreno);
  bool buscoPuerta(vector< unsigned char> terreno);
  bool buscoBateria(vector< unsigned char> terreno);
  bool obstaculoDelante(vector <unsigned char> terreno);
  bool buscoAgua(vector< unsigned char> terreno);
  bool buscoBosque(vector< unsigned char> terreno);
  bool buscoPrecipicios(vector <unsigned char> terreno);
  bool buscoPuertaPrecipicio(vector< unsigned char> terreno);
  bool buscoSalida(vector< unsigned char> terreno); 
  bool continuarPrecipicios(vector< unsigned char> terreno);  //Si no estoy posicionado, que siga precipicios
  
};
#endif

