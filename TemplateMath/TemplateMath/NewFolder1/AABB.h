#pragma once
#include "Vector.h"

namespace Engine
{
	// Axis Aligned Bounding Box
	struct AABB
	{
		Vector3 min;
		Vector3 max;

		// ì‡ïÔÇ∑ÇÈÇ©
		bool Contains(const Vector3& point) const;

		// ç≈è¨ãóó£
		float MinDistance(const Vector3& point) const;

	};
}