#pragma once

#include "LHazel/Renderer/Buffer.h"

#include <cstdint>

namespace LHazel
{

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:

        OpenGLVertexBuffer(float* _Vertices, uint32_t _Size);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const override;
        virtual void Unbind() const override;

    private:

        uint32_t _BufferID;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:

        OpenGLIndexBuffer(uint32_t* _Indices, uint32_t _Count);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual uint32_t GetCount() const override { return _Count; }

    private:

        uint32_t _BufferID;
        uint32_t _Count;
    };

}