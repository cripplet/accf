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

double accf::Point::x() { return this->_x; }
double accf::Point::y() { return this->_y; }
double accf::Point::z() { return this->_z; }

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
  // TODO(minkezhang): Put tolerance into config file.
  double tolerance = 1.0 / 100000000.0;
  return (abs(l.x() - r.x()) < tolerance) &&
         (abs(l.y() - r.y()) < tolerance) &&
         (abs(l.z() - r.z()) < tolerance);
}

bool operator!=(accf::Point l, accf::Point r) {
  return !(l == r);
}

