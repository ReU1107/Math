#pragma once
#include <cstdint>

/*
hlslのような書き方ができる
型指定と数指定

At(index)
[index]
使い分け
[]は変更可能
At()は変更できない const指定
*/
namespace Alpha
{

	template<class Type, uint32_t N>
	class TVector
	{
	private:
		Type v[N];

	public:
		static constexpr TVector<Type, N> Zero();
		static constexpr TVector<Type, N> One();

		TVector();
		TVector(const Type x);
		TVector(const Type x, const Type y);
		TVector(const Type x, const Type y, const Type z);
		TVector(const Type x, const Type y, const Type z, const Type w);

		template<uint32_t I>
		TVector(const TVector<Type, I>& vec0);

		template<uint32_t I, uint32_t J>
		TVector(const TVector<Type, I>& vec0, const TVector<Type, J>& vec1);

		template<uint32_t I, uint32_t J, uint32_t K>
		TVector(const TVector<Type, I>& vec0, const TVector<Type, J>& vec1, const TVector<Type, K>& vec2);

		template<uint32_t I, uint32_t J, uint32_t K, uint32_t L>
		TVector(const TVector<Type, I>& vec0, const TVector<Type, J>& vec1, const TVector<Type, K>& vec2, const TVector<Type, L>& vec3);

		inline TVector<Type, 1>& X();
		inline TVector<Type, 1>& Y();
		inline TVector<Type, 1>& Z();
		inline TVector<Type, 1>& W();

		inline TVector<Type, 2>& XY();
		inline TVector<Type, 3>& XYZ();
		inline TVector<Type, 4>& XYZW();

		inline TVector<Type, 1> CX() const;
		inline TVector<Type, 1> CY() const;
		inline TVector<Type, 1> CZ() const;
		inline TVector<Type, 1> CW() const;

		inline TVector<Type, N>& operator=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator+=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator-=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator*=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator/=(const TVector<Type, N>& other);

		inline TVector<Type, N>& operator=(const Type other);
		inline TVector<Type, N>& operator+=(const Type other);
		inline TVector<Type, N>& operator-=(const Type other);
		inline TVector<Type, N>& operator*=(const Type other);
		inline TVector<Type, N>& operator/=(const Type other);

		inline Type& operator[](const uint32_t index);

		inline Type At(const uint32_t index) const;

	};

	// 
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);

	// 
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const Type rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const Type rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const Type rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const Type rhs);

	// 
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator+(const Type lhs, const TVector<Type, N>& rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator-(const Type lhs, const TVector<Type, N>& rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator*(const Type lhs, const TVector<Type, N>& rhs);
	template<class Type, uint32_t N>
	static inline TVector<Type, N> operator/(const Type lhs, const TVector<Type, N>& rhs);

	using Vector1 = TVector<float, 1>;
	using Vector2 = TVector<float, 2>;
	using Vector3 = TVector<float, 3>;
	using Vector4 = TVector<float, 4>;

	using float1 = Vector1;
	using float2 = Vector2;
	using float3 = Vector3;
	using float4 = Vector4;
}

#include "VectorImpl.h"