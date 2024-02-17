#pragma once

#include "LHazel/Renderer/Shader.h"
#include "LHazel/Renderer/ShaderUtility.h"

namespace LHazel
{

    class VertexBuffer
    {
    public:

        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual const BufferLayout& GetLayout() const = 0;
        virtual void SetLayout(const BufferLayout& _Layout) = 0;

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

    class BufferLayout
    {
    public:

        BufferLayout() {}

        BufferLayout(std::initializer_list<BufferElement> _Elements)
            : _Elements(_Elements)
        {
            CalculateOffsetsAndStride();
        }

        uint32_t GetStride() const { return _Stride; }
        const std::vector<BufferElement>& GetElements() const { return _Elements; }

        std::vector<BufferElement>::iterator begin() { return _Elements.begin(); }
        std::vector<BufferElement>::iterator end() { return _Elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return _Elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return _Elements.end(); }

    private:

        std::vector<BufferElement> _Elements;
        uint32_t _Stride = 0;

        void CalculateOffsetsAndStride()
        {
            size_t _Offset = 0;
            _Stride = 0;
            for (auto& element : _Elements)
            {
                element.Offset = _Offset;
                _Offset += element.Size;
                _Stride += element.Size;
            }
        }
    };

    struct BufferElement
    {
    public:

        std::string Name;
        Enum_ShaderDataType Type;
        uint32_t Size;
        size_t Offset;
        bool Normalized;

        BufferElement() = default;

        BufferElement(Enum_ShaderDataType _Type, const std::string& _Name, bool _Normalized = false)
            : Name(_Name), Type(_Type), Size(GetSizeOfShaderDataType(_Type)), Offset(0), Normalized(_Normalized)
        {
        }

        uint32_t GetComponentCount() const
        {
            switch (Type)
            {
                case Enum_ShaderDataType::Float:   return 1;
                case Enum_ShaderDataType::Float2:  return 2;
                case Enum_ShaderDataType::Float3:  return 3;
                case Enum_ShaderDataType::Float4:  return 4;
                case Enum_ShaderDataType::Mat3:    return 3; // 3* float3
                case Enum_ShaderDataType::Mat4:    return 4; // 4* float4
                case Enum_ShaderDataType::Int:     return 1;
                case Enum_ShaderDataType::Int2:    return 2;
                case Enum_ShaderDataType::Int3:    return 3;
                case Enum_ShaderDataType::Int4:    return 4;
                case Enum_ShaderDataType::Bool:    return 1;
                default:
                {
                    LH_CORE_ASSERT(false, "Unknown shader data type at GetSizeOfShaderDataType(Enum_ShaderDataType).");
                    return 0;
                }
            }
        }
    };

}