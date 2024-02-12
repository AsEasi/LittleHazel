#pragma once

#include "LHazel/Core.h"
#include "LHazel/Layer/Layer.h"
#include "LHazel/Event/ApplicationEvent.h"
#include "LHazel/Event/KeyEvent.h"
#include "LHazel/Event/MouseEvent.h"

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
        virtual void OnEvent(Event& _Event) override;

    private:

        float _Time = 0;

        bool OnWindowResizedEvent       (WindowResizedEvent& _Event);
        bool OnMouseButtonPressedEvent  (MouseButtonPressedEvent& _Event);
        bool OnMouseButtonReleasedEvent (MouseButtonReleasedEvent& _Event);
        bool OnMouseScrolledEvent       (MouseScrolledEvent& _Event);
        bool OnMouseMovedEvent          (MouseMovedEvent& _Event);
        bool OnKeyPressedEvent          (KeyPressedEvent& _Event);
        bool OnKeyReleasedEvent         (KeyReleasedEvent& _Event);
        bool OnKeyTypedEvent            (KeyTypedEvent& _Event);
    };

}