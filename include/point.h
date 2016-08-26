#ifndef _ACCF_POINT_H
#define _ACCF_POINT_H

#include "messages.pb.h"

namespace accf {
  class Point {
    public:
      Point(protos::Point& p);
      Point(double r, double theta, double z);

      std::vector<double> coordinates();

    private:
      double _x;
      double _y;
      double _z;
  };

  Point PointFromCartesian(double x, double y, double z);
  Point PointFromCylindrical(double r, double theta, double z);
}

bool operator==(accf::Point l, accf::Point r);
bool operator!=(accf::Point l, accf::Point r);

#endif  // _ACCF_POINT_H
