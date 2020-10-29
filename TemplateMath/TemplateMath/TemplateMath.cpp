// TemplateMath.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "NewFolder1/Vector.h"
#include "NewFolder1/Matrix.h"
#include "NewFolder1/Math.h"
#pragma warning(disable:4002)

// 静的なポリモーフィズム(仮想関数を呼びだすもの)
// 欠点テンプレート引数の型が違うと配列で持てない
// 違う型同士を配列で使用しないものならこちらを使用する(そんな場面あるかな？)
template<class T>
class Print
{
public:
    void Show()
    {
        static_cast<T*>(this)->Implementation();
    }
};

class PrintD : public Print<PrintD>
{
public:
    void Implementation()
    {
        std::cout << "PrintDです";
    }

};
using namespace Engine;

#include <DirectXMath.h>

int main()
{
    /*
    目的:hlslのように簡単に掛けるようにする
    Vector4(Vector3,float)
    mul(Vector4,Matrix)
    等
    */

    Matrix4x4 mat = Matrix4x4(
        Vector4(0.0f, 2.0f, 3.0f, 4.0f),
        Vector4(1.0f, 2.0f, 3.0f, 4.0f),
        Vector4(2.0f, 2.0f, 3.0f, 4.0f),
        Vector4(3.0f, 2.0f, 3.0f, 4.0f)
    );

    Vector2 v = Vector2(0.0f, 1.0f);

    float de[3] = {};

    //Vector3 abc(de);

    Vector3 vec(1.0f, 2.0f, 3.0f);

    Vector3 vec3 = 1.0f - vec;

    Vector4 vec4(vec3, Vector1(1.0f));

    Matrix4x4 abc = Matrix4x4::Identity;

    auto vv = VectorMultiply(vec, Cast<3, 3>(mat));

    Matrix4x4Translation(vec3);

    vec.XY() = Vector2(0.0f, 2.0f);

    vec.XY() = 1.0f;

    Matrix4x4 a = Matrix4x4::Identity;
    a.v[0][0] = 1;
    a.v[0][1] = 1;
    a.v[0][2] = 1;
    a.v[0][3] = 1;

    a.v[1][0] = 2;
    a.v[1][1] = 2;
    a.v[1][2] = 2;
    a.v[1][3] = 2;

    a.v[2][0] = 3;
    a.v[2][1] = 3;
    a.v[2][2] = 3;
    a.v[2][3] = 3;

    a.v[3][0] = 4;
    a.v[3][1] = 4;
    a.v[3][2] = 4;
    a.v[3][3] = 4;

    Matrix4x4 b;
    b.v[0][0] = 1;
    b.v[0][1] = 2;
    b.v[0][2] = 3;
    b.v[0][3] = 4;
    
    b.v[1][0] = 1;
    b.v[1][1] = 2;
    b.v[1][2] = 3;
    b.v[1][3] = 4;
    
    b.v[2][0] = 1;
    b.v[2][1] = 2;
    b.v[2][2] = 3;
    b.v[2][3] = 4;
    
    b.v[3][0] = 1;
    b.v[3][1] = 2;
    b.v[3][2] = 3;
    b.v[3][3] = 4;

    auto c = a * b;
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
