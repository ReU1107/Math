#include "Collision.h"
#include "Capsule.h"
#include "Plane.h"
#include "Ray.h"
#include "Sphere.h"
#include "AABB.h"
#include "LineSegment.h"
#include "Math.h"

namespace Engine
{

	bool Intersect(const AABB& lhs, const AABB& rhs)
	{
		// Å‘å’l‚ª¬‚³‚¢–”‚ÍÅ¬’l‚ª‘å‚«‚¢‚È‚çŒğ·‚µ‚Ä‚È‚¢
		if (lhs.max.At(0) < rhs.min.At(0) || lhs.min.At(0) > rhs.max.At(0))
			return false;

		if (lhs.max.At(2) < rhs.min.At(2) || lhs.min.At(2) > rhs.max.At(2))
			return false;

		if (lhs.max.At(1) < rhs.min.At(1) || lhs.min.At(1) > rhs.max.At(1))
			return false;

		return true;
	}

	bool Intersect(const AABB& aabb, const Sphere& sphere)
	{
		float distance = aabb.MinDistance(sphere.center);

		if (distance > (sphere.radius * sphere.radius))
			return false;

		return true;
	}

	bool Intersect(const AABB& aabb, const LineSegment& segment)
	{
		return false;
	}

	bool Intersect(const LineSegment& segment, const Plane& plane)
	{
		float denominator = VectorDot(segment.end - segment.start, plane.normal);

		if (Math::NearZero(denominator))
		{
			if (Math::NearZero(VectorDot(segment.start, plane.normal) - plane.distance))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		else
		{
			float numerator = -VectorDot(segment.start, plane.normal) - plane.distance;
			float t = numerator / denominator;
			// // [0,1]“à‚È‚ç
			if (t >= 0.0f && t <= 1.0f)
			{
				return true;
			}
			else
			{
				return false;
			}

		}

		return false;
	}

	bool Intersect(const LineSegment& segment, const Sphere& sphere)
	{
		Vector3 vec1 = segment.start - sphere.center;
		Vector3 vec2 = segment.end - segment.start;

		float a = VectorDot(vec2, vec2);
		float b = VectorDot(vec1, vec2) * 2.0f;
		float c = VectorDot(vec1, vec2) - (sphere.radius * sphere.radius);

		float discriminant = b * b - 4.0f * a * c;

		if (discriminant < 0.0f)
		{
			return false;
		}
		else
		{
			discriminant = Math::Sqrt(discriminant);

			float tMin = (-b - discriminant) / (2.0f * a);
			float tMax = (-b + discriminant) / (2.0f * a);
			if (tMin >= 0.0f && tMin <= 1.0f)
			{

				return true;
			}
			else if (tMax >= 0.0f && tMax <= 1.0f)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		return false;
	}

	bool Intersect(const Capsule& lhs, const Capsule& rhs)
	{
		float distance = 0.0f;

		float radius = lhs.radius + rhs.radius;
		if (distance > (radius * radius))
			return false;

		return true;
	}

	bool Intersect(const Capsule& capsule, const Plane& plane)
	{
		return false;
	}

	bool Intersect(const Capsule& capsule, const Ray& ray)
	{
		return false;
	}

	bool Intersect(const Capsule& capsule, const Sphere& sphere)
	{
		return false;
	}

	bool Intersect(const Plane& lhs, const Plane& rhs)
	{
		return false;
	}

	bool Intersect(const Plane& plane, const Ray& ray)
	{
		return false;
	}

	bool Intersect(const Plane& plane, const Sphere& sphere)
	{
		return false;
	}

	bool Intersect(const Ray& lhs, const Ray& rhs)
	{
		return false;
	}

	bool Intersect(const Ray& ray, const Sphere& sphere)
	{
		return false;
	}

	bool Intersect(const Ray& ray, const Vector3& point)
	{
		VectorLength(Vector3Cross(ray.direction, point - ray.start));

		return false;
	}

	bool Intersect(const Sphere& lhs, const Sphere& rhs)
	{
		const Vector3 distance = lhs.center - rhs.center;
		const float range = Math::Pow((lhs.radius + rhs.radius), 2);
		const float length = VectorLength(distance);
		// ‹——£‚ª‹…‚Ì”ÍˆÍ‚æ‚è‰“‚¢‚È‚çÕ“Ë‚µ‚Ä‚¢‚È‚¢
		if (length >= range)
			return false;

		return true;
	}
}