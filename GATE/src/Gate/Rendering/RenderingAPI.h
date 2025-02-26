#pragma once

#include "Buffer.h"
#include "VertexArray.h"

namespace Gate {

    class RenderingAPI {
    public:
        virtual void Init() = 0;
        virtual void DrawExample() = 0;
        
        virtual VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) = 0;
        virtual IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size) = 0;
        virtual VertexArray* CreateVertexArray() = 0;
    };

}
