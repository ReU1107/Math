#pragma once
#include "Vector.h"
#include "Quaternion.h"
#include "Matrix.h"
#include "MathUtility.h"

namespace Alpha
{
	class MathLibrary
	{
	public:
		// ベクトルの長さ取得(Sqrtなし)
		template<class Type, int32_t N>
		static inline Type VectorLengthSq(const TVector<Type, N>& vec);

		// ベクトルの長さ取得(Sqrtあり)
		template<class Type, int32_t N>
		static inline Type VectorLength(const TVector<Type, N>& vec);

		// 内積計算
		template<class Type, int32_t N>
		static inline Type VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);

		// 正規化
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorNormalize(const TVector<Type, N>& vec);

		// 平行ベクトル
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

		// 反射ベクトル
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

		// ベクトル制限
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max);

		// ベクトル制限
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const TVector<Type, N>& min, const TVector<Type, N>& max);

		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorMin(const TVector<Type, N>& vec, const Type min);

		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorMin(const TVector<Type, N>& vec, const TVector<Type, N>& min);

		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorMax(const TVector<Type, N>& vec, const Type max);

		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorMax(const TVector<Type, N>& vec, const TVector<Type, N>& max);

		// 転置行列
		template<class Type, uint32_t R, uint32_t C>
		static inline TMatrix<Type, R, C> MatrixTranspose(const TMatrix<Type, R, C>& base);

		// Vector*Matrix
		template<class Type, uint32_t Row, uint32_t Column>
		static inline TVector<Type, Column> VectorMultiply(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat);

		// 外積計算
		static Vector3 Vector3Cross(const Vector3& lhs, const Vector3& rhs);

		// ベクトル*行列(位置用)
		static Vector3 Vector3Transform(const Vector3& vec, const Matrix4x4& mat);

		// ベクトル*行列(方向用)
		static Vector3 Vector3TransformDir(const Vector3& vec, const Matrix4x4& mat);

		// 逆行列
		static Matrix4x4 Matrix4x4Inverse(const Matrix4x4& mat);

		// ロール、ピッチ、ヨー回転
		static Matrix4x4 Matrix4x4RotationRollPitchYaw(const float roll, const float pitch, const float yaw, const RotationOrder order = RotationOrder::ZXY);

		// X軸回転行列
		static Matrix4x4 Matrix4x4RotationX(const float angle);

		// Y軸回転行列
		static Matrix4x4 Matrix4x4RotationY(const float angle);

		// Z軸回転行列
		static Matrix4x4 Matrix4x4RotationZ(const float angle);

		// スケーリング行列
		static Matrix4x4 Matrix4x4Scaling(const Vector3& scale);

		// 回転行列
		static Matrix4x4 Matrix4x4Rotation(const Quaternion& rotate);

		// 移動行列
		static Matrix4x4 Matrix4x4Translation(const Vector3& translation);

		// 
		static Matrix4x4 Matrix4x4LookAtLH(const Vector3& eye, const Vector3& target, const Vector3& up = Vector3(0.0f, 1.0f, 0.0f));

		// 射影変換行列(左手座標系)
		static Matrix4x4 Matrix4x4PerspectiveFovLH(const float fov, const float aspect, const float nearZ, const float farZ);

		// 四元数
		static float QuaternionLengthSq(const Quaternion& q);

		// 四元数
		static float QuaternionLength(const Quaternion& q);

		// 
		static float QuaternionDot(const Quaternion& lhs, const Quaternion& rhs);

		// 四元数正規化
		static Quaternion QuaternionNormalize(const Quaternion& q);

		// 回転
		static Quaternion QuaternionRotationAxis(const Vector3& axis, const float angle);

		// ロールピッチヨー
		static Quaternion QuaternionRollPitchYaw(float roll, float pitch, float yaw);

		// 共役四元数
		static Quaternion QuaternionConjugate(const Quaternion& q);

		// 逆四元数
		static Quaternion QuaternionInverse(const Quaternion& q);

		// 回転値補間
		static Quaternion QuaternionSlerp(const Quaternion& lhs, const Quaternion& rhs, const float t);

		// x,y,zそれぞれの回転値取得
		static Vector3 QuaternionAngle(const Quaternion& quaternion);
	};

}

#include "MathLibraryImpl.h"