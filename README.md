# Lucky Luke — Native Linux Port

Port du jeu *Lucky Luke* (version PC Windows, années 1990) vers Linux x64 natif, en SDL2/OpenGL. L'objectif est de remplacer le menu procédural OpenGL par les ressources originales (BIB/BIZ/COD, scènes localisées), sans modifier les assets d'origine ni l'exécutable `Lucky.exe`.

## État actuel

| Domaine | Statut |
|---------|--------|
| Fenêtre SDL2 + rendu OpenGL 640×480 | ✅ |
| Lecteur KXP (archives compressées, clé `"lucky"`) | ✅ |
| Décodeur PCX (indexé 8 bits + RGB 24 bits) | ✅ |
| Surface DirectDraw émulée (primary/backbuffer/offscreen) | ✅ |
| Presenter OpenGL (upload texture + blit) | ✅ |
| Chargement/configuration `config.ini` (mount CD, langue, son, intro) | ✅ |
| Logos de démarrage (APLOGO + logo localisé) | ✅ |
| Écran d'erreur des assets (BIB/BIZ/CONFIG/KXP manquant ou invalide) | ✅ |
| Menu principal : titre LUCKY LUKE, boutons GAME/OPTIONS, flèche de sélection | ✅ |
| Chargement BIB (`option_e.bib`, `option_f.bib`, …) | ✅ |
| Chargement BIZ (objets, sprites, tuiles, pages de texture) | ✅ |
| Décodage BIZ sprites (palette 16 couleurs, CLUT, pages de texture) | ✅ |
| Décodage son BIZ (VAGp, ADPCM IMA, 4 prédicteurs) | ✅ |
| Audio menu 16 kHz stéréo, 64 voix, gain logiciel | ✅ |
| Lecteur SOOL (VM avec dispatch des commandes et variables) | ✅ |
| Commandes SOOL : caméra, poses, objets 3D, sprites, groupes, sons, mot de passe | ✅ |
| Animation 3D des modèles BIB (frames, fondu enchaîné, boucle/one-shot) | ✅ |
| Animation sprite BIZ (progression temporelle par durée de frame) | ✅ |
| Scène 3D BIB : rendu des modèles géométriques du menu | ✅ |
| Abilene : chargement/exécution SOOL, trace et initialisation native partielle | ✅ (diagnostic ; gameplay incomplet) |
| Abilene : chemins natifs, collisions entre modèles, appui et poussée de caisses | Partiel |
| Lecture AVI (intro) | ❌ (sauf `skip_intro` déjà fonctionnel) |
| Sauvegarde des options / application des profils au gameplay | ❌ |

## Prérequis

- Compilateur C (gcc ou clang)
- `pkg-config`
- Bibliothèques de développement : SDL2, OpenGL
- `make` (optionnel, le script de build est en bash)

Sous Debian/Ubuntu :

```bash
sudo apt-get install build-essential pkg-config libsdl2-dev libgl1-mesa-dev
```

## Build

```bash
cd /home/nicolas/dev/recomp-luckyluke
./build-linux.sh
```

Le binaire natif est produit à `build/linux/lucky-luke`. Des tests unitaires sont aussi construits et exécutés automatiquement (renderer, PCX, SOOL, BIZ son, mixeur et banque audio native, caméra, collisions, trajectoires et pose BIB).

## Configuration

Créez un fichier `config.ini` dans le répertoire de lancement :

```ini
cd_mount=/run/media/nicolas/LuckyLuke
skip_intro=false
language=e
sound=true
```

- `cd_mount` : racine du CD ou de l'ISO monté (contient `CINEMA/`, `win/`, `abilene/`, etc.)
- `skip_intro` : `true`/`false` — saute les logos de démarrage
- `language` : code de langue (`e`=anglais, `f`=français, `d`=allemand, `s`=espagnol, `i`=italien, `u`=néerlandais, `b`=brésilien). Défaut : `e`.
- `sound` : `true`/`false` — active/désactive l'audio du menu et les effets d'Abilene

## Ressources originales requises

Le port lit les assets depuis `cd_mount`. Les fichiers clés du menu principal :

- `CINEMA/OPTION/option.cod` — script SOOL du menu
- `CINEMA/OPTION/option_<lang>.bib` — scène BIB localisée (ex: `option_e.bib`)
- `CINEMA/OPTION/option_<lang>.biz` — ressources BIZ localisées (objets, sprites, tuiles, textures, sons)
- `win/graphics/font.kxp` — logos de démarrage (APLOGO.PCX, LI_*.PCX)
- `ABILENE/abilene.cod` — véritable script SOOL du premier niveau
- `ABILENE/abilene.bib` — catalogue, modèles et poses d'Abilene
- `image/Abilene.pcx` — carte de présentation du niveau, utilisée sur l'écran de diagnostic

