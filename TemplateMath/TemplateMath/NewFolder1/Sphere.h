#pragma once
#include "Vector.h"

namespace Engine
{

	struct Sphere
	{
		Vector3 center;
		float radius;

		Sphere();

		// �����_�������ɓ����Ă��邩
		bool Contains(const Vector3& point) const;

	};
}