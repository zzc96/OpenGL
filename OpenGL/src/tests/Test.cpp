#include "Test.h"
#include "imgui/imgui.h"

namespace test{
	
	TestMenu::TestMenu(Test*& currenTestPointer)
		: m_CurrenTest(currenTestPointer)
	{

	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : m_Tests)
		{
			if (ImGui::Button(test.first.c_str()))
			{
				m_CurrenTest = test.second();
			}
		}
	}

}

