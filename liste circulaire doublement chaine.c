#include<stdio.h>
#include<stdlib.h>

// Déclaration de la liste doublement chaînée
typedef struct liste {
    int val;
    struct liste *suivant;
    struct liste *precedent;
} liste;

// Fonction pour créer un nœud
liste *create(int val) {
    liste *nouveau = (liste*)malloc(sizeof(liste));
    if(!nouveau) {
        printf("Erreur d'allocation\n");
        exit(1);
    }
    nouveau->val = val;
    nouveau->suivant = nouveau;   // Pointe vers lui-même
    nouveau->precedent = nouveau; // Pointe vers lui-même
    return nouveau;
}

// Fonction d'insertion en tête de liste
void inserttete(liste **tete, int val) {
    liste *nouveau = create(val);
    if(*tete == NULL) {
        // La liste est vide
        *tete = nouveau;
    } else {
        // Insérer en tête
        liste *dernier = (*tete)->precedent; // Le dernier nœud
        
        nouveau->suivant = *tete;
        nouveau->precedent = dernier;
        dernier->suivant = nouveau;
        (*tete)->precedent = nouveau;
        *tete = nouveau; // Nouvelle tête
    }
}

// Fonction pour insérer en fin
void insertfin(liste **tete, int val) {
    liste *nouveau = create(val);
    if(*tete == NULL) {
        // Liste vide
        *tete = nouveau;
    } else {
        liste *dernier = (*tete)->precedent; // Le dernier nœud
        
        dernier->suivant = nouveau;
        nouveau->precedent = dernier;
        nouveau->suivant = *tete;
        (*tete)->precedent = nouveau;
    }
}

// Fonction d'affichage dans le sens direct
void affiche(liste *tete) {
    if(tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    liste *T = tete;
    printf("Sens direct : ");
    do {
        printf("%d -> ", T->val);
        T = T->suivant;
    } while(T != tete);
    printf("(retour à tête : %d)\n", tete->val);
}

// Fonction d'affichage dans le sens inverse
void affiche_inverse(liste *tete) {
    if(tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    liste *T = tete->precedent; // Commencer par le dernier
    printf("Sens inverse : ");
    do {
        printf("%d -> ", T->val);
        T = T->precedent;
    } while(T != tete->precedent);
    printf("(retour au dernier : %d)\n", tete->precedent->val);
}

// Fonction principale
int main() {
    liste *tete = NULL;
    
    // Insertion en tête
    inserttete(&tete, 1);
    inserttete(&tete, 3);
    inserttete(&tete, 6);
    printf("Liste après insertion en tête :\n");
    affiche(tete);
    affiche_inverse(tete);
    
    // Insertion en fin
    insertfin(&tete, 5);
    insertfin(&tete, 7);
    printf("\nListe après insertion en fin :\n");
    affiche(tete);
    affiche_inverse(tete);
    
    return 0;
}