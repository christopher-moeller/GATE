#pragma once

#include "ShaderSource.h"

namespace Gate {

    class Quad2DShaderSource : public ShaderSource {
    public:
        ShaderSourceData GetOpenGLShader() const override {
            std::string vertexShaderSource = R"(
                #version 330 core
                
                layout(location = 0) in vec3 a_Position;

                uniform mat4 u_ViewProjection;
                uniform mat4 u_Transform;
                uniform vec4 u_Color;

                out vec4 v_Color;

                void main()
                {
                    v_Color = u_Color;
                    gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);   
                }
            )";

            std::string fragmentShaderSource = R"(
                #version 330 core
            
                out vec4 color;

                in vec4 v_Color;

                void main()
                {
                    color = v_Color;
                }
            )";

            return {vertexShaderSource, fragmentShaderSource};
        }
        
        ShaderSourceData GetOpenGLESShader() const override {
            std::string vertexShaderSource = R"(

            )";

            std::string fragmentShaderSource = R"(

            )";

            return {vertexShaderSource, fragmentShaderSource};
        }
        
    };

}
