#include "tools/Random.h"
#include "tools/string_utils.h"

class QSOrg {
private:
  double coop_prob;
  double ai_produce;
  double threshold;
  size_t resource_count;
public:
  QSOrg(double _coop=0.0, double _ai=0.0, double _thresh=0.0, size_t _rc=0)
    : coop_prob(_coop), ai_produce(_ai), threshold(_thresh)
    , resource_count(_rc) { ; }
  QSOrg(const QSOrg &) = default;
  QSOrg(QSOrg &&) = default;

  QSOrg & operator=(const QSOrg &) = default;
  QSOrg & operator=(QSOrg &&) = default;

  double GetCoopProb() const { return coop_prob; }
  double GetAIProduce() const { return ai_produce; }
  double GetThreshold() const { return threshold; }
  size_t GetResourceCount() const { return resource_count; }

  void SetCoopProb(double _in) { coop_prob = _in; }
  void SetAIProduce(double _in) { ai_produce = _in; }
  void SetThreshold(double _in) { threshold = _in; }

  void AddResource(size_t amt) { resource_count += amt; }
  void UseResource(size_t amt) { resource_count -= amt; }

  bool TestProduce(emp::Random & random, double ai_level) {
    if (ai_level < threshold) return false;
    return random.P(coop_prob);
  }
};

std::string PrintOrg(QSOrg * org) {
  if (!org) return "-";
  int out_val = org->GetCoopProb()*10;
  return emp::to_string(out_val);
}
