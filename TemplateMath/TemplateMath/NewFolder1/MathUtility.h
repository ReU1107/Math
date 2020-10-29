#pragma once
#include <cstdint>

namespace Engine
{
	class Math
	{
	public:
		// ����Ȃ�0�ɋ߂��l
		static constexpr float Epsilon = 0.00001f;
		// ��������
		static constexpr float Infinity = 3.402823466e+38f;
		// ���̖�������
		static constexpr float NegativeInfinity = -Infinity;
		// �~����
		static constexpr float PI = 3.14159265359f;
		// 
		static constexpr float PI2 = PI * 2.0f;
		// 
		static constexpr float PIDiv2 = PI / 2.0f;

		// ���W�A������x
		static constexpr float RadToDeg = 360.0f / (PI * 2);
		// �x���烉�W�A��
		static constexpr float DegToRad = (PI * 2) / 360.0f;

		// �قڃ[�����ۂ�
		static bool NearZero(const float value);

		// �x���烉�W�A���ɕϊ�
		static float ConvertDegreeToRadian(const float degree);

		// ���W�A������x�ɕϊ�
		static float ConvertRadianToDegree(const float radian);

		// �񐔂��ǂ���
		static bool IsNotANumber(const float value);

		// �u�����h�W��
		static float BlendCoefficient(const float current, const  float left, const  float right);

		// ���`���
		static float Lerp(const float lhs, const  float rhs, const  float t);

		// �ݏ�
		static float Pow(const float b, int32_t index);

		// �R�T�C��
		static float Cos(const float angle);
		// �T�C��
		static float Sin(const float angle);
		//�^���W�F���g
		static float Tan(const float angle);

		// �A�[�N�R�T�C��
		static float ACos(const float);
		// �A�[�N�T�C��
		static float ASin(const float);
		// �A�[�N�^���W�F���g
		static float ATan(const float);
		static float ATan2(const float, const float);

		static float Sqrt(const float t);

		// �傫������Ԃ�
		template<class T>
		static T Max(const T lhs, const T rhs);

		// ����������Ԃ�
		template<class T>
		static T Min(const T lhs, const T rhs);

		// �͈͐���
		template<class T>
		static T Clamp(const T source, const T min, const T max);
	};

	template<class T>
	inline T Math::Max(const T lhs, const T rhs)
	{
		return (lhs > rhs) ? lhs : rhs;
	}

	template<class T>
	inline T Math::Min(const T lhs, const T rhs)
	{
		return (lhs < rhs) ? lhs : rhs;
	}

	template<class T>
	inline T Math::Clamp(const T source, const T min, const T max)
	{
		float destination = source;
		if (source > max)
		{
			destination = max;
		}
		else if (source < min)
		{
			destination = min;
		}
		return destination;
	}

	// ��]����
	enum class RotationOrder : uint8_t
	{
		XYZ,	// 
		YZX,	// 
		ZXY,	// 
	};
}