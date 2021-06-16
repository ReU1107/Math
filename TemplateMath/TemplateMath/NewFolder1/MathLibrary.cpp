#include "MathLibrary.h"

namespace Alpha
{
	Vector3 MathLibrary::Vector3Cross(const Vector3& lhs, const Vector3& rhs)
	{
		Vector3 vec = Vector3::Zero();
		vec[0] = rhs.At(1) * lhs.At(2) - rhs.At(2) * lhs.At(1);
		vec[1] = rhs.At(2) * lhs.At(0) - rhs.At(0) * lhs.At(2);
		vec[2] = rhs.At(0) * lhs.At(1) - rhs.At(1) * lhs.At(0);

		return vec;
	}

	Matrix4x4 MathLibrary::Matrix4x4Inverse(const Matrix4x4& mat)
	{
		const float n11 = mat.At(0).At(0), n12 = mat.At(1).At(0), n13 = mat.At(2).At(0), n14 = mat.At(3).At(0);
		const float n21 = mat.At(0).At(1), n22 = mat.At(1).At(1), n23 = mat.At(2).At(1), n24 = mat.At(3).At(1);
		const float n31 = mat.At(0).At(2), n32 = mat.At(1).At(2), n33 = mat.At(2).At(2), n34 = mat.At(3).At(2);
		const float n41 = mat.At(0).At(3), n42 = mat.At(1).At(3), n43 = mat.At(2).At(3), n44 = mat.At(3).At(3);

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

	Vector3 MathLibrary::Vector3Transform(const Vector3& vec, const Matrix4x4& mat)
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

		Vector3 v = Vector3::Zero();
		v.X() = vec.At(0) * _11 + vec.At(1) * _21 + vec.At(2) * _31 + 1.0f * _41;
		v.Y() = vec.At(0) * _12 + vec.At(1) * _22 + vec.At(2) * _32 + 1.0f * _42;
		v.Z() = vec.At(0) * _13 + vec.At(1) * _23 + vec.At(2) * _33 + 1.0f * _43;

		return v;
	}

	Vector3 MathLibrary::Vector3TransformDir(const Vector3& vec, const Matrix4x4& mat)
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

		Vector3 v = Vector3::Zero();
		v.X() = vec.At(0) * _11 + vec.At(1) * _21 + vec.At(2) * _31;
		v.Y() = vec.At(0) * _12 + vec.At(1) * _22 + vec.At(2) * _32;
		v.Z() = vec.At(0) * _13 + vec.At(1) * _23 + vec.At(2) * _33;

