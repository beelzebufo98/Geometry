
#include "ray.h"

namespace geometry {
	Ray::Ray(const Point& start, const Point& direction) : start_(start), direction_(direction) {}
  const Point& Ray::GetStart() const {
    return start_;
  }
  const Point& Ray::GetDirection() const {
    return direction_;
  }
  IShape& Ray::Move(const Vector& vector) {
    start_.Move(vector);
    direction_.Move(vector);
    return *this;
  }
  bool Ray::ContainsPoint(const Point& point) const {
    Vector vect1 = Vector(point.getX() - start_.getX(), point.getY() - start_.getY());
    Vector vect2 = Vector(direction_.getX() - point.getX(), direction_.getY() - point.getY());
    double scalar = vect1.scalarProd(vect2);
    double vector_prod = vect1.vectorProd(vect2);
    if (vector_prod == 0 && scalar >= 0) {
      return true;
    }
    return false;
  }
  bool Ray::CrossesSegment(const Segment& segment) const {
    Vector a_b = Vector(direction_.getX() - start_.getX(), direction_.getY() - start_.getY());
    Vector c_d = Vector(segment.GetEnd().getX() - segment.GetStart().getX(), segment.GetEnd().getY() - segment.GetStart().getY());
    Vector a_c = Vector(segment.GetStart().getX() - start_.getX(), segment.GetStart().getY() - start_.getY());
    Vector a_d = Vector(segment.GetEnd().getX() - start_.getX(), segment.GetEnd().getY() - start_.getY());
    Vector c_a = Vector(start_.getX() - segment.GetStart().getX(), start_.getY() - segment.GetStart().getY());
    Vector c_b = Vector(direction_.getX() - segment.GetStart().getX(), direction_.getY() - segment.GetStart().getY());
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
  bool Ray::check(const Segment& segment) const {
    return (std::min(start_.getX(), direction_.getX()) <= std::max(segment.GetStart().getX(), segment.GetEnd().getX()) &&
      std::max(start_.getX(), direction_.getX()) >= std::min(segment.GetStart().getX(), segment.GetEnd().getX()) &&
      std::min(start_.getY(), direction_.getY()) <= std::max(segment.GetStart().getY(), segment.GetEnd().getY()) &&
      std::max(start_.getY(), direction_.getY()) >= std::min(segment.GetStart().getY(), segment.GetEnd().getY()));
  }

  std::unique_ptr<IShape> Ray::Clone() const {
    return std::make_unique<Ray>(*this);
  }

  std::string Ray::ToString() const {
    return "Ray(" + start_.ToString() + ", " + direction_.ToString() + ")";
  }

}
/*
    const Point& GetStart() const;
    const Point& GetDirection() const;

    IShape& Move(const Vector& vec) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    */