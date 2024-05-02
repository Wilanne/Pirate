# Nom du Projet

```plaintext
 ███████████   ███                       █████                        ███  
░░███░░░░░███ ░░░                       ░░███                        ░███   
 ░███    ░███ ████  ████████   ██████   ███████    ██████   █████    ░███
 ░██████████ ░░███ ░░███░░███ ░░░░░███ ░░░███░    ███░░███ ███░░     ░███
 ░███░░░░░░   ░███  ░███ ░░░   ███████   ░███    ░███████ ░░█████    ░███
 ░███         ░███  ░███      ███░░███   ░███ ███░███░░░   ░░░░███   ░░░ 
 █████        █████ █████    ░░████████  ░░█████ ░░██████  ██████     ███
░░░░░        ░░░░░ ░░░░░      ░░░░░░░░    ░░░░░   ░░░░░░  ░░░░░░     ░░░ 
```

## Description

Ce projet est écrit en C et se trouve dans le dossier 'base'. Ce projet est l'"aboutissement" du cours de C avancé, par Mr Jouault.

Le jeu s'articule sur la méthode actuellement utiliser en conception de jeu par les grands éditeurs. A savoir, le principe Run, HandleEvent, Update, Draw. Permettant de créer une interface "game" ayant accès à toutes les données possible et ne laissant à la fonction main uniquement la possibilité de lancer le jeu. 

## Installation

1. Clonez ce dépôt sur votre machine locale.
2. Naviguez jusqu'au dossier 'base'.
3. Compilez led fichierd *.c en utilisant : make

## Configuration

Dans le ficher `utils.h`, des macros sont présentes afin de pouvoir configurer les aspects du Jeu

```
// Map size
#define LINES 10
#define COLUMNS 10

// Number of elements
#define PLAYER 1
#define TREASURE 2
#define TRAP 5
#define PIRATE 2

// Player settings
#define POS_X 0
#define POS_Y 0
#define HEALTH 3 
```

## Flags de compilations 

    -g -pedantic -pedantic-errors -Wall -fsanitize=address

## Utilisation

Après la compilation, vous pouvez exécuter le programme avec `./Jeu`.

## Règles 

Les commandes sont de type WASD (clavier US), chaque `T` est un trésore et raporte un point, la partie est gagné quand tous les trésors sont trouvés.

Les pièges sont cachés et font perdre un ou plus de point de vie (configurable)

Les pirates se déplacent vers vous ! (Pas de perde de points de vie et bug, les pirates éffacent les charactères déjà présents sur la grille de jeu...)

Lorsque le joueur n'as plus de vie il perd la partie !

## Contribution

Les contributions sont les bienvenues.

## Licence

Ce projet est sous MIT

```
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```