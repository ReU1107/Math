#include "Sphere.h"
#include "Math.h"

namespace Engine
{
	Sphere::Sphere()
		: center()
		, radius(0.0f)
	{
	}

	bool Sphere::Contains(const Vector3& point) const
	{
		float distance = VectorLength(center - point);

		return distance <= (radius * radius);
	}
}