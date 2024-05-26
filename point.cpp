
#include "point.h"

namespace geometry {

	Point::Point():x_(0),y_(0){}
	Point::Point(int x, int y) :x_{ x }, y_{ y } {}
	int Point::getX() const { return x_; }
	int Point::getY() const { return y_; }
	Vector Point::operator-(const Point& other) const {
		return Vector(x_ - other.x_, y_ - other.y_);
	}
	IShape& Point::Move(const Vector& vector) {
		x_ += vector.getX();
		y_ += vector.getY();
		return *this;
	}
	bool Point::ContainsPoint(const Point& point) const {
		return x_ == point.x_ && y_ == point.y_;
	}
	bool Point::CrossesSegment(const Segment& segment) const {
		return segment.ContainsPoint(*this);
	}
	std::unique_ptr<IShape> Point::Clone() const {
		return std::make_unique<Point>(*this);
	}
	std::string Point::ToString() const {
		return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
	}
	
}