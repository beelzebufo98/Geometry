#pragma once
#include "ishape.h"
#include "point.h"
#include "vector.h"
namespace geometry {
  class Line : public IShape {
  public:
    Line(const Point& start, const Point& end);
    const Point& GetStart() const;
    const Point& GetEnd() const;
    bool check(const Segment& segment) const;
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;

  private:
    Point start_, end_;
  };
}