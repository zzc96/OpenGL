#pragma once

#include "Test.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <memory>

namespace test {
	class TestBatchRender : public Test
	{
	public:
		TestBatchRender();
		~TestBatchRender();



		void OnUpdate(float daltaTime) override;


		void OnRender() override;


		void OnImGuiRender() override;
	private:
		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<Shader> m_Shader;

		glm::mat4 m_Proj, m_View;
		glm::vec3 m_Translation;

	};
}