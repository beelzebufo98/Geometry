#pragma once

#include <cmath>
#include <string>
namespace geometry {
  class Vector {
  public:
    Vector();
    Vector(int x, int y);
    int getX() const;
    int getY() const;
    double length() const;
    int vectorProd(const Vector& other) const;
    int scalarProd(const Vector& other) const;
    Vector operator +() const;
    Vector operator -() const;
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator/(int scalar) const;
    Vector operator*(int scalar) const;
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator/=(int scalar);
    Vector& operator*=(int scalar);
    bool operator ==(const Vector& other) const;
    bool operator !=(const Vector& other) const;
    std::string ToString() const;
  private:
    int x_, y_;

  };
}