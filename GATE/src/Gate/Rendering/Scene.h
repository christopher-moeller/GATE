#pragma once

#include "RenderingAPI.h"
#include "Gate/Camera/Camera.h"
#include <memory>
#include "Objects/RenderingObject.h"

namespace Gate {

    class Scene {
    public:
        Scene(std::shared_ptr<RenderingAPI>& renderingApi, Camera* camera);
        
        void Submit(RenderingObject& object);
        void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);
        void ClearColor(const glm::vec4& color);
        void Render();
        
    private:
        std::shared_ptr<RenderingAPI>& m_RenderingAPI;
        Camera* m_Camera;
    };

}
