#include "LHPCH.h"
#include "LayerStack.h"

namespace LHazel
{

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
        _Layers.emplace(begin() + _LayerInsertIndex, _Layer);
        _LayerInsertIndex++;

        _Layer->OnAttach();
    }

    void LayerStack::PushOverlay(Layer* _Layer)
    {
        _Layers.emplace_back(_Layer);
        
        _Layer->OnAttach();
    }

    void LayerStack::PopLayer(Layer* _Layer)
    {
        auto _FirstLayer = begin();
        auto _LastLayer = begin() + _LayerInsertIndex;

        auto _Iterator = std::find(_FirstLayer, _LastLayer, _Layer);

        if (_Iterator != _LastLayer)
        {
            _Layers.erase(_Iterator);

            _Layer->OnDetach();

            _LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer* _Layer)
    {
        auto _FirstOverlay = begin() + _LayerInsertIndex;
        auto _LastOverLay = end();

        auto _Iterator = std::find(_FirstOverlay, _LastOverLay, _Layer);

        if (_Iterator != _LastOverLay)
        {
            _Layers.erase(_Iterator);

            _Layer->OnDetach();
        }
    }

}