#pragma once

namespace LHazel
{

	enum class Enum_RendererAPI
	{
		None = 0, OpenGL = 1,
	};

	class Renderer
	{
	public:

		inline static Enum_RendererAPI GetAPI() { return _RendererAPI; }

	private:

		static Enum_RendererAPI _RendererAPI;
	};
}