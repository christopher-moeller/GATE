#include "OpenGLShader.h"
#include "Gate/Base.h"

#include <glm/gtc/type_ptr.hpp>

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

    void OpenGLShader::UploadUniformInt(const std::string& name, int value)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniform1i(location, value);
    }

    void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniform1f(location, value);
    }

    void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& value)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniform2f(location, value.x, value.y);
    }

    void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& value)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniform3f(location, value.x, value.y, value.z);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& value)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniform4f(location, value.x, value.y, value.z, value.w);
    }

    void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
    {
        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

}
