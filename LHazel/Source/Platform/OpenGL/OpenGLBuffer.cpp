#include "LHPCH.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace LHazel
{

    #pragma region OpenGL Vertex Buffer

    OpenGLVertexBuffer::OpenGLVertexBuffer(float* _Vertices, uint32_t _Size)
    {
        glCreateBuffers(1, &_BufferID);
        glBindBuffer(GL_ARRAY_BUFFER, _BufferID);
        glBufferData(GL_ARRAY_BUFFER, _Size, _Vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &_BufferID);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _BufferID);
    }

    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    #pragma endregion
    
    #pragma region OpenGL Index Buffer

    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* _Indices, uint32_t _Count)
        : _Count(_Count)
    {
        glCreateBuffers(1, &_BufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _BufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _Count * sizeof(uint32_t), _Indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &_BufferID);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _BufferID);
    }

    void OpenGLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    #pragma endregion

}