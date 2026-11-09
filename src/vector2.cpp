#include <string>
#include "vector2.hpp"
Vector2::Vector2(float x_i, float y_i) {
	x = x_i;
	y = y_i;
};
Vector2 Vector2::operator-(const Vector2 &v) const {
	return Vector2(x + v.x, y + v.y);
}
Vector2 Vector2::operator+(const Vector2 &v) const {
	return Vector2(x + v.x, y + v.y);
}
Vector2 Vector2::operator*(float v) {
	return Vector2(x * v, y * v);
}
Vector2 Vector2::operator/(float v) {
	return Vector2(x / v, y / v);
}
void Vector2::operator/=(float value) {
	x /= value;
	y /= value;
}
void Vector2::operator*=(float value) {
	x *= value;
	y *= value;
}
void Vector2::operator-=(Vector2 value) {
	x -= value.x;
	y -= value.y;
}
void Vector2::operator+=(Vector2 value) {
	x += value.x;
	y += value.y;
}
std::string Vector2::to_string() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
