#include "pch.h"
#include "TransparantEffect.h"

TransparantEffect::TransparantEffect(ID3D11Device* pDevice, const std::wstring& assetFile)
{
}

TransparantEffect::~TransparantEffect()
{
}

void TransparantEffect::SetDiffuseMap(const Texture* pDiffuseTexture) const
{
}

void TransparantEffect::SetNormalMap(const Texture* pDiffuseTexture) const
{
}

void TransparantEffect::SetSpecularMap(const Texture* pDiffuseTexture) const
{
}

void TransparantEffect::SetGlossinessMap(const Texture* pDiffuseTexture) const
{
}

void TransparantEffect::SetMatrixViewProj(const dae::Matrix& matrix) const
{
}

void TransparantEffect::SetMatrixWorld(const dae::Matrix& matrix) const
{
}

void TransparantEffect::SetMatrixViewInv(const dae::Matrix& matrix) const
{
}
