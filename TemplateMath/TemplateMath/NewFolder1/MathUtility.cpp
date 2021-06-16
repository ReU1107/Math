#include "MathUtility.h"
#include <cmath>

namespace Alpha
{

    bool MathUtility::NearZero(const float value)
    {
        return (fabsf(value) <= Epsilon);
    }

    float MathUtility::ConvertDegreeToRadian(const float degree)
    {
        return degree * PI / 180.0f;
    }

    float MathUtility::ConvertRadianToDegree(const float radian)
    {
        return radian * 180.0f / PI;
    }

    bool MathUtility::IsNotANumber(const float value)
    {
        return (std::isnan<float>(value));
    }

    float MathUtility::BlendCoefficient(const float current, const float left, const float right)
    {
        float blend = 0.0f;

        const float numerator = current - left;
        const float denominator = right - left;
        // 0èúéZñhé~óp
        if (IsNotANumber(denominator))
            return 0.0f;

        blend = numerator / denominator;

        return blend;
    }

    float MathUtility::Lerp(const float lhs, const float rhs, const float t)
    {
        return lhs * (1.0f - t) + rhs * t;
    }

    float MathUtility::Normalize(const float current, const float start, const float end)
    {
        return (current - start) / (end - start);
    }

    float MathUtility::Pow(const float b, int32_t index)
    {
        return std::powf(b, (float)index);
    }

    float MathUtility::BezierCurve(const float s, const float c1, const float c2, const float e, const float t)
    {
        const float d = (1 - t);

        const float b1 = MathUtility::Pow(d, 3) * s;
        const float b2 = 3.0f * MathUtility::Pow(d, 2) * t * c1;
        const float b3 = 3.0f * d * MathUtility::Pow(t, 2) * c2;
        const float b4 = MathUtility::Pow(t, 3) * e;

        return b1 + b2 + b3 + b4;
    }

    float MathUtility::SimpleBezierCurve(const float c1, const float c2, const float t)
    {
        const float d = (1 - t);

        const float b2 = 3.0f * MathUtility::Pow(d, 2) * t * c1;
        const float b3 = 3.0f * d * MathUtility::Pow(t, 2) * c2;
        const float b4 = MathUtility::Pow(t, 3);

        return b2 + b3 + b4;
    }

    float MathUtility::Cos(const float angle)
    {
        return std::cosf(angle);
    }

    float MathUtility::Sin(const float angle)
    {
        return std::sinf(angle);
    }

    float MathUtility::Tan(const float angle)
    {
        return std::tanf(angle);
    }

    float MathUtility::ACos(const float t)
    {
        return std::acosf(t);
    }

    float MathUtility::ASin(const float t)
    {
        return std::asinf(t);
    }

    float MathUtility::ATan(const float t)
    {
        return std::atanf(t);
    }

    float MathUtility::ATan2(const float t, const float t1)
    {
        return std::atan2f(t, t1);
    }

    float MathUtility::Sqrt(const float t)
    {
        return std::sqrtf(t);
    }
}