# Harl 2.0

| Dossier de rendu | ex05/ |
| ----- | ----- |
| Fichiers à rendre | Makefile, main.cpp, Harl.cpp, Harl.{h, hpp} |
| Fonctions interdites | Aucune |
---
Connaissez-vous Harl ? Tout le monde connaît Harl, voyons. Au cas où vous n’en auriez jamais entendu parler, vous trouverez ci-dessous le genre de commentaires que Harl est capable de faire. Ils sont classés par niveau de gravité :

- Niveau "DEBUG" : Les messages de débug contiennent des informations contextuelles. On les utilise principalement pour établir des diagnostics.
> Exemple : "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
- Niveau "INFO" : Ces messages contiennent des informations détaillées. On les
utilise pour tracer l’exécution d’un programme en production.
> Exemple : "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
- Niveau "WARNING" : Les messages d’avertissement indiquent un problème potentiel dans le système. Toutefois, on est en mesure de le gérer ou de l’ignorer.
> Exemple : "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
- Niveau "ERROR" : Ces messages indiquent qu’une erreur irrécupérable s’est produite. Il s’agit généralement d’un problème critique qui nécessite une intervention manuelle.
> Exemple : "This is unacceptable ! I want to speak to the manager now."

Vous allez automatiser Harl. Ce ne sera pas difficile étant donné qu’il se répète beaucoup. Vous devez créer une classe Harl avec les fonctions membres privées suivantes :
- `void debug( void );`
- `void info( void );`
- `void warning( void );`
- `void error( void );`

Harl a également une fonction membre publique qui, selon le niveau passé en paramètre, fait appel à l’une des quatre fonctions membres ci-dessus :

`void complain( std::string level );`

Le but de l’exercice est de vous faire utiliser des pointeurs sur fonctions membres.

Ce n’est pas qu’une suggestion. Harl doit pouvoir se plaindre **sans** avoir recours à une forêt de if/else if/else. Il n’y réfléchit pas à deux fois !

Créer et rendre des tests pour montrer que Harl se plaint beaucoup. Vous pouvez utiliser les exemples de commentaires indiqué au dessus dans le sujet ou choisir d’utiliser des commentaires de votre choix.