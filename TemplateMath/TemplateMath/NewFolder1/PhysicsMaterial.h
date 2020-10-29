#pragma once

namespace Engine
{

	class PhysicsMaterial
	{
	private:
		float m_mass;		// 質量
		float m_friction;	// 摩擦係数

	public:
		// コンストラクタ
		PhysicsMaterial();
		// デストラクタ
		~PhysicsMaterial();

		// 質量設定
		void SetMass(const float mass);

		// 摩擦係数
		//void SetFriction(const float friction);
	};

}