# Quad
Quadcopter simulation and control

## Installation & Setup
### Build JSBSim
```bash
git submodule update --init --recursive
cd third_party/jsbsim
mkdir build && cd build
cmake ..
make
```

## Start Flightgear
something like this
```bash
fgfs --fdm=--fdm=network,localhost,5502 --aircraft=ufo
```
