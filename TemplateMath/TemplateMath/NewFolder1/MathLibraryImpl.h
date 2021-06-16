#pragma once
#include "MathLibrary.h"

namespace Alpha
{
	template<class Type, int32_t N>
	Type MathLibrary::VectorLengthSq(const TVector<Type, N>& vec)
	{
		Type value = 0.0f;
		for (uint32_t i = 0; i < N; i++)
		{
			value += vec.At(i) * vec.At(i);
		}

		return value;
	}

	template<class Type, int32_t N>
	Type MathLibrary::VectorLength(const TVector<Type, N>& vec)
	{
		return MathUtility::Sqrt(VectorLengthSq(vec));
	}

	template<class Type, int32_t N>
	Type MathLibrary::VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		float value = 0.0f;
		for (uint32_t i = 0; i < N; i++)
		{
			value += lhs.At(i) * rhs.At(i);
		}
		return value;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorNormalize(const TVector<Type, N>& vec)
	{
		return vec / MathLibrary::VectorLength(vec);
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir)
	{
		return normal * MathLibrary::VectorDot(normal, -dir) + dir;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir)
	{
		return normal * MathLibrary::VectorDot(normal, -dir) * 2 + dir;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = MathUtility::Clamp(vec.At(i), min, max);
		}

		return v;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorClamp(const TVector<Type, N>& vec, const TVector<Type, N>& min, const TVector<Type, N>& max)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = MathUtility::Clamp(vec.At(i), min.At(i), max.At(i));
		}

		return v;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorMin(const TVector<Type, N>& vec, const Type min)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = MathUtility::Min(vec.At(i), min);
		}

		return v;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorMin(const TVector<Type, N>& vec, const TVector<Type, N>& min)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = MathUtility::Min(vec.At(i), min.At(i));
		}

		return v;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorMax(const TVector<Type, N>& vec, const Type max)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = MathUtility::Max(vec.At(i), max);
		}

		return v;
	}

	template<class Type, int32_t N>
	TVector<Type, N> MathLibrary::VectorMax(const TVector<Type, N>& vec, const TVector<Type, N>& max)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = MathUtility::Max(vec.At(i), max.At(i));
		}

		return v;
	}

	template<class Type, uint32_t R, uint32_t C>
	TMatrix<Type, R, C> MathLibrary::MatrixTranspose(const TMatrix<Type, R, C>& base)
	{
		TMatrix<Type, R, C> m;

		for (uint32_t i = 0; i < R; i++)
		{
			for (uint32_t j = 0; j < C; j++)
			{
				m[i][j] = base.At(j).At(i);
			}
		}

		return m;
	}

	template<class Type, uint32_t Row, uint32_t Column>
	TVector<Type, Column> MathLibrary::VectorMultiply(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat)
	{
		TVector<Type, Column> v = TVector<Type, Column>::Zero();
		for (uint32_t i = 0; i < Column; i++)
		{
			for (uint32_t j = 0; j < Row; j++)
			{
				v[i] += vec.At(j) * mat.At(j).At(i);
			}
		}

		return v;
	}

	//template<class Type, uint32_t Row, uint32_t Column>
	//TVector<Type, Column> Mul(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat)
	//{
	//	TVector<Type, Column> v = TVector<Type, Column>::Zero();
	//	for (uint32_t i = 0; i < Column; i++)
	//	{
	//		for (uint32_t j = 0; j < Row; j++)
	//		{
	//			v[i] += vec.At(j) * mat.At(j).At(i);
	//		}
	//	}

	//	return v;
	//}

}
