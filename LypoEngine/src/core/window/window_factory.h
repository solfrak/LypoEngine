//
// Created by lapor on 8/8/2024.
//

#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H
#include "lypch.h"

#include "window.h"

namespace Lypo
{
    class WindowFactory
    {
    public:
        static std::unique_ptr<Window> createDefaultWindow(const std::string& title, int width, int height);
    };
}


#endif //WINDOW_FACTORY_H
