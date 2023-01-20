#pragma once
#include "Utils.h"
#include "Camera.h"

struct SDL_Window;
struct SDL_Surface;

namespace dae
{
	enum FilteringMethods
	{
		Point,
		Linear,
		Anisotropic
	};

	class Renderer final
	{
	public:
		Renderer(SDL_Window* pWindow);
		~Renderer();

		void PressFilterMethod();

		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) noexcept = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) noexcept = delete;

		void Update(const Timer* pTimer);
		void Render() const;

	private:
		SDL_Window* m_pWindow{};

		int m_Width{};
		int m_Height{};

		bool m_IsInitialized{ false };

		//DIRECTX
		HRESULT InitializeDirectX();
		ID3D11Device* m_pDevice{ nullptr };
		ID3D11DeviceContext* m_pDeviceContext{ nullptr };
		IDXGISwapChain* m_pSwapChain{ nullptr };
		ID3D11Texture2D* m_pDepthStencilBuffer{ nullptr };
		ID3D11DepthStencilView* m_pDepthStencilView{ nullptr };
		ID3D11Resource* m_pRenderTargetBuffer{ nullptr };
		ID3D11RenderTargetView* m_pRenderTargetView{ nullptr };

		ID3DX11EffectSamplerVariable* m_pEffectSamplerVariable{};
		ID3D11SamplerState* m_pSamplerState{};
		D3D11_SAMPLER_DESC m_SamplerDesc{};
		
		FilteringMethods m_FilteringMethod{ Anisotropic };

		std::vector<Mesh*> m_pMeshes{};
		Camera* m_pCamera{};

		void CreateMesh();
	};
}
