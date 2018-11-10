#include <stdio.h>
#include <stdlib.h>

int m = 0;
int n = 0;
int NmaxF = 1;
int NmaxC = 1;
void filas(int **PistasFilas,int numero,char matriz[numero][numero]){
	int contador = 0;
	int contadorAnterior = 0;
	int o=1;
	int m = 0;
	for(int i = 0 ; i < numero ; i++){
		for (int j = 0; j < numero ; ++j)
		{
			if(matriz[i][j] == '#'){
				contador++;
			}
			if(matriz[i][j+1] == '#'){
				contador = contador ;	
			}
			else if(contador != 0){
					if(n>NmaxF){
						NmaxF = n;
					}
					else{
						NmaxF = NmaxF;
					}
					PistasFilas[m][n] = contador;
					contadorAnterior = contador;
					contador = 0;	
					n++;
			}
			else if(contador == 0 && j==numero-1 && contadorAnterior == 0){
					PistasFilas[m][n] = 0;
					contador = 0;
					n=0;
			}
		}
		n=0;
		m++;
	}
}
void columnas(int **PistasColumnas,int numero,char matriz[numero][numero]){
	int contador = 0;
	int o=1;
	int m = 0;
	for(int i = 0 ; i < numero ; i++){
		for (int j = 0; j < numero ; ++j)
		{	
			if(matriz[j][i] == '#'){
				contador++;
			}
			if(matriz[j+1][i] == '#'){
				contador = contador ;
			}
			else if(contador != 0){
					
					if(n>NmaxC){
						NmaxC = n;
					}
					else{
						NmaxC = NmaxC;
					}
					PistasColumnas[m][n] = contador;
					contador = 0;
					n++;
			}
		}
		n=1;
		m++;
	}
}
int CrearArchivoF(int numero,int **PistasFilas,int m , int nn){
	FILE *filas;
   	filas = fopen("PistasFilas.txt", "w"); //abre archivo, si no existe lo crea y si existe su contenido se destruye
   	if (filas == NULL){
      	printf("El fichero no se puede abrir");
      	exit(1); 
  	}
	for (int i = 0; i <m; ++i)
	{	
		for (int j = 0; j <= nn; ++j)
		{	
			if(PistasFilas[i][0]==0){
				fprintf(filas,"%i",PistasFilas[i][j]);
				fputs("\n",filas);
				j=nn;
			}
			if(PistasFilas[i][j]<numero && PistasFilas[i][j]>0){
				fprintf(filas,"%i",PistasFilas[i][j]);
				fputs("\t",filas);
				if(PistasFilas[i][j+1]==0 || PistasFilas[i][j+1]==0 && PistasFilas[i][j+2]==0){
					fputs("\n",filas);
				}
			}
		}
	}
	fclose(filas);
}
int CrearArchivoC(int numero,int **PistasColumnas,int m , int nn){
	FILE *columnas;
   	columnas = fopen("PistasColumnas.txt", "w"); //abre archivo, si no existe lo crea y si existe su contenido se destruye
   	if (columnas == NULL){
      	printf("El fichero no se puede abrir");
      	exit(1); 
  	}
	for (int i = 0; i <m; ++i)
	{	
		for (int j = 0; j <= nn; ++j)
		{	
			if(PistasColumnas[i][j]==0){
				i=i;
			}
			else
			{	
				if(PistasColumnas[i][j]<=numero){
					fprintf(columnas,"%i",PistasColumnas[i][j]);
				}
				if(PistasColumnas[i][j+1]>0){
					fputs("\t",columnas);
				}
				else if(PistasColumnas[i][j+1]<=0){
					fputs("\n",columnas);
				}
				//printf("PistasFilas[%i][%i]=%i\n",i,j,PistasFilas[i][j]);
				/*else if(j == nn){
					printf("\n");
				}*/
			}
		}
	}
	fclose(columnas);
	
}
int main(int argc, char const *argv[])
{

	int espacio = 1; 
	int **PistasFilas;
	PistasFilas = (int **)malloc(sizeof(int * ) * 100);
	for(int i = 0; i < (100); ++i)
	{
		PistasFilas[i] = (int *)malloc(sizeof(int )* n);
	}
	int **PistasColumnas;
	PistasColumnas = (int **)malloc(sizeof(int * ) * 100);
	for(int i = 0; i < (100); ++i)
	{
		PistasColumnas[i] = (int *)malloc(sizeof(int )* n);
	}
	FILE *archivo;
	
	int c;
	int jj=0;
	
	//int numero;
	archivo = fopen("hola.txt", "r");
	//fscanf(archivo, "%i",&numero);   //Abrimo  el archivo
	
	
	/*int nuum;
	fscanf(archivo,"%i",&nuum);
	printf("el numero es %i\n",nuum);*/
	int numero;
	numero = 10;
	// con fscanf obtenemos el numero
	// con fscanf obtenemos el numero
	char matriz[numero][numero];
	int ii=0;
	while(ii<numero){
		while(jj<numero){
			PistasFilas[ii][jj] = 0;
			jj++;
		}
		ii++;
	}
	
	for(int k=0;k<numero;k++)                                   //Iteramos i,j para  ir almacenando los valores.
	    for(int l=0;l<numero+1;l++){
	        fscanf(archivo, "%c", &matriz[k][l]);
	        //printf("matriz[%i][%i] %c\n",k,l,matriz[k][l]);            // Leemos un float y lo guardamos en A en la posicion i,j
	                		                             // Leemos un float y lo guardamos en B en la posicion i,j
	}
	fclose(archivo);
	int contador = 0;
	/*for(int i = 0 ; i < numero; i++){
		for (int j = 0; j < numero ; ++j)
		{
			printf("%c",matriz[i][j]);
		}
		printf("\n");
	}
	//printf("%c \n",matriz[numero][numero+1]);*/

	
	
	//printf("%c",matriz[3][0]);
	printf("\n");
	filas(PistasFilas,numero,matriz);
	columnas(PistasColumnas,numero,matriz);

	int j = 0;
	int i = 0;
	int nn = NmaxF;
	int mm = NmaxC;
	printf("el nn %i\n",nn);
	printf("el mm %i\n",mm);
	m = numero;
	printf("m%i\n",m);	
	CrearArchivoF(numero,PistasFilas,m,nn);
	CrearArchivoC(numero,PistasColumnas,m,mm);
	/*while(i<m+1){
		while(j<n){
			printf(" pos i%i , pos j%i , letra = %i\n", i , j , PistasFilas[i][j]);
			j++;
		}
		i++;
	}*/
	
	/*for (int i = 0; i < m; ++i)
	{	
		for (int j = 0; j <= nn; ++j)
		{	
			if(PistasFilas[i][0]==0){
				printf("pista %i %i = %i\n",i,j,PistasFilas[i][j]);
				j=nn;
			}
			if(PistasFilas[i][j]<numero && PistasFilas[i][j]>0){
				printf("pista %i %i = %i ",i,j,PistasFilas[i][j]);
				printf("\t");
				if(PistasFilas[i][j+1]==0){
					printf("\n");
				}
			}
			if(PistasFilas[i][j]==0){
				i=i;
			}
			else
			{	
				if(PistasFilas[i][j]<=numero){
					printf("pista %i %i = %i ",i,j,PistasFilas[i][j]);
				}
				if(PistasFilas[i][j+1]>0 && PistasFilas[i][j+1]<numero){
					printf("\t");
				}
				else if(PistasFilas[i][j+1]<=0){
					printf("\n");
				}
				
				else if(j == nn){
					printf("\n");
				}
			}
		}
	}*/
	

	return 0;
}