//
// Created by lapor on 8/8/2024.
//

#include "window_factory.h"

#ifdef LYPO_PLATFORM_WINDOWS
#include "platform/windows/windows_window.h"
std::unique_ptr<Lypo::Window> Lypo::WindowFactory::createDefaultWindow(const std::string& title, int width, int height)
{
    return std::make_unique<WindowsWindow>(title, width, height);
}
#endif

#ifdef LYPO_PLATFORM_LINUX
std::unique_ptr<Lypo::Window> Lypo::WindowFactory::createDefaultWindow(std::string title, int width, int height)
{
    //TODO
}
#endif
