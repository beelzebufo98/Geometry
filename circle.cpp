#include "circle.h"


namespace geometry {

  Circle::Circle(const Point& center, int radius) : center_(center), radius_(radius) {}

  const Point& Circle::GetCenter() const {
    return center_;
  }

  int Circle::GetRadius() const {
    return radius_;
  }

  IShape& Circle::Move(const Vector& vec) {
    center_.Move(vec);
    return *this;
  }

  bool Circle::ContainsPoint(const Point& point) const {
    Vector vect(point.getX() - center_.getX(), point.getY() - center_.getY());
    return vect.length() == radius_;
  }

  bool Circle::CrossesSegment(const Segment& segment) const {
    Point p1 = segment.GetStart();
    Point p2 = segment.GetEnd();

    bool p1_inside = ContainsPoint(p1);
    bool p2_inside = ContainsPoint(p2);

    if (p1_inside || p2_inside) {
      return true;
    }

    int dist1 = (p1.getX() - center_.getX()) * (p1.getX() - center_.getX()) + (p1.getY() - center_.getY()) * (p1.getY() - center_.getY());
    int dist2 = (p2.getX() - center_.getX()) * (p2.getX() - center_.getX()) + (p2.getY() - center_.getY()) * (p2.getY() - center_.getY());

    if ((dist1 < radius_ * radius_ && dist2 > radius_ * radius_) || (dist1 > radius_ * radius_ && dist2 < radius_ * radius_)) {
      return true;
    }

    int a = p1.getY() - p2.getY();
    int b = p2.getX() - p1.getX();
    int c = p1.getX() * p2.getY() - p2.getX() * p1.getY();

    double distance = std::abs(a * center_.getX() + b * center_.getY() + c) / std::sqrt(a * a + b * b);
    return distance < radius_;
  }

  std::unique_ptr<IShape> Circle::Clone() const {
    return std::make_unique<Circle>(*this);
  }
  std::string Circle::ToString() const {
    return "Circle(" + center_.ToString() + ", " + std::to_string(radius_) + ")";
  }
} 
