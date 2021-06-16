#pragma once
#include "Vector.h"
#include <cassert>

namespace Alpha
{
	template<class Type, uint32_t N>
	inline constexpr TVector<Type, N> TVector<Type, N>::Zero()
	{
		return TVector<Type, N>();
	}

	template<class Type, uint32_t N>
	inline constexpr TVector<Type, N> TVector<Type, N>::One()
	{
		return TVector<Type, N>(1.0f);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>::TVector()
		: v()
	{
		static_assert(N > 0, "");
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>::TVector(const Type x)
		: v()
	{
		for (uint32_t i = 0; i < N; i++)
		{
			v[i] = x;
		}
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>::TVector(const Type x, const Type y)
		: v()
	{
		static_assert(N >= 2, "");
		v[0] = x;
		v[1] = y;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>::TVector(const Type x, const Type y, const Type z)
		: v()
	{
		static_assert(N >= 3, "");
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>::TVector(const Type x, const Type y, const Type z, const Type w)
		: v()
	{
		static_assert(N >= 4, "");
		v[0] = x;
		v[1] = y;
		v[2] = z;
		v[3] = w;
	}

	template<class Type, uint32_t N>
	template<uint32_t I>
	inline TVector<Type, N>::TVector(const TVector<Type, I>& vec0)
		: v()
	{
		// Vector4 = Vector3
		// Vector3 = Vector4‚à‚Å‚«‚é‚æ‚¤‚É‚·‚é
		const uint32_t count = (I > N) ? N : I;

		for (uint32_t i = 0; i < count; i++)
		{
			v[i] = vec0.At(i);
		}
	}

	template<class Type, uint32_t N>
	template<uint32_t I, uint32_t J>
	inline TVector<Type, N>::TVector(const TVector<Type, I>& vec0, const TVector<Type, J>& vec1)
		: v()
	{
		static_assert(N >= I + J, "");

		uint32_t index = 0;

		for (uint32_t i = 0; i < I; i++)
		{
			v[i] = vec0.At(i);
		}
		index += I;

		for (uint32_t i = 0; i < J; i++)
		{
			v[index + i] = vec1.At(i);
		}
	}

	template<class Type, uint32_t N>
	template<uint32_t I, uint32_t J, uint32_t K>
	inline TVector<Type, N>::TVector(const TVector<Type, I>& vec0, const TVector<Type, J>& vec1, const TVector<Type, K>& vec2)
		: v()
	{
		static_assert(N >= I + J + K, "");

		uint32_t index = 0;

		for (uint32_t i = 0; i < I; i++)
		{
			v[i] = vec0.At(i);
		}
		index += I;

		for (uint32_t i = 0; i < J; i++)
		{
			v[index + i] = vec1.At(i);
		}
		index += J;

		for (uint32_t i = 0; i < K; i++)
		{
			v[index + i] = vec2.At(i);
		}
	}

	template<class Type, uint32_t N>
	template<uint32_t I, uint32_t J, uint32_t K, uint32_t L>
	inline TVector<Type, N>::TVector(const TVector<Type, I>& vec0, const TVector<Type, J>& vec1, const TVector<Type, K>& vec2, const TVector<Type, L>& vec3)
		: v()
	{
		static_assert(N >= I + J + K + L, "");

		uint32_t index = 0;

		for (uint32_t i = 0; i < I; i++)
		{
			v[i] = vec0.At(i);
		}
		index += I;

		for (uint32_t i = 0; i < J; i++)
		{
			v[index + i] = vec1.At(i);
		}
		index += J;

		for (uint32_t i = 0; i < K; i++)
		{
			v[index + i] = vec2.At(i);
		}
		index += K;

		for (uint32_t i = 0; i < L; i++)
		{
			v[index + i] = vec3.At(i);
		}
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1>& TVector<Type, N>::X()
	{
		static_assert(N >= 1, "Count is less than 1(X)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[0]);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1>& TVector<Type, N>::Y()
	{
		static_assert(N >= 2, "Count is less than 2(Y)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[1]);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1>& TVector<Type, N>::Z()
	{
		static_assert(N >= 3, "Count is less than 3(Z)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[2]);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1>& TVector<Type, N>::W()
	{
		static_assert(N >= 4, "Count is less than 4(W)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[3]);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 2>& TVector<Type, N>::XY()
	{
		static_assert(N >= 2, "Count is less than 2(XY)");
		return *reinterpret_cast<TVector<Type, 2>*>(this);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 3>& TVector<Type, N>::XYZ()
	{
		static_assert(N >= 3, "Count is less than 3(XYZ)");
		return *reinterpret_cast<TVector<Type, 3>*>(this);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 4>& TVector<Type, N>::XYZW()
	{
		static_assert(N >= 4, "Count is less than 4(XYZW)");
		return *reinterpret_cast<TVector<Type, 4>*>(this);
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1> TVector<Type, N>::CX() const
	{
		static_assert(N >= 1, "Count is less than 1(X)");
		return v[0];
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1> TVector<Type, N>::CY() const
	{
		static_assert(N >= 2, "Count is less than 1(Y)");
		return v[1];
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1> TVector<Type, N>::CZ() const
	{
		static_assert(N >= 3, "Count is less than 1(Z)");
		return v[2];
	}

	template<class Type, uint32_t N>
	inline TVector<Type, 1> TVector<Type, N>::CW() const
	{
		static_assert(N >= 4, "Count is less than 1(W)");
		return v[3];
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator=(const TVector<Type, N>& other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = other.v[i];
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator+=(const TVector<Type, N>& other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] += other.v[i];
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator-=(const TVector<Type, N>& other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] -= other.v[i];
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator*=(const TVector<Type, N>& other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] *= other.v[i];
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator/=(const TVector<Type, N>& other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] /= other.v[i];
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator=(const Type other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = other;
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator+=(const Type other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] += other;
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator-=(const Type other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] -= other;
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator*=(const Type other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] *= other;
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N>& TVector<Type, N>::operator/=(const Type other)
	{
		for (int32_t i = 0; i < N; i++)
		{
			v[i] /= other;
		}

		return *this;
	}

	template<class Type, uint32_t N>
	inline Type& TVector<Type, N>::operator[](const uint32_t index)
	{
		assert(index < N && "Index is greater than Num");
		return v[index];
	}

	template<class Type, uint32_t N>
	inline Type TVector<Type, N>::At(const uint32_t index) const
	{
		assert(index < N && "Index is greater than Num");
		return v[index];
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type,N>(lhs) += rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) -= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) *= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) /= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) += rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) -= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) *= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) /= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator+(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) += rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator-(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) -= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator*(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) *= rhs;
	}

	template<class Type, uint32_t N>
	inline TVector<Type, N> operator/(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) /= rhs;
	}

}