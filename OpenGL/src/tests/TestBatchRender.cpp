#include "TestBatchRender.h"
#include "Renderer.h"
#include "imgui/imgui.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace test {
	test::TestBatchRender::TestBatchRender()
		: m_Proj(glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0))), 
		m_Translation(glm::vec3(0, 0, 0))
	{
		float positions[] = {
			100.0f, 100.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			200.0f, 100.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			200.0f, 200.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			100.0f, 200.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,

			300.0f, 100.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			400.0f, 100.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			400.0f, 200.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			300.0f, 200.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,

			4, 5, 6, 
			6, 7, 4
		};

		m_VAO = std::make_unique<VertexArray>();
		m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 8 * 8 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		layout.Push<float>(4);
		m_VAO->AddBuffer(*m_VertexBuffer, layout);

		m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 12);

		m_Shader = std::make_unique<Shader>("res/shaders/Batch.shader");
		m_Shader->Bind();

	}

	test::TestBatchRender::~TestBatchRender()
	{

	}

	void test::TestBatchRender::OnUpdate(float daltaTime)
	{
	}

	void test::TestBatchRender::OnRender()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;

		glm::mat4 mvp = m_Proj * m_View;
		m_Shader->Bind();

		m_Shader->SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
	}

	void test::TestBatchRender::OnImGuiRender()
	{
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}
