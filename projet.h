#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct noeud {
  int valeur;
  struct noeud *lettre[28];
} noeud ;

typedef struct{
	noeud *dictionnaire[26];
} dico;

void creer_et_initialiser_le_noeud(noeud ** parbre, int v);

void remplissage(noeud ** parbre, char ch[128]);

void lecture(noeud ** parbre, FILE *fichier,int v);

void insertion_dictionnaire(noeud * Arbre[26]);

void initialiser_dictionnaire(noeud * Arbre[26]);

int existe(noeud ** parbre,char ch[128]);

void corriger_texte(noeud*arbre[26]);

void desallouer_arbre(noeud *arbre);

void desallouer_dictionnaire(noeud*arbre[26]);








