#ifndef _ACCF_POINT_H
#define _ACCF_POINT_H

#include "messages.pb.h"

namespace accf {
  class Point {
    public:
      Point(protos::Point& p);
      Point(double r, double theta, double z);

      std::vector<double> coordinates();
      double x();
      double y();
      double z();

    private:
      double _x;
      double _y;
      double _z;
  };

  Point PointFromCartesian(double x, double y, double z);
  Point PointFromCylindrical(double r, double theta, double z);

  template<typename T>
  T ComputeAngularAverage(std::function<T(Point&)> f, double r, double z);
}  // namespace accf

bool operator==(accf::Point l, accf::Point r);
bool operator!=(accf::Point l, accf::Point r);

#include "point.tpp"

#endif  // _ACCF_POINT_H
