#include "LineSegment.h"
#include "Math.h"

namespace Engine
{
	LineSegment::LineSegment()
		: start()
		, end()
	{
	}

	float LineSegment::MinDistance(const Vector3& point) const
	{
		Vector3 ab = end - start;
		Vector3 ba = ab * -1.0f;
		Vector3 ac = point - start;
		Vector3 bc = point - end;

		// �J�n�ʒu����O���ɂ���
		if (VectorDot(ab, ac) < 0.0f)
		{
			return VectorLength(ac);
		}
		// �I���ʒu��艜���ɂ���
		else if (VectorDot(ba, bc) < 0.0f)
		{
			return VectorLength(bc);
		}
		// �����̓����ɂ���
		else
		{
			float scalar = VectorDot(ac, ab) / VectorDot(ab, ab);

			Vector3 p = ab * scalar;
			// �����̏ꏊ�ɂ���_�Ƃ̋��������߂�
			return VectorLength(ac - p);
		}


		return 0.0f;
	}
}
