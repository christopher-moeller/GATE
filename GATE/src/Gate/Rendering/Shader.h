#pragma once

#include <string>

namespace Gate {

    class Shader {
    public:
        Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) : m_VertexShaderSource(vertexShaderSource), m_FragmentShaderSource(fragmentShaderSource) {}
        
        virtual ~Shader() = default;
        
        virtual void Compile() = 0;
        virtual bool IsCompiled() = 0;
        
        virtual void Destroy() = 0;
        virtual void Use() = 0;
        
    protected:
        std::string m_VertexShaderSource;
        std::string m_FragmentShaderSource;
    };

}
