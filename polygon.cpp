
#include "polygon.h"
namespace geometry {
	Polygon::Polygon(const std::vector<Point>& points):points_(points){}
	const std::vector<Point>& Polygon::GetVertices() const {
		return points_;
	}
	IShape& Polygon::Move(const Vector& vector) {
		for (auto& k : points_) {
			k.Move(vector);
		}
		return *this;
	}
	
	bool Polygon::ContainsPoint(const Point& point) const {
		size_t n = points_.size();
		bool result = false;
		for (size_t i = 0, j = n - 1; i < n; j = i++) {
			if ((points_[i].getY() > point.getY()) != (points_[j].getY() > point.getY()) &&
				(point.getX() < (points_[j].getX() - points_[i].getX()) * (point.getY() - points_[i].getY()) / (points_[j].getY() - points_[i].getY()) + points_[i].getX())) {
				result = !result;
			}
		}
		return result;
	}

	bool Polygon::CrossesSegment(const Segment& segment) const {
		size_t n = points_.size();
		for (size_t i = 0; i < n; ++i) {
			Segment edge(points_[i], points_[(i + 1) % n]);
			if (edge.CrossesSegment(segment)) {
				return true;
			}
		}
		return false;
	}
	std::unique_ptr<IShape> Polygon::Clone() const {
		return std::make_unique<Polygon>(*this);
	}
	std::string Polygon::ToString() const {
		std::string result = "Polygon(";
		for (size_t i = 0; i < points_.size(); ++i) {
			result += points_[i].ToString();
			if (i < points_.size() - 1) {
				result += ", ";
			}
		}
		result += ")";
		return result;
	}
}
/*
* bool Polygon::ContainsPoint(const Point& point) const {
		bool result = false;
		int j = points_.size() - 1;
		for (int i = 0; i < points_.size(); i++) {
			if ((points_[i].getY() < point.getY() && points_[j].getY() >= point.getY()) ||
				(points_[j].getY() < point.getY() && points_[i].getY() >= point.getY())) {
				if (points_[i].getX() + (point.getY() - points_[i].getY()) /
					static_cast<double>(points_[j].getY() - points_[i].getY()) *
					(points_[j].getX() - points_[i].getX()) < point.getX()) {
					result = !result;
				}
			}
			j = i;
		}
		return result;
	}
		Polygon(const std::vector<Point>& vertices);
		const std::vector<Point>& GetVertices() const;
		IShape& Move(const Vector& vector) override;
		bool ContainsPoint(const Point& point) const override;
		bool CrossesSegment(const Segment& segment) const override;
		std::unique_ptr<IShape> Clone() const override;
		std::string ToString() const override;
		 Пересекает ли прямая многоугольник можно определить так:
1. Берете вектор, описывающий прямую при этом дополняете его третьей нулевой координатой
2. Берете все вектора, исходящие из одной точки на этой прямой до всех точек многоугольника.
3. Находите все векторные произведения вектора из п.1 на векторы из п.2
4. Если у всех полученных в результате векторов третья координата имеет один и тот же знак(либо все положительные либо все отрицательные), то прямая многоугольник не пересекает
5. Если хотя бы у одного вектора третья координата по знаку отличается от других или равна нулю, то прямая пересекает многоугольник
6. Далее, так как у вас луч, то нужно определить пересекает ли ваша половина прямой данный многоугольник. Для этого можно найти все точки пересечения с прямыми, образующими многоугольник. И если вектор вашего луча сонаправлен хотя бы с одним вектором до точек пересечения, то луч пересекает многоугольник

bool Polygon::CrossesSegment(const Segment& segment) const {
		// Iterate through all edges of the polygon
		for (size_t i = 0; i < vertices_.size(); ++i) {
				size_t j = (i + 1) % vertices_.size(); // Next vertex index (loop back to the first vertex at the end)

				// Check if the segment intersects with the edge
				if (EdgeIntersectsRay(vertices_[i], vertices_[j], segment.GetStart(), segment.GetDirection())) {
						return true; // If intersection found, return true
				}
		}

		return false; // If no intersections found, return false
}

bool Polygon::EdgeIntersectsRay(const Point& start, const Point& end, const Point& rayOrigin, const Vector& rayDirection) const {
		// Check if the ray origin is between the start and end points of the edge
		if ((start.getY() > rayOrigin.getY()) != (end.getY() > rayOrigin.getY()) &&
				(rayOrigin.getX() < (end.getX() - start.getX()) * (rayOrigin.getY() - start.getY()) / (end.getY() - start.getY()) + start.getX())) {
				// If the above condition is true, then the ray intersects with the edge
				return true;
		}

		return false;
}
*/