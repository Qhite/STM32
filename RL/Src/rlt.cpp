#include <rl_tools/operations/arm.h>
#include <rl_tools/nn/layers/dense/operations_arm/opt.h>
#include <rl_tools/nn/optimizers/adam/instance/operations_generic.h>
#include <rl_tools/nn_models/mlp/operations_generic.h>
#include <rl_tools/nn/optimizers/adam/operations_generic.h>

namespace rlt = rl_tools;
using DEVICE = rlt::devices::DefaultARM;
using T = float;
using TI = typename DEVICE::index_t;

constexpr TI BATCH_SIZE = 1;
constexpr TI INPUT_DIM_MLP = 5;
constexpr TI OUTPUT_DIM_MLP = 1;
constexpr TI NUM_LAYERS = 5;
constexpr TI HIDDEN_DIM = 5;
constexpr auto ACTIVATION_FUNCTION_MLP = rlt::nn::activation_functions::RELU;
constexpr auto OUTPUT_ACTIVATION_FUNCTION_MLP = rlt::nn::activation_functions::IDENTITY;

using MODEL_SPEC = rlt::nn_models::mlp::Specification<T, DEVICE::index_t, INPUT_DIM_MLP, OUTPUT_DIM_MLP, NUM_LAYERS, HIDDEN_DIM, ACTIVATION_FUNCTION_MLP, OUTPUT_ACTIVATION_FUNCTION_MLP>;
using PARAMETER_TYPE = rlt::nn::parameters::Adam;
using CAPABILITY = rlt::nn::layer_capability::Gradient<PARAMETER_TYPE, BATCH_SIZE>;
using MODEL_TYPE = rlt::nn_models::mlp::NeuralNetwork<CAPABILITY, MODEL_SPEC>;

using OPTIMIZER_SPEC = rlt::nn::optimizers::adam::Specification<T, TI>;
using OPTIMIZER = rlt::nn::optimizers::Adam<OPTIMIZER_SPEC>;

void test() {
    TI seed = 1;
    auto rng = rlt::random::default_engine(DEVICE::SPEC::RANDOM(), seed);
    
    DEVICE device;
    OPTIMIZER optimizer;
    MODEL_TYPE model;
    typename MODEL_TYPE::Buffer<BATCH_SIZE> buffer;

    rlt::malloc(device, model);
    rlt::init_weights(device, model, rng); // recursively initializes all layers using kaiming initialization
    rlt::zero_gradient(device, model); // recursively zeros all gradients in the layers
    rlt::reset_optimizer_state(device, optimizer, model);
    rlt::malloc(device, buffer);

    rlt::MatrixDynamic<rlt::matrix::Specification<T, TI, BATCH_SIZE, INPUT_DIM_MLP>> input_mlp;
    rlt::MatrixDynamic<rlt::matrix::Specification<T, TI, BATCH_SIZE, OUTPUT_DIM_MLP>> d_output_mlp;
    rlt::malloc(device, input_mlp);
    rlt::malloc(device, d_output_mlp);

    for(TI i=0; i < 1000; i++){
        rlt::zero_gradient(device, model);
        T mse = 0;
        for(TI batch_i=0; batch_i < 32; batch_i++){
            rlt::randn(device, input_mlp, rng);
            rlt::forward(device, model, input_mlp, buffer, rng);
            T output_value = get(model.output_layer.output, 0, 0);
            T target_output_value = rlt::max(device, input_mlp);
            T error = target_output_value - output_value;
            rlt::set(d_output_mlp, 0, 0, -error);
            rlt::backward(device, model, input_mlp, d_output_mlp, buffer);
            mse += error * error;
        }
        rlt::step(device, optimizer, model);
    }
}