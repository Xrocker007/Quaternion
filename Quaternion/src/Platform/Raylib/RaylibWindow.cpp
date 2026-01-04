#include "pch.h"
#include "RaylibWindow.h"

namespace QUA {

	Window* Window::Create(const WindowProps& props)
	{
		return new RaylibWindow(props);
	}

	Color RaylibBackgroundColor(Colour colour)
	{
		return ColorFromNormalized(Vector4{ colour.r, colour.g, colour.b, colour.a });
	}

	RaylibWindow::RaylibWindow(const WindowProps& props)
	{
		Init(props);
	}

	RaylibWindow::~RaylibWindow()
	{
		Shutdown();
	}

	void RaylibWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.BackgroundColour = {0.9, 0.9, 0.9, 1};

		InitWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str());

		SetResizable(true);
		SetVSync(true);
	}

	void RaylibWindow::Shutdown()
	{
		CloseWindow();
	}

	void RaylibWindow::BeginFrame()
	{
		BeginDrawing();

		ClearBackground(RaylibBackgroundColor(m_Data.BackgroundColour));
	}

	void RaylibWindow::EndFrame()
	{
		EndDrawing();
	}

	void RaylibWindow::SetFullscreen(bool enabled)
	{
		if (enabled)
		{
			SetWindowState(FLAG_FULLSCREEN_MODE);
		}
		else
		{
			ClearWindowState(FLAG_FULLSCREEN_MODE);
		}

		m_Data.Fullscreen = enabled;
	}

	bool RaylibWindow::GetFullscreen() const
	{
		return m_Data.Fullscreen;
	}

	void RaylibWindow::SetResizable(bool enabled)
	{
		if (enabled)
		{
			SetWindowState(FLAG_WINDOW_RESIZABLE);
		}
		else
		{
			ClearWindowState(FLAG_WINDOW_RESIZABLE);
		}

		m_Data.Resizable = enabled;
	}

	bool RaylibWindow::GetResizable() const
	{
		return m_Data.Resizable;
	}

	void RaylibWindow::SetBorderless(bool enabled)
	{
		if (enabled)
		{
			SetWindowState(FLAG_WINDOW_UNDECORATED);
		}
		else
		{
			ClearWindowState(FLAG_WINDOW_UNDECORATED);
		}

		m_Data.Borderless = enabled;
	}

	bool RaylibWindow::GetBorderless() const
	{
		return m_Data.Borderless;
	}

	void RaylibWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			SetWindowState(FLAG_VSYNC_HINT);
		}
		else
		{
			ClearWindowState(FLAG_VSYNC_HINT);
		}

		m_Data.VSync = enabled;
	}

	bool RaylibWindow::GetVSync() const
	{
		return m_Data.VSync;
	}

	void RaylibWindow::SetBackgroundColour(Colour colour)
	{
		m_Data.BackgroundColour = colour;
	}

	bool RaylibWindow::IsWindowRunning()
	{
		return !WindowShouldClose();
	}


}