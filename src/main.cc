#include <iostream>
#include <math.h>

#include "messages.pb.h"

#include "point.h"

int main() {
  assert(accf::PointFromCartesian(0, 0, 0) == accf::PointFromCartesian(0, 0, 0));
  assert(accf::PointFromCartesian(0, 0, 0) == accf::PointFromCylindrical(0, 0, 0));
  assert(accf::PointFromCartesian(1, 0, 0) == accf::PointFromCylindrical(1, 0, 0));
  assert(accf::PointFromCartesian(-1, 0, 0) == accf::PointFromCylindrical(1, M_PI, 0));
  return(0);
}
