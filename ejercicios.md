[MST] Ejercicio 1
pendiente
Se vence el 06/11/2026 18:18100 puntos
Dado el siguiente grafo, calcula su MST usando Kruskal
                      (0)
                     /  \
                     /     \
                    /         \
                  /            \ 2
                 /               \
                 /                  \
                /                      \
 (4)------------+-----5------------------(1)
  \  \          /                      /  /
   \    \    6 /                    /    /
    \     \   /                   /     /
    \        \/                /        /
    \        /  \           /           /
   9 \      /    7 \     / 8           / 3
      \     /         X               /
      \    /       /     \            /
      \   /     /           \         /
       \ /    /               \      / 
        \/ /                     \  /
       (3)                         (2)
en forma de lista de adyacencia


Nodo


Vecinos (peso)


0


1 (2), 3 (6)


1


0 (2), 2 (3), 3 (8), 4 (5)


2


1 (3), 4 (7)


3


0 (6), 1 (8), 4 (9)


4


1 (5), 2 (7), 3 (9)
Lineamientos
calcula el MST del del grafo anterior
crea un archivo que contenga el grafo y kruskal
en el main genera el grafo con la lista anterior e imprime el peso total del MST
Pruebas
#1
Entrada
(sin entrada)
Salida esperada
16