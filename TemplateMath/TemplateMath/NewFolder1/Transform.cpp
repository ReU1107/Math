#include "Transform.h"

namespace Alpha
{
	Transform::Transform()
		: m_location()
		, m_rotation(Quaternion::Identity())
		, m_scale(Vector3::One())
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::SetLocation(const Vector3& location)
	{
		m_location = location;
	}

	void Transform::SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}

	void Transform::SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}

	Vector3 Transform::GetLocation() const
	{
		return m_location;
	}

	Quaternion Transform::GetRotation() const
	{
		return m_rotation;
	}

	Vector3 Transform::GetScale() const
	{
		return m_scale;
	}
}