#pragma once
#include "Vector.h"
#include "Quaternion.h"

/*
�s��̑���͕ʂɂ킽��
�����܂Ńf�[�^�\���̂悤�Ȃӂ�܂�������
*/

namespace Engine
{
	class Transform
	{
	private:
		Vector3 m_location;		// �ʒu
		Quaternion m_rotation;	// ��]
		Vector3 m_scale;		// �g��

	public:
		// �R���X�g���N�^
		Transform();
		// �f�X�g���N�^
		~Transform();

		// �ʒu�ݒ�
		void SetLocation(const Vector3& location);
		// ��]�l�ݒ�
		void SetRotation(const Quaternion& rotation);
		// �g�嗦�ݒ�
		void SetScale(const Vector3& scale);
		// �ʒu�擾
		Vector3 GetLocation() const;
		// ��]�l�擾
		Quaternion GetRotation() const;
		// �g�嗦�擾
		Vector3 GetScale() const;

		
	};

}