#pragma once
#include "Gate/Rendering/Shader.h"
#include "OpenGLContext.h"

namespace Gate {

    class OpenGLShader : public Shader {
        
    public:
        OpenGLShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) : Shader(vertexShaderSource, fragmentShaderSource) {}
        
        ~OpenGLShader();
        
        void Compile() override;
        
        void Destroy() override;
        void Use() override;
        
        inline bool IsCompiled() override { return m_ProgramId; }
        
        void UploadUniformInt(const std::string& name, int value) override;
        
        void UploadUniformFloat(const std::string& name, float value) override;
        void UploadUniformFloat2(const std::string& name, const glm::vec2& value) override;
        void UploadUniformFloat3(const std::string& name, const glm::vec3& value) override;
        void UploadUniformFloat4(const std::string& name, const glm::vec4& value) override;

        void UploadUniformMat3(const std::string& name, const glm::mat3& matrix) override;
        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) override;
        
    private:
        GLuint m_ProgramId;
        
        GLuint CompileShader(const char *source, GLint shaderType);
    };

}
