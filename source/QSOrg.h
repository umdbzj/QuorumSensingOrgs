#include "tools/Random.h"
#include "tools/string_utils.h"

class QSOrg {
private:
  double coop_prob;
  double ai_produce;
  double threshold;
public:
  QSOrg(double _coop=0.0, double _ai=0.0, double _thresh=0.0)
    : coop_prob(_coop), ai_produce(_ai), threshold(_thresh) { ; }
  QSOrg(const QSOrg &) = default;
  QSOrg(QSOrg &&) = default;

  QSOrg & operator=(const QSOrg &) = default;
  QSOrg & operator=(QSOrg &&) = default;

  double GetCoopProb() const { return coop_prob; }
  double GetAIProduce() const { return ai_produce; }
  double GetThreshold() const { return threshold; }

  void SetCoopProb(double _in) { coop_prob = _in; }
  void SetAIProduce(double _in) { ai_produce = _in; }
  void SetThreshold(double _in) { threshold = _in; }
};

std::string PrintOrg(QSOrg * org) {
  if (!org) return "-";
  int out_val = org->GetCoopProb()*10;
  return emp::to_string(out_val);
}
