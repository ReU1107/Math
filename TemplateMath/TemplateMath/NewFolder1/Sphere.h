#pragma once
#include "Vector.h"

namespace Engine
{

	struct Sphere
	{
		Vector3 center;
		float radius;

		Sphere();

		// ‚ ‚éˆê“_‚ª‹…“à‚É“ü‚Á‚Ä‚¢‚é‚©
		bool Contains(const Vector3& point) const;

	};
}