Les textures originales d'`abilene.biz` alimentent le rendu des décors et
des modèles squelettiques visibles du niveau. L'archive `abilene.kxp` du
prototype n'est pas présente dans la copie examinée ; le moteur SOOL n'en
dépend pas.

Les fichiers ne sont jamais modifiés ; toutes les sorties générées vont dans `build/`.

Le véritable `ABILENE/abilene.cod` s'exécute lorsque le menu SOOL demande
l'état 2 via sa commande `0x12`. Le runtime conserve les paramètres, modèles,
sprites BIB/BIZ, le modèle joueur, la configuration des groupes orbitaux et les
attentes d'animation portés. Le rendu affiche désormais les décors, Lucky Luke
et les modèles animés BIB, dont Jolly Jumper. Lucky peut marcher, courir,
sauter, retomber et tirer sur les chemins natifs, avec ses animations originales.
Les liens de collision du script séparent maintenant les modèles : Lucky
s'arrête contre les obstacles, pousse les caisses mobiles et peut sauter dessus.
La poussée et le blocage utilisent leurs animations originales ; un objet
servant d'appui entraîne aussi le joueur lorsqu'il se déplace.
Les trois caisses piégées projettent Lucky, s'ouvrent et font apparaître leur
bonus avec les animations et le son du script original. La première est testée
depuis le départ avec les commandes ordinaires, jusqu'au ramassage de sa carte.
Les pièces du décor sont également affichées et ramassables, avec leur compteur
et leur effet original. L'affichage des compteurs dans le HUD reste partiel.
Les charges suspendues suivent leurs cordes. Les objets tenus par les ennemis
suivent les pivots animés de leurs mains, puis conservent leur position au
détachement. Les tonneaux lancés suivent désormais les calculs entiers du jeu :
chute, freinage, roulement, impact sur Lucky ou une caisse, éclatement et remise
en place par le script de l'ennemi.
Le tir reprend les six visées, la cadence d'animation et le pool natif de dix
balles et dix effets ; les projectiles sont affichés dans le décor.
Les tirs ennemis utilisent maintenant les pivots animés et les cibles du script.
Un impact sur Lucky applique les paliers de santé originaux, son cri et le
clignotement qui protège temporairement des coups suivants.
Les dégâts demandés par les scripts d'ennemis et de pièges utilisent aussi
ce traitement, avec la même immunité. Un essai sur le script original vérifie
également qu'une balle du revolver déclenche la réaction prévue pour l'ennemi.
La perte d'une vie lance désormais la séquence SOOL originale : fondus,
animations de Lucky puis retour au point de reprise. Les commandes redeviennent
actives après cette séquence ; l'écran de fin de partie reste à porter.
La banque BIZ fournit désormais ses 54 sons aux scripts et au contrôleur :
revolver, atterrissages, répliques d'attente et ambiances, avec les 64 voix du
mixeur natif. Les préférences de volume et de stéréo du menu sont respectées.
Les animations à l'envers et le déplacement extrait des squelettes permettent
désormais à d'autres séquences d'ennemis et au décor animé de poursuivre leurs scripts.
Par défaut : flèches pour la direction, Bas pour s'accroupir, C pour courir,
G pour sauter, B pour tirer et V pour poser un bâton de dynamite après en avoir récupéré
(profil A ; réglages du menu respectés). La caméra
suit désormais le déplacement avec un décalage progressif dans le sens de marche.
Les panoramiques du script et leurs transitions de retour s'exécutent également ;
une nouvelle pression de touche peut raccourcir l'attente de présentation.
Le ciel en dégradé, les reliefs et les nuages utilisent les trois couches du
script original, leurs textures BIZ et leur parallaxe. Ils s'arrêtent pendant
la scène de perte de vie puis reprennent au retour dans le niveau.
La pause utilise maintenant les images de l'archive localisée du jeu : P pour
mettre en pause ou reprendre, Échap pour choisir entre continuer et quitter,
puis confirmer la sortie. Le script, la caméra et les animations restent figés
pendant ces écrans.
Les quatre segments où le moteur impose la marche ou la course suivent maintenant
les chemins et les animations d'origine, puis rendent les commandes au joueur.
Le script assombrit Lucky dans la zone prévue et rétablit sa luminosité à la sortie.
Le paquet de dynamite fournit ses trois bâtons par le script d'origine. La pose,
la mèche, l'explosion, ses dégâts sur Lucky et les secousses de caméra s'exécutent ;
s'éloigner permet d'éviter les dégâts. La pause fige aussi la mèche et l'explosion.
L'explosion détruit aussi la barricade de caisses de fin de niveau par son script d'origine.
Le passage lance l'animation de sortie, le déplacement de Lucky et le fondu noir,
puis charge le script et les ressources d'origine d'`Abi_Boss`.
Dans cette scène, les déplacements latéraux et l'action B du profil A poursuivent
les scripts du duel ; pause et retour au menu fonctionnent également.
La victoire, la défaite et la transition après ce duel restent à vérifier et compléter.
Les autres branches de combat, la fin de partie, les autres états du contrôleur
et les autres modes d'attache aux squelettes restent à porter.
Une branche de contrôleur absente est signalée et arrête ce callback.
Une sortie confirmée puis une nouvelle entrée dans le niveau le réinitialisent.
Avec l'archive de pause chargée, la trace actuelle reconnaît 2763 appels sur
24 ticks et laisse un contexte arrêté ; sur 240 ticks, seul l'appel à la
musique CD reste bloqué au démarrage.
Le gameplay natif et la musique CD restent incomplets. Les appels manquants arrêtent leur contexte avec une trace.
Le prototype avec joueur et pièces procéduraux n'est plus lancé par ce chemin.

