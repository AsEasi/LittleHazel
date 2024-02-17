#include "LHPCH.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace LHazel
{

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &_VertexArrayID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &_VertexArrayID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(_VertexArrayID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& _VertexBuffer)
    {
        LH_CORE_ASSERT((_VertexBuffer->GetLayout().GetElements().size() > 0), "_VertexBuffer layout has no element.");

        glBindVertexArray(_VertexArrayID);

        _VertexBuffer->Bind();

        // Set layout.

        const BufferLayout& _Layout = _VertexBuffer->GetLayout();

        uint32_t _Index = 0;
        for (BufferElement _Element : _Layout)
        {
            glEnableVertexAttribArray(_Index);
            glVertexAttribPointer(
                _Index,
                _Element.GetComponentCount(),
                ShaderDataTypeToOpenGLBaseType(_Element.Type),
                _Element.Normalized,
                _Layout.GetStride(),
                (const void*)_Element.Offset
            );

            // Update index.
            _Index++;
        }

        // Enlist this buffer.
        _VertexBuffers.push_back(_VertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& _IndexBuffer)
    {
        glBindVertexArray(_VertexArrayID);

        _IndexBuffer->Bind();

        this->_IndexBuffer = _IndexBuffer;
    }

}