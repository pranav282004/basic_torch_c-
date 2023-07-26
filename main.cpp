#include<iostream>
#include<torch/torch.h>

using namespace std;


int main(){
		
	cout<<"Welcome to Generative AI";
	auto cuda_aval = torch::cuda::is_avaliable();
	torch::Device device(cuda_aval ? torch::kCUDA : torch::kCPU);


	const int64_t batch_size  = 64;
	const double lr = 0.001;
	const int64_t hidden = 256;
	const int64_t latent = 100;
	const int64_t image_size = 28 * 28;

	torch::nn::Sequential D{
		torch::nn::Linear(image_size,hidden),
		torch::nn::LeakyRelu(torch::nn::LeakyReluOptions().negative_slope(0.2)),
		torch::nn::Linear(hidden,hidden),
		torch::nn::LeakyRelu(torch::nn::LeakyReluOptions().negative_slope(0.2)),
		torch::nn::Linear(hidden,1),
		torch::nn.Sigmoid()
	
	};

	torch::nn::Sequential G{
		torch::nn::Linear(latent_size,hidden_size),
		torch::nn::Relu(),
		torch::nn::Linear(hidden_size,hidden_size),
		torch::nn::Relu(),
		torch::nn::Linear(hidden_size,image_size),
		torch::nn:Tanh()
	};

	torch::optim::Adam d_optim(D->parameters(),torch::optim::AdamOptions(lr));
	torch::optim::Adam g_optim(G->parameters(),torch::optim::AdamOptions(lr));



	}
