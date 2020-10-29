#include "MathUtility.h"
#include <cmath>

namespace Engine
{

    bool Math::NearZero(const float value)
    {
        return (fabsf(value) <= Epsilon);
    }

    float Math::ConvertDegreeToRadian(const float degree)
    {
        return degree * PI / 180.0f;
    }

    float Math::ConvertRadianToDegree(const float radian)
    {
        return radian * 180.0f / PI;
    }

    bool Math::IsNotANumber(const float value)
    {
        return (std::isnan<float>(value));
    }

    float Math::BlendCoefficient(const float current, const float left, const float right)
    {
        float blend = 0.0f;

        const float numerator = current - left;
        const float denominator = right - left;
        // 0œZ–h~—p
        if (IsNotANumber(denominator))
            return 0.0f;

        blend = numerator / denominator;

        return blend;
    }

    float Math::Lerp(const float lhs, const float rhs, const float t)
    {
        return lhs * (1.0f - t) + rhs * t;
    }

    float Math::Pow(const float b, int32_t index)
    {
        return std::powf(b, (float)index);
    }

    float Math::Cos(const float angle)
    {
        return std::cosf(angle);
    }

    float Math::Sin(const float angle)
    {
        return std::sinf(angle);
    }

    float Math::Tan(const float angle)
    {
        return std::tanf(angle);
    }

    float Math::ACos(const float t)
    {
        return std::acosf(t);
    }

    float Math::ASin(const float t)
    {
        return std::asinf(t);
    }

    float Math::ATan(const float t)
    {
        return std::atanf(t);
    }

    float Math::ATan2(const float t, const float t1)
    {
        return std::atan2f(t, t1);
    }

    float Math::Sqrt(const float t)
    {
        return std::sqrtf(t);
    }
}