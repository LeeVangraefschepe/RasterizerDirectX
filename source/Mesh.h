#include "pch.h"

class Effect;
class Texture;

namespace dae
{
	struct Vertex
	{
		Vector3 Position;
		Vector2 UV;
	};

	class Mesh final
	{
	public:

		explicit Mesh(ID3D11Device* pDevice, const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);
		~Mesh();

		Mesh(const Mesh&) = delete;
		Mesh(Mesh&&) noexcept = delete;
		Mesh& operator=(const Mesh&) = delete;
		Mesh& operator=(Mesh&&) noexcept = delete;

		void Render(ID3D11DeviceContext* pDeviceContext) const;
		void SetMatrix(const dae::Matrix& matrix);

		void RotateY(float rotation)
		{
			m_RotationMatrix = Matrix::CreateRotationY(rotation) * m_RotationMatrix;
		}

		ID3DX11EffectSamplerVariable* GetSampleVar();
	private:

		Effect* m_pEffect{};
		Texture* m_pTexture{};
		ID3DX11EffectTechnique* m_pTechnique{};

		ID3D11Buffer* m_pVertexBuffer{};
		ID3D11InputLayout* m_pInputLayout{};
		ID3D11Buffer* m_pIndexBuffer{};

		uint32_t m_NumIndices{};

		Matrix m_RotationMatrix{ Vector3::UnitX, Vector3::UnitY, Vector3::UnitZ, Vector3::Zero };
	};
}