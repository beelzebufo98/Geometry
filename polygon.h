#pragma once
#include "ishape.h"
#include "point.h"
#include <vector>
namespace geometry {
	class Polygon:public IShape {
	public:
		Polygon(const std::vector<Point>& points);
		const std::vector<Point>& GetVertices() const;
		IShape& Move(const Vector& vector) override;
		bool ContainsPoint(const Point& point) const override;
		bool CrossesSegment(const Segment& segment) const override;
		std::unique_ptr<IShape> Clone() const override;
		bool Intersects(const Point& start, const Point& end, const Point& rayOrigin, const Vector& ray) const;
		std::string ToString() const override;
	private:
		std::vector<Point> points_;
	};
}