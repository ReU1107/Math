#pragma once
#include "Vector.h"

namespace Alpha
{
	/*
	x,y,z,w‚Ì‡”Ô‚ÅŠi”[
	*/
	// pure imaginary // ƒ‹•lŒ³”
	// pure reality // ƒÀlŒ³”

	// lŒ³”
	class Quaternion
	{
	private:
		union
		{
			struct
			{
				Vector3 imaginary;	// ‹•”(ƒxƒNƒgƒ‹•\Œ»)
				float real;			// À”
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

		// À””{
		inline Quaternion& operator*=(const float real);

		// À”‚Å‚ÌœZ
		inline Quaternion& operator/=(const float real);

		inline float& operator[](const int32_t index);

		inline float At(const int32_t index) const;

	};

	inline Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);

	inline Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs);

	inline Quaternion operator*(const Quaternion& lhs, const float rhs);
}

#include "QuaternionImpl.h"