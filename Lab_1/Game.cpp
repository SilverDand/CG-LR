#include "Game.h"

#include <chrono>

#include "Lib/TimeAccumulator.h"
#include "Engine/Input/Keyboard.h"

using namespace Engine;

// Статический метод возврата экземпляра game
Game* Game::Instance()
{
    static auto* instance = new Game();
    return instance;
}

// Инициализация окна, ввода и конвеера. Ставим имя окна
void Game::Compose(const char16* pName) const
{
    constexpr Point size = {800, 800};
    window_->Compose(pName, size);
    inputDevice_->Compose(window_->GetHandlerWindow());
    pipeline_->Compose(window_->GetHandlerWindow(), size);
}


// Основной игровой цикл
void Game::Run()
{
    Lib::TimeAccumulator time; // Запускаем часы

    // Основной цикл обновления часов (кадров) и ренедера
    while (!isFinished_)
    {
        time.Update();
        Input();
        while (time.Accumulated() > 0.1)
        {
            FixedUpdate();
            time.Accumulated(time.Accumulated() - time.Delta());
        }
        Update();
        pipeline_->Render();
    }
}

// Освобожение памяти
void Game::Destroy() const
{
    delete pipeline_;
    delete inputDevice_;
    delete window_;
}

// Проверка на завершение
void Game::Input()
{
    MSG msg;

    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if (msg.message == WM_QUIT) isFinished_ = true;
    if (inputDevice_->IsKeyDown(Input::Keyboard::Keys::Escape)) isFinished_ = true;
}

// Пока пустой апдейт
void Game::FixedUpdate()
{
}

// Пока пустой апдейт 2
void Game::Update()
{
}
