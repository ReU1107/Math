#pragma once
#include "Vector.h"

namespace Engine
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
		static const Quaternion Identity;

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

		inline Quaternion operator*(const Quaternion& other)
		{	
			const float w1 = real;
			const float w2 = other.real;
			const float x1 = imaginary.At(0);
			const float x2 = other.imaginary.At(0);
			const float y1 = imaginary.At(1);
			const float y2 = other.imaginary.At(1);
			const float z1 = imaginary.At(2);
			const float z2 = other.imaginary.At(2);

			Quaternion q;
			q.real = (w1 * w2) - (x1 * x2) - (y1 * y2) - (z1 * z2);
			q.imaginary.X() = (w1 * x2) + (w2 * x1) + (y1 * z2) - (y2 * z1);
			q.imaginary.Y() = (w1 * y2) + (w2 * y1) + (z1 * x2) - (z2 * x1);
			q.imaginary.Z() = (w1 * z2) + (w2 * z1) + (x1 * y2) - (x2 * y1);

			return q;
		}

		inline Quaternion operator+(const Quaternion& other) const
		{
			Quaternion q;
			q.real = real + other.real;
			q.imaginary.X() = imaginary.At(0) + other.imaginary.At(0);
			q.imaginary.Y() = imaginary.At(1) + other.imaginary.At(1);
			q.imaginary.Z() = imaginary.At(2) + other.imaginary.At(2);
			return q;
		}

		inline Quaternion operator*(float real) const
		{
			Quaternion q;
			q.real = this->real * real;
			q.imaginary.X() = imaginary.At(0) * real;
			q.imaginary.Y() = imaginary.At(1) * real;
			q.imaginary.Z() = imaginary.At(2) * real;
			return q;
		}

		inline Quaternion& operator+=(const Quaternion& other)
		{
			this->real += other.real;
			this->imaginary += other.imaginary;
			return *this;
		}

		// À””{
		inline Quaternion& operator*=(float real)
		{
			this->real *= real;
			this->imaginary *= real;
			return *this;
		}

		inline Quaternion& operator*=(const Quaternion& other)
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

		inline float& operator[](const int32_t index)
		{
			return t[index];
		}

		inline float At(const int32_t index) const
		{
			return t[index];
		}

		// À”‚Å‚ÌœZ
		inline Quaternion& operator/=(float real)
		{
			this->real /= real;
			this->imaginary /= real;
			return *this;
		}

	};
}