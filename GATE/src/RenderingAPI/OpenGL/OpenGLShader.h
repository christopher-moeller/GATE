#pragma once
#include "Gate/Rendering/Shader.h"
#include "OpenGL.h"

namespace Gate {

    class OpenGLShader : public Shader {
        
    public:
        OpenGLShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) : Shader(vertexShaderSource, fragmentShaderSource) {}
        
        ~OpenGLShader();
        
        void Compile() override;
        
        void Destroy() override;
        void Use() override;
        
        inline bool IsCompiled() override { return m_ProgramId; }
    private:
        GLuint m_ProgramId;
        
        GLuint CompileShader(const char *source, GLint shaderType);
    };

}
