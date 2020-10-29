#pragma once
#include "Vector.h"
#include "Quaternion.h"
#include "Matrix.h"
#include "MathUtility.h"

namespace Engine
{
	// ベクトルの長さ取得(Sqrtなし)
	template<class Type, int32_t N>
	inline Type VectorLengthSq(const TVector<Type, N>& vec)
	{
		Type value = 0.0f;
		for (uint32_t i = 0; i < N; i++)
		{
			value += vec.value[i] * vec.value[i];
		}

		return value;
	}

	// ベクトルの長さ取得(Sqrtあり)
	template<class Type, int32_t N>
	inline Type VectorLength(const TVector<Type, N>& vec)
	{
		Type value = 0.0f;
		for (uint32_t i = 0; i < N; i++)
		{
			value += vec.At(i) * vec.At(i);
		}

		return Math::Sqrt(value);
	}

	// 内積計算
	template<class Type, int32_t N>
	inline Type VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		float value = 0.0f;
		for (uint32_t i = 0; i < N; i++)
		{
			value += lhs.At(i) * rhs.At(i);
		}
		return value;
	}

	// 外積計算
	inline Vector3 Vector3Cross(const Vector3& lhs, const Vector3& rhs)
	{
		Vector3 vec = Vector3::Zero;
		vec[0] = rhs.At(1) * lhs.At(2) - rhs.At(2) * lhs.At(1);
		vec[1] = rhs.At(2) * lhs.At(0) - rhs.At(0) * lhs.At(2);
		vec[2] = rhs.At(0) * lhs.At(1) - rhs.At(1) * lhs.At(0);

		return vec;
	}

	// 正規化
	template<class Type, int32_t N>
	inline TVector<Type, N> VectorNormalize(const TVector<Type, N>& vec)
	{
		return vec / VectorLength(vec);
	}

	// 平行ベクトル
	template<class Type, int32_t N>
	inline TVector<Type, N> VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir)
	{
		return normal * VectorDot(normal, -dir) + dir;
	}

	// 反射ベクトル
	template<class Type, int32_t N>
	inline TVector<Type, N> VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir)
	{
		return normal * VectorDot(normal, -dir) * 2 + dir;
	}

	// ベクトル制限
	template<class Type, int32_t N>
	inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = Clamp(vec.At(i), min, max);
		}

		return v;
	}

	// ベクトル制限
	template<class Type, int32_t N>
	inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const TVector<Type, N>& min, const TVector<Type, N>& max)
	{
		TVector<Type, N> v;
		for (int32_t i = 0; i < N; i++)
		{
			v[i] = Clamp(vec.At(i), min.At(i), max.At(i));
		}

		return v;
	}

	// 逆行列
	inline Matrix4x4 MatrixInverse(const Matrix4x4& m)
	{
		const float n11 = m.At(0).At(0), n12 = m.At(1).At(0), n13 = m.At(2).At(0), n14 = m.At(3).At(0);
		const float n21 = m.At(0).At(1), n22 = m.At(1).At(1), n23 = m.At(2).At(1), n24 = m.At(3).At(1);
		const float n31 = m.At(0).At(2), n32 = m.At(1).At(2), n33 = m.At(2).At(2), n34 = m.At(3).At(2);
		const float n41 = m.At(0).At(3), n42 = m.At(1).At(3), n43 = m.At(2).At(3), n44 = m.At(3).At(3);

		const float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
		const float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
		const float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
		const float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

		const float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;
		const float idet = 1.0f / det;

		Matrix4x4 ret;

		ret[0][0] = t11 * idet;
		ret[0][1] = (n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44) * idet;
		ret[0][2] = (n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44) * idet;
		ret[0][3] = (n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43) * idet;

		ret[1][0] = t12 * idet;
		ret[1][1] = (n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44) * idet;
		ret[1][2] = (n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44) * idet;
		ret[1][3] = (n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43) * idet;

		ret[2][0] = t13 * idet;
		ret[2][1] = (n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44) * idet;
		ret[2][2] = (n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44) * idet;
		ret[2][3] = (n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43) * idet;

		ret[3][0] = t14 * idet;
		ret[3][1] = (n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34) * idet;
		ret[3][2] = (n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34) * idet;
		ret[3][3] = (n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33) * idet;

		return ret;
	}

	// 転置行列
	template<class Type, uint32_t R, uint32_t C>
	inline TMatrix<Type, R, C> MatrixTranspose(const TMatrix<Type, R, C>& base)
	{
		TMatrix<Type, R, C> m;

		for(uint32_t i = 0; i < R; i++)
		{ 
			for (uint32_t j = 0; j < C; j++)
			{
				m[i][j] = base.At(j).At(i);
			}
		}

		return m;
	}

	// Vector*Matrix
	template<class Type,uint32_t R, uint32_t C>
	inline TVector<Type, C> VectorMultiply(const TVector<Type, C>& vec, const TMatrix<Type, C, R>& mat)
	{
		TVector<Type, C> v = TVector<Type, C>::Zero;
		for (int32_t i = 0; i < C; i++)
		{
			for (int32_t j = 0; j < R; j++)
			{
				v[j] += vec.At(j)* mat.At(i).At(j);
			}
		}

		return v;
	}

	// ベクトル*行列(位置用)
	inline Vector3 Vector3Transform(const Vector3& vec, const Matrix4x4& mat)
	{
		const float _11 = mat.At(0).At(0);
		const float _21 = mat.At(1).At(0);
		const float _31 = mat.At(2).At(0);
		const float _41 = mat.At(3).At(0);

		const float _12 = mat.At(0).At(1);
		const float _22 = mat.At(1).At(1);
		const float _32 = mat.At(2).At(1);
		const float _42 = mat.At(3).At(1);

		const float _13 = mat.At(0).At(2);
		const float _23 = mat.At(1).At(2);
		const float _33 = mat.At(2).At(2);
		const float _43 = mat.At(3).At(2);

		Vector3 v = Vector3::Zero;
		v.X() = vec.At(0) * _11 + vec.At(1) * _21 + vec.At(2) * _31 + 1.0f * _41;
		v.Y() = vec.At(0) * _12 + vec.At(1) * _22 + vec.At(2) * _32 + 1.0f * _42;
		v.Z() = vec.At(0) * _13 + vec.At(1) * _23 + vec.At(2) * _33 + 1.0f * _43;

		return v;
	}

	// ベクトル*行列(方向用)
	inline Vector3 Vector3TransformDir(const Vector3& vec, const Matrix4x4& mat)
	{
		const float _11 = mat.At(0).At(0);
		const float _21 = mat.At(1).At(0);
		const float _31 = mat.At(2).At(0);

		const float _12 = mat.At(0).At(1);
		const float _22 = mat.At(1).At(1);
		const float _32 = mat.At(2).At(1);

		const float _13 = mat.At(0).At(2);
		const float _23 = mat.At(1).At(2);
		const float _33 = mat.At(2).At(2);

		Vector3 v = Vector3::Zero;
		v.X() = vec.At(0) * _11 + vec.At(1) * _21 + vec.At(2) * _31;
		v.Y() = vec.At(0) * _12 + vec.At(1) * _22 + vec.At(2) * _32;
		v.Z() = vec.At(0) * _13 + vec.At(1) * _23 + vec.At(2) * _33;

		return v;
	}

	// ロール、ピッチ、ヨー回転
	inline Matrix4x4 Matrix4x4RotationRollPitchYaw(const float roll, const float pitch, const float yaw, const RotationOrder order = RotationOrder::ZXY)
	{
		Matrix4x4 m = Matrix4x4::Identity;

		return m;
	}

	// X軸回転行列
	inline Matrix4x4 Matrix4x4RotationX(const float angle)
	{
		Matrix4x4 m = Matrix4x4::Identity;
		m[1][1] = Math::Cos(angle);
		m[2][2] = Math::Cos(angle);
		m[1][2] = Math::Sin(angle);
		m[2][1] = -Math::Sin(angle);

		return m;
	}

	// Y軸回転行列
	inline Matrix4x4 Matrix4x4RotationY(const float angle)
	{
		Matrix4x4 m = Matrix4x4::Identity;
		m[0][0] = Math::Cos(angle);
		m[2][2] = Math::Cos(angle);
		m[0][2] = -Math::Sin(angle);
		m[2][0] = Math::Sin(angle);

		return m;
	}

	// Z軸回転行列
	inline Matrix4x4 Matrix4x4RotationZ(const float angle)
	{
		Matrix4x4 m = Matrix4x4::Identity;
		m[0][0] = Math::Cos(angle);
		m[1][1] = Math::Cos(angle);
		m[0][1] = Math::Sin(angle);
		m[1][0] = -Math::Sin(angle);

		return m;
	}

	// スケーリング行列
	inline Matrix4x4 Matrix4x4Scaling(const Vector3& scale)
	{
		Matrix4x4 scaling = Matrix4x4::Identity;
		scaling[0][0] = scale.At(0);
		scaling[1][1] = scale.At(1);
		scaling[2][2] = scale.At(2);

		return scaling;
	}

	// 回転行列
	inline Matrix4x4 Matrix4x4Rotation(const Quaternion& rotate)
	{
		const float x = rotate.At(0);
		const float y = rotate.At(1);
		const float z = rotate.At(2);
		const float w = rotate.At(3);

		const float x2 = (x * x) * 2;
		const float y2 = (y * y) * 2;
		const float z2 = (z * z) * 2;
		const float xy = (x * y) * 2;
		const float xz = (x * z) * 2;
		const float xw = (x * w) * 2;
		const float yz = (y * z) * 2;
		const float yw = (y * w) * 2;
		const float zw = (z * w) * 2;

		Matrix4x4 rotation = Matrix4x4::Identity;

		return Matrix4x4(
			Vector4(1.0f - y2 - z2, xy + zw, xz - yw),
			Vector4(xy - zw, 1.0f - x2 - z2, xy + xw),
			Vector4(xz + yw, yz - xw, 1.0f - x2 - y2),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		);

		return rotation;
	}

	inline Matrix4x4 Matrix4x4Translation(const Vector3& translation)
	{
		Matrix4x4 location = Matrix4x4::Identity;
		location[3] = translation;

		return location;
	}

	inline float QuaternionLengthSq(const Quaternion& q)
	{
		return (q.At(0) * q.At(0)) + (q.At(1) * q.At(1)) + (q.At(2) * q.At(2)) + (q.At(3) * q.At(3));
	}

	inline float QuaternionLength(const Quaternion& q)
	{
		return Math::Sqrt(QuaternionLengthSq(q));
	}

	inline float QuaternionDot(const Quaternion& lhs, const Quaternion& rhs)
	{
		return lhs.At(0) * rhs.At(0) + lhs.At(1) * rhs.At(1) + lhs.At(2) * rhs.At(2) + lhs.At(3) * rhs.At(3);
	}

	inline Quaternion QuaternionNormalize(const Quaternion& q)
	{
		Quaternion quaternion;
		const auto l = 1 / QuaternionLength(q);
		quaternion[0] = q.At(0) * l;
		quaternion[1] = q.At(1) * l;
		quaternion[2] = q.At(2) * l;
		quaternion[3] = q.At(3) * l;

		return quaternion;
	}

	// 回転
	inline Quaternion QuaternionRotationAxis(const Vector3& axis, const float angle)
	{
		const float s = Math::Sin(angle / 2);
		const float c = Math::Cos(angle / 2);

		Quaternion q;
		q[0] = axis.At(0) * s;
		q[1] = axis.At(1) * s;
		q[2] = axis.At(2) * s;
		q[3] = c;

		return q;
	}

	// ロールピッチヨー
	inline Quaternion QuaternionRollPitchYaw(float roll, float pitch, float yaw)
	{
		// それぞれの軸の四元数作成後に合成
		Quaternion rQuaternion;
		roll /= 2;
		rQuaternion[3] = Math::ACos(roll);
		rQuaternion[2] = Math::Sin(roll);

		Quaternion pQuaternion;
		pitch /= 2;
		pQuaternion[3] = Math::Cos(pitch);
		pQuaternion[1] = Math::Sin(pitch);

		Quaternion yQuaternion;
		yaw /= 2;
		yQuaternion[3] = Math::Cos(yaw);
		yQuaternion[0] = Math::Sin(yaw);

		return rQuaternion * pQuaternion * yQuaternion;
	}

	// 共役四元数
	inline Quaternion QuaternionConjugate(const Quaternion& q)
	{
		// 虚数部分を反転したもの
		Quaternion conj;
		conj[3] = q.At(3);
		conj[0] = -q.At(0);
		conj[1] = -q.At(1);
		conj[2] = -q.At(2);

		return conj;
	}

	// 逆四元数
	inline Quaternion QuaternionInverse(const Quaternion& q)
	{
		Quaternion inv;
		float length = QuaternionLength(q);

		// 共役を大きさの二乗で割ったもの
		inv = QuaternionConjugate(q);
		inv /= length;
		return inv;
	}

	// 回転値補間
	inline Quaternion QuaternionSlerp(const Quaternion& lhs, const Quaternion& rhs, const float t)
	{
		/*
		引数の四元数が単位四元数として考える
		*/

		const float angle = QuaternionDot(lhs, rhs);
		const float a = Math::ACos(angle);
		const float sa = Math::Sin(a);
		const float isa = 1.0f / sa;
		Quaternion q;

		float b = Math::Sin((1 - t) * a) * isa;
		float c = Math::Sin(t * a) * isa;

		q = (lhs * b) + (rhs * c);

		return q;
	}

	// x,y,zそれぞれの回転値取得
	inline Vector3 QuaternionAngle(const Quaternion& quaternion)
	{
		Matrix4x4 matrix = Matrix4x4Rotation(quaternion);

		float sinX = -matrix[2][1];
		if (sinX > 1 - 1.0e-5f)
		{
			return Vector3(0.0f, 0.0f, 0.0f);
		}
		float angleX = Math::ASin(sinX);
		float cosX = Math::Cos(angleX);

		float sinY = matrix[2][0] / cosX;
		float cosY = matrix[2][2] / cosX;
		float angleY = Math::ATan2(sinY, cosY);

		float sinZ = matrix[0][1] / cosX;
		float cosZ = matrix[1][1] / cosX;
		float angleZ = Math::ATan2(sinZ, cosZ);

		return Vector3(angleX, angleY, angleZ);
	}
}