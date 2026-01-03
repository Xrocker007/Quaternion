#pragma once
#include "raylib.h"
#include "Quaternion/Window.h"

namespace QUA {

	class RaylibWindow : public Window
	{
	public:
		RaylibWindow(const WindowProps& props);
		virtual ~RaylibWindow();

		void BeginFrame() override;
		void EndFrame() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Window attributes
		void SetFullscreen(bool enabled) override;
		bool GetFullscreen() const override;

		void SetResizable(bool enabled) override;
		bool GetResizable() const override;

		void SetBorderless(bool enabled) override;
		bool GetBorderless() const override;

		void SetVSync(bool enabled) override;
		bool GetVSync() const override;

		void SetBackgroundColour(unsigned int hexValue) override;

		bool IsWindowRunning() override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool Fullscreen;
			bool Resizable;
			bool Borderless;
			bool VSync;
			unsigned int BackgroundColour;
			bool windowRunning;
		};

		WindowData m_Data;
	};

}