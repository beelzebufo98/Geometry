
#include "line.h"

namespace geometry {
  Line::Line(const Point& start, const Point& end) {
    start_ = start;
    end_ = end;
  }
  const Point& Line::GetStart() const {
    return start_;
  }
  const Point& Line::GetEnd() const {
    return end_;
  }
  IShape& Line::Move(const Vector& vector) {
    start_.Move(vector);
    end_.Move(vector);
    return *this;
  }
  bool Line::ContainsPoint(const Point& point) const {
    Vector vect1 = Vector(point.getX() - start_.getX(), point.getY() - start_.getY());
    Vector vect2 = Vector(end_.getX() - point.getX(), end_.getY() - point.getY());
    double scalar = vect1.scalarProd(vect2);
    double vector_prod = vect1.vectorProd(vect2);
    if (vector_prod == 0 && scalar >= 0) {
      return true;
    }
    return false;
  }
  bool Line::CrossesSegment(const Segment& segment) const {
    Vector a_b = Vector(end_.getX() - start_.getX(), end_.getY() - start_.getY());
    Vector c_d = Vector(segment.GetEnd().getX() - segment.GetStart().getX(), segment.GetEnd().getY() - segment.GetStart().getY());
    Vector a_c = Vector(segment.GetStart().getX() - start_.getX(), segment.GetStart().getY() - start_.getY());
    Vector a_d = Vector(segment.GetEnd().getX() - start_.getX(), segment.GetEnd().getY() - start_.getY());
    Vector c_a = Vector(start_.getX() - segment.GetStart().getX(), start_.getY() - segment.GetStart().getY());
    Vector c_b = Vector(end_.getX() - segment.GetStart().getX(), end_.getY() - segment.GetStart().getY());
    double dotProduct1 = a_b.vectorProd(a_c);
    double dotProduct2 = a_b.vectorProd(a_d);
    double dotProduct3 = c_d.vectorProd(c_a);
    double dotProduct4 = c_d.vectorProd(c_b);
    if (dotProduct1 * dotProduct2 <= 0 && dotProduct3 * dotProduct4 <= 0) {
      if (dotProduct1 == 0 && dotProduct2 == 0 && dotProduct3 == 0 && dotProduct4 == 0) {
        return check(segment);
      }
      return true;
    }
    return false;
  }
  bool Line::check(const Segment& segment) const {
    return (std::min(start_.getX(), end_.getX()) <= std::max(segment.GetStart().getX(), segment.GetEnd().getX()) &&
      std::max(start_.getX(), end_.getX()) >= std::min(segment.GetStart().getX(), segment.GetEnd().getX()) &&
      std::min(start_.getY(), end_.getY()) <= std::max(segment.GetStart().getY(), segment.GetEnd().getY()) &&
      std::max(start_.getY(), end_.getY()) >= std::min(segment.GetStart().getY(), segment.GetEnd().getY()));
  }
  std::unique_ptr<IShape> Line::Clone() const {
    return std::make_unique<Line>(*this);
  }
  std::string Line::ToString() const {
    double a = end_.getY() - start_.getY();
    double b = start_.getX() - end_.getX();
    double c = -(a * start_.getX() + b * start_.getY());
    return "Line(" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ")";
  }
}

/*
    Line(const Point& start, const Point& end);
    const Point& GetStart() const;
    const Point& GetEnd() const;
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
*/