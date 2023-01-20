#pragma once
#include "Texture.h"
class TransparantEffect
{
	TransparantEffect(ID3D11Device* pDevice, const std::wstring& assetFile);
	~TransparantEffect();

	TransparantEffect(const TransparantEffect&) = delete;
	TransparantEffect(TransparantEffect&&) noexcept = delete;
	TransparantEffect& operator=(const TransparantEffect&) = delete;
	TransparantEffect& operator=(TransparantEffect&&) noexcept = delete;

	static ID3DX11Effect* LoadEffect(ID3D11Device* pDevice, const std::wstring& assetFile);
	void SetDiffuseMap(const Texture* pDiffuseTexture) const;
	void SetNormalMap(const Texture* pDiffuseTexture) const;
	void SetSpecularMap(const Texture* pDiffuseTexture) const;
	void SetGlossinessMap(const Texture* pDiffuseTexture) const;

	ID3DX11Effect* GetEffect() const
	{
		return m_pEffect;
	}

	ID3DX11EffectTechnique* GetTechnique() const
	{
		return m_pTechnique;
	}
	void SetMatrixViewProj(const dae::Matrix& matrix) const;
	void SetMatrixWorld(const dae::Matrix& matrix) const;
	void SetMatrixViewInv(const dae::Matrix& matrix) const;

private:

	ID3DX11Effect* m_pEffect{};
	ID3DX11EffectTechnique* m_pTechnique{};

	//Matrices
	ID3DX11EffectMatrixVariable* m_pMatWorldViewProjVariable{};
	ID3DX11EffectMatrixVariable* m_pMatWorldVariable{};
	ID3DX11EffectMatrixVariable* m_pMatViewInvVariable{};

	//Textures
	ID3DX11EffectShaderResourceVariable* m_pDiffuseMapVariable{};
	ID3DX11EffectShaderResourceVariable* m_pNormalMapVariable{};
	ID3DX11EffectShaderResourceVariable* m_pSpecularMapVariable{};
	ID3DX11EffectShaderResourceVariable* m_pGlossinessMapVariable{};
};