		return v;
	}

	Matrix4x4 MathLibrary::Matrix4x4RotationRollPitchYaw(const float roll, const float pitch, const float yaw, const RotationOrder order)
	{
		Matrix4x4 m = Matrix4x4::Identity();

		return m;
	}

	Matrix4x4 MathLibrary::Matrix4x4RotationX(const float angle)
	{
		Matrix4x4 m = Matrix4x4::Identity();
		m[1][1] = MathUtility::Cos(angle);
		m[2][2] = MathUtility::Cos(angle);
		m[1][2] = MathUtility::Sin(angle);
		m[2][1] = -MathUtility::Sin(angle);

		return m;
	}

	Matrix4x4 MathLibrary::Matrix4x4RotationY(const float angle)
	{
		Matrix4x4 m = Matrix4x4::Identity();
		m[0][0] = MathUtility::Cos(angle);
		m[2][2] = MathUtility::Cos(angle);
		m[0][2] = -MathUtility::Sin(angle);
		m[2][0] = MathUtility::Sin(angle);

		return m;
	}

	Matrix4x4 MathLibrary::Matrix4x4RotationZ(const float angle)
	{
		Matrix4x4 m = Matrix4x4::Identity();
		m[0][0] = MathUtility::Cos(angle);
		m[1][1] = MathUtility::Cos(angle);
		m[0][1] = MathUtility::Sin(angle);
		m[1][0] = -MathUtility::Sin(angle);

		return m;
	}

	Matrix4x4 MathLibrary::Matrix4x4Scaling(const Vector3& scale)
	{
		Matrix4x4 scaling = Matrix4x4::Identity();
		scaling[0][0] = scale.At(0);
		scaling[1][1] = scale.At(1);
		scaling[2][2] = scale.At(2);

		return scaling;
	}

	Matrix4x4 MathLibrary::Matrix4x4Rotation(const Quaternion& rotate)
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

		Matrix4x4 rotation = Matrix4x4::Identity();

		return Matrix4x4(
			Vector4(1.0f - y2 - z2, xy + zw, xz - yw),
			Vector4(xy - zw, 1.0f - x2 - z2, xy + xw),
			Vector4(xz + yw, yz - xw, 1.0f - x2 - y2),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		);

		return rotation;
	}

	Matrix4x4 MathLibrary::Matrix4x4Translation(const Vector3& translation)
	{
		Matrix4x4 location = Matrix4x4::Identity();
		location[3] = translation;

		return location;
	}

	Matrix4x4 MathLibrary::Matrix4x4LookAtLH(const Vector3& eye, const Vector3& target, const Vector3& up)
	{
		const Vector3 zAxis = MathLibrary::VectorNormalize(target - eye);

		const Vector3 xAxis = MathLibrary::VectorNormalize(MathLibrary::Vector3Cross(up, zAxis));

		const Vector3 yAxis = MathLibrary::VectorNormalize(MathLibrary::Vector3Cross(zAxis, xAxis));

		Matrix4x4 mat = Matrix4x4::Identity();
		mat._1() = xAxis;
		mat._2() = yAxis;
		mat._3() = zAxis;
		mat._4() = Vector4(eye, Vector1(1.0f));

		return mat;
	}

	Matrix4x4 MathLibrary::Matrix4x4PerspectiveFovLH(const float fov, const float aspect, const float nearZ, const float farZ)
	{
		Matrix4x4 mat = Matrix4x4::Identity();

		const float y = 2 * MathUtility::ATan(fov * 0.5f) / aspect;

		const float x = y / aspect;
		mat._11() = x;
		mat._22() = y;
		mat._33() = farZ / (farZ - nearZ);
		mat._34() = 1.0f;
		mat._43() = -nearZ * farZ / (farZ - nearZ);

		return mat;
	}

	float MathLibrary::QuaternionLengthSq(const Quaternion& q)
	{
		return (q.At(0) * q.At(0)) + (q.At(1) * q.At(1)) + (q.At(2) * q.At(2)) + (q.At(3) * q.At(3));
	}

	float MathLibrary::QuaternionLength(const Quaternion& q)
	{
		return MathUtility::Sqrt(QuaternionLengthSq(q));
	}

	float MathLibrary::QuaternionDot(const Quaternion& lhs, const Quaternion& rhs)
	{
		return lhs.At(0) * rhs.At(0) + lhs.At(1) * rhs.At(1) + lhs.At(2) * rhs.At(2) + lhs.At(3) * rhs.At(3);
	}

	Quaternion MathLibrary::QuaternionNormalize(const Quaternion& q)
	{
		Quaternion quaternion = Quaternion::Identity();
		const auto l = 1 / QuaternionLength(q);
		quaternion[0] = q.At(0) * l;
		quaternion[1] = q.At(1) * l;
		quaternion[2] = q.At(2) * l;
		quaternion[3] = q.At(3) * l;

		return quaternion;
	}

	Quaternion MathLibrary::QuaternionRotationAxis(const Vector3& axis, const float angle)
	{
		const float s = MathUtility::Sin(angle / 2);
		const float c = MathUtility::Cos(angle / 2);

		Quaternion q = Quaternion::Identity();
		q[0] = axis.At(0) * s;
		q[1] = axis.At(1) * s;
		q[2] = axis.At(2) * s;
		q[3] = c;

		return q;
	}

	Quaternion MathLibrary::QuaternionRollPitchYaw(float roll, float pitch, float yaw)
	{
		// それぞれの軸の四元数作成後に合成
		Quaternion rQuaternion = Quaternion::Identity();
		roll /= 2;
		rQuaternion[3] = MathUtility::ACos(roll);
		rQuaternion[2] = MathUtility::Sin(roll);

		Quaternion pQuaternion = Quaternion::Identity();
		pitch /= 2;
		pQuaternion[3] = MathUtility::Cos(pitch);
		pQuaternion[1] = MathUtility::Sin(pitch);

		Quaternion yQuaternion = Quaternion::Identity();
		yaw /= 2;
		yQuaternion[3] = MathUtility::Cos(yaw);
		yQuaternion[0] = MathUtility::Sin(yaw);

		return rQuaternion * pQuaternion * yQuaternion;
	}

	Quaternion MathLibrary::QuaternionConjugate(const Quaternion& q)
	{
		// 虚数部分を反転したもの
		Quaternion conj = Quaternion::Identity();
		conj[3] = q.At(3);
		conj[0] = -q.At(0);
		conj[1] = -q.At(1);
		conj[2] = -q.At(2);

		return conj;
	}

	Quaternion MathLibrary::QuaternionInverse(const Quaternion& q)
	{
		Quaternion inv = MathLibrary::QuaternionConjugate(q);
		const float length = MathLibrary::QuaternionLength(q);

		// 共役を大きさの二乗で割ったもの
		inv /= length;
		return inv;
	}

	Quaternion MathLibrary::QuaternionSlerp(const Quaternion& lhs, const Quaternion& rhs, const float t)
	{
		/*
		引数の四元数が単位四元数として考える
		*/

		const float angle = MathLibrary::QuaternionDot(lhs, rhs);
		const float ac = MathUtility::ACos(angle);
		const float s = MathUtility::Sin(ac);
		const float isa = 1.0f / s;
		Quaternion q = Quaternion::Identity();

		float b = MathUtility::Sin((1 - t) * ac) * isa;
		float c = MathUtility::Sin(t * ac) * isa;

		q = (lhs * b) + (rhs * c);

		return q;
	}

	Vector3 MathLibrary::QuaternionAngle(const Quaternion& quaternion)
	{
		Matrix4x4 matrix = MathLibrary::Matrix4x4Rotation(quaternion);

		float sinX = -matrix[2][1];
		if (sinX > 1 - 1.0e-5f)
		{
			return Vector3(0.0f, 0.0f, 0.0f);
		}
		float angleX = MathUtility::ASin(sinX);
		float cosX = MathUtility::Cos(angleX);

		float sinY = matrix[2][0] / cosX;
		float cosY = matrix[2][2] / cosX;
		float angleY = MathUtility::ATan2(sinY, cosY);

		float sinZ = matrix[0][1] / cosX;
		float cosZ = matrix[1][1] / cosX;
		float angleZ = MathUtility::ATan2(sinZ, cosZ);

		return Vector3(angleX, angleY, angleZ);
	}
}