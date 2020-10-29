#include "Plane.h"
#include "Math.h"

namespace Engine
{

	Plane::Plane(const Vector3& a, const Vector3& b, const Vector3& c)
		: normal(Vector3::Zero)
		, distance(0.0f)
	{
		Vector3 ab = b - a;
		Vector3 ac = c - a;
		normal = VectorNormalize(Vector3Cross(ab, ac));

		distance = -VectorDot(a, normal);
	}

	float Plane::SignedDistance(const Vector3& point) const
	{
		return VectorDot(point, normal) - distance;
	}
}
