#pragma once
#include <cstdint>

namespace Engine
{
	class Math
	{
	public:
		// 限りなく0に近い値
		static constexpr float Epsilon = 0.00001f;
		// 無限小数
		static constexpr float Infinity = 3.402823466e+38f;
		// 負の無限小数
		static constexpr float NegativeInfinity = -Infinity;
		// 円周率
		static constexpr float PI = 3.14159265359f;
		// 
		static constexpr float PI2 = PI * 2.0f;
		// 
		static constexpr float PIDiv2 = PI / 2.0f;

		// ラジアンから度
		static constexpr float RadToDeg = 360.0f / (PI * 2);
		// 度からラジアン
		static constexpr float DegToRad = (PI * 2) / 360.0f;

		// ほぼゼロか否か
		static bool NearZero(const float value);

		// 度からラジアンに変換
		static float ConvertDegreeToRadian(const float degree);

		// ラジアンから度に変換
		static float ConvertRadianToDegree(const float radian);

		// 非数かどうか
		static bool IsNotANumber(const float value);

		// ブレンド係数
		static float BlendCoefficient(const float current, const  float left, const  float right);

		// 線形補間
		static float Lerp(const float lhs, const  float rhs, const  float t);

		// 累乗
		static float Pow(const float b, int32_t index);

		// コサイン
		static float Cos(const float angle);
		// サイン
		static float Sin(const float angle);
		//タンジェント
		static float Tan(const float angle);

		// アークコサイン
		static float ACos(const float);
		// アークサイン
		static float ASin(const float);
		// アークタンジェント
		static float ATan(const float);
		static float ATan2(const float, const float);

		static float Sqrt(const float t);

		// 大きい方を返す
		template<class T>
		static T Max(const T lhs, const T rhs);

		// 小さい方を返す
		template<class T>
		static T Min(const T lhs, const T rhs);

		// 範囲制限
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

	// 回転順序
	enum class RotationOrder : uint8_t
	{
		XYZ,	// 
		YZX,	// 
		ZXY,	// 
	};
}