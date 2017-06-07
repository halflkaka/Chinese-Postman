# Chinese-Postman

An algorithm for Chinese Postman Problem.

Including 'Edmonds' & 'Dijkstra'

postier.h is an exemple

Mission is to design a programe which produce a cycle of Chinese postman with the weight minimal.
The output should be in form of  [0,3,1,5,4,2,6,8,7,0] which interpretes the cycle 0 → 3 → 1 → 5 → 4 → 2 → 6 → 8 → 7 → 0.
  
# 中国邮递员问题

最短路径算法 + 欧拉回路算法 + 最大匹配算法

# Algorithmes que j’ai utilisé dans le problème Postier Chinois :

## 1.1	 Dijkstra
Mon code ‘dijkstra.h’ utilise l’algorithme Dijkstra pour trouver le chemin du poids minimal et doubler ces chemins.
Pi[N] enregistre le poids minimal du départ à d’autre sommet. Au début, les valeurs sont egaux aux distances réels entre deux sommets. 
 
Chaque fois choisir un sommet qui n’a pas été étiqueté et du poids minimal. On étiquete ce sommet [pt]. Pour tous les sommets non étiqueté [i], si distance(départ,i) > distance(départ,pt) + distance(pt,i), on peut avoir un plus court chemin du départ à i(départ -> pt -> i). On note [pt] est le sommet précédent du [i] et on refait l’étape initial.
 
Ma fonction ‘dijkstra(départ, arrive)’ donne le poids minimal entre le départ et la destination. Les sommets parcourus dans ce chemin sont aussi enregistrés.
La fonction ‘doubler’ est presque même que ‘dijkstra’, elle double le chemin du poids minimal à la fin. Pour trouver tous les sommets parcourus dans ce chemin, pre[] nous donne le sommet précédent du sommet actuel jusqu’à trouver le départ finalement.
 
## 1.2	 Edmond/Hongrois
Mon code “Hungrois.h” utilise l’algorithme Edmond pour trouver le couplage maximal du poids minimal . J ‘ai aussi écrit un code pour trouver le couplage maximal (“Edmond.h”), mais il n’est pas utilisé dans Postier Chinois. 
D’abord j’ai utilisé la profondeur de recherche (DFS) pour trouver un chemin augmentant et ainsi qu’un couplage. Ensuite, il faut comparer le poids de tous les couplages et déterminer un couplage maximal du poids minimal.
Dans ma fonction “DFS ”, d’abord enlever tous les étiquettes. On part d’un sommet non-étiqueté et pas dans le couplage, pour chaque son sommet adjacent, s’il n’est pas dans le couplage, y ajouter. Sinon, appliquer DFS pour ce sommet (C’est pour trouver un chemin augmentant). Enfin, on a un couplage maximal.
Dans ma fonction ”couplage_poids“, l’idée est d’abord comparer les poids des différents couplage maximals et déterminer le poids le plus petit. Ensuite, retrouver les couplage maximals, si son poids égal au poids minimal, on termine.

## 1.3	 Euler
Après doubler les chemins pour les sommets d’indice impair, il faut trouver un cycle eulérien. 
L’algorithme Euler aussi utilise la méthode de la profondeur de recherche. L’idée est de trouver différents cycles et enlever les chemins parcourus. Enfin combiner les cycles.
Dans mon code “Euler.h”, j’utilise une pile (stack) pour enregistrer le cycle. La fonction “dfs” ajouter le cycle origine du départ.
Dans la fonction “Euler”, pour le cime de la pile, juger s’il n’y a plus d’arret part de ce sommet. Si il n’y en a plus, enlever ce sommet. Sinon, c’est-à-dire il y a encore un cycle part de ce sommet, et en faisant dfs en ce sommet, on peut combiner ce cycle dans le cycle eulérien.	

