#include <FGFDMExec.h>
#include <models/FGFCS.h>
#include <models/FGInput.h>

#include <iostream>

#include "initialization/FGInitialCondition.h"

int main() {
  JSBSim::FGFDMExec exec;
  exec.SetRootDir(SGPath("config/"));
  exec.SetAircraftPath(SGPath("aircraft/"));
  exec.SetEnginePath(SGPath("engine/"));
  exec.SetSystemsPath(SGPath("systems/"));
  exec.SetOutputDirectives(SGPath("output/OutputCSV.xml"));
  //  exec.SetOutputDirectives(SGPath("output/OutputFG.xml"));
  exec.LoadModel("F450");

  auto fgic = exec.GetIC();
  fgic->Load(SGPath("reset00.xml"));

  //  auto propMgr = exec.GetPropertyManager();
  //  propMgr->GetNode()->SetDouble("fcs/cmdEscFR_nd", 0.0);
  exec.SetPropertyValue("fcs/cmdEscFR_nd", 0.0);
  exec.SetPropertyValue("fcs/cmdEscAL_nd", 0.0);
  exec.SetPropertyValue("fcs/cmdEscFL_nd", 0.0);
  exec.SetPropertyValue("fcs/cmdEscAR_nd", 0.0);
  exec.RunIC();

  //  double altitude = exec.GetPropertyValue("position/h-agl-ft");
  //  double lat = exec.GetPropertyValue("position/lat-geod-deg");

  double max_t = 10.0;
  for (double t = 0.0; t <= max_t;) {
    exec.Run();
    t = exec.GetSimTime();
    double cmd = exec.GetPropertyValue("fcs/cmdEscFR_nd");
    double time = exec.GetSimTime();
    double alt = exec.GetPropertyValue("position/h-agl-ft");
    //    std::cout << time << ", " << alt << ", " << cmd << std::endl;
  }
  return 0;
}
