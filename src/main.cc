#include <iostream>
#include <string>

#include "config.pb.h"

#include "fileio.h"
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

  protos::Config c;
  c.set_tolerance(1.0 / 100000000.0);
  c.set_n_angular_buckets(1000);

  accf::DumpConfig("data/simpleconfig.buf", c, false);
  protos::Config d = accf::LoadConfig("data/simpleconfig.buf", false);

  std::string cs, ds;
  c.SerializeToString(&cs);
  d.SerializeToString(&ds);
  assert(cs == ds);

  try {
    accf::DumpConfig("data/simpleconfig.buf", c, true);
  } catch(const std::logic_error& e) {
  }

  try {
    accf::LoadConfig("data/simpleconfig.buf", true);
  } catch(const std::logic_error& e) {
  }

  try {
    accf::LoadConfig("data/non-existent", false);
  } catch(const std::runtime_error& e) {
  }

  return(0);
}
