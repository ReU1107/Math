#pragma once
#include "Vector.h"

namespace Engine
{
	// 線分
	struct LineSegment
	{
		Vector3 start;	// 開始位置
		Vector3 end;	// 終了位置

		LineSegment();

		float MinDistance(const Vector3& point) const;

	};

}
