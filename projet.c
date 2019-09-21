#include "projet.h"

void creer_et_initialiser_le_noeud(noeud ** parbre, int v){
  *parbre=malloc(sizeof(noeud));
  (*parbre)->valeur=v;
  for(int i=0;i<28;i++)
    (*parbre)->lettre[i]=NULL;
}

void remplissage(noeud ** parbre, char ch[128]){
	int i,n=strlen(ch);
	if(*parbre==NULL)
	  creer_et_initialiser_le_noeud(parbre,tolower(ch[0]));
	for(i=1;i<n;i++){
	  if(ch[i]==39)
	    parbre=&(*parbre)->lettre[26];
	  else
	    parbre=&(*parbre)->lettre[tolower(ch[i])-'a'];
	  if(*parbre == NULL)
	    creer_et_initialiser_le_noeud(parbre,tolower(ch[i]));
	}
	creer_et_initialiser_le_noeud(&(*parbre)->lettre[27],0);
}


void lecture(noeud ** parbre, FILE *fichier,int v){
	char ch[128];
	noeud ** tmp_parbre=parbre;
	while(fscanf(fichier,"%s",ch)==1)
	  if(tolower(ch[0])==v)
	    remplissage(tmp_parbre,ch);
}

void insertion_dictionnaire(noeud * Arbre[26]){
  int i;
  for(i=0;i<26;i++){
    FILE *dico=fopen("dico.txt","r");
    lecture(&Arbre[i],dico,i+'a');
    fclose(dico);
  }
}

void initialiser_dictionnaire(noeud * Arbre[26]){
  int i;
  for(i=0;i<26;i++)
    Arbre[i]=NULL;
}

int existe(noeud ** parbre,char ch[128]){
  int n=strlen(ch);
  int a,cpt=0;
  noeud ** tmp_parbre=parbre;
  for(int i=0;i<n-1;i++){
    if((*tmp_parbre)!=NULL){
      if(tolower(ch[i])==(*tmp_parbre)->valeur){
	cpt++;
	if (ch[i+1]==39)
	  tmp_parbre=&(*tmp_parbre)->lettre[26];
	else
	  tmp_parbre=&(*tmp_parbre)->lettre[tolower(ch[i+1])-'a'];
      }
    }
  }
  if ((*tmp_parbre)!=NULL){
    if (tolower(ch[cpt])==(*tmp_parbre)->valeur)
      if ((*tmp_parbre)->lettre[27]!=NULL)
	a=1;
  }
  else a=0;
	return a;
}
void corriger_texte(noeud*arbre[26]){
  char ch[128];
  FILE *texte=fopen("texte.txt","r");
  while(fscanf(texte,"%s",ch)==1){
    if(!existe(&arbre[tolower(ch[0])-'a'],ch))
      printf("%s\n",ch);
	}
  fclose(texte);
}


void desallouer_arbre(noeud *arbre){
  
  if(arbre != NULL)
    for(int i=0;i<28;i++){
      if(arbre->lettre[i] != NULL)
	desallouer_arbre(arbre->lettre[i]);
    }
  else
    free(arbre);
  
}
void desallouer_dictionnaire(noeud*arbre[26]){
  for(int i=0;i<26;i++)
    desallouer_arbre(arbre[i]);
}

