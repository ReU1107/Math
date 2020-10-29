#include "AABB.h"
#include "Math.h"

namespace Engine
{
	bool AABB::Contains(const Vector3& point) const
	{
		if (min.At(0) < point.At(0) || max.At(0) > point.At(0))
			return false;
		if (min.At(1) < point.At(1) || max.At(1) > point.At(1))
			return false;
		if (min.At(2) < point.At(2) || max.At(2) > point.At(2))
			return false;

		return true;
	}

	float AABB::MinDistance(const Vector3& point) const
	{
		/*
		—á:x‚Ì‚Ý
		point.x = 0.0f;
		min.x = 1.0f;
		max.x > min.x;
		(1.0f - 0.0f) > 0.0f;
		1.0f > 0.0f - 1.0f
		*/

		float dx = Math::Max(min.At(0) - point.At(0), 0.0f);
		dx = Math::Max(dx, point.At(0) - max.At(0));

		float dy = Math::Max(min.At(1) - point.At(1), 0.0f);
		dy = Math::Max(dy, point.At(1) - max.At(1));

		float dz = Math::Max(min.At(2) - point.At(2), 0.0f);
		dz = Math::Max(dz, point.At(2) - max.At(2));

		return 0.0f;
	}
}