//
// Created by GuillaumeIsCoding on 7/26/2024.
//
#include "windows_window.h"

namespace Lypo
{
        WindowsWindow::WindowsWindow(const std::string& title, const uint32_t& width, const uint32_t& height, const WindowFlags& flag) noexcept : WindowsWindow(WindowProperties(title, width, height, flag)) {}
        
        WindowsWindow::WindowsWindow(const WindowProperties& properties) noexcept
        {
            initialize(properties);
        }

        WindowsWindow::~WindowsWindow() noexcept
        {
            shutdown();
        }

        void WindowsWindow::initialize(const WindowProperties& properties) noexcept
        {
            data_.title = properties.title;
            data_.width = properties.width;
            data_.height = properties.height;

            int result = glfwInit();

            switch (properties.flag)
            {
                    case WindowFlags::FULLSCREEN:
                        monitor_ = glfwGetPrimaryMonitor();
                    case WindowFlags::DEFAULT:
                        window_ = glfwCreateWindow(data_.width, data_.height, data_.title.c_str(), monitor_, NULL);
                        break;
                    case WindowFlags::WINDOWED_FULLSCREEN:
                        window_ = glfwCreateWindow(data_.width, data_.height, data_.title.c_str(),monitor_, NULL);
                        monitor_ = glfwGetPrimaryMonitor();
                        mode_ = glfwGetVideoMode(monitor_);
                        glfwSetWindowMonitor(window_, monitor_, 0, 0, mode_->width, mode_->height, mode_->refreshRate);
                        break;
            }

            if (!window_)
            {
                std::cout << "Error while initializing the window" << std::endl;
                return;
            }

            glfwMakeContextCurrent(window_);

            if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
            {
                std::cout << "Error in glad load" << std::endl;
                return;
            }

            glfwSetWindowUserPointer(window_, &data_);
            setVSync(true);
        }

        void WindowsWindow::shutdown() noexcept
        { 
            glfwDestroyWindow(window_);
            glfwTerminate();
        }

        void WindowsWindow::onUpdate()
        {
            /* Swap front and back buffers */
            glfwSwapBuffers(window_);

            glfwPollEvents();
        }

        void WindowsWindow::setVSync(bool enabled)
        {
            glfwSwapInterval(enabled ? 1 : 0);
            data_.vSync = enabled;
        }

        bool WindowsWindow::isVSync() const 
        {
            return data_.vSync;
        }

        uint32_t WindowsWindow::getWidth() const 
        {
            return data_.width;
        }

        uint32_t WindowsWindow::getHeight() const 
        {
            return data_.height;
        }

        void* WindowsWindow::getNativeWindow() const
        {
            return window_;
        }
}