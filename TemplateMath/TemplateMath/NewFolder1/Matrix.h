#pragma once
#include "Vector.h"

namespace Engine
{
	/*
	Row:行
	Column:列
	*/

	template<class Type, uint32_t Row, uint32_t Column>
	class TMatrix
	{
	public:
		union
		{
			TVector<Type, Column> v[Row];
			Type e[Row * Column];
		};
	public:
		static const TMatrix<Type, Row, Column> Identity;
		static const TMatrix<Type, Row, Column> Zero;

		TMatrix()
			: v()
		{
		}

		// 対角線上に値を代入
		TMatrix(const Type scalar)
			: v()
		{
			for (uint32_t i = 0; i < Row; i++)
			{
				v[i][i] = scalar;
			}
		}
		
		template<class... Args>
		TMatrix(const Args... args)
			: v()
		{
			constexpr auto argsCount = sizeof...(Args);
			static_assert(Row >= argsCount, "Count is less than Args(TMatrx)");

			Assign(G(args)...);
		}

		inline TMatrix operator*(const TMatrix& other) const
		{
			TMatrix mat = TMatrix::Zero;

#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < Row; i++)
			{
				for (int32_t j = 0; j < Column; j++)
				{
					for (int32_t k = 0; k < Row; k++)
					{
						mat[i][j] += v[i].At(j) * other.v[k].At(j);
					}
				}
			}
			return mat;
		}

		inline TMatrix& operator*=(const TMatrix& other)
		{
#ifdef _OPENMP
#pragma omp parallel for
#endif
			for (int32_t i = 0; i < Row; i++)
			{
				for (int32_t j = 0; j < Column; j++)
				{
					for (int32_t k = 0; k < Row; k++)
					{
						v[i][j] *= other.v[k].At(j);
					}
				}
			}
			return *this;
		}

		inline TVector<Type, Column>& operator[](const uint32_t index)
		{
			return v[index];
		}

		inline TVector<Type, Column> At(const uint32_t index) const
		{
			return v[index];
		}

	private:
		// パラメーターパック展開関数
		inline TVector<Type, Column> G(const TVector<Type, Column>& t) { return t; }

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

	template<class Type, uint32_t Row, uint32_t Column>
	const TMatrix<Type, Row, Column> TMatrix<Type, Row, Column>::Identity = TMatrix(1.0f);

	template<class Type, uint32_t Row, uint32_t Column>
	const TMatrix<Type, Row, Column> TMatrix<Type, Row, Column>::Zero = TMatrix(0.0f);

	using Matrix2x2 = TMatrix<float, 2, 2>;
	using Matrix3x3 = TMatrix<float, 3, 3>;
	using Matrix3x4 = TMatrix<float, 3, 4>;
	using Matrix4x3 = TMatrix<float, 4, 3>;
	using Matrix4x4 = TMatrix<float, 4, 4>;

	using matrix2x2 = Matrix2x2;
	using matrix3x3 = Matrix3x3;
	using matrix3x4 = Matrix3x4;
	using matrix4x3 = Matrix4x3;
	using matrix4x4 = Matrix4x4;

	using float2x2 = Matrix2x2;
	using float3x3 = Matrix3x3;
	using float3x4 = Matrix3x4;
	using float4x3 = Matrix4x3;
	using float4x4 = Matrix4x4;

	template<uint32_t Row, uint32_t Column>
	inline Matrix3x3 Cast(const Matrix4x4& mat)
	{
		Matrix3x3 m;
		for (int32_t i = 0; i < Row; i++)
		{
			for (int32_t j = 0; j < Column; j++)
			{
				m[i][j] = mat.At(i).At(j);
			}
		}

		return m;
	}
}