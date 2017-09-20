#include "base/assert.h"
#include "evo/World.h"
#include "tools/Random.h"

#include "QSOrg.h"

const size_t produce_cost = 8;
const size_t repro_cost = 50;

class QSWorld {
private:
  emp::Random random;
  emp::evo::GridWorld<QSOrg> world;
  size_t width;
  size_t height;
  int ai_radius;

  size_t GetX(size_t id) const { return id % width; }
  size_t GetY(size_t id) const { return id / width; }
  size_t GetID(size_t x, size_t y) const { return y * width + x; }

  size_t OffsetID(size_t id, int x_off, int y_off) {
    size_t new_x = (GetX(id) + (size_t) (x_off + (int) width)) % width;
    size_t new_y = (GetY(id) + (size_t) (y_off + (int) height)) % height;
    return GetID(new_x, new_y);
  }
public:
  QSWorld(size_t _width=100, size_t _height=100, int _air=10)
    : width(_width), height(_height), ai_radius(_air)
  {
    world.ConfigPop(width,height);
    world.Insert( QSOrg(0.0, 0.0, 0.6) );  // defector
    world.Insert( QSOrg(1.0, 0.0, 0.6) );  // wild type
    world.Insert( QSOrg(1.0, 0.0, 0.0) ); // unconditional cooperator
  }

  size_t GetWidth() const { return width; }
  size_t GetHeight() const { return height; }
  int GetAIRadius() const { return ai_radius; }

  double GetAveAI(size_t id) {
    double total_ai = 0.0;
    size_t org_count = 0;
    for (int x_off = -ai_radius; x_off <= ai_radius; x_off++) {
      for (int y_off = -ai_radius; y_off <= ai_radius; y_off++) {
	size_t test_id = OffsetID(id, x_off, y_off);
	if (world.IsOccupied(test_id)) total_ai += world[test_id].GetAIProduce();
	org_count++;
      }
    }
    return total_ai / (double) org_count;
  }

  void Update(size_t new_resources=10) {
    // Give each organism extra resources.
    for (size_t i = 0; i < world.GetSize(); i++) {
      if (world.IsOccupied(i) == false) continue;
      world[i].AddResource(new_resources);
    }

    // Check to see if each organism produces public goods.
    for (size_t i = 0; i < world.GetSize(); i++) {
      if (world.IsOccupied(i) == false) continue;  // No organism here...
      double ave_ai = GetAveAI(i);
      if (world[i].TestProduce(random, ave_ai) == false) continue; // Not producing!

      // Pay costs for producing...
      world[i].UseResource(produce_cost);

      // Figure out neighborhood ID's
      emp::vector<size_t> ids;
      for (int x_off = -1; x_off <= 1; x_off++) {
	for (int y_off = -1; y_off <= 1; y_off++) {
	  size_t test_id = OffsetID(i, x_off, y_off);
	  if (world.IsOccupied(test_id)) ids.push_back(test_id);
	}
      }

      // Give out the resources.
      size_t base = 45 / ids.size();
      size_t extras = 45 % ids.size();
      for (size_t test_id : ids) {
	world[test_id].AddResource(base);
	if (extras) { world[test_id].AddResource(1); extras--; }
      }
    }

    // If anyone has hit the reproduce threshold, do so.
    for (size_t i = 0; i < world.GetSize(); i++) {
      if (world.IsOccupied(i) == false) continue;  // No organism here...
      if (world[i].GetResourceCount() > repro_cost) {
	world[i].UseResource(repro_cost);
	world.InsertBirth(world[i], i);
      }
    }
  }

  void Print() {
    world.Print(PrintOrg);
  }

};
