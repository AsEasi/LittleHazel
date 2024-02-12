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
            _Layer->OnDetach();

            delete _Layer;
        }
    }

    void LayerStack::PushLayer(Layer* _Layer)
    {
        _LayerInsert = _Layers.emplace(_LayerInsert, _Layer);

        _Layer->OnAttach();
    }

    void LayerStack::PushOverlay(Layer* _Layer)
    {
        _Layers.emplace_back(_Layer);
        
        _Layer->OnAttach();
    }

    void LayerStack::PopLayer(Layer* _Layer)
    {
        auto _Iterator = std::find(begin(), end(), _Layer);

        if (_Iterator != end())
        {
            _Layers.erase(_Iterator);

            _Layer->OnDetach();

            _LayerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer* _Layer)
    {
        auto _Iterator = std::find(begin(), end(), _Layer);

        if (_Iterator != end())
        {
            _Layers.erase(_Iterator);

            _Layer->OnDetach();
        }
    }

}