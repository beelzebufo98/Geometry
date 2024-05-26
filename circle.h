#pragma once
#include "ishape.h"
#include "point.h"
#include <memory>
#include <string>
#include <cmath>

namespace geometry {
  class Circle : public IShape {
  public: 
    Circle(const Point& center, int radius);

    const Point& GetCenter() const;
    int GetRadius() const;

    IShape& Move(const Vector& vec) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
  private:
    Point center_;
    int radius_;
  };
}