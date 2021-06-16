#pragma once
#include "Quaternion.h"

namespace Alpha
{
	inline const Quaternion Quaternion::Identity()
	{
		return Quaternion(Vector3::Zero(), 1.0f);
	}

	inline Quaternion& Quaternion::operator+=(const Quaternion& other)
	{
		this->real += other.real;
		this->imaginary += other.imaginary;
		return *this;
	}

	inline Quaternion& Quaternion::operator*=(const Quaternion& other)
	{
		const float w1 = real;
		const float w2 = other.real;
		const float x1 = imaginary.At(0);
		const float x2 = other.imaginary.At(0);
		const float y1 = imaginary.At(1);
		const float y2 = other.imaginary.At(1);
		const float z1 = imaginary.At(2);
		const float z2 = other.imaginary.At(2);

		this->real = (w1 * w2) - (x1 * x2) - (y1 * y2) - (z1 * z2);
		this->imaginary.X() = (w1 * x2) + (w2 * x1) + (y1 * z2) - (y2 * z1);
		this->imaginary.Y() = (w1 * y2) + (w2 * y1) + (z1 * x2) - (z2 * x1);
		this->imaginary.Z() = (w1 * z2) + (w2 * z1) + (x1 * y2) - (x2 * y1);

		return *this;
	}

	inline Quaternion& Quaternion::operator*=(const float real)
	{
		this->real *= real;
		this->imaginary *= real;
		return *this;
	}

	inline Quaternion& Quaternion::operator/=(const float real)
	{
		this->real /= real;
		this->imaginary /= real;
		return *this;
	}
	
	inline float& Quaternion::operator[](const int32_t index)
	{
		return t[index];
	}

	inline float Quaternion::At(const int32_t index) const
	{
		return t[index];
	}

	Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
	{
		return Quaternion(lhs) *= rhs;
	}

	Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs)
	{
		return Quaternion(lhs) += rhs;
	}

	Quaternion operator*(const Quaternion& lhs, const float rhs)
	{
		return Quaternion(lhs) *= rhs;
	}

}