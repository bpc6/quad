#include <FGFDMExec.h>

#include <iostream>

#include "initialization/FGInitialCondition.h"

int main() {
  JSBSim::FGFDMExec exec;
  exec.SetRootDir(SGPath("config/"));
  exec.SetAircraftPath(SGPath("aircraft/"));
  exec.SetEnginePath(SGPath("engine/"));
  exec.SetSystemsPath(SGPath("systems/"));
  exec.SetOutputDirectives(SGPath("output/OutputFG.xml"));
  exec.LoadModel("F450");

  auto fgic = exec.GetIC();
  fgic->Load(SGPath("reset00.xml"));
  exec.RunIC();

  int num_steps = 10000;
  for (int i = 0; i < num_steps; ++i) {
    exec.Run();
    double time = exec.GetSimTime();
    double altitude = exec.GetPropertyValue("position/h-agl-ft");
    double lat = exec.GetPropertyValue("position/lat-geod-deg");
    //    std::cout << time << ", " << altitude << ", " << lat << std::endl;
  }
  return 0;
}
