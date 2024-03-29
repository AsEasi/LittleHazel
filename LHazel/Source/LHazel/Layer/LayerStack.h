#pragma once

#include "LHazel/Core.h"
#include "Layer.h"

namespace LHazel
{

    class LayerStack
    {
    public:

        LayerStack() = default;
        ~LayerStack();

        void PushLayer(Layer* _Layer);
        void PushOverlay(Layer* _Overlay);
        void PopLayer(Layer* _Layer);
        void PopOverlay(Layer* _Overlay);

        std::vector<Layer*>::iterator begin() { return _Layers.begin(); };
        std::vector<Layer*>::iterator end() { return _Layers.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return _Layers.rbegin(); };
        std::vector<Layer*>::reverse_iterator rend() { return _Layers.rend(); }

        std::vector<Layer*>::const_iterator begin() const { return _Layers.begin(); };
        std::vector<Layer*>::const_iterator end() const { return _Layers.end(); }
        std::vector<Layer*>::const_reverse_iterator rbegin() const { return _Layers.rbegin(); };
        std::vector<Layer*>::const_reverse_iterator rend() const { return _Layers.rend(); }

    private:

        std::vector<Layer*> _Layers;
        unsigned int _LayerInsertIndex = 0;
    };

}