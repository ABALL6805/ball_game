# Ball Game

A simple infinite scrolling 2D obstacle game built in C++ using SFML 3, featuring a local high score leaderboard.

---

## Requirements

- **Microsoft Visual Studio 2026** (or any IDE supporting C++17)
- **SFML 3** — Simple and Fast Multimedia Library
  - Download from [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)
  - Ensure you download the version built for your compiler (MSVC)

---

## Dependencies

The following SFML DLL files must be present in the same directory as the compiled executable:

```
sfml-graphics-3.dll
sfml-window-3.dll
sfml-system-3.dll
sfml-audio-3.dll
```

These can be found in the `bin/` folder of your SFML 3 installation.

---

## Building the Project

1. Clone or download this repository
2. Open `BallGame.sln` in Visual Studio
3. Link SFML 3 to the project:
   - Go to **Project → Properties**
   - Under **C/C++ → General**, add the SFML `include/` directory to **Additional Include Directories**
   - Under **Linker → General**, add the SFML `lib/` directory to **Additional Library Directories**
   - Under **Linker → Input**, add the required SFML libraries to **Additional Dependencies**
4. Copy the required SFML DLL files (listed above) into the build output directory (`x64/Debug/` or `x64/Release/`)
5. Copy all asset files (fonts, sounds) into the same directory as the executable
6. Build the solution with **Build → Build Solution** (Ctrl+Shift+B)

---

## Running the Project

### From Visual Studio
Press **F5** to build and run in Debug mode, or **Ctrl+F5** to run without the debugger.

### From the Executable
Navigate to `x64/Release/` and run `BallGame.exe` directly, ensuring all DLL and asset files are present in the same folder.

---

## Assets Required

The following asset files must be present in the same directory as the executable:

| File | Type | Purpose |
|---|---|---|
| `consola.ttf` | Font | UI and score text |
| `Arial.ttf` | Font | Button and text field text |
| `jump.flac` | Audio | Player jump sound effect |
| `slam.flac` | Audio | Player slam sound effect |
| `Game Theme.flac` | Audio | Background music |
| `Instructions.drawio.png` | Image | Instructions graphic on menu screen |

---

## Gameplay

- **Up Arrow** — Jump (double jump supported)
- **Down Arrow** — Slam downward while airborne
- Avoid the incoming obstacles
- Score increases over time — survive as long as possible
- A second obstacle appears after reaching a score of 500
- Enter your name on the game over screen to save your score to the local leaderboard

---

## Score Storage

Scores are saved locally to `scores.txt` in the same directory as the executable. This file is created automatically on first run. The leaderboard displays the top 3 scores on the main menu.

---

## Project Structure

```
BallGame/
├── main.cpp
├── gameState.cpp / gameState.h
├── player.cpp / player.h
├── obstacle.cpp / obstacle.h
├── scoreStore.cpp / scoreStore.h
├── button.cpp / button.h
├── textField.cpp / textField.h
├── mainMenu.cpp / mainMenu.h
└── BallGame.vcxproj
```

---

## Built With

- **C++17**
- **SFML 3** — [https://www.sfml-dev.org](https://www.sfml-dev.org)
- **Microsoft Visual Studio 2026**
