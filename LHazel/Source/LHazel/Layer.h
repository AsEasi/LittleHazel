#pragma once

#include "Core.h"
#include "LHazel/Events/Event.h"

namespace LHazel
{

    class Layer
    {
    public:

        Layer(const std::string& _Name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return _DebugName; }

    protected:

        std::string _DebugName;
    };

}