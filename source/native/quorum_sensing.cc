// This is the main function for the NATIVE version of this project.

#include <iostream>

#include "../QSWorld.h"

int main()
{
  QSWorld world(20, 20, 5);
  int numUpdates = 1;  // for testing
  
  // I just want to see what it looks like before the updates
  std::cout << "Initial World Map" << std::endl;
  world.Print();
  std::cout << std::endl;
  std::cout << std::endl;
  
  std::cout << "How many updates do you want to run?" << std::endl;
  std::cin >> numUpdates;

  for (size_t ud = 0; ud < numUpdates; ud++) {  // production number of updates is 100
    world.Update();
  }
  world.Print();
}
