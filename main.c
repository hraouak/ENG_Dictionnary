#include "projet.h"

int main (){
  dico d;
  initialiser_dictionnaire(d.dictionnaire);
  insertion_dictionnaire(d.dictionnaire);
  printf("-----------------------------------------------------------\n");
  printf("Bienvenue dans le correcteur orthographique de HAROUN V1.0\n");
  printf("-----------------------------------------------------------\n");
  printf("\nvoici les fautes dans le texte: \n \n");
  corriger_texte(d.dictionnaire);
  desallouer_dictionnaire(d.dictionnaire);
  printf("\n");
  
  return 0;
}