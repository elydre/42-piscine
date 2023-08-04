# Ma piscine C à 42 - Juillet 2023

![level](https://elydre.github.io/img/piscine/level.png)

## Description

Ce repo contient les projets réalisés lors de ma piscine C à 42.
La piscine C est un mois intensif de programmation en C pour intégrer
l'école 42. La piscine permet d'apprendre les bases d'unix, de la programmation
en C et de donner un avant-goût de la pédagogie de l'école, basée sur le peer-learning.

## Mise en Garde

Ce repo est public, et vous êtes libre de vous en inspirer pour vos projets.
Cependant, si vous êtes piscineux, je vous déconseille fortement de copier
coller le code de ce repo sans le comprendre. Cela ne vous aidera pas à
progresser, et vous risquez d'avoir des surprises lors de la correction et
des examens machines...

## Astuces et Conseils

### Avant la piscine

Bien qu'il soit possible de réussir la piscine sans aucune connaissance
préalable, avoir quelques bases en programmation et en C vous aidera
grandement pour vous concentrer sur les projets et la pédagogie de l'école.
Installez Linux (wsl existe pour Windows) et commencez à vous familiariser
avec les commandes de base. Vous pouvez aussi commencer à apprendre le C
avec des tutoriels en ligne.

### Pendant la piscine

Ne restez pas seul ! Même si vous n'êtes pas à l'aise (oui je sais), vous
trouverez toujours quelqu'un pour vous aider. Google est aussi votre ami,
durant les examens machines vous n'aurez pas accès à internet, mais vous
pouvez toujours chercher des informations sur le `man` de votre machine.

Trouvez le temps de dormir, de bien mangez et de vous détendre; c'est
long un mois :)

Si vous êtes bloqué sur un projet, passez au suivant et revenez-y plus tard.
Les days (shell00, shell01, c00, c01, etc.) ne doivent pas être fait a 100%
pour passer à la suite, 50% suffisent. Les derniers exercices d'un day sont
souvent plus difficiles que le debut du jour suivant (la fin du c00...)

## Déroulement Global

Chaque semaine se déroule de la même manière:

### Lundi-Jeudi

Le debut de semaine est consacré sur les days (shell00, shell01, c00, c01, etc.)
Chaque day est composé d'exercices à rendre (généralement une petite dizaine)
apres avoir rendu les exercices (avec git), vous devez les faire valider par
deux piscineux (ils pourront avoir un niveau très différent du votre).
Après vos deux correcteurs 'humains', une correction automatique est lancée
(nommée `moulinette`) qui vérifie que votre code compile et qu'il passe
quelques tests. Une moyenne sera calculée entre les notes de vos correcteurs
et la moulinette. Si vous avez une moyenne supérieure à 50, vous passez au
day suivant, sinon vous devez refaire le day (seulement les exercices ratés).

Vous aurez aussi l'occasion de mettre des plages de disponibilités pour
corriger les exercices des autres piscineux. C'est une bonne occasion pour
rencontrer d'autres humains et de voir comment ils ont résolu les exercices.

### Vendredi

Le vendredi est consacré à un examen machine, qui est une série d'exercices
à faire en 4h (ou 8h pour l'examen final). Les exercices sont similaires à
ceux des days, mais vous n'avez pas de correcteurs humains, et vous n'avez
pas accès à internet. La correction est faite automatiquement, dans les
premiers examens, vous aurez accès à un historique des tests passés et ratés
pour vous aider à corriger votre code.

### Week-end

Le week-end est consacré à un projet (rush) à faire en groupe créé aléatoirement.
Ils sont généralement plus difficiles que les days, et vous avez 48h pour les
rendre. Les rushs ne sont pas corrigés par des piscineux, mais par des membres
du staff. Les rushs sont les seuls projets où vous pouvez tenté de faire des
bonus (documentations, fonctionnalités supplémentaires, etc.)

## Quelques Détails

### Le Shell

<img src="https://elydre.github.io/img/piscine/shells.png" width="300">

Les premiers jours de la piscine sont consacrés à l'apprentissage du shell.
Je ne connais personne qui a trouvé ça fun, mais c'est un mal nécessaire.
Ne vous attardez pas trop sur le shell (surtout le `shell01`)

### Le C

<img src="https://elydre.github.io/img/piscine/days.png" width="300">

Le C est au coeur de la piscine. Tout le code que vous écrirez devra être
à la norme de l'école (et donc passer la norminette).
La correction automatique est très stricte, votre code doit être parfaitement
à la norme, et fonctionner dans TOUS les cas.

Les fonctions qui gèrent les entiers doivent fonctionner avec INT_MIN et INT_MAX,
les chaines de caractères doivent fonctionner avec des chaines vides, etc.

Bien que les tests de la moulinette ne soient pas accessibles, vous pouvez
tester votre code vous même avec des tests génériques, vous pouvez aussi trouver
des tests comme [semi-auto-correct-42](https://github.com/Buom01/semi-auto-correct-42)
ou la [francinette](https://github.com/xicodomingues/francinette) qui ne
sont pas parfaits, mais qui peuvent vous aider à trouver des erreurs auxquelles
vous n'auriez pas pensé.

### Les Examens

<img src="https://elydre.github.io/img/piscine/exams.png" width="300">

Je n'ai d'astuces particulières pour les examens, vous serez guidés par le
staff durant les premiers examens...

### Les Rushs

<img src="https://elydre.github.io/img/piscine/rush.png" width="300">

Les rushs n'ont qu'une seule correction, assurez vous que votre projet
respecte bien le sujet, et faite un maximum de tests avant de le rendre.
Durant la presentation, vous devrez expliquer comment vous avez fait votre
projet et comment c'est passé le travail en groupe.
Vous avez carte blanche pour les bonus, surtout si vous avez fini le rush.

### Le BSQ

<img src="https://elydre.github.io/img/piscine/bsq.png" width="300">

Le BSQ est le dernier projet de la piscine, il est à rendre en 3 jours.
La correction est faite par trois piscineux ainsi que par la moulinette.
Le BSQ est un projet assez difficile, faite attention à l'optimisation de
votre code.

## Conclusion

Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
Mais quel enfer la norme! Mais quel enfer la norme! Mais quel enfer la norme!
