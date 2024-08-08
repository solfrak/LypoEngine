//
// Created by GuillaumeIsCoding on 7/26/2024.
//
#pragma once

#include "../../core/window/window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstdint>

namespace Lypo
{
        /**
         * @brief Windows concrete class of core::Window
         */
        class WindowsWindow : public Window
        {
        public:
            WindowsWindow(const std::string& title, const uint32_t& width, const uint32_t& height, const WindowFlags& flag = WindowFlags::DEFAULT) noexcept;
            WindowsWindow(const WindowProperties& properties) noexcept;
            virtual ~WindowsWindow() noexcept override;

            void onUpdate() override;

            uint32_t getWidth() const override;
            uint32_t getHeight() const override;

            void setVSync(bool enabled) override;
            bool isVSync() const override; 

            void* getNativeWindow() const;
        private:
            void initialize(const WindowProperties& properties) noexcept;
            void shutdown() noexcept;
        private:
            GLFWwindow* window_ = nullptr;
            GLFWmonitor* monitor_ = nullptr;
            const GLFWvidmode* mode_ = nullptr;
            
            struct WindowsData
            {
                std::string title;
                uint32_t width, height;
                bool vSync;
            };

            WindowsData data_;
        };
}