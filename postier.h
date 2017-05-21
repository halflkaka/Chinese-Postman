#include <limits.h>
#define INFINI INT_MAX

// Taille du graphe (nombre de sommets)
#define N 8

// Matrice d'adjacence du graphe
unsigned int Adjacence[N][N] = {
    {0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
    {1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 },
    {1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 },
    {1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 },
    {1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 },
    {1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 },
    {1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 },
    {1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 }};

// Matrice des poids du graphe
// représentant les kilomètres à parcourir par
// le postier chinois.
unsigned int Kilometres[N][N] = {
    {INFINI , 4 , 7 , 7 , 7 , 10, 4 , 10},
    {4 , INFINI , 10, 7 , 8 , 5 , 10, 1 },
    {7 , 10, INFINI , 10, 7 , 1 , 6 , 6 },
    {7 , 7 , 10, INFINI , 4 , 9 , 6 , 10},
    {7 , 8 , 7 , 4 , INFINI , 2 , 5 , 6 },
    {10, 5 , 1 , 9 , 2 , INFINI , 5 , 3 },
    {4 , 10, 6 , 6 , 5 , 5 , INFINI , 3 },
    {10, 1 , 6 , 10, 6 , 3 , 3 , INFINI }};

// Charge maximale
const unsigned int CHARGE_MAXIMALE = 25;

// Matrice des poids des colis à porter par arête
unsigned int Poids_des_colis[N][N] = {
    {INFINI , 14, 2 , 8 , 12, 4 , 12, 1 },
    {14, INFINI , 13, 1 , 14, 5 , 12, 10},
    {2 , 13, INFINI , 11, 12, 8 , 2 , 13},
    {8 , 1 , 11, INFINI , 1 , 5 , 15, 15},
    {12, 14, 12, 1 , INFINI , 10, 1 , 9 },
    {4 , 5 , 8 , 5 , 10, INFINI , 8 , 4 },
    {12, 12, 2 , 15, 1 , 8 , INFINI , 12},
    {1 , 10, 13, 15, 9 , 4 , 12, INFINI }};
