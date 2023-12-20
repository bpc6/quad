#include <FGFDMExec.h>

#include <iostream>

#include "initialization/FGInitialCondition.h"

int main() {
  JSBSim::FGFDMExec exec;
  exec.SetRootDir(SGPath("config/"));
  exec.SetAircraftPath(SGPath("aircraft/"));
  exec.SetEnginePath(SGPath("engine/"));
  exec.SetSystemsPath(SGPath("systems/"));
  exec.LoadModel("F450");

  auto fgic = exec.GetIC();
  fgic->Load(SGPath("initGrnd.xml"));
  exec.RunIC();

  int num_steps = 10;
  for (int i = 0; i < num_steps; ++i) {
    exec.Run();
    double time = exec.GetSimTime();
    double altitude = exec.GetPropertyValue("position/h-sl-ft");
    double lat = exec.GetPropertyValue("position/lat-geod-deg");
    std::cout << time << ", " << altitude << ", " << lat << std::endl;
  }
  return 0;
}
