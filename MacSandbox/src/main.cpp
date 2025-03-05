#include "Gate.h"
#include "Utils/MacOSUtils.h"
#include <GLFW/glfw3.h>


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
    
    std::string vertexShaderSource = R"(
        #version 330 core
        
        layout(location = 0) in vec3 a_Position;
        layout(location = 1) in vec4 a_Color;

        uniform mat4 u_ViewProjection;
        uniform mat4 u_Transform;

        out vec3 v_Position;
        out vec4 v_Color;

        void main()
        {
            v_Position = a_Position;
            v_Color = a_Color;
            gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);   
        }
    )";

    std::string fragmentShaderSource = R"(
        #version 330 core
        
        layout(location = 0) out vec4 color;

        in vec3 v_Position;
        in vec4 v_Color;

        void main()
        {
            color = vec4(v_Position * 0.5 + 0.5, 1.0);
            color = v_Color;
        }
    )";
        
    std::shared_ptr<Gate::Shader> shader;
    shader.reset(app->GetRenderer()->CreateShader(vertexShaderSource, fragmentShaderSource));
    shader->Compile();
    
    std::shared_ptr<Gate::VertexArray> vertexArray;
    vertexArray.reset(app->GetRenderer()->CreateVertexArray());
    
    float vertices[3 * 7] = {
        -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
         0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
         0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
    };
    
    
    std::shared_ptr<Gate::VertexBuffer> vertexBuffer;
    vertexBuffer.reset(app->GetRenderer()->CreateVertexBuffer(vertices, sizeof(vertices)));
    Gate::BufferLayout layout = {
                { Gate::ShaderDataType::Float3, "a_Position" },
                { Gate::ShaderDataType::Float4, "a_Color" }
            };
    vertexBuffer->SetLayout(layout);
    vertexArray->AddVertexBuffer(vertexBuffer);
    
    uint32_t indices[3] = { 0, 1, 2 };
    std::shared_ptr<Gate::IndexBuffer> indexBuffer;
    indexBuffer.reset(app->GetRenderer()->CreateIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
    vertexArray->SetIndexBuffer(indexBuffer);
    
    vertexArray->Unbind();
    
    float fov = 45.0f;
    float aspectRatio = 1200.0f / 800.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;
    
    Gate::StandardCamera* standardCamera = new Gate::StandardCamera(fov, aspectRatio, nearPlane, farPlane);
    
    Gate::StandardCameraController cameraController(standardCamera, Gate::DeviceType::DESKTOP_COMPUTER);
    cameraController.Init();
    
    while (isRunning) {
        
        Gate::Timestep timestep = app->CalculateNextTimestep();
        
        Gate::Scene scene = app->GetRenderer()->NewScene(standardCamera);
        scene.ClearColor({1.0f, 0.0f, 0.0f, 1.0f});
        scene.Submit(shader, vertexArray);
        scene.Render();
        
        Gate::CameraControllerAppContext context(app->GetEventManager().get(), timestep);
        cameraController.UpdateOnStep(context);

        app->Step();
    }
    
    delete app;
    
}
