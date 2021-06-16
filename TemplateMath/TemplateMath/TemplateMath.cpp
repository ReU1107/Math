// TemplateMath.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
//#include "NewFolder1/Vector.h"
//#include "NewFolder1/Matrix.h"
//#include "NewFolder1/Math.h"
#pragma warning(disable:4002)

// 静的なポリモーフィズム(仮想関数を呼びだすもの)
// 欠点テンプレート引数の型が違うと配列で持てない
// 違う型同士を配列で使用しないものならこちらを使用する(そんな場面あるかな？)
//template<class T>
//class Print
//{
//public:
//    void Show()
//    {
//        static_cast<T*>(this)->Implementation();
//    }
//};
//
//class PrintD : public Print<PrintD>
//{
//public:
//    void Implementation()
//    {
//        std::cout << "PrintDです";
//    }
//
//};
//#include "NewFolder1/AnimationCurve.h"
//#include "NewFolder1/AnimationClip.h"

//using namespace Alpha;


#include <DirectXMath.h>

#pragma once
#include <cstdint>
#include <cassert>
//#include <omp.h>
#include "NewFolder1/Vector.h"
#include "NewFolder1/MathLibrary.h"
using namespace std;
using namespace DirectX;


void Ass(int32_t& count)
{
    cout << "終了" << endl;
}

template<class Head, class... Tail>
void Ass(int32_t& count, Head head, Tail... tail)
{
    cout << count++;
    cout << (&head)[0] << endl;
    Ass(count,tail...);
}

using namespace Alpha;

// ベクトルの長さ取得(Sqrtなし)
template<class Type, int32_t N>
inline Type VectorLengthSq(const TVector<Type, N>& vec)
{
    Type value = 0.0f;
    for (uint32_t i = 0; i < N; i++)
    {
        value += vec.At(i) * vec.At(i);
    }

    return value;
}

int main()
{
    //int32_t count = 0;
    //Ass(count, 1.0f, 2.0f, 3.0f);


 /*   AnimationCurveTransform* curve = new AnimationCurveTransform();

    KeyframeT key;

    curve->AddKeyframe(key);*/

    //AnimationClip* clip = new AnimationClip();
    //clip->AddAnimationCurve(curve);

    /*
    目的:hlslのように簡単に掛けるようにする
    Vector4(Vector3,float)
    mul(Vector4,Matrix)
    等
    */

    float3 a = float3(0.0f, 1.0f, 2.0f);

    float4 bbb = float4(a, float1(2.0f));

    Matrix4x4 mat = Matrix4x4(
        Vector4(0.0f, 2.0f, 3.0f),
        Vector4(1.0f, 2.0f, 3.0f, 4.0f),
        Vector4(2.0f, 2.0f, 3.0f, 4.0f),
        Vector4(3.0f, 2.0f, 3.0f, 4.0f)
    );

	int i = 0;

    XMVECTOR v2 = XMVectorSet(0.0f, 1.0f, 2.0f, 0.0f);

    v2 = XMVector3LengthSq(v2);

    cout << XMVectorGetX(v2);

    float3 aa = float3::Zero();

    Quaternion q = Quaternion::Identity();

    float3x3 ma = float3x3(

    );

    aa = float3::One();

    aa.X() = 2.0f;

    float3 ab = aa* a;

    float3 ac = aa * 2.0f;

    float3 ad = 2.0f * aa;

    MathLibrary::Vector3Transform(aa, ma);

    MathLibrary::VectorNormalize(aa);

    MathLibrary::VectorMax(aa, 0.0f);

    //float de[3] = {};

    ////Vector3 abc(de);

    Vector3 vec(1.0f, 2.0f, 3.0f);

    Vector3 vec3 = 1.0f - vec;

    Vector4 vec4(vec3, Vector1(1.0f));

    Vector4 vec5(float1(1.0f), float2(3.9f, 2.0f), float1(4.0f));

    int bbbbi = 0;
    Vector4 vec41(vec4.XYZ(), vec3.X());

    //Matrix4x4 abc = Matrix4x4::Identity;

    float4x4 vv = MathLibrary::VectorMultiply(vec4, mat);

    auto vb = MathLibrary::Vector3TransformDir(vec, mat);

    MathLibrary::Matrix4x4LookAtLH((10.f, 10.f, 10.f), (0.0f, 0.f, 0.f));

    float f = vec3.X().At(0);

    //auto vc = Vector3Transform(vec, mat);

    //float3 vd = Mul(Vector4(vec, Vector1(1.0f)), mat);

    //Matrix4x4Translation(vec3);

    //vec.XY() = Vector2(0.0f, 2.0f);

    //vec.XY() = 1.0f;

    //Matrix4x4 a = Matrix4x4::Identity;
    //a.v[0][0] = 1;
    //a.v[0][1] = 1;
    //a.v[0][2] = 1;
    //a.v[0][3] = 1;

    //a.v[1][0] = 2;
    //a.v[1][1] = 2;
    //a.v[1][2] = 2;
    //a.v[1][3] = 2;

    //a.v[2][0] = 3;
    //a.v[2][1] = 3;
    //a.v[2][2] = 3;
    //a.v[2][3] = 3;

    //a.v[3][0] = 4;
    //a.v[3][1] = 4;
    //a.v[3][2] = 4;
    //a.v[3][3] = 4;

    //Matrix4x4 b;
    //b.v[0][0] = 1;
    //b.v[0][1] = 2;
    //b.v[0][2] = 3;
    //b.v[0][3] = 4;
    //
    //b.v[1][0] = 1;
    //b.v[1][1] = 2;
    //b.v[1][2] = 3;
    //b.v[1][3] = 4;
    //
    //b.v[2][0] = 1;
    //b.v[2][1] = 2;
    //b.v[2][2] = 3;
    //b.v[2][3] = 4;
    //
    //b.v[3][0] = 1;
    //b.v[3][1] = 2;
    //b.v[3][2] = 3;
    //b.v[3][3] = 4;

    //auto c = a * b;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
