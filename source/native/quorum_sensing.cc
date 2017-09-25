// This is the main function for the NATIVE version of this project.

#include <iostream>

#include "../QSWorld.h"

int main()
{
  QSWorld world(20, 20, 5);
  int numUpdates = 1;  // for testing
  int ControlOption = 9; 
  
  // I just want to see what it looks like before the updates
  std::cout << "Initial World Map" << std::endl;
  world.Print();
  std::cout << std::endl << std::endl;
  
  do {
  	std::cout << "Options: " << std::endl;
  	std::cout << "1 - Print world." << std::endl;
  	std::cout << "2 - Run updates (defined on command line)." << std::endl;
  	std::cout << "3 - Bottleneck event." << std::endl;
  	std::cout << "4 - Run 100 updates with a bottleneck event at end." << std::endl;
  	std::cout << "5 - Run reports." << std::endl;
  	std::cout << "Your choice? " << std::endl;
  	std::cin >> ControlOption;
  	
  	if (ControlOption == 1) {
  	    world.Print();
  	} else if (ControlOption == 2) {
  	  std::cout << "How many updates do you want to run?" << std::endl;
      std::cin >> numUpdates;
      
      for (size_t ud = 0; ud < numUpdates; ud++) {  // production number of updates is 100
         world.Update();
      }
  	} else if (ControlOption == 3) {
  		std::cout << "Bottleneck event would happen here." << std::endl;
  	} else if (ControlOption == 4) {
  	     for (size_t ud = 0; ud < 100; ud++) {  // production number of updates is 100
             world.Update();
      }
      std::cout << "Need to call bottleneck event here." << std::endl;
  	
  	} else if (ControlOption == 5) {
  		std::cout << "Report menu would appear here." << std::endl;
  	
  	} else if (ControlOption == 9) {
  		std::cout << "Good bye." << std::endl;
  	} else {
  		std::cout << "Invalid option" << std::endl;
  	}
  
  
  } while (ControlOption != 9);
  


}
