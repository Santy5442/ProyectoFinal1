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

struct destinos{
	char d1[20];	
};

struct horario{
	int hora;
	int costo;
};

struct aviones{
	int asiento;
	char numavion[20];
	char nombreCompania[20];
};

struct factura{
	int numFact;
	cliente datosCliente;
	destinos datosDestinos;
	horario datosHorario;
	aviones datosAvion;
};

void datosEmpresa(factura datempresa){
	printf(" ");
	puts(datempresa.datcompania.nombre);
	printf("\n RUC: %ld ",datempresa.datcompania.ruc);
	printf("\n tel: %ld",datempresa.datcompania.telf);
}

void ingresarfact(factura f1[],int i){
	char valid;
	do{
		printf("\n Ingrese numero de factura: ");
		scanf("%d",&f1[i].numfact);
		fflush(stdin);
		printf(" Cliente : ");
		gets(f1[i].datcliente.nombre);
		//fflush(stdin);
		fflush(stdin);
		printf(" Direccion : ");
		gets(f1[i].datcliente.direccion);
		fflush(stdin);
		printf("\n Telefono : ");
		scanf("%ld",&f1[i].datcliente.telf);
		printf(" Cedula de identidad : ");
		scanf("%ld",&f1[i].datcliente.ci);
		printf(" \n Eliga la Hora de viaje ");
		printf(" \n\t 1.- TEMPRANO: \n\t\t Salida: 9:30 A.M Llegada: 10:15 A.M  ");
		printf(" \n\t 2.- TARDE: \n\t\t Salida: 10:30 P.M Llegada: 11:15 P.M  ");
		printf(" \n\t ==> ");
		scanf("%d",&f1[i].dathorario.hora);
		f1[i].dataviones.asiento=(rand()% 10)+1;
		fflush(stdin);
		printf("CONFIRMAR RESERVACION (S/N): ");
		scanf("%c",&valid);
		fflush(stdin);
	} while(valid=='N' || valid=='n');
}

void imprimirfact(factura f1[],int i){
	printf("\n *******************\n Factura: %d ",f1[i].numfact);
	printf("\n Cliente : ");
	puts(f1[i].datcliente.nombre);
	printf(" Cedula de identidad : %ld ",f1[i].datcliente.ci);
	printf("\n Direccion : ");
	puts(f1[i].datcliente.direccion);
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
}

