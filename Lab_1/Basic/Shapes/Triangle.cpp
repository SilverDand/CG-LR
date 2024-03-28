#include "Triangle.h"

#include <d3dcompiler.h>

#pragma comment(lib, "d3dcompiler.lib")

using namespace Basic::Shapes;

Triangle::Triangle(const float2& p1, const float2& p2, const float2& p3) : Rendering()
{
    pointsTriangle_[0] = float4(p1.x, p1.y, 0.5f, 1.0f);
    pointsTriangle_[1] = float4(1.0f, 0.0f, 0.0f, 1.0f);
    pointsTriangle_[2] = float4(p2.x, p2.y, 0.5f, 1.0f);
    pointsTriangle_[3] = float4(0.0f, 1.0f, 0.0f, 1.0f);
    pointsTriangle_[4] = float4(p3.x, p3.y, 0.5f, 1.0f);
    pointsTriangle_[5] = float4(0.0f, 0.0f, 1.0f, 1.0f);
    pPoints_ = pointsTriangle_;

    indicesTriangle_[0] = 0;
    indicesTriangle_[1] = 1;
    indicesTriangle_[2] = 2;
    pIndices_ = indicesTriangle_;

    indicesAmount_ = 3;
}

void Triangle::Compose(Engine::Render::Pipeline* pPipeline)
{
    Rendering::Compose(pPipeline);

    auto* device = pPipeline_->GetDevice();
    constexpr DXShaderMacros pixelShaderMacros[] = {
        "TEST", "1", "TCOLOR", "float4(0.0f, 0.0f, 1.0f, 1.0f)", nullptr, nullptr
    };

    CreateVertexShader(L"./Shaders/Shader.hlsl", nullptr, nullptr);
    CreatePixelShader(L"./Shaders/Shader.hlsl", pixelShaderMacros, nullptr);
    CreateLayout();
    CreateVertexBuffer(3 * 2);
    CreateIndexBuffer(3);
    CreateRasterizerState();

    pPipeline_->GetDeviceContext()->RSSetState(pRasterizerState_);
}
