#include "Quad.h"
#include"Camera.h"

Quad::Quad(): pVertexBuffer_(nullptr), pIndexBuffer_(nullptr),
pConstantBuffer_(nullptr),pTexture_(nullptr),
vertexNum_(0),indexNum_(0)
{
}

Quad::~Quad()
{
	Release();
}

HRESULT Quad::Initialize()
{
	InitVertexData();

	if (FAILED(CreateVertexBuffer()))
	{
		return E_FAIL;
	}

	InitIndexData();

	if (FAILED(CreateIndexBuffer()))
	{
		return E_FAIL;
	}
	if (FAILED(CreateConstantBuffer()))
	{
		return E_FAIL;
	}

	if (FAILED(LoadTexture()))
	{
		return E_FAIL;
	}

	return S_OK;

	// 頂点情報
	//VERTEX vertices[] =
	//{
	//	//四角形
	//	{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), {0.0, 0.0, 0.0, 0.0}},// 四角形の頂点（左上）
	//	{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	 {1.0, 0.0, 0.0, 0.0}},// 四角形の頂点（右上）
	//	{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	 {1.0, 1.0, 0.0, 0.0}},// 四角形の頂点（右下）
	//	{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), {0.0, 1.0, 0.0, 0.0}},	// 四角形の頂点（左下）		
	//};
	//五角形
	//XMVectorSet(0.5f,  1.2f, 0.0f, 0.0f),//五角形の頂点（一番上）
	//XMVectorSet(-0.3f, 0.5f, 0.0f, 0.0f),//五角形の頂点（左上）
	//	XMVectorSet(0.0f, -0.5f, 0.0f, 0.0f),//五角形の頂点（左下）
	//	XMVectorSet(1.0f, -0.5f, 0.0f, 0.0f),//五角形の頂点（右下）
	//	XMVectorSet(1.3f, 0.5f, 0.0f, 0.0f),//五角形の頂点（右上）*/
	//6角形
	//XMVectorSet(0.5f,  1.0f, 0.0f, 0.0f),//六角形の頂点（右上）
	//	XMVectorSet(1.0f,  0.0f, 0.0f, 0.0f),//六角形の頂点（右中央）
	//	XMVectorSet(0.5f,  -1.0f, 0.0f, 0.0f),//六角形の頂点（右下）
	//	XMVectorSet(-0.5f,  -1.0f, 0.0f, 0.0f),//六角形の頂点（左下）
	//	XMVectorSet(-1.0f,  0.0f, 0.0f, 0.0f),//六角形の頂点（左中央）
	//	XMVectorSet(-0.5f,  1.0f, 0.0f, 0.0f),//六角形の頂点（左上）*/
	//四角錐
	//XMVectorSet(-0.5f,  0.0f, 1.0f, 0.0f),	// 四角錐の頂点（左上）
	//XMVectorSet(1.5f,  0.0f, 1.0f, 0.0f),	// 四角錐の頂点（右上）
	//XMVectorSet(0.5f, 0.0f, -1.0f, 0.0f),	// 四角錐の頂点（右下）
	//XMVectorSet(-1.5f, 0.0f, -1.0f, 0.0f),	// 四角錐の頂点（左下）	
	//XMVectorSet(0.0f, 3.0f, 0.0f, 0.0f),     //四角錐の頂点（一番上）
	////インデックス情報 四角形
	//int index[] = { 0,2,3, 0,1,2, }
	//五角形
	//int index[] = { 0,1,2, 0,2,3, 0,3,4, };
	//六角形
	//int index[] = {0,1,2 };
	//インデックス情報 四角形
	//int index[] = { 0,2,3, 0,1,2, 0,1,4, 1,2,4, 2,3,4, 0,3,4, };
}

