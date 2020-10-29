#pragma once
#include "Vector.h"

namespace Engine
{
	// Axis Aligned Bounding Box
	struct AABB
	{
		Vector3 min;
		Vector3 max;

		// ����邩
		bool Contains(const Vector3& point) const;

		// �ŏ�����
		float MinDistance(const Vector3& point) const;

	};
}