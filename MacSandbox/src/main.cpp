#include "Gate.h"
#include "Utils/MacOSUtils.h"


int main() {
    
    MacOSUtils::EnsureSingleProgramInstance();
    
    Gate::Application::Create();
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    bool isRunning = true;
    
    app->GetEventManager()->AddListener(Gate::EventType::WindowClose, [&isRunning](Gate::Event& event) {
        isRunning = false;
        return false;
    });
    
    std::string vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    std::string fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";
    
    auto renderingAPI = app->GetRenderer()->GetRenderingApi();
    
    std::shared_ptr<Gate::Shader> shader;
    shader.reset(renderingAPI->CreateShader(vertexShaderSource, fragmentShaderSource));
    shader->Compile();
    
    std::shared_ptr<Gate::VertexArray> vertexArray;
    vertexArray.reset(renderingAPI->CreateVertexArray());
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left
         0.5f, -0.5f, 0.0f, // right
         0.0f,  0.5f, 0.0f  // top
    };
    
    
    std::shared_ptr<Gate::VertexBuffer> vertexBuffer;
    vertexBuffer.reset(renderingAPI->CreateVertexBuffer(vertices, sizeof(vertices)));
    Gate::BufferLayout layout = {
                { Gate::ShaderDataType::Float3, "a_Pos" }
            };
    vertexBuffer->SetLayout(layout);
    vertexArray->AddVertexBuffer(vertexBuffer);
    
    uint32_t indices[3] = { 0, 1, 2 };
    std::shared_ptr<Gate::IndexBuffer> indexBuffer;
    indexBuffer.reset(renderingAPI->CreateIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
    vertexArray->SetIndexBuffer(indexBuffer);
    
    vertexArray->Unbind();

    
    while (isRunning) {
        app->Step();
        app->GetRenderer()->Submit(shader, vertexArray);
    }
    
    delete app;
    
}