void Quad::Draw(Transform& transform)
{
	//コンスタントバッファに渡す情報
	//XMVECTOR position = { 0, 3, -10, 0 };	//カメラの位置
	//XMVECTOR target = { 0, 0, 0, 0 };	//カメラの焦点
	//XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//ビュー行列
	//XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//射影行列
	////画角、アスペクト比、ニア平面、ファー平面
	//CONSTANT_BUFFER cb;
	//cb.matWVP = XMMatrixTranspose(worldMatrix * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	//cb.matW = XMMatrixTranspose(worldMatrix);
	//
	//D3D11_MAPPED_SUBRESOURCE pdata;
	//Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
	//memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// データを値を送る
	//Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
	////頂点バッファ
	//UINT stride = sizeof(VERTEX);
	//UINT offset = 0;
	//Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
	//// インデックスバッファーをセット
	//stride = sizeof(int);
	//offset = 0;
	//Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
	////コンスタントバッファ
	//Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
	//Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
	////サンプラーとシェーダーリソースビューをシェーダにセット
	//ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	//Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
	//ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	//Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);
	//Direct3D::pContext->DrawIndexed(6, 0, 0); //四角形
	////Direct3D::pContext->DrawIndexed(9, 0, 0); 五角形
	////Direct3D::pContext->DrawIndexed(18, 0, 0);//四角錐

	Direct3D::SetShader(SHADER_3D);
	transform.Calculation();//トランスフォームを計算

	//コンスタントバッファに情報渡す
	PassDataToCB(transform);

	//頂点バッファ、インデックスバッファ、コンスタントバッファをパイプラインにセット
	SetBufferToPipeline();

	Direct3D::pContext->DrawIndexed(index_.size(), 0, 0);
}
	

void Quad::Release()
{
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}

void Quad::InitVertexData()
{
	vertices_ =
	{
		{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), {0.0, 0.0, 0.0, 0.0}},// 四角形の頂点（左上）
		{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	 {1.0, 0.0, 0.0, 0.0}},// 四角形の頂点（右上）
		{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	 {1.0, 1.0, 0.0, 0.0}},// 四角形の頂点（右下）
		{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), {0.0, 1.0, 0.0, 0.0}},	// 四角形の頂点（左下）	
	};
	vertexNum_ = vertices_.size();
}

HRESULT Quad::CreateVertexBuffer()
{
	HRESULT hr;
	// 頂点データ用バッファの設定
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;//メモリの占有サイズをとる　
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices_.data();//vectorの先頭にある数値をとる
	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);

	if (FAILED(hr))
	{
		MessageBox(NULL, L"頂点バッファの作成に失敗", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

void Quad::InitIndexData()
{
	index_ = { 0,2,3, 0,1,2 };
	indexNum_ = index_.size();
}

HRESULT Quad::CreateIndexBuffer()
{
	HRESULT hr;

	// インデックスバッファを生成する
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(int) * indexNum_;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index_.data();
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"インデックスバッファの作成に失敗", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

HRESULT Quad::CreateConstantBuffer()
{
	HRESULT hr;

	//コンスタントバッファ作成
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// コンスタントバッファの作成
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"コンスタントバッファの作成に失敗", NULL, MB_OK);
		return hr;
	}

	return S_OK;
	/*pTexture_ = new Texture;
	pTexture_->Load("Asset\\dice.png");*/

}

HRESULT Quad::LoadTexture()
{
	pTexture_ = new Texture;
	HRESULT hr;
	if (FAILED(hr = pTexture_->Load("Assets\\dice.png")))
	{
		MessageBox(NULL, L"テクスチャの作成に失敗", L"error", MB_OK);
		return hr;
	}
	return S_OK;
}

void Quad::PassDataToCB(Transform& transform)
{
	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(transform.GetWorldMatrix() * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	cb.matW = XMMatrixTranspose(transform.GetNormalMatrix());

	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// データを値を送る
	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
}

void Quad::SetBufferToPipeline()
{
	//頂点バッファ
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// インデックスバッファーをセット
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//コンスタントバッファ
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用

	//サンプラーとシェーダーリソースビューをシェーダにセット
	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);

	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);
}
