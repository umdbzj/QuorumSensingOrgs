#include "evo/World.h"
#include "tools/Random.h"

#include "QSOrg.h"

class QSWorld {
private:
  emp::Random random;
  emp::evo::GridWorld<QSOrg> world;
  size_t ai_radius;

public:
  QSWorld(size_t width=100, size_t height=100, size_t _air=10) : ai_radius(_air) {
    world.ConfigPop(width,height);
    world.Insert( QSOrg(0.0, 0.0, 0.0) );
    world.Print(PrintOrg);
  }

  double GetAveAI(size_t id) {
    return 0.0;
  }

  void Update(size_t new_resources=10) {
    // Give each organism extra resources.
    for (size_t i = 0; i < world.GetSize(); i++) {
      if (world.IsOccupied(i) == false) continue;
      world[i].AddResource(new_resources);
    }

    // Check to see if each organism produces public goods.
    for (size_t i = 0; i < world.GetSize(); i++) {
      if (world.IsOccupied(i) == false) continue;
      
    }
  }
};
