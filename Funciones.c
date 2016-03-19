include "Alien_t.h"
include <string.h>


void alien add_Alien(char nombre, int id, char especie);
void add_Planeta(char nombre, int code, char agua, char oxigen);
void add_idioma(char nombre, char tipo, int simbolos);

void add_Alien(alien *lista, char name, int ID, char esp){
	
	lista = malloc(sizeof(alien));
	strcpy(lista->nombre, name);
	lista->id = ID;
	lista->especie = malloc(strlen(esp));
	strcpy(lista->especie, esp);

}


void add_Planeta(planetas *lista, char name, int code, char water, char oxigen){

	lista = malloc(sizeof(planetas));
	strcpy(lista->nombre, name);
	lista->star_wars_code = code;
	lista->agua = water;
	lista->oxigeno = oxigen;
	
	
}


void add_idioma(idioma *lista, char name, char type, int symbols){

	lista = malloc(sizeof(idioma));
	strcpy(lista->nombre, name);
	lista->tipo = type;
	lista->simbolos = symbols;

}


