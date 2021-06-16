#pragma once
#include "Matrix.h"

namespace Alpha
{
	template<class Type, uint32_t Row, uint32_t Column>
	inline constexpr TMatrix<Type, Row, Column> TMatrix<Type, Row, Column>::Zero()
	{
		return TMatrix<Type, Row, Column>(0.0f);
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline constexpr TMatrix<Type, Row, Column> TMatrix<Type, Row, Column>::Identity()
	{
		return TMatrix<Type, Row, Column>(1.0f);
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TMatrix<Type, Row, Column>::TMatrix()
		: v()
	{
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TMatrix<Type, Row, Column>::TMatrix(const Type scalar)
		: v()
	{
		for (uint32_t i = 0; i < Row; i++)
		{
			v[i][i] = scalar;
		}
	}

	template<class Type, uint32_t Row, uint32_t Column>
	template<uint32_t R, uint32_t C>
	inline TMatrix<Type, Row, Column>::TMatrix(const TMatrix<Type, R, C>& other)
		: v()
	{
		const int32_t count = (R > Row) ? Row : R;

		for (uint32_t i = 0; i < count; i++)
		{
			v[i] = other.At(i);
		}
	}

	template<class Type, uint32_t Row, uint32_t Column>
	template<uint32_t C>
	inline TMatrix<Type, Row, Column>::TMatrix(const TVector<Type, C>& row0)
		: v()
	{
		static_assert(Row > 0, "");
		v[0] = row0;
	}

	template<class Type, uint32_t Row, uint32_t Column>
	template<uint32_t C>
	inline TMatrix<Type, Row, Column>::TMatrix(const TVector<Type, C>& row0, const TVector<Type, C>& row1)
		: v()
	{
		static_assert(Row > 1, "");
		v[0] = row0;
		v[1] = row1;
	}

	template<class Type, uint32_t Row, uint32_t Column>
	template<uint32_t C>
	inline TMatrix<Type, Row, Column>::TMatrix(const TVector<Type, C>& row0, const TVector<Type, C>& row1, const TVector<Type, C>& row2)
		: v()
	{
		static_assert(Row > 2, "");
		v[0] = row0;
		v[1] = row1;
		v[2] = row2;
	}

	template<class Type, uint32_t Row, uint32_t Column>
	template<uint32_t C>
	inline TMatrix<Type, Row, Column>::TMatrix(const TVector<Type, C>& row0, const TVector<Type, C>& row1, const TVector<Type, C>& row2, const TVector<Type, C>& row3)
		: v()
	{
		static_assert(Row > 3, "");
		v[0] = row0;
		v[1] = row1;
		v[2] = row2;
		v[3] = row3;
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TMatrix<Type, Row, Column>& TMatrix<Type, Row, Column>::operator*=(const TMatrix<Type, Row, Column>& other)
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

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, Column>& TMatrix<Type, Row, Column>::operator[](const uint32_t index)
	{
		return v[index];
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, Column> TMatrix<Type, Row, Column>::At(const uint32_t index) const
	{
		return v[index];
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, Column>& TMatrix<Type, Row, Column>::_1()
	{
		return v[0];
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, Column>& TMatrix<Type, Row, Column>::_2()
	{
		return v[1];
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, Column>& TMatrix<Type, Row, Column>::_3()
	{
		return v[2];
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, Column>& TMatrix<Type, Row, Column>::_4()
	{
		return v[3];
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_11()
	{
		return v[0].X();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_12()
	{
		return v[0].Y();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_13()
	{
		return v[0].Z();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_14()
	{
		return v[0].W();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_21()
	{
		return v[1].X();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_22()
	{
		return v[1].Y();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_23()
	{
		return v[1].Z();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_24()
	{
		return v[1].W();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_31()
	{
		return v[2].X();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_32()
	{
		return v[2].Y();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_33()
	{
		return v[2].Z();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_34()
	{
		return v[2].W();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_41()
	{
		return v[3].X();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_42()
	{
		return v[3].Y();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_43()
	{
		return v[3].Z();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TVector<Type, 1>& TMatrix<Type, Row, Column>::_44()
	{
		return v[3].W();
	}

	template<class Type, uint32_t Row, uint32_t Column>
	inline TMatrix<Type,Row,Column> operator*(const TMatrix<Type, Row, Column>& lhs, const TMatrix<Type, Row, Column>& rhs)
	{
		return TMatrix<Type, Row, Column>(lhs) *= rhs;
	}

}