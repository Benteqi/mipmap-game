#include <string>
#pragma once
class Vector2 {
	float x, y;
	public: 
	Vector2(float x_i, float y_i) ;
	Vector2 operator-(const Vector2 &v) const;
	Vector2 operator+(const Vector2 &v) const;
	Vector2 operator/(float v);
	Vector2 operator*(float v);
	void operator*=(float value);
	void operator/=(float value);
	void operator+=(Vector2 value);
	void operator-=(Vector2 value);
	std::string to_string();
};
