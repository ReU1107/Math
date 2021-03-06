#pragma once
#include "Vector.h"

namespace Alpha
{
	/*
	x,y,z,wの順番で格納
	*/
	// pure imaginary // 純虚四元数
	// pure reality // 純実四元数

	// 四元数
	class Quaternion
	{
	private:
		union
		{
			struct
			{
				Vector3 imaginary;	// 虚数(ベクトル表現)
				float real;			// 実数
			};
			struct
			{
				float x, y, z, w;
			};
			float t[4];
		};
	public:
		static const Quaternion Identity();

		Quaternion()
			: imaginary(0.0f, 0.0f, 0.0f)
			, real(1.0f)
		{
		}

		Quaternion(const Vector3& imaginary, float real)
			: imaginary(imaginary)
			, real(real)
		{
		}

		inline Quaternion& operator=(const Quaternion& other)
		{
			this->real = other.real;
			this->imaginary = other.imaginary;
			return *this;
		}

		inline Quaternion& operator+=(const Quaternion& other);

		inline Quaternion& operator*=(const Quaternion& other);

		// 実数倍
		inline Quaternion& operator*=(const float real);

		// 実数での除算
		inline Quaternion& operator/=(const float real);

		inline float& operator[](const int32_t index);

		inline float At(const int32_t index) const;

	};

	inline Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);

	inline Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs);

	inline Quaternion operator*(const Quaternion& lhs, const float rhs);
}

#include "QuaternionImpl.h"