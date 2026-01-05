#pragma once
#include "pch.h"
#include "Core.h"

namespace QUA {

	class QUA_API Scene
	{
	public:
		Scene(const std::string& name = "Scene") : name(name) {}
		virtual ~Scene() {}

		virtual void OnUpdate() {}

		inline const std::string& GetName() const { return name; }
	protected:
		std::string name;
	};

}