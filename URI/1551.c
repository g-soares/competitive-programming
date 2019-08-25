#include <stdio.h>
   
int main(){
    char letra;
    int teste[26];
    int cont,parada,confere,n_linha;
    scanf("%d ", &n_linha);      
 
    while(n_linha > 0 ){
        parada = 0;
        
        for(cont = 0; cont < 26 ; cont++){
            teste[cont] = 0;
        }
           
        while(parada == 0){
            letra = getchar();
           
            if(letra == ' '){
            }
            else if(letra == ','){
               
            }else if (letra == '\n'){
                parada = 1;
            }
            else{
             teste[letra-97] = 1;
            }
        }
           
        confere = 0;
        for(cont = 0; cont < 26; cont++){
            if(teste[cont] == 1){
                confere ++;
            }
        }
        
        if(confere == 26){
            printf("frase completa\n");
        }
        else if ( confere > 12){
            printf("frase quase completa\n");
        }
        else{
            printf("frase mal elaborada\n");
        }
        n_linha--;      
    }
       
    return 0;
}