#include "Catch/catch.hpp"

#include "point.h"

double DistanceToOrigin(accf::Point& p) {
  return std::sqrt(p.x() * p.x() + p.y() * p.y());
}

TEST_CASE("point|simple init", "Tests simple Point constructor") {
  REQUIRE(accf::PointFromCartesian(0, 0, 0) == accf::PointFromCartesian(0, 0, 0));
  REQUIRE(accf::PointFromCartesian(0, 0, 0) == accf::PointFromCylindrical(0, 0, 0));
  REQUIRE(accf::PointFromCartesian(1, 0, 0) == accf::PointFromCylindrical(1, 0, 0));
  REQUIRE(accf::PointFromCartesian(-1, 0, 0) == accf::PointFromCylindrical(1, M_PI, 0));
}

TEST_CASE("point|angular average", "Tests ComputeAngularAverage") {
  std::function<double(accf::Point&)> f = DistanceToOrigin;
  // TODO(minkezhang): Put tolerance into config file.
  REQUIRE(std::abs(accf::ComputeAngularAverage(f, 1, 0) - 1) < (1.0 / 100000000.0));
}
