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
		// �x�N�g���̒����擾(Sqrt�Ȃ�)
		template<class Type, int32_t N>
		static inline Type VectorLengthSq(const TVector<Type, N>& vec);

		// �x�N�g���̒����擾(Sqrt����)
		template<class Type, int32_t N>
		static inline Type VectorLength(const TVector<Type, N>& vec);

		// ���όv�Z
		template<class Type, int32_t N>
		static inline Type VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);

		// ���K��
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorNormalize(const TVector<Type, N>& vec);

		// ���s�x�N�g��
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

		// ���˃x�N�g��
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

		// �x�N�g������
		template<class Type, int32_t N>
		static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max);

		// �x�N�g������
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

		// �]�u�s��
		template<class Type, uint32_t R, uint32_t C>
		static inline TMatrix<Type, R, C> MatrixTranspose(const TMatrix<Type, R, C>& base);

		// Vector*Matrix
		template<class Type, uint32_t Row, uint32_t Column>
		static inline TVector<Type, Column> VectorMultiply(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat);

		// �O�όv�Z
		static Vector3 Vector3Cross(const Vector3& lhs, const Vector3& rhs);

		// �x�N�g��*�s��(�ʒu�p)
		static Vector3 Vector3Transform(const Vector3& vec, const Matrix4x4& mat);

		// �x�N�g��*�s��(�����p)
		static Vector3 Vector3TransformDir(const Vector3& vec, const Matrix4x4& mat);

		// �t�s��
		static Matrix4x4 Matrix4x4Inverse(const Matrix4x4& mat);

		// ���[���A�s�b�`�A���[��]
		static Matrix4x4 Matrix4x4RotationRollPitchYaw(const float roll, const float pitch, const float yaw, const RotationOrder order = RotationOrder::ZXY);

		// X����]�s��
		static Matrix4x4 Matrix4x4RotationX(const float angle);

		// Y����]�s��
		static Matrix4x4 Matrix4x4RotationY(const float angle);

		// Z����]�s��
		static Matrix4x4 Matrix4x4RotationZ(const float angle);

		// �X�P�[�����O�s��
		static Matrix4x4 Matrix4x4Scaling(const Vector3& scale);

		// ��]�s��
		static Matrix4x4 Matrix4x4Rotation(const Quaternion& rotate);

		// �ړ��s��
		static Matrix4x4 Matrix4x4Translation(const Vector3& translation);

		// 
		static Matrix4x4 Matrix4x4LookAtLH(const Vector3& eye, const Vector3& target, const Vector3& up = Vector3(0.0f, 1.0f, 0.0f));

		// �ˉe�ϊ��s��(������W�n)
		static Matrix4x4 Matrix4x4PerspectiveFovLH(const float fov, const float aspect, const float nearZ, const float farZ);

		// �l����
		static float QuaternionLengthSq(const Quaternion& q);

		// �l����
		static float QuaternionLength(const Quaternion& q);

		// 
		static float QuaternionDot(const Quaternion& lhs, const Quaternion& rhs);

		// �l�������K��
		static Quaternion QuaternionNormalize(const Quaternion& q);

		// ��]
		static Quaternion QuaternionRotationAxis(const Vector3& axis, const float angle);

		// ���[���s�b�`���[
		static Quaternion QuaternionRollPitchYaw(float roll, float pitch, float yaw);

		// �����l����
		static Quaternion QuaternionConjugate(const Quaternion& q);

		// �t�l����
		static Quaternion QuaternionInverse(const Quaternion& q);

		// ��]�l���
		static Quaternion QuaternionSlerp(const Quaternion& lhs, const Quaternion& rhs, const float t);

		// x,y,z���ꂼ��̉�]�l�擾
		static Vector3 QuaternionAngle(const Quaternion& quaternion);
	};

}

#include "MathLibraryImpl.h"