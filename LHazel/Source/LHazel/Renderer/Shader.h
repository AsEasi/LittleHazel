#pragma once

#include "LHazel/Core.h"

namespace LHazel
{

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