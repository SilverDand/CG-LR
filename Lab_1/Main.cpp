#include "Game.h"
#include "Basic/Shapes/Square.h"
#include "Basic/Shapes/Triangle.h"

int main()
{
    auto* game = Game::Instance();
    //auto* square = new Basic::Shapes::Square(float2(0, 0), float2(0.5f, 0.5f));
    auto* triangle = new Basic::Shapes::Triangle(float2(0, 0.5f), float2(-0.5f, -0.5f), float2(0.5f, -0.5f));
    game->Compose(L"Game");
    //game->GetRenderPipeline()->Add(square);
    game->GetRenderPipeline()->Add(triangle);
    game->Run();
}
