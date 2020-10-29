#pragma once
#include <cstdint>
#include <cassert>
#include <omp.h>
#include <initializer_list>

/*
hlslのような書き方ができる
型指定と数指定

At(index)
[index]
使い分け
[]は変更可能
At()は変更できない const指定
*/

/*
テンプレート可変長引数の
パラメーターパックの展開を関数で行う理由:
{}を使用したくないから(std::initializer_listだと{}を指定しないといけないっぽい)
*/
namespace Engine
{

	template<class Type, int32_t N>
	class TVector
	{
	private:
		Type v[N];

	public:
		static const TVector<Type, N> Zero;
		static const TVector<Type, N> One;

		TVector()
			: v()
		{
			static_assert(N > 0, "");
		}

		template<class... Args>
		TVector(Args... args)
			: v()
		{
			constexpr auto argsCount = sizeof...(Args);
			static_assert(N >= argsCount, "Count is less than Args(TVector)");

			Assign(G(args)...);
		}

		template<class T, int32_t I>
		TVector(const TVector<T, I>& vec)
			: v()
		{
			// Vector4 = Vector3
			// Vector3 = Vector4もできるようにする
			const int32_t count = (I > N) ? N : I;
			
			for (int32_t i = 0; i < count; i++)
			{
				v[i] = vec.At(i);
			}
		}

		template<class T, int32_t I>
		TVector(const TVector<T, I>& vec, const TVector<T, N - I>& vec1)
			: v()
		{
			static_assert(N >= I,"Count is less than Args");

			const int32_t count = (I > N) ? N : I;

			for (int32_t i = 0; i < count; i++)
			{
				v[i] = vec.At(i);
			}

			for (int32_t i = 0; i < N - I; i++)
			{
				v[count + i] = vec1.At(i);
			}
		}


		inline TVector<Type, N>& operator=(const Type value)
		{
			for (int32_t i = 0; i < N; i++)
			{
				v[i] = value;
			}
			return *this;
		}

		inline Type& X()
		{
			static_assert(N >= 1, "Count is less than 1(X)");
			return v[0];
		}

		inline Type& Y()
		{
			static_assert(N >= 2, "Count is less than 2(Y)");
			return v[1];
		}

		inline Type& Z()
		{
			static_assert(N >= 3, "Count is less than 3(Z)");
			return v[2];
		}

		inline Type& W()
		{
			static_assert(N >= 4, "Count is less than 4(W)");
			return v[3];
		}

		inline TVector<Type, 2>& XY()
		{
			static_assert(N >= 2, "Count is less than 2(XY)");
			return *reinterpret_cast<TVector<Type, 2>*>(this);
		}

		inline TVector<Type, 3>& XYZ()
		{
			static_assert(N >= 3, "Count is less than 3(XYZ)");
			return *reinterpret_cast<TVector<Type, 3>*>(this);
		}

		inline TVector<Type, 4>& XYZW()
		{
			static_assert(N >= 4, "Count is less than 4(XYZW)");
			return *reinterpret_cast<TVector<Type, 4>*>(this);
		}

		inline TVector<Type, N> operator+(const TVector<Type, N>& other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] + other.v[i];
			}

			return vec;
		}

		inline TVector<Type, N> operator-(const TVector<Type, N>& other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] - other.v[i];
			}

			return vec;
		}

		inline TVector<Type, N> operator*(const TVector<Type, N>& other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] * other.v[i];
			}

			return vec;
		}

		inline TVector<Type, N> operator/(const TVector<Type, N>& other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] / other.v[i];
			}

			return vec;
		}

		inline TVector<Type, N> operator+(const Type other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] + other;
			}

			return vec;
		}

		inline TVector<Type, N> operator-(const Type other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] - other;
			}

			return vec;
		}

		inline TVector<Type, N> operator*(const Type other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] * other;
			}

			return vec;
		}

		inline TVector<Type, N> operator/(const Type other) const
		{
			TVector<Type, N> vec;
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				vec.v[i] = this->v[i] / other;
			}

			return vec;
		}

		inline TVector<Type, N>& operator+=(const TVector<Type, N>& other)
		{
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				this->v[i] += other.v[i];
			}

			return *this;
		}

		inline TVector<Type, N>& operator-=(const TVector<Type, N>& other)
		{
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				this->v[i] -= other.v[i];
			}

			return *this;
		}

		inline TVector<Type, N>& operator*=(const TVector<Type, N>& other)
		{
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				this->v[i] *= other.v[i];
			}

			return *this;
		}

		inline TVector<Type, N>& operator/=(const TVector<Type, N>& other)
		{
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < N; i++)
			{
				this->v[i] /= other.v[i];
			}

			return *this;
		}

		inline Type& operator[](const uint32_t index)
		{
			assert(index < N, "Index is greater than Num");
			return v[index];
		}

		inline Type At(const uint32_t index) const
		{
			assert(index < N, "Index is greater than Num");
			return v[index];
		}

	private:
		// パラメーターパック展開関数
		inline Type G(Type t) { return t; }

		template<class... Args>
		void Assign(Args const&... args)
		{
			int32_t i = 0;
			for (auto const& value : { args... })
			{
				v[i++] = value;
			}
		}
	};

	template<class Type, int32_t N>
	inline TVector<Type, N> operator+(const Type value, const TVector<Type, N>& vec)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = value + vec.At(i);
		}

		return v;
	}

	template<class Type, int32_t N>
	inline TVector<Type, N> operator-(const Type value, const TVector<Type, N>& vec)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = value - vec.At(i);
		}

		return v;
	}

	template<class Type, int32_t N>
	inline TVector<Type, N> operator*(const Type value, const TVector<Type, N>& vec)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = value * vec.At(i);
		}

		return v;
	}

	template<class Type, int32_t N>
	inline TVector<Type, N> operator/(const Type value, const TVector<Type, N>& vec)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = value / vec.At(i);
		}

		return v;
	}

	template<class Type, int32_t N>
	const TVector<Type, N> TVector<Type, N>::Zero = TVector<Type, N>(0.0f);

	template<class Type, int32_t N>
	const TVector<Type, N> TVector<Type, N>::One = TVector<Type, N>(1.0f);

	using Vector1 = TVector<float, 1>;
	using Vector2 = TVector<float, 2>;
	using Vector3 = TVector<float, 3>;
	using Vector4 = TVector<float, 4>;

	using float1 = Vector1;
	using float2 = Vector2;
	using float3 = Vector3;
	using float4 = Vector4;

}