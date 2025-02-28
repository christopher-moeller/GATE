#pragma once

#include "RenderingAPI.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Scene.h"
#include "Gate/Camera/Camera.h"

#include <memory>

namespace Gate {

    class Renderer {
    public:
        Renderer(RenderingAPI* renderingAPI);
        void Init();
        void OnTargetResize(uint32_t width, uint32_t height);
        
        VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size);
        IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size);
        VertexArray* CreateVertexArray();
        Shader* CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
        
        Scene NewScene(Camera* camera);

    private:
        std::shared_ptr<RenderingAPI> m_RenderingAPI;
    };

}
