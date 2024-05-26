#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "vector.h"
#include "point.h"
#include "segment.h"
#include "ray.h"
#include "line.h"
#include "circle.h"
#include "polygon.h"
namespace geometry {
  class Point;
  class Segment;
  class Vector;
  class Segment;
  class Ray;
  class Polygon;
  class Circle;
  class IShape {
  public:
    virtual ~IShape() = default;

    virtual IShape& Move(const geometry::Vector& vec) = 0;
    virtual bool ContainsPoint(const geometry::Point& point) const = 0;
    virtual bool CrossesSegment(const geometry::Segment& segment) const = 0;
    virtual std::unique_ptr<IShape> Clone() const = 0;
    virtual std::string ToString() const = 0;
  };
}