Pour tracer le script sans fenêtre ni SDL :

```bash
./build/linux/abilene-trace /chemin/ABILENE/abilene.cod /chemin/ABILENE/abilene.bib /chemin/ABILENE/abilene.biz 24
```

Ajouter `--pause-archive /chemin/win/graphics/MENU_F.KXP` pour fournir les images
françaises de pause au traceur (`MENU_E.KXP` pour l'anglais).

Le code de sortie `3` signifie que des contextes attendent des fonctions
natives à porter ; `2` signale une entrée invalide et `0` une exécution sans
blocage signalé (sans prouver que le script entier est terminé).
`LL_TRACE_LEVEL_SOOL=1` active aussi les appels reconnus dans le jeu.
Voir [l'état du portage SOOL d'Abilene](docs/ABILENE_SOOL.md).

## Utilisation

```bash
./build/linux/lucky-luke
```

### Contrôles menu

- Haut / Bas ou W / S : sélectionner GAME ou OPTIONS
- Entrée : valider la sélection
- Échap : revenir au menu principal ou quitter
- Souris : survol et clic fonctionnent aussi

### Abilene

L'écran indique l'état du script et les fonctions natives manquantes.

- Flèches : se déplacer ; C : courir ; G : sauter ; B : tirer (profil A).
- P : mettre en pause ou reprendre, au relâchement de la touche.
- Échap : ouvrir le choix continuer/quitter ; gauche/droite et Entrée : choisir
  et valider. La sortie demande une confirmation, avec « non » sélectionné par défaut.

Les réglages de contrôle du menu sont respectés pendant le jeu. Les choix de
pause utilisent les flèches, comme dans l'original.

## Structure du dépôt

```
src/linux/           # Code source du port natif Linux
  main.c             # Boucle principale, render_menu(), machine d'état menu, SOOL dispatch
  cod.c / cod.h      # Lecteur COD (expérimental, CRC3)
  native_animation.c / native_animation.h # Application des poses aux squelettes BIB
  bib.c / bib.h      # Lecteur BIB (sélecteurs, catalogue 3DX, animations, SOOL)
  biz.c / biz.h      # Lecteur BIZ (objets, sprites, tuiles, pages, son VAGp)
  sool.c / sool.h    # VM SOOL (décodage d'instructions, exécution d'états)
  level.c / level.h  # Gestion des niveaux (BIB, arrière-plan, état jeu)
  surface.c / surface.h # Surfaces DirectDraw émulées
  object.c / object.h   # Liste générique d'objets de jeu
  gameplay.c / gameplay.h # Gameplay niveau 1 (joueur, pièces, collisions)
  renderer.c / renderer.h # Présentateur OpenGL
  menu_art.c / menu_art.h # Textures PCX du menu
  pcx.c / pcx.h           # Décodeur PCX
  kxp.c / kxp.h           # Lecteur d'archives KXP
  audio_mix.c / audio_mix.h # Mixeur audio logiciel
  native_audio.c / native_audio.h # Banque BIZ et contrôles des 64 voix d'Abilene
  native_camera.c         # Caméra native (projection, écran, grille)
  asset_config.c          # Lecture de config.ini
docs/NATIVE_PORT.md       # Documentation détaillée du port
scripts/                  # Scripts (build, extraction KXP, etc.)
build/linux/              # Sorties de compilation (gitignoré)
```

## Licence

Ce port ne distribue aucun asset original du jeu. Les ressources (CINEMA/, win/, abilene/, Lucky.exe, Game.run, etc.) doivent être fournies par l'utilisateur à partir de sa propre copie du jeu.

## Travail restant

- Interprétation complète des scripts d'animation BIZ (états d'objets scénographiques au fil du temps)
- Identification de la géométrie/collision de niveau depuis les données originales
- Intégration de la lecture AVI (l'intro)
- Traduction des commentaires en français restants
- Polissage du rendu menu (silhouette Lucky Luke, flèches, etc.)
