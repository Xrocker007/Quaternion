#pragma once

#include "Quaternion/CameraManager.h"

namespace QUA {

	class RaylibCamera2D : public CameraManager
	{
	public:
		RaylibCamera2D();
		~RaylibCamera2D();

		void startCamera(QUA::Camera2D& cam) override;
		void endCamera() override;

	};
}