#include "LineSegment.h"
#include "Math.h"

namespace Engine
{
	LineSegment::LineSegment()
		: start()
		, end()
	{
	}

	float LineSegment::MinDistance(const Vector3& point) const
	{
		Vector3 ab = end - start;
		Vector3 ba = ab * -1.0f;
		Vector3 ac = point - start;
		Vector3 bc = point - end;

		// 開始位置より手前側にある
		if (VectorDot(ab, ac) < 0.0f)
		{
			return VectorLength(ac);
		}
		// 終了位置より奥側にある
		else if (VectorDot(ba, bc) < 0.0f)
		{
			return VectorLength(bc);
		}
		// 線分の内部にある
		else
		{
			float scalar = VectorDot(ac, ab) / VectorDot(ab, ab);

			Vector3 p = ab * scalar;
			// 垂直の場所にある点との距離を求める
			return VectorLength(ac - p);
		}


		return 0.0f;
	}
}
