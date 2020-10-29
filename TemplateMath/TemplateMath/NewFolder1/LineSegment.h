#pragma once
#include "Vector.h"

namespace Engine
{
	// ����
	struct LineSegment
	{
		Vector3 start;	// �J�n�ʒu
		Vector3 end;	// �I���ʒu

		LineSegment();

		float MinDistance(const Vector3& point) const;

	};

}
