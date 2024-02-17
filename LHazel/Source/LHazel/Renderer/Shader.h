#pragma once

#include "LHazel/Core.h"

namespace LHazel
{

    enum class Enum_ShaderDataType
    {
        None = 0,
        Float, Float2, Float3, Float4,
        Mat3, Mat4,
        Int, Int2, Int3, Int4,
        Bool
    };

    class Shader
    {
    public:

        Shader(std::string& _VertexSource, std::string& _FragmentSource);
        ~Shader();

        void Bind();
        void Unbind();

    private:

        uint32_t _ProgramID;
    };
}