#include <rlt_wrapper.h>
#include <stdio.h>

#include <rl_tools/operations/arm.h>
// #include <rl_tools/nn/layers/dense/operations_arm/opt.h>
#include <rl_tools/nn/layers/dense/operations_arm/dsp.h>
#include <rl_tools/nn_models/sequential/operations_generic.h>

#include <rl_tools/nn/optimizers/adam/instance/operations_generic.h>
#include <rl_tools/nn_models/mlp/operations_generic.h>
#include <rl_tools/nn/optimizers/adam/operations_generic.h>

namespace rlt = rl_tools;

using DEV_SPEC  = rlt::devices::DefaultARMSpecification;
using DEVICE    = rlt::devices::arm::OPT<DEV_SPEC>;
DEVICE device;

auto rng = rlt::random::default_engine(DEVICE::SPEC::RANDOM(), 1);

using TI    = DEVICE::index_t;
using T     = float;

constexpr TI BATCH_SIZE = 1;

constexpr TI INPUT_DIM  = 5;
constexpr TI OUTPUT_DIM = 1;
constexpr TI NUM_LAYERS = 3;
constexpr TI HIDDEN_DIM = 64;

constexpr auto ACTIVATION_FUNCTION  = rlt::nn::activation_functions::RELU;
constexpr auto OUTPUT_ACTIVATION    = rlt::nn::activation_functions::IDENTITY;

using MODEL_SPEC = rlt::nn_models::mlp::Specification<T, TI, INPUT_DIM, OUTPUT_DIM, NUM_LAYERS, HIDDEN_DIM, ACTIVATION_FUNCTION, OUTPUT_ACTIVATION>;

using PARAMETER_TYPE = rlt::nn::parameters::Adam;
using CAPABILITY = rlt::nn::layer_capability::Gradient<PARAMETER_TYPE, BATCH_SIZE>;
using OPTIMIZER_SPEC = rlt::nn::optimizers::adam::Specification<T, TI>;
using OPTIMIZER = rlt::nn::optimizers::Adam<OPTIMIZER_SPEC>;
using MODEL_TYPE = rlt::nn_models::mlp::NeuralNetwork<CAPABILITY, MODEL_SPEC>;

OPTIMIZER optimizer;
MODEL_TYPE model;
typename MODEL_TYPE::Buffer<BATCH_SIZE> buffer;

rlt::MatrixDynamic<rlt::matrix::Specification<T, TI, BATCH_SIZE, INPUT_DIM>> input_mlp;
rlt::MatrixDynamic<rlt::matrix::Specification<T, TI, BATCH_SIZE, OUTPUT_DIM>> d_output_mlp;

void init_rlt() {
    rlt::malloc(device, model);
    rlt::init_weights(device, model, rng);
    rlt::zero_gradient(device, model);
    rlt::reset_optimizer_state(device, optimizer, model);

    rlt::malloc(device, input_mlp);
    rlt::malloc(device, d_output_mlp);
    return;
}

void train(float *mse) {
    rlt::zero_gradient(device, model);
    T mse_ = 0;
    for(TI batch_i=0; batch_i < 256; batch_i++){
        rlt::randn(device, input_mlp, rng);
        rlt::forward(device, model, input_mlp, buffer, rng);
        T output_value = get(model.output_layer.output, 0, 0);
        T target_output_value = rlt::max(device, input_mlp);
        T error = target_output_value - output_value;
        rlt::set(d_output_mlp, 0, 0, -error);
        rlt::backward(device, model, input_mlp, d_output_mlp, buffer);
        mse_ += error * error;
    }
    rlt::step(device, optimizer, model);
    *mse = mse_ / 32;

    return;
}