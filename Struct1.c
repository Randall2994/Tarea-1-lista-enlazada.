#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Alien_t.h"

main(){
	alien *lista_aliens;	
	lista_aliens=malloc(sizeof(alien));	
	strcpy(lista_aliens->nombre,"Alien1:Superman");
	lista_aliens->id=40;
	

	printf("%s\n",lista_aliens->nombre);
	printf("%d\n",lista_aliens->id);
	printf("%s\n",lista_aliens->especie);	
return 1;
}

