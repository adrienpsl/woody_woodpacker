# Research
https://www.welivesecurity.com/2008/10/27/an-introduction-to-packers/

Packing veut dire compression, zip, cab, rar sont des fichiers compresser,
par des packers.

La phrase
    `The monkey does not know he is a monkey, he thinks that you are the monkey.`
devient une fois pack/e
    `The % does not know he is a %, he thinks that you are the %.`

Un packed file peut contenir malware et si mon antivirus ne sais pas comment
les extraires, ils resteront indetectables.
Mais si le malware est packed, il ne peut pas se lancer.
Il y a donc des runtime packer, qui n'est que parciellement packed
et qui se depack lui meme, l'algo de pack est dans le debut du programm
lui meme.

Rustime packer sont les plus utiliser,
pour se proteger de ca, les antivirus, scan avec une machine virtuel
qui va run le program, et donc le faire se depack.

Une autre approch regarder si le package utilise des maniere de pack
similaire et de match ca avec ce qui est deja connue.
Ce qui donne nombre de faux positifs, car tres peux de packers
sont utiliser uniquement pour les virus.

Une autre aproche est de combiner la reconitions avec une recherche
plus fine, si le programme est par exemple packer avec Themida,
il devient tres suspicieux, car Themida est largement utiliser en ce
moment par les hackers.

je peux utiliser un algo plustot simple pour faire ca,

1 -> add une phrase qui se print quand le main de mon programme se lance
2 -> el program se lance, et dans sa memoire, il y a un

-> je prend le binaire et convertit tout avec ma clee de chiffrement
   une fois converti...
   mon programme se lance, le debut dechiffre la fin,
   mais la fin qui est deja en memoire?
   Comment je sais ce qu'elle fait, je le sais car c'est en memoire,
   je ne vois que ca de possible.
   j'ajoute au debut du binaire ce dont j'ai besoin,
   mon programm, doit se lance

   prendre un program, le parcer et le retourner:
   voir comment faire grossir la memoir pour avoir des multiple de getpagesize


comment un program est load en memoire, et comment l'obscure

bon enfaite ca va, je dois 'juste changer la partie data'

-> si je veux que ce truc marche:
   comprendre comment marche un elf header.


-> taille de la partie data  
-> modification des address de la parti data pour fit avec le new program  
-> comment je decompile en memoire ce que je fais?
-> modifier les address pour avoir les bonne nouvelles


-> parces efl-64
-> aller a la partie data, print ma function
   ajouter printf,
   leave
-> if I add some stuff to text, I will need to move that element,
-> if the file is little indian, I will need to correct it,

-> I get the data, I move the stuff, add add to each addr the new
   value ?












