#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule {
    int Val;
    struct Cellule* Suiv;
} Cellule;

// Fonction pour afficher la liste
void afficher(Cellule* P) {
    while (P != NULL) {
        printf("%d -> ", P->Val);
        P = P->Suiv;
    }
    printf("NULL\n");
}

// Fonction pour trier la liste (tri par échange simple)
void trier(Cellule* P) {
    if (P == NULL) return;

    Cellule *i, *j;
    int tmp;

    for (i = P; i->Suiv != NULL; i = i->Suiv) {
        for (j = i->Suiv; j != NULL; j = j->Suiv) {
            if (i->Val > j->Val) {
                tmp = i->Val;
                i->Val = j->Val;
                j->Val = tmp;
            }
        }
    }
}

int main() {
    Cellule *P = NULL, *L, *Nouveau, *Dernier;
    int V, n, i;

    // ---- 1. Création de la liste ----
    printf("Combien de valeurs voulez-vous mettre dans la liste ? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Entrer la valeur %d : ", i + 1);
        scanf("%d", &V);

        Nouveau = (Cellule*) malloc(sizeof(Cellule));
        Nouveau->Val = V;
        Nouveau->Suiv = NULL;

        if (P == NULL) {
            P = Nouveau;
            Dernier = P;
        } else {
            Dernier->Suiv = Nouveau;
            Dernier = Nouveau;
        }
    }

    printf("Liste initiale : ");
    afficher(P);

    // ---- 2. Tri de la liste ----
    trier(P);
    printf("Liste apres tri : ");
    afficher(P);

    // ---- 3. Insertion dans la liste triée ----
    printf("Entrer une valeur a inserer dans la liste triee : ");
    scanf("%d", &V);

    if (P == NULL || V < P->Val) {
        // Insérer en tête
        Nouveau = (Cellule*) malloc(sizeof(Cellule));
        Nouveau->Val = V;
        Nouveau->Suiv = P;
        P = Nouveau;
    } else {
        // Parcourir pour trouver la bonne position
        L = P;
        while ((L->Suiv != NULL) && (L->Suiv->Val < V)) {
            L = L->Suiv;
        }
        Nouveau = (Cellule*) malloc(sizeof(Cellule));
        Nouveau->Val = V;
        Nouveau->Suiv = L->Suiv;
        L->Suiv = Nouveau;
    }

    printf("Liste finale apres insertion : ");
    afficher(P);

    return 0;
}