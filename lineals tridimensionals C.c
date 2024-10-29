#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


typedef struct{
	
	double x;
	double y;
	double z;
	
} punt;    //Establim l'estructura "punt", on posarem les coordenades de cada punt 

punt puntMig(punt prim, punt seg, double rao){
	
	punt puntmig;
	
	puntmig.x = (seg.x+prim.x)/(double) rao;
	puntmig.y = (seg.y+prim.y)/(double) rao;
	puntmig.z = (seg.z+prim.z)/(double) rao;
		
	return puntmig;                     //D'aquesta manera, cada cop que li manem de fer "puntMig" 
}                                      //ens retornarà el punt mig entre els dos donats

int main(){
	
	char nom[100];
	int i, j, n, p;
	double m, rao;
	FILE *f;
	punt PM={0.25,0.5, 0};                
    punt *Punts;                       //anomenem les variables i els unts que utilitzarem, també creem el fitxer
	
	srand(time(NULL));                 //després necessiarem utilitzar un nombre aleatori. Això ens permetrà tenir aquest nombre
	
	printf("Escriu el nom del fitxer:\t");
	scanf("%s",nom);
	
	printf("Escriu el nombre d'iteracions:\t");
	scanf("%d",&n);    
    
    printf("Escriu el nombre de punts:\t");
	scanf("%d",&p);
    
    printf("Escriu la rao:\t"); // el programa ens demanarà posar nom al fitxer que ha creat, 
	scanf("%lf",&rao);          // quantes iteracions volem fer, el nombre de punts i la raó del fractal 
    
    Punts = (punt *)calloc(p,sizeof(punt));
    
    if(Punts == NULL){
    printf("No hi ha suficient memoria");
    exit(1);
    }          //Això simplement és un mecanisme de seguretat, per si es posa un nombre de punts massa gran
   
    
    f = fopen (nom, "w");  //S'obre el fitxer, per poder escriure
    
    for(j=1 ; j<=p ; j++){
        
        printf("Escriu la component x del punt %d:\t", j);
        scanf("%lf",&Punts[j].x);
        
        printf("Escriu la component y del punt %d:\t", j);
        scanf("%lf",&Punts[j].y);
        
        printf("Escriu la component z del punt %d:\t", j);
        scanf("%lf",&Punts[j].z);
        
        
        fprintf(f,"%lf \t %lf \t %lf \n", Punts[j].x, Punts[j].y, Punts[j].z);
        
    }                                       //L'ordinador pregunta les components de tots els punts demanats
	
	fprintf(f,"%lf \t %lf \t %lf \n", PM.x, PM.y, PM.z);
	
	for(i=0 ; i<n ; i++){
		
		m = (rand()/(double)RAND_MAX)*p;                  // ens dóna un nombre aleatori entre 0 i p (el nombre de punts)
    
		for(j=1 ; j<=p ; j++){                             // es busca aquest punt aleatori
            
            if(m>=(j-1) && m<j){
                PM = puntMig(PM, Punts[j], rao);            // es fa el punt mig entre el punt aleatori i el que ja teníem
            }
        }
        	
		fprintf(f,"%lf \t %lf \t %lf \n", PM.x, PM.y, PM.z);                                     //S'escriu el punt resultant
	}
	
	fclose(f);
	
	return 0;                                                   //Si el programa retorna 0 vol dir que s'ha executat correctament
}
