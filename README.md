# Cube3D

## Description
Cube3D is a 42 project inspired by *Wolfenstein 3D*.  
It implements a simple raycasting engine to render a 3D perspective view from a 2D map using the MiniLibX library.

---

## Features
- 2D map parsing  
- First-person view rendering with raycasting  
- Basic player movement and rotation  
- Floor, ceiling, and wall drawing  

---

## Build
Requirements on Linux/WSL:  
```bash
sudo apt-get install build-essential libx11-dev libxext-dev libbsd-dev zlib1g-dev
```

Compile with:  
```bash
make
```

---

## Run
```bash
./cube3d maps/example.cub
```

---

## Controls
- `W / S` → move forward / backward  
- `A / D` → strafe left / right  
- `← / →` → rotate view  
- `ESC` → quit  

---

## Example map
```
111111
100001
101001
100001
111111
```
- `1` → wall  
- `0` → empty space  
- `N/S/E/W` → player start position  
