#include "OpenGLShader.h"
#include "Gate/Base.h"

namespace Gate {

    OpenGLShader::~OpenGLShader() {
        Destroy();
    }

    void OpenGLShader::Compile() {
        
        GLuint vertexShader = CompileShader(m_VertexShaderSource.c_str(), GL_VERTEX_SHADER);
        GLuint fragmentShader = CompileShader(m_FragmentShaderSource.c_str(), GL_FRAGMENT_SHADER);
                
        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        
        GLint success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
            GATE_ASSERT(false, "ERROR: Shader Program Linking Failed: {}", infoLog);
            return;
        }
        
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        
        m_ProgramId = shaderProgram;
        
    }

    void OpenGLShader::Destroy() {
        glDeleteProgram(m_ProgramId);
    }

    void OpenGLShader::Use() {
        glUseProgram(m_ProgramId);
    }

    GLuint OpenGLShader::CompileShader(const char *source, GLint shaderType) {
        GLuint glShader = glCreateShader(shaderType);
        glShaderSource(glShader, 1, &source, nullptr);
        glCompileShader(glShader);
        
        // Check for compilation errors
        GLint success;
        char infoLog[512];
        glGetShaderiv(glShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(glShader, 512, nullptr, infoLog);
            GATE_ASSERT(false, "ERROR: Vertex Shader Compilation Failed: {}", infoLog);
        }
        
        return glShader;
    }

}
