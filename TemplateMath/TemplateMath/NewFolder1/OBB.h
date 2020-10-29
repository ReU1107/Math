#pragma once
#include "Vector.h"
#include "Quaternion.h"

namespace Engine
{
	// Oriented Bounding Box
	struct OBB
	{
		Vector3 center;			// 中心座標
		Quaternion rotation;	// 回転
		Vector3 extents;		// 広がり
	};
}