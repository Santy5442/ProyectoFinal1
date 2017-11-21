#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

void pausa(){
	printf("\n");
    cout << " Pulsa enter para continuar...";
    getwchar();
    getwchar();
}

struct cliente{
	char nombre [20];
	char direccion[50];
	long int ci;
	long int telf;
};

struct tiempo{
	int hora;
	int minutos;
};

struct destinos{
	char d1[20];
	float costo;
	tiempo hora;	
};

struct aviones{
	int asiento;
	char numavion[20];
	char nombreCompania[20];
};

struct factura{
	int numfact;
	cliente datosCliente;
	destinos datosDestinos;
	aviones datosAvion;
};

struct NodoCliente{
	cliente datosCliente;
	NodoCliente *siguienteDireccion,*anteriorDireccion;
};

void crearListaCliente(NodoCliente **clientes, cliente dato){
	NodoCliente *aux;
	aux=new NodoCliente();
	
	aux->datosCliente=dato;
	aux->anteriorDireccion=NULL;
	aux->siguienteDireccion=NULL;
	if (*clientes==NULL){
		*clientes=aux;
	}
}

void insertarListaCliente(NodoCliente **clientes, cliente dato){
	NodoCliente *aux;
	NodoCliente *aux2;
	
	aux=new NodoCliente();
	aux2=new NodoCliente();
	
	aux2 = (*clientes);
	while(aux2->siguienteDireccion!=NULL){
		aux2=aux2->siguienteDireccion;
	}
	aux->datosCliente=dato;
	aux->siguienteDireccion=NULL;
	aux->anteriorDireccion=aux2;
	aux2->siguienteDireccion=aux;
	
}

void ingresarfact(factura f1[],int i){
	char valid;
	do{
		printf("\n Ingrese numero de factura: ");
		scanf("%d",&f1[i].numfact);
		fflush(stdin);
		printf(" Cliente : ");
		gets(f1[i].datosCliente.nombre);
		//fflush(stdin);
		fflush(stdin);
		printf(" Direccion : ");
		gets(f1[i].datosCliente.direccion);
		fflush(stdin);
		printf("\n Telefono : ");
		scanf("%ld",&f1[i].datosCliente.telf);
		printf(" Cedula de identidad : ");
		scanf("%ld",&f1[i].datosCliente.ci);
		printf(" \n Eliga la Hora de viaje ");
		printf(" \n\t 1.- TEMPRANO: \n\t\t Salida: 9:30 A.M Llegada: 10:15 A.M  ");
		printf(" \n\t 2.- TARDE: \n\t\t Salida: 10:30 P.M Llegada: 11:15 P.M  ");
		printf(" \n\t ==> ");
		//scanf("%d",&f1[i].dathorario.hora);
		f1[i].datosAvion.asiento=(rand()% 10)+1;
		fflush(stdin);
		printf("CONFIRMAR RESERVACION (S/N): ");
		scanf("%c",&valid);
		fflush(stdin);
	} while(valid=='N' || valid=='n');
}

void mostrarLista(NodoCliente **listaClientes){
	NodoCliente *aux=NULL;
	aux=new NodoCliente();
	aux=(*listaClientes);
	system("cls");
	printf ("\t\tSISTEMA DE VISUALIZACION\n\n");
	if (aux!=NULL){
		printf ("La lista es: ");
		while(aux!=NULL){
			printf ("%s\t%s\t%d",aux->datosCliente.nombre,aux->datosCliente.direccion,aux->datosCliente.telf);
			if (aux->siguienteDireccion!=NULL){
				cout <<"--->";
			}
			aux=aux->siguienteDireccion;
		}
	printf ("\n\n");	
	}
	else{
		printf ("La lista esta vacia :c\n\n");
	}
}

/*void imprimirfact(factura f1[],int i){
	printf("\n *******************\n Factura: %d ",f1[i].numfact);
	printf("\n Cliente : ");
	puts(f1[i].datosCliente.nombre);
	printf(" Cedula de identidad : %ld ",f1[i].datcliente.ci);
	printf("\n Direccion : ");
	puts(f1[i].datosCliente.direccion);
	printf(" Celular : 0%ld ",f1[i].datcliente.telf);
	printf("\n Vuelo: ");
	puts(f1[i].datdestinos.d1);
	if(f1[i].dathorario.hora==1)
		printf("\n Horario:\n TEMPRANO: Salida: 9:30 A.M Llegada: 10:15 A.M ");
	else
		printf("\n Horario:\n TARDE: Salida: 10:30 P.M Llegada: 11:15 P.M");
	printf("\n Numero de Avion : ");
	puts(f1[i].dataviones.numavion);
	printf(" Numero de asiento : %d \n",f1[i].dataviones.asiento);
	printf("\n Costo: $ %d dolares ",f1[i].dathorario.costo);
	printf("\n\n\n ______________\t\t    _____________");
	printf("\n  F.autorizada\t\t      F.Cliente");
	printf("\n\n\t** Gracias por Preferirnos**\n Para mayor informacion llame al: 1800viajabarato\n");
}*/

int main(){
	factura f1[30];
	factura datempresa;
	int opcion1,opcion2,opcion3,opcion4,opc1;
	int cas1=0,cas2=0;
	int i=0,j,k,cont=0,busnfact;
	char valid1,valid2,valid3;
	char busnombre[50],tecla;
	NodoCliente *listaClientes=NULL;
	
	fflush(stdin);
/*	printf("\n Nombre de la empresa: ");
	gets(datempresa.datcompania.nombre);
	fflush(stdin);
	printf("\n RUC de la empresa: ");
	scanf("%ld",&datempresa.datcompania.ruc);
	printf("\n Telefono de la empresa: ");
	scanf("%ld",&datempresa.datcompania.telf);*/

f1[i].datosCliente.ci=1724567522;
	strcpy(f1[i].datosCliente.direccion,"SANGOLKA");
	strcpy(f1[i].datosCliente.nombre,"MIGUEL");
	f1[i].datosCliente.telf=2339585;
	
	if (listaClientes == NULL){
		crearListaCliente(&listaClientes,f1[i].datosCliente);
	}
	else{
		insertarListaCliente(&listaClientes,f1[i].datosCliente);
	}	
	mostrarLista(&listaClientes);

	return (1);
}
