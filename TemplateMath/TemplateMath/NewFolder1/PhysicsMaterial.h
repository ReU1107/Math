#pragma once

namespace Engine
{

	class PhysicsMaterial
	{
	private:
		float m_mass;		// ����
		float m_friction;	// ���C�W��

	public:
		// �R���X�g���N�^
		PhysicsMaterial();
		// �f�X�g���N�^
		~PhysicsMaterial();

		// ���ʐݒ�
		void SetMass(const float mass);

		// ���C�W��
		//void SetFriction(const float friction);
	};

}