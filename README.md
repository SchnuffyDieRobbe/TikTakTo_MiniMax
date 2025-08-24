# 🎮 TikTakToe Minimax
Ein intelligentes Tic-Tac-Toe Spiel in C++, das den **Minimax-Algorithmus** zur Realisierung einer unschlagbaren KI verwendet.
## 🎯 Über das Spiel
Dieses Projekt implementiert das klassische Tic-Tac-Toe (3x3) Spiel, bei dem ein menschlicher Spieler gegen eine künstliche Intelligenz antritt. Die KI nutzt den Minimax-Algorithmus und ist daher **unschlagbar** - bestenfalls kann man ein Unentschieden erreichen!
### ✨ Features
- **Konsolen-basierte Benutzeroberfläche** mit übersichtlicher Spielfeld-Darstellung
- **Intelligente KI** mit Minimax-Algorithmus
- **Eingabevalidierung** für alle Spielerzüge
- **Automatische Spielende-Erkennung** (Gewinn/Unentschieden)
- **Koordinatensystem** für einfache Bedienung (1-3 für Zeilen und Spalten)

## 🚀 Installation & Ausführung
### Voraussetzungen
- C++20 kompatiler Compiler (GCC, Clang, MSVC)
- CMake (Version 3.0 oder höher)
  
### Kompilieren
``` bash
git clone https://github.com/[IhrUsername]/TikTakTo_Minimax.git
cd TikTakTo_Minimax
mkdir build && cd build
cmake ..
make
```
### Ausführen
``` bash
./TikTakTo_Minimax
```


## 🎮 Spielanleitung
1. **Spieler X (Mensch)** beginnt immer
2. **Spieler O (KI)** folgt automatisch
3. **Eingabeformat**: `Zeile,Spalte,Symbol` (z.B. oder `2,3,O`) `1,1,X`
4. **Koordinaten**: 1-3 für beide Achsen

### Beispiel-Spielfeld:
``` 
0 1 2 3 
1 . . . 
2 . X . 
3 . . . 
```
 

## 🧠 Der Minimax-Algorithmus
Der **Minimax-Algorithmus** ist ein fundamentaler Algorithmus der Spieltheorie und künstlichen Intelligenz für Zwei-Spieler-Nullsummenspiele.
### Funktionsweise:
1. **Maximizing Player**: Die KI versucht ihren Nutzen zu maximieren
2. **Minimizing Player**: Der Gegner versucht den KI-Nutzen zu minimieren
3. **Rekursive Bewertung**: Alle möglichen Spielverläufe werden bis zum Ende durchgespielt
4. **Optimale Entscheidung**: Der Algorithmus wählt immer den Zug mit dem besten Ergebnis

### Bewertungssystem:
- **+1**: KI gewinnt
- **-1**: KI verliert
- **0**: Unentschieden

  ### Algorithmus-Ablauf:
``` 
1. Generiere alle möglichen Züge
2. Für jeden Zug:
   - Führe Zug aus
   - Rufe Minimax rekursiv für Gegner auf
   - Mache Zug rückgängig
   - Bewerte Ergebnis
3. Wähle besten Zug aus
```

## 🏗️ Projektstruktur
``` 
├── main.cpp           # Hauptprogramm und Spielschleife
├── Spielfeld.h/cpp    # Spielfeld-Klasse mit Logik
├── MiniMax.h/cpp      # Minimax-Algorithmus Implementation
└── CMakeLists.txt     # Build-Konfiguration
```
### Klassen-Übersicht:
#### `Spielfeld`
- Verwaltet das 3x3 Spielbrett
- Validiert Spielerzüge
- Erkennt Gewinn-/Endzustände
- Implementiert Undo-Funktionalität

#### `MiniMax`
- Implementiert den Minimax-Algorithmus
- Generiert alle möglichen Züge
- Bewertet Spielpositionen
- Findet optimale Züge für die KI

## 🔧 Technische Details
- **Sprache**: C++20
- **Build-System**: CMake
- **Architektur**: Objektorientiert
- **Algorithmus**: Minimax mit vollständiger Spielbaum-Exploration
- **Datenstrukturen**: 2D Vector für Spielfeld-Repräsentation




