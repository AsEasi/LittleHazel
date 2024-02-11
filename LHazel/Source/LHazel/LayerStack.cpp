#include "LHPCH.h"
#include "LayerStack.h"

namespace LHazel
{

    LayerStack::LayerStack()
    {
        _LayerInsert = begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer* _Layer : _Layers)
        {
            delete _Layer;
        }
    }

    void LayerStack::PushLayer(Layer* _Layer)
    {
        _LayerInsert = _Layers.emplace(_LayerInsert, _Layer);
    }

    void LayerStack::PushOverlay(Layer* _Overlay)
    {
        _Layers.emplace_back(_Overlay);
    }

    void LayerStack::PopLayer(Layer* _Layer)
    {
        auto _Iterator = std::find(begin(), end(), _Layer);

        if (_Iterator != end())
        {
            _Layers.erase(_Iterator);

            _LayerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer* _Overlay)
    {
        auto _Iterator = std::find(begin(), end(), _Overlay);

        if (_Iterator != end())
        {
            _Layers.erase(_Iterator);
        }
    }

}