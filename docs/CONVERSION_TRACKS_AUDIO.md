# Conversion des pistes audio CD en WAV

## Projet

*Lucky Luke: Sur la Piste des Daltons* — Infogrames, 2000, CD-ROM (région France).

## Fichiers source

Le disque a été extrait en 20 pistes, décrites par le fichier `LuckyLuke.cue` :

| Piste | Type | Fichier | Taille | Description |
|-------|------|---------|--------|-------------|
| 01 | MODE1/2352 (DATA) | `LuckyLuke (Track 01).bin` | 249 027 408 octets | Données du jeu (CD-ROM mode 1) |
| 02 | AUDIO | `LuckyLuke (Track 02).bin` | 15 701 952 octets | Audio CD (CD-DA) |
| 03 | AUDIO | `LuckyLuke (Track 03).bin` | 17 374 224 octets | Audio CD (CD-DA) |
| 04 | AUDIO | `LuckyLuke (Track 04).bin` | 16 805 040 octets | Audio CD (CD-DA) |
| 05 | AUDIO | `LuckyLuke (Track 05).bin` | 14 725 872 octets | Audio CD (CD-DA) |
| 06 | AUDIO | `LuckyLuke (Track 06).bin` | 17 717 616 octets | Audio CD (CD-DA) |
| 07 | AUDIO | `LuckyLuke (Track 07).bin` | 18 557 280 octets | Audio CD (CD-DA) |
| 08 | AUDIO | `LuckyLuke (Track 08).bin` | 18 289 152 octets | Audio CD (CD-DA) |
| 09 | AUDIO | `LuckyLuke (Track 09).bin` | 16 308 768 octets | Audio CD (CD-DA) |
| 10 | AUDIO | `LuckyLuke (Track 10).bin` | 16 614 528 octets | Audio CD (CD-DA) |
| 11 | AUDIO | `LuckyLuke (Track 11).bin` | 19 112 352 octets | Audio CD (CD-DA) |
| 12 | AUDIO | `LuckyLuke (Track 12).bin` | 15 636 096 octets | Audio CD (CD-DA) |
| 13 | AUDIO | `LuckyLuke (Track 13).bin` | 17 167 248 octets | Audio CD (CD-DA) |
| 14 | AUDIO | `LuckyLuke (Track 14).bin` | 17 209 584 octets | Audio CD (CD-DA) |
| 15 | AUDIO | `LuckyLuke (Track 15).bin` | 15 958 320 octets | Audio CD (CD-DA) |
| 16 | AUDIO | `LuckyLuke (Track 16).bin` | 16 666 272 octets | Audio CD (CD-DA) |
| 17 | AUDIO | `LuckyLuke (Track 17).bin` | 15 436 176 octets | Audio CD (CD-DA) |
| 18 | AUDIO | `LuckyLuke (Track 18).bin` | 18 609 024 octets | Audio CD (CD-DA) |
| 19 | AUDIO | `LuckyLuke (Track 19).bin` | 17 209 584 octets | Audio CD (CD-DA) |
| 20 | AUDIO | `LuckyLuke (Track 20).bin` | 15 744 288 octets | Audio CD (CD-DA) |

- La **piste 01** est une piste de données (jeu), **non convertie**.
- Les **pistes 02 à 20** (19 pistes) sont des pistes audio CD-DA, converties en WAV.

## Format des fichiers .bin audio

Chaque piste audio est un dump brut de secteurs CD-DA :

