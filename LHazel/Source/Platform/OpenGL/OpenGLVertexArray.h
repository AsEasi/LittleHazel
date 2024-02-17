#pragma once

#include "LHazel/Core.h"
#include "LHazel/Renderer/VertexArray.h"

namespace LHazel
{

    class OpenGLVertexArray : public VertexArray
    {
    public:

        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& _VertexBuffer) override;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& _IndexBuffer) override;

        virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return _VertexBuffers; }
        virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return _IndexBuffer; }

    private:

        uint32_t _VertexArrayID;

        std::vector<std::shared_ptr<VertexBuffer>> _VertexBuffers;
        std::shared_ptr<IndexBuffer> _IndexBuffer;
    };

}