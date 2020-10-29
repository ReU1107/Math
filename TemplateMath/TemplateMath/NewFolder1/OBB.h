#pragma once
#include "Vector.h"
#include "Quaternion.h"

namespace Engine
{
	// Oriented Bounding Box
	struct OBB
	{
		Vector3 center;			// ���S���W
		Quaternion rotation;	// ��]
		Vector3 extents;		// �L����
	};
}