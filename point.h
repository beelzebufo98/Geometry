#pragma once
#include "vector.h"
#include "segment.h"
#include "ishape.h"

namespace geometry {


  class Point : public IShape {
  public:
    
    Point();
    Vector operator-(const Point& other) const;
    Point(int x, int y);
    int getX() const;
    int getY() const;
    IShape& Move(const Vector& vector) override;
    bool ContainsPoint(const Point& point) const override;
    bool CrossesSegment(const Segment& segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
  private:
    int x_, y_;
  };
}