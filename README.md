# Ma piscine C à 42 - Juillet 2023

![level](https://elydre.github.io/img/piscine/level.png)

## Description

Ce repo contient les projets réalisés lors de ma piscine C à 42.
La piscine C est un mois intensif de programmation en C pour intégrer
l'école 42. La piscine permet d'apprendre les bases d'Unix, de la
programmation en C et de donner un avant-goût de la pédagogie de l'école,
basée sur le peer-learning.

## Mise en Garde

Ce repo est public, et vous êtes libre de vous en inspirer pour vos projets.
Cependant, si vous êtes piscineux, je vous déconseille fortement de copier-coller
le code de ce repo sans le comprendre. Cela ne vous aidera pas à progresser, et
vous risquez d'avoir des surprises lors de la correction et des examens machines...

## Astuces et Conseils

### Avant la piscine

Bien qu'il soit possible de réussir la piscine sans aucune connaissance
préalable, avoir quelques bases en programmation et en C vous aidera
grandement pour vous concentrer sur les projets et la pédagogie de l'école.
Installez une distribution Linux (WSL existe pour Windows) et familiarisez
vous avec les commandes de base. Vous pouvez aussi commencer à apprendre le
C avec des tutoriels en ligne.

### Pendant la piscine

Ne restez pas seul ! Même si vous n'êtes pas à l'aise (oui, je sais), vous
trouverez toujours quelqu'un pour vous aider. Les moteurs de recherche sont
aussi vos amis! Durant les examens machines, vous n'aurez pas accès à
Internet, mais vous pouvez toujours chercher des informations sur le `man`
de votre machine.

Trouvez le temps de dormir, de bien manger et de vous détendre; c'est
long, un mois :)

Si vous êtes bloqué sur un projet, passez au suivant et revenez-y plus tard.
Les days (shell00, shell01, c00, c01, etc.) ne doivent pas être faits à 100%
pour passer à la suite, 50% suffisent. Les derniers exercices d'un day sont
souvent plus difficiles que le début du jour suivant (la fin du c00...).

## Déroulement Global

Chaque semaine se déroule de la même manière:

### Lundi-Jeudi

Le début de semaine est consacré aux days (shell00, shell01, c00, c01, etc.).
Chaque day est composé d'exercices à rendre, généralement une petite dizaine.
Après avoir rendu les exercices (avec git), vous devez les faire valider par
deux piscineux (ils peuvent avoir un niveau très différent du vôtre). Après
vos deux correcteurs 'humains', une correction automatique est lancée
(nommée `moulinette`) qui vérifie que votre code compile et qu'il passe
quelques tests. Une moyenne sera calculée entre les notes de vos correcteurs
et la moulinette. Si vous avez une moyenne supérieure à 50, vous passez au
day suivant, sinon vous devez refaire le day (seulement les exercices ratés).

Vous aurez aussi l'occasion de proposer des plages de disponibilité pour
corriger les exercices des autres piscineux. C'est une bonne occasion de
rencontrer d'autres personnes et de voir comment ils ont résolu les exercices.

### Vendredi

