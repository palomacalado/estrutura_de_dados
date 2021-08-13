#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int particiona(int vetor[],int menor, int maior);
void quick(int vetor[],int menor, int maior);
void merge_sort(int vetor[], int inicio,int fim);
void merge(int vetor[], int inicio,int meio, int fim);
void selection(int vetor[], int n);

int main (int argc,char **argv){
	int *vetor = (int*) malloc(10000*sizeof(int));
	int i=0, contador = 0;
	int inicio=0;

    // leitura e armazenamento dos numeros

	while (!feof(stdin)){
		int num;
		if(scanf ("%d",&num)!=0){
		vetor[i++] = num;
		contador++;
		
        		if (contador==10000){
        			vetor = (int*)realloc(vetor,20000*sizeof(int));
       
        		}
        	}else{
			printf ("Nao foram passados os argumentos\n");
			return 0;
	        }
 	}



	//testa a entrada e executa o algoritmo selecionado na linha de comando
	
	if(argc==1){
		selection(vetor,contador);
   		for(int i=0;i<contador-1;i++)
      			printf("%d\n",vetor[i]);
       
       	free (vetor);
   		return 0;
	}
	if (strcmp(argv[1],"-q")==0){
		quick(vetor,inicio,contador);
   		for(int i=0;i<contador-1;i++)
      			printf("%d\n",vetor[i]);
       	
       	free (vetor);
   		return 0;
	}
	if (strcmp(argv[1],"-m")==0){
		merge_sort(vetor, inicio,contador);
     		for(i=0;i<contador-1;i++)
			printf(" %d\n",vetor[i]);
			
        	free(vetor);
		return 0;
	
	}
	
	return 0;
}

int particiona(int vetor[],int menor, int maior){

   int aux; //troca de posicoes
   int cont = menor;

   for(int i=menor+1 ; i<=maior ; i++){

       if( vetor[i] < vetor[menor] ){
           cont++;
           aux=vetor[i];
           vetor[i]=vetor[cont];
           vetor[cont]=aux;
       }
   }
   aux=vetor[menor];
   vetor[menor]=vetor[cont];
   vetor[cont]=aux;

   return cont;
}

void quick(int vetor[],int menor, int maior){
   int pivo;

   if(menor < maior){
       pivo = particiona(vetor,menor,maior);
       quick(vetor,menor,pivo-1);
       quick(vetor,pivo+1,maior);
   }
}

void merge_sort(int vetor[], int inicio,int fim){
    int meio;

    if(inicio<fim-1){  // testa se o vetor tem 1 unidade
        meio = floor((inicio+fim)/2); // calcula o meio arredondando para menos
        merge_sort(vetor,inicio,meio);
        merge_sort(vetor,meio+1,fim);
        merge(vetor,inicio,meio,fim);
    }
    
}
void merge(int vetor[], int inicio,int meio, int fim){

	
     //temp tem que ser um vetor temporário, que nitidamente podemos ver que não é
    int *temp = malloc((fim-inicio)* sizeof(int));
    int i = inicio;
    int j = meio;
    int pos =0;


   while(i<meio && j<=fim){
        if (vetor[i]<=vetor[j]){
            temp[pos++] = vetor[i++];
            
        }
        else {
            temp[pos++] = vetor[j++];
           
        }
    }
    //um dos dois lados acabou de ser percorrido, agora falta o outro lado
    while (i< meio){
        temp[pos++] = vetor[i++];
    }
    while(j<fim){
    	temp[pos++] = vetor[j++];
    }
  
    //Agora falta transferir os componentes do vetor temporário
    //para o vetor definitivo
    for(i = inicio;i< fim;i++){
        vetor[i] = temp[i-inicio];
    }

    free(temp);

}

void selection(int vetor[], int n){ 
    int temp=0,i,j;

            for(i=0;i<n-1;i++){
                for(j=0;j<n;j++){
                    if(vetor[i] < vetor[j]){
                        temp = vetor[i];
                        vetor[i] = vetor[j];
                        vetor[j] = temp;
                    }
                }
                
            }
    
}




