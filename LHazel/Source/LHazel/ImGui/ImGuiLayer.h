#pragma once

#include "LHazel/Core.h"
#include "LHazel/Layer/Layer.h"

namespace LHazel
{

    class LHAZEL_API ImGuiLayer : public Layer
    {
    public:

        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnUpdate() override;
        virtual void OnEvent(Event& event) override;

    private:

        float _Time = 0;
    };

}