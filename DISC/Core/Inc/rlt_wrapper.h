#ifndef RLT_WRAPPER_H
#define RLT_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

void init_rlt();
void train(float *mse);

#ifdef __cplusplus
}
#endif

#endif