#pragma once

#include "Engine/Render/Pipeline.h"
#include "Engine/Input/PC.h"
#include "Engine/Render/Window.h"

// Основной контроллер приложения
class Game final
{
public:
    Game()
            : window_(new Engine::Render::Window()),    // Указатель на объект окна, отвечающий за отображение графики
            pipeline_(new Engine::Render::Pipeline()),  // Указатель на объект конвейера рендеринга, управляющий процессом рисования
            inputDevice_(new Engine::Input::PC()),      // Указатель на устройство ввода, отвечающее за обработку пользовательского ввода
            isFinished_(false)                          // Флаг, указывающий, завершена ли работа приложения.
    {}

    static Game* Instance(); // Возвращает указатель на единственный экземпляр класса

    void Compose(const char16* pName) const;    // Создание окна с указанным именем
    void Run();                                 // Запуск игрового цикла
    void Destroy() const;                       // Освобождение памяти при закрытии

    // Геттеры
    Engine::Render::Window* GetWindow() const { return window_; }
    Engine::Render::Pipeline* GetRenderPipeline() const { return pipeline_; }
    Engine::Input::Device* GetInputDevice() const { return inputDevice_; }

private:
    void Input();           
    void FixedUpdate();     // Пустой метод
    void Update();          // Пустой метод

    Engine::Render::Window* window_;
    Engine::Render::Pipeline* pipeline_;
    Engine::Input::Device* inputDevice_;

    bool isFinished_;
};
