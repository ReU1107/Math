#pragma once
#include "Vector.h"

namespace Engine
{
	struct Ray
	{
		Vector3 start;		// 開始位置
		Vector3 direction;	// 方向

		Ray();

	};
}