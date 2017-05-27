// This is the main function for the NATIVE version of this project.

#include <iostream>

#include "../QSWorld.h"

int main()
{
  std::cout << "Hello World!" << std::endl;
  QSWorld world(20, 20, 5);

  for (size_t ud = 0; ud < 100; ud++) {
    world.Update();
  }
  world.Print();
}
