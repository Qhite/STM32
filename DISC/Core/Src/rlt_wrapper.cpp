#include <rlt_wrapper.h>
#include <rl_tools/operations/arm.h>
#include <rl_tools/nn/layers/dense/operations_arm/dsp.h>
#include <rl_tools/nn/layers/dense/operations_arm/opt.h>
#include <rl_tools/nn_models/sequential/operations_generic.h>

namespace rlt = rl_tools;

using DEV_SPEC = rlt::devices::DefaultARMSpecification;
using DEVICE = rlt::devices::arm::OPT<DEV_SPEC>;
DEVICE device;

using TI = DEVICE::index_t;
using T = float;

rlt::MatrixDynamic<rlt::matrix::Specification<T, TI, 100, 50>> input_;
rlt::MatrixDynamic<rlt::matrix::Specification<T, TI, 100, 10>> output_;

void init_rlt() {
    rlt::malloc(device, input_);
    rlt::malloc(device, output_);
    return;
}