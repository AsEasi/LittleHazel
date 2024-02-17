#include "LHPCH.h"
#include "VertexArray.h"
#include "LHazel/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace LHazel
{
    
    VertexArray* VertexArray::Create()
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
                return new OpenGLVertexArray();
            }
            default:
            {
                LH_CORE_ASSERT(false, "Unknow renderer API.");
                return nullptr;
            }
        }
    }

}