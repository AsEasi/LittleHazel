#include "LHPCH.h"
#include "Buffer.h"
#include "LHazel/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace LHazel
{

    VertexBuffer* VertexBuffer::Create(float* _Vertices, uint32_t _Size)
    {
        switch (Renderer::GetAPI())
        {
            case Enum_RendererAPI::None:
            {
                LH_CORE_ASSERT(false, "RendererAPI::None is not supported.");
                return nullptr;
            }
            case Enum_RendererAPI::OpenGL:
            {
                return new OpenGLVertexBuffer(_Vertices, _Size);
            }
            default:
            {
                LH_CORE_ASSERT(false, "Unknow renderer API.");
                return nullptr;
            }
        }
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* _Indices, uint32_t _Size)
    {
        switch (Renderer::GetAPI())
        {
            case Enum_RendererAPI::None:
            {
                LH_CORE_ASSERT(false, "RendererAPI::None is not supported.");
                return nullptr;
            }
            case Enum_RendererAPI::OpenGL:
            {
                return new OpenGLIndexBuffer(_Indices, _Size);
            }
            default:
            {
                LH_CORE_ASSERT(false, "Unknow renderer API.");
                return nullptr;
            }
        }
    }

}