- **Taille du secteur** : 2352 octets (pas de sous-en-tête de correction d'erreur sur les pistes audio)
- **Encodage** : PCM non signé 16 bits, little-endian, stéréo
- **Fréquence d'échantillonnage** : 44 100 Hz
- **Canaux** : 2 (stéréo)
- **Débit** : 44100 × 2 canaux × 2 octets × 16 bits / 8 = 176 400 octets/seconde = 1 411,2 kbit/s
- **Échantillons par secteur** : 2352 / 4 = 588 frames (44100 / 75 secteurs/seconde = 588)

Tous les fichiers `.bin` des pistes 02–20 sont des multiples exacts de 2352 (et de 4), donc aucun cadre d'échantillon n'est tronqué aux frontières de secteurs. Aucun en-tête ni aucune métadonnée n'est à supprimer : le contenu du fichier est directement du PCM brut.

## Méthode de conversion

Outil utilisé : **ffmpeg** (déjà installé sur le système).

Commande utilisée pour chaque piste :

```bash
ffmpeg -nostdin -y \
  -f s16le \
  -ar 44100 \
  -ac 2 \
  -i "LuckyLuke (Track XX).bin" \
  "wav/LuckyLuke (Track XX).wav"
```

Explication des options :

| Option | Valeur | Signification |
|--------|--------|---------------|
| `-f s16le` | s16le | Format d'entrée : PCM signé 16 bits little-endian (raw) |
| `-ar 44100` | 44100 | Fréquence d'échantillonnage : 44,1 kHz |
| `-ac 2` | 2 | Nombre de canaux : stéréo |
| `-i` | fichier.bin | Fichier d'entrée (PCM brut) |
| fichier.wav | — | Fichier de sortie au format WAV (RIFF/PCM) |

ffmpeg génère automatiquement un en-tête WAV standard (44 octets) devant les données PCM. Aucune ré-encodage ni conversion de fréquence n'est appliquée : le flux audio est recopié tel quel.

## Script de conversion complet

Le script shell suivant a été exécuté pour convertir l'ensemble des pistes 02 à 20 :

```bash
mkdir -p wav
for i in $(seq -w 2 20); do
  f="LuckyLuke (Track 0$i).bin"
  if [ ! -f "$f" ]; then
    f="LuckyLuke (Track $i).bin"
  fi
  out="wav/LuckyLuke (Track $i).wav"
  ffmpeg -nostdin -y -f s16le -ar 44100 -ac 2 -i "$f" "$out"
done
```

## Fichiers WAV produits

Dossier de sortie : `wav/`

| Fichier WAV | Durée approximative | Taille |
|-------------|---------------------|--------|
| `LuckyLuke (Track 02).wav` | 1 min 29 s | 15 702 030 octets |
| `LuckyLuke (Track 03).wav` | 1 min 38 s | 17 374 302 octets |
| `LuckyLuke (Track 04).wav` | 1 min 35 s | 16 805 118 octets |
| `LuckyLuke (Track 05).wav` | 1 min 23 s | 14 725 950 octets |
| `LuckyLuke (Track 06).wav` | 1 min 40 s | 17 717 694 octets |
| `LuckyLuke (Track 07).wav` | 1 min 45 s | 18 557 358 octets |
| `LuckyLuke (Track 08).wav` | 1 min 43 s | 18 289 230 octets |
| `LuckyLuke (Track 09).wav` | 1 min 32 s | 16 308 846 octets |
| `LuckyLuke (Track 10).wav` | 1 min 34 s | 16 614 606 octets |
| `LuckyLuke (Track 11).wav` | 1 min 48 s | 19 112 430 octets |
| `LuckyLuke (Track 12).wav` | 1 min 28 s | 15 636 174 octets |
| `LuckyLuke (Track 13).wav` | 1 min 37 s | 17 167 326 octets |
| `LuckyLuke (Track 14).wav` | 1 min 37 s | 17 209 662 octets |
| `LuckyLuke (Track 15).wav` | 1 min 30 s | 15 958 398 octets |
| `LuckyLuke (Track 16).wav` | 1 min 34 s | 16 666 350 octets |
| `LuckyLuke (Track 17).wav` | 1 min 30 s | 15 436 254 octets |
| `LuckyLuke (Track 18).wav` | 1 min 45 s | 18 609 102 octets |
| `LuckyLuke (Track 19).wav` | 1 min 37 s | 17 209 662 octets |
| `LuckyLuke (Track 20).wav` | 1 min 29 s | 15 744 366 octets |

Durée totale d'audio : environ 33 minutes.

Chaque fichier WAV est 78 à 88 octets plus grand que son `.bin` d'origine en raison de l'en-tête RIFF/WAV ajouté par ffmpeg.

## Vérification d'intégrité

Exemple de vérification sur la piste 02 :

```
$ file wav/LuckyLuke\ \(Track\ 02\).wav
RIFF (little-endian) data, WAVE audio, Microsoft PCM, 16 bit, stereo 44100 Hz

$ ffprobe -v error -show_entries format=duration,bit_rate \
  -show_entries stream=sample_rate,channels,bits_per_sample \
  -of default=noprint_wrappers=1 wav/LuckyLuke\ \(Track\ 02\).wav
sample_rate=44100
channels=2
bits_per_sample=16
duration=89.013333
bit_rate=1411207
```

Résultat confirmé : PCM 16 bits, stéréo, 44100 Hz, débit 1 411,2 kbit/s.

## Relecture

Les fichiers WAV peuvent être lus avec n'importe quel lecteur audio (ffplay, vlc, aplay, etc.) :

```bash
ffplay -autoexit "wav/LuckyLuke (Track 02).wav"
# ou
aplay "wav/LuckyLuke (Track 02).wav"
```

## Notes

- La piste 01 contient les données du jeu (CD-ROM Mode 1) et n'est **pas** de l'audio ; elle n'a pas été convertie.
- Les pistes audio sont de la musique/CD audio du jeu (Red Book audio), jouées par le CD-Audio du PC lors du jeu.
- Aucun traitement de normalisation, de coupe ou de filtrage n'a été appliqué. L'audio est une copie bit-à-bit du PCM source.
- Pour extraire également la piste de données (ISO ou fichiers), il faudrait utiliser un outil comme `cdrdao`, `bchunk` ou `7z` sur le fichier `.bin` de la piste 01 avec le fichier `.cue` associé.
