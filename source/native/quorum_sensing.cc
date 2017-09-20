// This is the main function for the NATIVE version of this project.

#include <iostream>

#include "../QSWorld.h"

int main()
{
  QSWorld world(20, 20, 5);
  
  // I just want to see what it looks like before the updates
  std::cout << "Initial World" << std::endl;
  world.Print();
  std::cout << std::endl;
  std::cout << std::endl;

  for (size_t ud = 0; ud < 100; ud++) {
    world.Update();
  }
  world.Print();
}
