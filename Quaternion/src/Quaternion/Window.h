#pragma once

#include "pch.h"
#include "Core.h"

namespace QUA {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Quaternion Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	class QUA_API Window
	{
	public:
		virtual ~Window() {}

		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetFullscreen(bool enabled) = 0;
		virtual bool GetFullscreen() const = 0;

		virtual void SetResizable(bool enabled) = 0;
		virtual bool GetResizable() const = 0;

		virtual void SetBorderless(bool enabled) = 0;
		virtual bool GetBorderless() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool GetVSync() const = 0;

		virtual void SetBackgroundColour(Colour colour) = 0;

		virtual bool IsWindowRunning() = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};

}