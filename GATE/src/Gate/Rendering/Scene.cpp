#include "Scene.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Gate {

    Scene::Scene(std::shared_ptr<RenderingAPI>& renderingApi, Camera* camera) : m_RenderingAPI(renderingApi), m_Camera(camera) {
        
    }

    void Scene::ClearColor(const glm::vec4 &color) {
        m_RenderingAPI->SetClearColor(color);
        m_RenderingAPI->Clear();
    }

    void Scene::Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray) {
        
        glm::mat4 view = m_Camera->GetViewMatrix();
        glm::mat4 projection = m_Camera->GetProjectionMatrix();

        glm::mat4 model(1.0f);
        model = glm::translate(model, {0.0f, 0.0f, -2.0f});
        
        shader->UploadUniformMat4("view", view);
        shader->UploadUniformMat4("projection", projection);
        shader->UploadUniformMat4("model", model);
        
        m_RenderingAPI->Draw(shader, vertexArray);
    }

    void Scene::Render() {
        // TODO: render all commands just here
    }

}
