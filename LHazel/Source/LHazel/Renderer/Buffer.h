#pragma once

namespace LHazel
{

    class VertexBuffer
    {
    public:

        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static VertexBuffer* Create(float* _Vertices, uint32_t _Size);
    };

    class IndexBuffer
    {
    public:

        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(uint32_t* _Indices, uint32_t _Size);
    };
}