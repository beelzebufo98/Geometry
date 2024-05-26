
#include "segment.h"

namespace geometry {
  Segment::Segment(const Point& p1, const Point& p2) {
    start_ = p1;
    end_ = p2;
  }
  const Point& Segment::GetStart() const {
    return start_;
  }
  const Point& Segment::GetEnd() const{
    return end_;
  }
  IShape& Segment::Move(const Vector& vector) {
    start_.Move(vector);
    end_.Move(vector);
    return *this;
  }
  bool Segment::ContainsPoint(const Point& point) const {
    Vector vect1 = Vector(point.getX() - start_.getX(), point.getY() - start_.getY());
    Vector vect2 = Vector(end_.getX() - point.getX(), end_.getY() - point.getY());
    int scalar = vect1.scalarProd(vect2);
    int vector_prod = vect1.vectorProd(vect2);
    if (vector_prod == 0 && scalar >= 0) {
      return true;
    }
    return false;
  }
  bool Segment::CrossesSegment(const Segment& segment) const {
    Vector a_b = Vector(end_.getX() - start_.getX(), end_.getY() - start_.getY());
    Vector c_d = Vector(segment.GetEnd().getX() - segment.GetStart().getX(), segment.GetEnd().getY() - segment.GetStart().getY());
    Vector a_c = Vector(segment.GetStart().getX() - start_.getX(), segment.GetStart().getY() - start_.getY());
    Vector a_d = Vector(segment.GetEnd().getX() - start_.getX(), segment.GetEnd().getY() - start_.getY());
    Vector c_a = Vector(start_.getX() - segment.GetStart().getX(), start_.getY() - segment.GetStart().getY());
    Vector c_b = Vector(end_.getX() - segment.GetStart().getX(), end_.getY() - segment.GetStart().getY());
    int dotProduct1 = a_b.vectorProd(a_c);
    int dotProduct2 = a_b.vectorProd(a_d);
    int dotProduct3 = c_d.vectorProd(c_a);
    int dotProduct4 = c_d.vectorProd(c_b);
    if (dotProduct1 * dotProduct2 <= 0 && dotProduct3 * dotProduct4 <= 0) {
      if (dotProduct1 == 0 && dotProduct2 == 0 && dotProduct3 == 0 && dotProduct4 == 0) {
        return check(segment);
      }
      return true;
    }
    return false;
  }
  bool Segment::check(const Segment& segment) const {
    return (std::min(start_.getX(), end_.getX()) <= std::max(segment.GetStart().getX(), segment.GetEnd().getX()) &&
      std::max(start_.getX(), end_.getX()) >= std::min(segment.GetStart().getX(), segment.GetEnd().getX()) &&
      std::min(start_.getY(), end_.getY()) <= std::max(segment.GetStart().getY(), segment.GetEnd().getY()) &&
      std::max(start_.getY(), end_.getY()) >= std::min(segment.GetStart().getY(), segment.GetEnd().getY()));
  }
  std::unique_ptr<IShape> Segment::Clone() const {
    return std::make_unique<Segment>(*this);
  }
  std::string Segment::ToString() const {
    return "Segment(" + start_.ToString() + ", " + end_.ToString() + ")";
  }
}