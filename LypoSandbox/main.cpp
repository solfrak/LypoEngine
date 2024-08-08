#include "lypch.h"

//TODO remove glad include
#include "glad/glad.h"
#include "core/rendering/shader.h"
//TODO remove opengl_shader include
#include "platform/opengl/opengl_shader.h"

#include "core/window/window.h"
#include "core/window/window_factory.h"

#include <core/rendering/VertexArray.hpp>


int main()
{
    std::unique_ptr<Lypo::Window> window = Lypo::WindowFactory::createDefaultWindow("LypoSandbox", 500, 400);

    std::unique_ptr<Lypo::VertexArray> vertex_array(Lypo::VertexArray::create());
    float vertices[3 * 7] = {
        -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
        0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
    };

    std::shared_ptr<Lypo::VertexBuffer> vertex_buffer(Lypo::VertexBuffer::create(vertices, sizeof(vertices)));
    Lypo::BufferLayout layout = {
        {Lypo::ShaderDataType::Float3, "a_Position"},
        {Lypo::ShaderDataType::Float4, "a_Color"},
    };

    vertex_buffer->setLayout(layout);
    vertex_array->addVertexBuffer(vertex_buffer);

    uint32_t indices[3] = { 0, 1, 2 };
    std::shared_ptr<Lypo::IndexBuffer> indexBuffer(Lypo::IndexBuffer::create(indices, sizeof(indices)));
    vertex_array->setIndexBuffer(indexBuffer);


    std::unique_ptr<Lypo::Shader> shader = std::make_unique<Lypo::OpenglShader>("assets/default.vertex.glsl", "assets/default.fragment.glsl");

    while(true)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        shader->bind();
        vertex_array->bind();
        glDrawElements(GL_TRIANGLES, vertex_array->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
        window->onUpdate();
    }
}
