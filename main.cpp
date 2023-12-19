#include <FGFDMExec.h>

#include <iostream>

int main() {
  JSBSim::FGFDMExec exec;
  exec.SetRootDir(SGPath("third_party/jsbsim/"));
  exec.SetAircraftPath(SGPath("aircraft/"));
  exec.SetEnginePath(SGPath("engine/"));
  exec.LoadModel("F450");

  //  int num_steps = 100;
  //  exec.RunIC()
  //  for (int i = 0; i < num_steps; ++i) {
  //    exec.Run();
  //    double time = exec.GetSimTime();
  //    double altitude = exec.GetPropertyValue("position/h-sl-meters");
  //    std::cout << time << ", " << altitude << std::endl;
  //  }
  return 0;
}
