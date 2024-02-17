#pragma once

#include "LHazel/Core.h"
#include "LHazel/Renderer/Shader.h"

#include <glad/glad.h>

namespace LHazel
{

    static GLenum ShaderDataTypeToOpenGLBaseType(Enum_ShaderDataType type)
    {
        switch (type)
        {
            case Enum_ShaderDataType::Float:    return GL_FLOAT;
            case Enum_ShaderDataType::Float2:   return GL_FLOAT;
            case Enum_ShaderDataType::Float3:   return GL_FLOAT;
            case Enum_ShaderDataType::Float4:   return GL_FLOAT;
            case Enum_ShaderDataType::Mat3:     return GL_FLOAT;
            case Enum_ShaderDataType::Mat4:     return GL_FLOAT;
            case Enum_ShaderDataType::Int:      return GL_INT;
            case Enum_ShaderDataType::Int2:     return GL_INT;
            case Enum_ShaderDataType::Int3:     return GL_INT;
            case Enum_ShaderDataType::Int4:     return GL_INT;
            case Enum_ShaderDataType::Bool:     return GL_BOOL;
            default:
            {
                LH_CORE_ASSERT(false, "Unknown shader data type.");
                return 0;
            }
        }
    }

    static uint32_t GetSizeOfShaderDataType(Enum_ShaderDataType _Type)
    {
        switch (_Type)
        {
            case Enum_ShaderDataType::Float:    return 4;
            case Enum_ShaderDataType::Float2:   return 4 * 2;
            case Enum_ShaderDataType::Float3:   return 4 * 3;
            case Enum_ShaderDataType::Float4:   return 4 * 4;
            case Enum_ShaderDataType::Mat3:     return 4 * 3 * 3;
            case Enum_ShaderDataType::Mat4:     return 4 * 4 * 4;
            case Enum_ShaderDataType::Int:      return 4;
            case Enum_ShaderDataType::Int2:     return 4 * 2;
            case Enum_ShaderDataType::Int3:     return 4 * 3;
            case Enum_ShaderDataType::Int4:     return 4 * 4;
            case Enum_ShaderDataType::Bool:     return 1;
            default:
            {
                LH_CORE_ASSERT(false, "Unknown shader data type at GetSizeOfShaderDataType(Enum_ShaderDataType).");
                return 0;
            }
        }
    }

}