#include "point.h"

template<typename T> T accf::ComputeAngularAverage(std::function<T(Point&)> f, double r, double z) {
  // TODO(minkezhang): Read this from config file ANGULAR_GRAIN instead.
  double _grain = 1000;

  std::vector<double> range(_grain);
  std::iota(range.begin(), range.end(), 0);
  std::transform(range.begin(), range.end(), range.begin(), [_grain](int index) {
      return(index / _grain * 2 * M_PI);});

  std::vector<T> result(_grain);
  std::transform(range.begin(), range.end(), result.begin(),
      [f, r, z](double theta) {
        auto p = accf::PointFromCylindrical(r, theta, z);
        return(f(p));
      });
  return std::accumulate(result.begin(), result.end(), 0, std::plus<T>()) / _grain;
}
