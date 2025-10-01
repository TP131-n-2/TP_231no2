#include<stdio.h>
#include<stdlib.h>
struct Noeud {
     	int val;
     	struct Noeud*suiv ;
	 };
	 void insertionfin(struct Noeud** n,int t){
	 	struct Noeud*p=(struct Noeud*)malloc(sizeof(struct Noeud));
	 	p->val=t ;
	 	p->suiv= NULL;
	 	  if (*n == NULL){
		   *n=p;
		   } else {
		   struct Noeud*l=*n;
		   while(l->suiv !=NULL){
		   	l=l->suiv;
		   }
		   l->suiv=p;
	 }
}
	 void supprimerlesoccurrences(struct Noeud**n,int t){
	 	struct Noeud*m=*n;
	 	struct Noeud*prec=NULL;
	 	 while(m!=NULL){
	 	 	if(m->val==t){
	 	 		if (prec==NULL){
	 	 			*n=m->suiv;
	 	 			free(m);
	 	 			m=*n;
				  } else {
				  	prec->suiv=m->suiv;
				  	free(m);
				  	m=prec->suiv;
				  }
			  } else {
			  	prec=m;
			  	m=m->suiv;
			  }
		  }
	}
	 void afficher(struct Noeud*n){
	 	struct Noeud*l=n;
	 	while(l!=NULL){
		 printf("%d ->",l->val);
		 l=l->suiv;
		 }
		 printf("NULL\n");
	 }
		  int main() {
		  	struct Noeud*n=NULL;
		  	int j,y,z,i=1;
		  printf("combien d element voulez vous inserer\n");
		  scanf("%d",&j);
		  if(j==0){
		  	printf("votre liste est actuellement vide aucune suppression ne peut etre effectue");
		  } else{
		  
		      while(i<=j){
		  	printf("entrez l element numero %d\n",i);
		  	scanf(" %d",&y);
		  	insertionfin(&n,y);
		  	i++;
		  }
		  printf("quel element voulez vous supprimer ?\n");
		  scanf("%d",&z);
		  printf("Votre liste avant la suppression de toute les occurrences de l element %d\n",z);
		   afficher(n);
		   supprimerlesoccurrences(&n, z);
		   printf("Votre liste apres la suppression de l element %d est \n",z);
		   afficher(n);
	}
		   return 0;
		  }
		  
	 
