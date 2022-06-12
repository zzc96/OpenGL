#pragma once

namespace test {
	class Test
	{
	public:
		Test() {}
		virtual ~Test() {}

		virtual void OnUpdate(float daltaTime) {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}
	};
}