Le vendredi, c'est l'exam machine, est une série d'exercices à faire en 4 heures
(ou 8 heures pour l'examen final). Les exercices sont similaires à ceux des days,
mais vous n'avez pas de correcteurs humains et vous n'avez pas accès à Internet.
La correction est faite automatiquement; pendant les premiers examens, vous aurez
accès à un historique des tests passés et ratés pour vous aider à corriger votre
code.

### Week-end

Le week-end est consacré à un projet (rush) à faire en groupe créé aléatoirement.
Les rushs sont généralement plus difficiles que les days et vous avez 48 heures
pour les rendre. Ils ne sont pas corrigés par des piscineux, mais par des membres
du staff. Les rushs sont les seuls projets où vous pouvez tenter de faire des
bonus (documentation, fonctionnalités supplémentaires, etc.).

## Quelques Détails

### Le Shell

<img src="https://elydre.github.io/img/piscine/shells.png" width="300">

Les premiers jours de la piscine sont dédiés à l'apprentissage du shell.
Je ne connais personne qui ait trouvé ça fun, mais c'est un mal nécessaire.
Ne vous attardez pas trop sur le shell (surtout le `shell01`).

### Le C

<img src="https://elydre.github.io/img/piscine/days.png" width="300">

Le C est au cœur de la piscine. Tout le code que vous écrirez devra être
à la norme de l'école (et donc passer la norminette).
La correction automatique est très stricte: votre code doit être parfaitement
à la norme et fonctionner dans TOUS les cas.

Les fonctions qui gèrent les entiers doivent fonctionner avec `INT_MIN` et
`INT_MAX`; les chaînes de caractères pourront être vides, les tableaux aussi, etc.

Bien que les tests de la moulinette ne soient pas accessibles, vous pouvez
tester votre code vous-même avec des tests génériques. Vous pouvez aussi trouver
des tests comme [semi-auto-correct-42](https://github.com/Buom01/semi-auto-correct-42)
ou la [francinette](https://github.com/xicodomingues/francinette) qui ne sont
pas parfaits, mais qui peuvent vous aider à trouver des erreurs auxquelles vous
n'auriez pas pensé.

### Les Examens

<img src="https://elydre.github.io/img/piscine/exams.png" width="300">

Le staff vous donnera des indications pour vous identifier et vous connecter.
Il y a généralement un `README.md` dans le HOME de votre machine qui vous donnera
des informations pour rendre les fichiers.

Il y a au total 4 examens machines, un par semaine. Les examens sont de plus
en plus difficiles, mais ils sont tous basés sur les notions vues dans les
days. Les examens sont corrigés automatiquement; les premiers examens vous
donneront un historique des tests passés et ratés pour vous aider à corriger
votre code.

### Les Rushs

<img src="https://elydre.github.io/img/piscine/rush.png" width="300">

Les rushs n'ont qu'une seule correction, assurez-vous que votre projet
respecte bien le sujet et faites un maximum de tests avant de le rendre.
Durant la présentation, vous devrez expliquer comment vous avez réalisé
votre projet et comment s'est passé le travail en groupe.
Vous avez carte blanche pour les bonus, surtout si vous avez fini le rush.

Le correcteur risque de vérifier les fuites de mémoire de votre programme,
pensez à bien libérer vos mallocs. Utilisez `valgrind` ou `cc -fsanitize=address -g`
pour vérifier que votre programme ne fuit pas; vérifiez aussi en cas d'erreur.

### Le BSQ

<img src="https://elydre.github.io/img/piscine/bsq.png" width="300">

Le BSQ est le dernier projet de la piscine, il est à rendre en 3 jours.
La correction est faite par trois piscineux ainsi que par la moulinette.
Le BSQ est un projet assez difficile, faites attention à l'optimisation
de votre code et à la gestion de la mémoire.

## Mon Avis

*Mon avis est subjectif et je ne parle que de certains aspects de la piscine.*

La piscine est une bonne expérience, elle permet de rencontrer des gens, de
se faire des amis, de travailler en groupe et de découvrir de nouvelles choses.
J'ai passé une très bonne piscine, voilà juste quelques points que je n'ai pas
appréciés ou sur lesquels je me suis posé des questions:

Les groupes sont créés aléatoirement, ce qui permet de rencontrer des gens de tous
les niveaux. Les groupes avec des niveaux très différents ne permettent pas toujours
un travail très homogène, mais c'est une bonne occasion de rencontrer des gens et
de partager des connaissances (idem pour les corrections).

Bien que le C soit l'un de mes langages préférés, je ne sais pas si c'est le meilleur
langage pour apprendre la programmation. Le C est un langage très bas niveau, il
faut gérer la mémoire, les pointeurs, etc. Commencer avec le C permet d'avoir beaucoup
de rigueur et de mieux comprendre le fonctionnement de la mémoire. Il est possible
que selon les personnes, un langage plus haut niveau soit plus adapté pour apprendre
la programmation.

Je ne suis pas non plus fan de la norme que je trouve trop stricte sur certains
points. Le code est souvent bien moins clair et simple à modifier après l'avoir
normé, et certaines fonctionnalités interdites sont très utiles comme les ternaires,
les switchs... Cependant, elle permet d'avoir un code homogène et facilement
identifiable comme du code de l'école.

La norminette me paraît un peu buggée dans certains cas, par exemple:

```c
if (...)
    if (...)
        ........
    else
        ........
else
    ........
```

Doit être tabulé comme ça (peut-être que ça a changé depuis):

```c
if (...)
    if (...)
        ........
else
    ........
else
    ........
```

*Il est vrai que la syntaxe sans accolades est ambiguë mais elle permet de gagner
beaucoup de lignes (les fonctions ont une limite de 25 lignes).*

## Conclusion

Rares sont les écoles qui proposent un parcours d'entrée aussi intéressant que
la piscine. Elle permet de découvrir de nouvelles choses, de rencontrer des gens
et de se faire des amis. Un grand merci à tous les membres du staff, les tuteurs
et toutes les personnes qui ont rendu cette piscine possible. Je pourrais
la recommander à n'importe qui. Bonne piscine à tous !

----------------------

![repo views](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Felydre%2F42-piscine&count_bg=%23EB00FF&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=views&edge_flat=false)
![GitHub Repo stars](https://img.shields.io/github/stars/elydre/42-piscine?style=flat)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/elydre/42-piscine?color=88aa22)
