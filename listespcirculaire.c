#include<stdio.h>
#include<stdlib.h>

// Déclaration de la liste
typedef struct liste {
    int val;
    struct liste *suivant;
} liste;

// Fonction pour créer un nœud
liste *create(int val) {
    liste *nouveau = (liste*)malloc(sizeof(liste));
    if(!nouveau) {
        printf("Erreur d'allocation\n");
        exit(1);
    }
    nouveau->val = val;
    nouveau->suivant = nouveau; // Pointer vers lui-même (circular)
    return nouveau;
}

// Fonction d'insertion en tête de liste
void inserttete(liste **tete, int val) {
    liste *nouveau = create(val);
    if(*tete == NULL) {
        // La liste est vide, ajout en tête
        *tete = nouveau;
    } else {
        // Insérer en tête
        liste *T = *tete;
        // Trouver le dernier nœud pour maintenir la circularité
        while(T->suivant != *tete) {
            T = T->suivant;
        }
        T->suivant = nouveau; // Le dernier pointe vers le nouveau
        nouveau->suivant = *tete; // Le nouveau pointe vers l'ancienne tête
        *tete = nouveau;
    }
}

// Fonction pour insérer en fin
void insertfin(liste **tete, int val) {
    liste *nouveau = create(val);
    if(*tete == NULL) {
        // Liste vide, devient la tête
        *tete = nouveau;
    } else {
        liste *T = *tete;
        // Trouver le dernier nœud
        while(T->suivant != *tete) {
            T = T->suivant;
        }
        T->suivant = nouveau;
        nouveau->suivant = *tete;
    }
}

// Fonction d'affichage
void affiche(liste *tete) {
    if(tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    liste *T = tete;
    do {
        printf("%d -> ", T->val);
        T = T->suivant;
    } while(T != tete);
    printf("(retour à tête : %d)\n", tete->val);
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
    
    // Insertion en fin
    insertfin(&tete, 5);
    insertfin(&tete, 7);
    printf("\nListe après insertion en fin :\n");
    affiche(tete);
    
    return 0;
}