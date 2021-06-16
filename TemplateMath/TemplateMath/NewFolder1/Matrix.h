#pragma once
#include "Vector.h"
#include <initializer_list>
/*

Matrix4x4(0,0,0,0,
          0,0,0,0,
		  0,0,0,0,
		  0,0,0,0);
ができないようになっている

↑のようにやりたいときは
Matrix4x4(Vector4(0,0,0,0),
          Vector4(0,0,0,0),
		  Vector4(0,0,0,0),
		  Vector4(0,0,0,0));
と記述しないといけない。

記述がめんどくさくなるが
見た目としてはわかりやすいと思う。

Matrix4x4(1);
で
(1,0,0,0)
(0,1,0,0)
(0,0,1,0)
(0,0,0,1)
になる、
*/


namespace Alpha
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
		static constexpr TMatrix<Type, Row, Column> Zero();
		static constexpr TMatrix<Type, Row, Column> Identity();

		TMatrix();
		// 対角線上に値を代入
		TMatrix(const Type scalar);

		template<uint32_t R,uint32_t C> 
		TMatrix(const TMatrix<Type, R, C>& other);

		template<uint32_t C = Column>
		TMatrix(const TVector<Type, C>& row0);

		template<uint32_t C = Column>
		TMatrix(const TVector<Type, C>& row0, const TVector<Type, C>& row1);

		template<uint32_t C = Column>
		TMatrix(const TVector<Type, C>& row0, const TVector<Type, C>& row1, const TVector<Type, C>& row2);

		template<uint32_t C = Column>
		TMatrix(const TVector<Type, C>& row0, const TVector<Type, C>& row1, const TVector<Type, C>& row2, const TVector<Type, C>& row3);
		
		inline TMatrix& operator*=(const TMatrix& other);

		inline TVector<Type, Column>& operator[](const uint32_t index);

		inline TVector<Type, Column> At(const uint32_t index) const;

		inline TVector<Type, Column>& _1();
		inline TVector<Type, Column>& _2();
		inline TVector<Type, Column>& _3();
		inline TVector<Type, Column>& _4();

		inline TVector<Type, 1>& _11();
		inline TVector<Type, 1>& _12();
		inline TVector<Type, 1>& _13();
		inline TVector<Type, 1>& _14();
		
		inline TVector<Type, 1>& _21();
		inline TVector<Type, 1>& _22();
		inline TVector<Type, 1>& _23();
		inline TVector<Type, 1>& _24();
		
		inline TVector<Type, 1>& _31();
		inline TVector<Type, 1>& _32();
		inline TVector<Type, 1>& _33();
		inline TVector<Type, 1>& _34();

		inline TVector<Type, 1>& _41();
		inline TVector<Type, 1>& _42();
		inline TVector<Type, 1>& _43();
		inline TVector<Type, 1>& _44();
	};

	template<class Type, uint32_t Row, uint32_t Column>
	static inline TMatrix<Type, Row, Column> operator*(const TMatrix<Type, Row, Column>& lhs, const TMatrix<Type, Row, Column>& rhs);

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

}

#include "MatrixImpl.h"