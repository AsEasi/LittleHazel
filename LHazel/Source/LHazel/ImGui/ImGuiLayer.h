#pragma once

#include "LHazel/Core.h"
#include "LHazel/Layer/Layer.h"
#include "LHazel/Event/ApplicationEvent.h"
#include "LHazel/Event/KeyEvent.h"
#include "LHazel/Event/MouseEvent.h"

namespace LHazel
{

    class ImGuiLayer : public Layer
    {
    public:

        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGui() override;
        virtual void OnEvent(Event& _Event) override;

        void BeginImGui();
        void EndImGui();

    private:

        float _Time = 0;
    };

}