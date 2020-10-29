#pragma once
#include "Vector.h"
#include "Quaternion.h"

namespace Engine
{
	// Oriented Bounding Box
	struct OBB
	{
		Vector3 center;			// ’†SÀ•W
		Quaternion rotation;	// ‰ñ“]
		Vector3 extents;		// L‚ª‚è
	};
}