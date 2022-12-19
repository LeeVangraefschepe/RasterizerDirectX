#pragma once
#include "Texture.h"

class Effect final
{
public:

	Effect(ID3D11Device* pDevice, const std::wstring& assetFile);
	~Effect();

	Effect(const Effect&) = delete;
	Effect(Effect&&) noexcept = delete;
	Effect& operator=(const Effect&) = delete;
	Effect& operator=(Effect&&) noexcept = delete;

	static ID3DX11Effect* LoadEffect(ID3D11Device* pDevice, const std::wstring& assetFile);
	void SetDiffuseMap(Texture* pDiffuseTexture);

	ID3DX11Effect* GetEffect() const
	{
		return m_pEffect;
	}
	ID3DX11EffectTechnique* GetTechnique() const
	{
		return m_pTechnique;
	}
	void SetMatrix(const dae::Matrix& matrix);

private:

	ID3DX11Effect* m_pEffect{};
	ID3DX11EffectTechnique* m_pTechnique{};
	ID3DX11EffectMatrixVariable* m_pMatWorldViewProjVariable{};
	ID3DX11EffectShaderResourceVariable* m_pDiffuseMapVariable{};
};