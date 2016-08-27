#include <iostream>

#include "messages.pb.h"

#include "point.h"

double _R(accf::Point& p) {
  return std::sqrt(p.x() * p.x() + p.y() * p.y());
}

int main() {
  assert(accf::PointFromCartesian(0, 0, 0) == accf::PointFromCartesian(0, 0, 0));
  assert(accf::PointFromCartesian(0, 0, 0) == accf::PointFromCylindrical(0, 0, 0));
  assert(accf::PointFromCartesian(1, 0, 0) == accf::PointFromCylindrical(1, 0, 0));
  assert(accf::PointFromCartesian(-1, 0, 0) == accf::PointFromCylindrical(1, M_PI, 0));

  std::function<double(accf::Point&)> f = _R;
  // TODO(minkezhang): Put tolerance into config file.
  assert(std::abs(accf::ComputeAngularAverage(f, 1, 0) - 1) < (1.0 / 100000000.0));

  return(0);
}
