#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ascii 48;
#define emp 0;

/*Francisco Cobos Loriente
DAM1 Programacion ejer 07hanoi
realiza el juego de hanoi recursivo en modo grafico*/
/*Globales*/
const int m=3; /*m de montes*/
int *mont;
void pinta(int);

main(){
int n,np;
int i,j;
char *sa=(char *)malloc(10*sizeof(char));
int anch;

void movFichas(int,int,int,int,int);

printf("\n###Hanoi grafico recursivo\n");
printf("Introduce el numero de discos\n");
scanf("%s",sa);
n=*sa-ascii;

mont=(int*)malloc((m*n+5)*(sizeof(int))); /*damos memoria al pntero de las torres*/

for(i=0; i<m; i++)
for(j=0;j<=n;j++)*(mont+n*i+j)=emp;/*Ponesmos los ceros en las torrs que nos serviran para encotrar el final*/

anch=n*2-1;
for(i=0;i<n;i++){*(mont+n*0+i)=anch;anch-=2;} /*Damos el tamaño a las fichas*/

np=n; /*np es n fija*/
pinta(np);
getchar;
movFichas(n,np,0,1,2);
}

void movFichas(int n, int np, int org, int aux, int des){
/*pre: recibe los identificadores de las torres
post: implementa el algoritmo de hanoi y llama a la funcion para imprimir los graficos*/
int i=0;
int j=0;
char pau[10];
if(n==1){

while(*(mont+np*org+i)!=0)i+=1; /*buscamos el primer 0 de origen*/
while(*(mont+np*des+j)!=0)j+=1;
*(mont+np*des+j)=*(mont+np*org+(i-1)); /*pasmamos origen a destino*/
*(mont+np*org+(i-1))=0;
pinta(np);
}
else{
movFichas (n-1,np,org,des,aux);
while(*(mont+np*org+i)!=0)i+=1; /*buscamos el primer 0 de origen*/
while(*(mont+np*des+j)!=0)j+=1;
*(mont+np*des+j)=*(mont+np*org+(i-1)); /*pasmamos origen a destino*/
*(mont+np*org+(i-1))=0;
pinta(np);
movFichas (n-1,np,aux,org,des);
}
}

void pinta(int np){
/*pre: recibe el numero fijo de torres
post: pinta las torres despues de los mobimientos*/
int i,j,k,l;
int espa=np*2-1; /*calculamos los espacios en blanco*/
int espa2=np/2+2;
for(i=np-1;i>-1;i--){
for(j=0;j<m;j++){
printf(" ");
if(j==0)for(k=espa2;k>-1;k--)printf(" ");
for(k=0;k<*(mont+np*j+i);k++)printf("x");/*pintamos las torres*/
for(k=*(mont+np*j+i);k<espa+3;k++)printf(" ");

}
espa2-=1;
printf("\n");
}
printf(" ");

printf("Origen");for(k=0;k<((np*2)-3);k++)printf(" "); /*pintamos los nombres de las torres y calculamos espacios*/
printf("Auxiliar");for(k=0;k<((np*2)-3);k++)printf(" ");
printf("Destino");

printf("\nEnter para continuar...\n");
getchar();
}