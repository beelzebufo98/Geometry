
#include "vector.h"

namespace geometry {
	Vector::Vector() : x_(0), y_(0) {}
	Vector::Vector(int x, int y) : x_(x), y_(y) {}
	int Vector::getX() const { return x_; }
	int Vector::getY() const { return y_; }
  int Vector::vectorProd(const Vector& other) const {
    return x_ * other.y_ - y_ * other.x_;
  }
  int Vector::scalarProd(const Vector& other) const {
    return x_ * other.x_ + y_ * other.y_;
  }
  Vector Vector::operator +() const {
    return *this;
  }
  Vector Vector::operator -() const {
    return { -x_,-y_ };
  }
  Vector Vector::operator+(const Vector& other) const {
    return Vector(x_ + other.x_, y_ + other.y_);
  }
  Vector Vector::operator-(const Vector& other) const {
    return Vector(x_ + other.x_, y_ + other.y_);
  }
  Vector Vector::operator/(int scalar) const {
    return { x_ / scalar,y_ / scalar };
  }
  Vector Vector::operator*(int scalar) const {
    return { x_ * scalar,y_ * scalar };
  }
  Vector& Vector::operator+=(const Vector& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
  }
  Vector& Vector::operator-=(const Vector& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
  }
  double Vector::length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
  }
  Vector& Vector::operator/=(int scalar) {
    x_ /= scalar;
    y_ /= scalar;
    return *this;
  }
  Vector& Vector::operator*=(int scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
  }
  bool Vector::operator ==(const Vector& other) const {
    return x_ == other.x_ && y_ == other.y_;
  }
  bool Vector::operator !=(const Vector& other) const {
    return !(*this == other);
  }

  std::string Vector::ToString() const {
    return "Vector(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
  }
  
}