#pragma once

#include "../Components/Rendering.h"

namespace Basic
{
    namespace Shapes
    {
        class Triangle final : public Components::Rendering
        {
        public:
            Triangle(const float2& p1, const float2& p2, const float2& p3);

            void Compose(Engine::Render::Pipeline* pPipeline) override;

        private:
            float4 pointsTriangle_[3 * 2]{};
            int32 indicesTriangle_[3]{};
        };
    }
}
