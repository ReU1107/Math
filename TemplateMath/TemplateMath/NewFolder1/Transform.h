#pragma once
#include "Vector.h"
#include "Quaternion.h"

/*
行列の操作は別にわたす
あくまでデータ構造のようなふるまいをする
*/

namespace Engine
{
	class Transform
	{
	private:
		Vector3 m_location;		// 位置
		Quaternion m_rotation;	// 回転
		Vector3 m_scale;		// 拡大

	public:
		// コンストラクタ
		Transform();
		// デストラクタ
		~Transform();

		// 位置設定
		void SetLocation(const Vector3& location);
		// 回転値設定
		void SetRotation(const Quaternion& rotation);
		// 拡大率設定
		void SetScale(const Vector3& scale);
		// 位置取得
		Vector3 GetLocation() const;
		// 回転値取得
		Quaternion GetRotation() const;
		// 拡大率取得
		Vector3 GetScale() const;

		
	};

}