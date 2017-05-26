#include "evo/World.h"
#include "tools/Random.h"

#include "QSOrg.h"

class QSWorld {
private:
  emp::Random random;
  emp::evo::GridWorld<QSOrg> world;

public:
  QSWorld() {
    world.ConfigPop(20,20);
    world.Insert( QSOrg(0.0, 0.0, 0.0) );
    world.Print(PrintOrg);
  }
};
