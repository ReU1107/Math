#pragma once
#include "Vector.h"

namespace Engine
{

	struct Sphere
	{
		Vector3 center;
		float radius;

		Sphere();

		// ある一点が球内に入っているか
		bool Contains(const Vector3& point) const;

	};
}