#include "messages.pb.h"

#include "point.h"

accf::Point::Point(protos::Point& p) {
  this->_x = p.x();
  this->_y = p.y();
  this->_z = p.z();
}

accf::Point::Point(double r, double theta, double z) {
  this->_x = r * std::cos(theta);
  this->_y = r * std::sin(theta);
  this->_z = z;
}

std::vector<double> accf::Point::coordinates() {
  return std::vector<double>({this->_x, this->_y, this->_z});
}

accf::Point accf::PointFromCartesian(double x, double y, double z) {
  protos::Point p;
  p.set_x(x);
  p.set_y(y);
  p.set_z(z);
  return accf::Point(p);
}

accf::Point accf::PointFromCylindrical(double r, double theta, double z) {
  return accf::Point(r, theta, z);
}


bool operator==(accf::Point l, accf::Point r) {
  double tolerance = 5.0 / 10000.0;
  auto lc = l.coordinates();
  auto rc = r.coordinates();
  return (abs(lc.at(0) - rc.at(0)) < tolerance) &&
         (abs(lc.at(1) - rc.at(1)) < tolerance) &&
         (abs(lc.at(2) - rc.at(2)) < tolerance);
}

bool operator!=(accf::Point l, accf::Point r) {
  return !(l == r);
}