int main(){
	factura f1[30];
	factura datempresa;
	int opcion1,opcion2,opcion3,opcion4,opc1;
	int cas1=0,cas2=0;
	int i=0,j,k,cont=0,busnfact;
	char valid1,valid2,valid3;
	char busnombre[50],tecla;
	
	fflush(stdin);
	printf("\n Nombre de la empresa: ");
	gets(datempresa.datcompania.nombre);
	fflush(stdin);
	printf("\n RUC de la empresa: ");
	scanf("%ld",&datempresa.datcompania.ruc);
	printf("\n Telefono de la empresa: ");
	scanf("%ld",&datempresa.datcompania.telf);

do{
	do{
		system("cls");
		printf("\n    DESTINOS ");
		printf("\n\n\t*** 1.- QUITO - GUAYAQUIL *** ");
		printf("\n\n\t*** 2.- QUITO - CUENCA ***");
		printf("\n\n\t*** 3.- QUITO - GALAPAGOS ***");
		printf("\n\n\t*** 4.- SALIR ***\n\n\t  ===> ");
		scanf("%d",&opcion1);
		
		switch (opcion1){
			case 1:
				do{
					system("cls");
					printf("\n QUITO - GUAYAQUIL ");
					printf("\n 1.- Reservar ");
					printf("\n 2.- Factura ");
					printf("\n 3.- Salir o registrar nuevo cliente \n ==> ");
					scanf("%d",&opcion2);
					switch (opcion2){
						case 1:
							system("cls");
							
							ingresarfact(f1,i);
							f1[i].dathorario.costo=50;
							strcpy(f1[i].datdestinos.d1,"Quito-Guayaquil");
							strcpy(f1[i].dataviones.numavion,"Airbus A320 ");
							//pausa();
							cont++;
						break ;	
						
						case 2:
							system("cls");
							datosempresa(datempresa);
							imprimirfact(f1,i);
							pausa();
						break;
					}
				}while (opcion2!=3);
				i++;
			break;
			case 2:
				do{
					system("cls");
					printf("\n QUITO - CUENCA ");
					printf("\n 1.- Reservar ");
					printf("\n 2.- Factura ");
					printf("\n 3.- Salir o registrar nuevo cliente \n ==> ");
					scanf("%d",&opcion2);
					switch (opcion2){
						case 1:
							system("cls");
							
							ingresarfact(f1,i);
							strcpy(f1[i].datdestinos.d1,"Quito-Cuenca");
							strcpy(f1[i].dataviones.numavion,"Airbus A380 ");
							f1[i].dathorario.costo=80;
							//pausa();
							cont++;
						break ;	
						
						case 2:
							system("cls");
							datosempresa(datempresa);
							imprimirfact(f1,i);
							pausa();
						break;
					}
				}while (opcion2!=3);
				i++;	
			break;
			
			case 3:
				do{
					system("cls");
					printf("\n QUITO - GALAPAGOS ");
					printf("\n 1.- Reservar ");
					printf("\n 2.- Factura ");
					printf("\n 3.- Salir o registrar nuevo cliente \n ==> ");
					scanf("%d",&opcion2);
					switch (opcion2){
						case 1:
							system("cls");
							
							ingresarfact(f1,i);
							strcpy(f1[i].datdestinos.d1,"Quito-Galapagos");
							strcpy(f1[i].dataviones.numavion,"Boing 737 ");
							f1[i].dathorario.costo=100;
							//pausa();
							cont++;
						break ;	
						
						case 2:
							system("cls");
							datosempresa(datempresa);
							imprimirfact(f1,i);
							pausa();
						break;
					}
				}while (opcion2!=3);
				i++;
			break;
		}
	}while (opcion1!=4);
	
	/////////////////////////////////////////////////////////////////////////
	do{
		system("cls");
		printf("\n   CONSULTA DE TRANSACCIONES ");
		printf("\n\n\t*** 1.- Por Nombre *** ");
		printf("\n\n\t*** 2.- Por Numero de Factura ***");
		printf("\n\n\t*** 3.- Consultar las 5 ultimas Transacciones *** ");
		printf("\n\n\t*** 4.- Todas las Transacciones *** ");
		printf("\n\n\t*** 5.- SALIR ***\n\n\t  ===> ");
		scanf("%d",&opc1);
		switch (opc1){
			case 1:
				system("cls");
				cas1=0;
				fflush(stdin);
				printf("Ingrese el Nombre: ");
				gets(busnombre);
				fflush(stdin);
				for(j=0;j<i;j++){
					k=stricmp(busnombre,f1[j].datcliente.nombre);
					if(k==0){ //printf("Las palabras son iguales\n");
						printf("\n Cliente encontrado \n");
						datosempresa(datempresa);
						imprimirfact(f1,j);
						cas1=1;
					}
				}
				if(cas1==0)
					printf("\n Cliente no existe \n");
				pausa();
			break;
			
			case 2:
				system("cls");
				cas2=0;
				printf("Ingrese el Numero de la Factura: ");
				scanf("%d",&busnfact);
				for(j=0;j<i;j++){
					if(busnfact==f1[j].numfact){
						printf("\n Cliente encontrado \n");
						datosempresa(datempresa);
						imprimirfact(f1,j);
						cas2=1;
					}
				}
				if(cas2==0)
					printf("\n Cliente no existe \n");
				pausa();
			break;
			
			case 3:
				system("cls");
				j=i-1;
				k=0;
				do{
					printf("\n Factura: %d ",f1[j].numfact);
					printf("\n\t Cliente : ");
					puts(f1[j].datcliente.nombre);
					printf("\t Destino : ");
					puts(f1[j].datdestinos.d1);
					j--;
					k++;
				}while(k<5 && j>=0);
				pausa();
			break;
			case 4:
				system("cls");
				for(j=0;j<i;j++){
					printf("\n Factura: %d ",f1[j].numfact);
					printf("\n\t Cliente : ");
					puts(f1[j].datcliente.nombre);
					printf("\t Destino : ");
					puts(f1[j].datdestinos.d1);
				}	
				printf("\n Personas que viajaron el dia de hoy : %d personas",cont);
				pausa();
			break ;
		}
	}while(opc1!=5);
	
	fflush (stdin);
	printf("\n Desea Reservar Nuevamente (S/N): ");
	scanf("%c",&tecla);
	fflush (stdin);
	
} while(tecla=='S' || tecla=='s');	

	return 0;
}
