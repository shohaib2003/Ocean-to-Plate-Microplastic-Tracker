
## 📖 **Description**
An interactive 3D computer graphics simulation built with OpenGL/GLUT that visualizes the journey of microplastics from plastic bottle degradation through aquatic ecosystems to human consumption. This educational tool demonstrates how plastic pollution breaks down into microscopic particles and enters the food chain, ultimately affecting human health.

---

## ✨ **Features**

| Scene | Description |
|-------|-------------|
| 🎬 **Opening Screen** | Project credits and university information |
| 🏞️ **Scene 1** | Riverside environment with a person disposing plastic bottles into water |
| 💧 **Scene 2** | Underwater ecosystem showing plastic fragmentation into microplastics |
| 🐟 **Scene 3** | Fish consuming microplastics in aquatic environment |
| 🍽️ **Scene 4** | Human consumption of contaminated seafood |
| 🌙 **Night Mode** | Toggle between day/night scenes with keyboard controls |

---

## 🎮 **Interactive Controls**

| Key | Action |
|-----|--------|
| `S` | Start the simulation |
| `M` | Show awareness message |
| `Z` | Continue to next scene |
| `A` | Night mode - Scene 1 |
| `E` | Day mode - Scene 2 |
| `T` | Night mode - Scene 2 |
| `X` | Scene 3 - Microplastic ingestion |
| `Q` | Quit application |

---

## 🎨 **Visual Elements**
- Dynamic Animations (clouds, sun, vehicles, fish, particles)
- Day/Night Cycle with automatic lighting transitions
- Physics Simulation (plastic bottle fragmentation and sinking)
- Microplastic Visualization (tiny particles entering organisms)
- Complex Environments (rivers, roads, buildings, underwater scenes)

---

┌─────────────────────────────────────┐
│ OpenGL / GLUT (Graphics Library) │
├─────────────────────────────────────┤
│ C++ (Core Logic & Animation) │
├─────────────────────────────────────┤
│ Windows Multimedia API (Sound) │
├─────────────────────────────────────┤
│ Mathematical Modeling (Physics) │
└─────────────────────────────────────┘



---

## 🔧 **Installation & Compilation**

### **Prerequisites**
- Windows OS (due to `windows.h` and `mmsystem.h`)
- OpenGL and GLUT installed
- C++ Compiler (MinGW/GCC or Visual Studio)

### **Compilation Commands**

**MinGW:**
```bash
g++ main.cpp -o microplastic_sim.exe -lopengl32 -lglu32 -lfreeglut -lwinmm

## 🛠️ **Technologies Used**
