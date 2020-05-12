#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(a) (a *) malloc ( sizeof(a) )

struct no{
   int dado;
   struct no *proximo;
   struct no *anterior;
};

// ponteiros de referência
struct no *inicio;
struct no *fim;

void inserirLista ( int dado ){
   struct no *novo = MALLOC ( struct no );
   struct no *atual;
        
   if ( !novo ){
      perror ( "Malloc: " );
      return ;
   }
        
   // atribução do novo valor...
   novo -> dado = dado;
        
   // cria lista
   if ( !inicio ){
      novo -> proximo = NULL;
      novo -> anterior  = NULL;
      inicio = novo;
      fim = novo;
                
      return ;
   }
        
   // se não for o primeiro elemento da lista...
   atual = inicio;
        
   while ( atual ){
      if ( atual -> dado < dado ){
         atual = atual->proximo;
      }
      else{
         // elemento intermediário - caso 2
         if ( atual->anterior ){
            novo -> proximo = atual;
            novo -> anterior = atual -> anterior;
            atual -> anterior -> proximo = novo;
            atual  ->anterior = novo;
                                
            return ;
         }
         // novo primeiro elemento - caso 1
         novo -> proximo = atual;
         novo -> anterior = NULL;
         atual -> anterior = novo;
         inicio = novo;
                        
         return ;
      }
   }
   // novo último elemento - caso 3
   fim -> proximo = novo;
   novo -> proximo = NULL;
   novo -> anterior = fim;
   fim = novo;
  
   return ;
}

void imprimeLista (){
   struct no *atual = inicio;
        
   while ( atual ){
      printf ( "Dado contido na lista:  %.2d\n", atual -> dado );
      atual = atual -> proximo;
   }
   return ;
}

struct no *procurar ( int dado ){
   struct no *atual = inicio;
        
   while ( atual ){
      if ( atual -> dado == dado){
         return atual;
      } 
      else{
         atual = atual -> proximo;
      }
   }
   return NULL;
}

void removerLista ( struct no *dado ){
   if ( !dado ){
      return ;
   }
        
   // item intermediário
   if ( dado -> proximo && dado -> anterior ){
      dado -> anterior -> proximo = dado -> proximo;
      dado -> proximo -> anterior = dado -> anterior;
                
      free( dado );
      return ;
   }
        
   // primeiro item
   if ( dado == inicio ){
      inicio = dado -> proximo;
      inicio -> anterior = NULL;
                
      free( dado );
      return ;
   }
        
   // último elemento
   if ( dado == fim ){
      fim = dado -> anterior;
      fim -> proximo = NULL;
                
      free( dado );
      return ;
   }
}

int main ( void ){
   int contador;
   inicio = fim = NULL;
        
   for ( contador = 1; contador <= 10; contador++ ){
      inserirLista(contador); // caso 3 - inserção no final...
   }
      
   imprimeLista(); 
   puts("");
        
   inserirLista(0);  // caso 1
   inserirLista(12); // caso 3
   inserirLista(11); // caso 2
        
   imprimeLista(); 
   puts("");
        
   // teste da função de procura
   printf ("Procurar( 3 ): %.2d\n\n", procurar(3) -> dado );

   removerLista( procurar( 0) ); // caso 1
   removerLista( procurar( 5) ); // caso 2
   removerLista( procurar(12) ); // caso 3
        
   imprimeLista(); 
   puts("");
        
   return 0;
}