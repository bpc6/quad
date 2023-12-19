#include <FGFDMExec.h>

#include <iostream>

int main() {
  // Create an instance of the flight dynamics model
  JSBSim::FGFDMExec exec;
  exec.SetRootDir(SGPath("third_party/jsbsim"));

  exec.LoadScript(SGPath("scripts/c1723.xml"));
  auto result = exec.Run();
  while (result) {        // cyclic execution
    result = exec.Run();  // execute JSBSim
  }

  return 0;
}
