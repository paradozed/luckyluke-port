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
| Collisions / géométrie de niveau depuis les données originales | ❌ |
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

Le binaire natif est produit à `build/linux/lucky-luke`. Des tests unitaires sont aussi construits et exécutés automatiquement (renderer, PCX, SOOL, BIZ son, mixeur audio, caméra native, pose BIB).

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
- `sound` : `true`/`false` — active/désactive l'audio du menu

## Ressources originales requises

Le port lit les assets depuis `cd_mount`. Les fichiers clés du menu principal :

- `CINEMA/OPTION/option.cod` — script SOOL du menu
- `CINEMA/OPTION/option_<lang>.bib` — scène BIB localisée (ex: `option_e.bib`)
- `CINEMA/OPTION/option_<lang>.biz` — ressources BIZ localisées (objets, sprites, tuiles, textures, sons)
- `win/graphics/font.kxp` — logos de démarrage (APLOGO.PCX, LI_*.PCX)
- `ABILENE/abilene.cod` — véritable script SOOL du premier niveau
- `ABILENE/abilene.bib` — catalogue, modèles et poses d'Abilene
- `image/Abilene.pcx` — carte de présentation du niveau, utilisée sur l'écran de diagnostic

Les ressources natives d'Abilene comprennent aussi `abilene.biz`, dont
l'intégration au rendu du niveau reste à faire. L'archive `abilene.kxp` du
prototype n'est pas présente dans la copie examinée ; le moteur SOOL n'en
dépend pas.

Les fichiers ne sont jamais modifiés ; toutes les sorties générées vont dans `build/`.

Le véritable `ABILENE/abilene.cod` s'exécute lorsque le menu SOOL demande
l'état 2 via sa commande `0x12`. Le runtime conserve les paramètres, modèles,
sprites BIB/BIZ, le modèle joueur et les attentes d'animation portés. La trace
actuelle reconnaît 764 appels sur 24 ticks et laisse 69 contextes arrêtés ; le gameplay natif
reste incomplet. Les appels manquants arrêtent leur contexte avec une trace.
Le prototype avec joueur et pièces procéduraux n'est plus lancé par ce chemin.

Pour tracer le script sans fenêtre ni SDL :

```bash
./build/linux/abilene-trace /chemin/ABILENE/abilene.cod /chemin/ABILENE/abilene.bib /chemin/ABILENE/abilene.biz 24
```

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
Échap retourne au menu. Déplacements et sauts attendent le contrôleur original.

## Structure du dépôt

```
src/linux/           # Code source du port natif Linux
  main.c             # Boucle principale, render_menu(), machine d'état menu, SOOL dispatch
  cod.c / cod.h      # Lecteur COD (expérimental, CRC3)
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
