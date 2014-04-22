
/* This file is generated by gen_blas.py in the root of the distribution */
#if !defined(FETCH_CONTEXT) || !defined(PREFIX) || !defined(ARRAY) || !defined(POST_CALL)
#error "required macros not defined"
#endif

#ifdef ORDER
#ifndef PREP_ORDER_GEMV
#define PREP_ORDER_GEMV
#endif
#ifndef HANDLE_ORDER_GEMV
#define HANDLE_ORDER_GEMV
#endif
#ifndef PREP_ORDER_GEMM
#define PREP_ORDER_GEMM
#endif
#ifndef HANDLE_ORDER_GEMM
#define HANDLE_ORDER_GEMM
#endif
#ifndef PREP_ORDER_GER
#define PREP_ORDER_GER
#endif
#ifndef HANDLE_ORDER_GER
#define HANDLE_ORDER_GER
#endif
#else
#define ORDER
#endif

#ifndef INIT_ARGS
#define INIT_ARGS
#endif

#ifndef TRAIL_ARGS
#define TRAIL_ARGS
#endif

#ifndef SZ
#define SZ(a) a
#endif

#ifndef TRANS
#define TRANS(t) t
#endif

#ifndef SCAL
#define SCAL(s) s
#endif

#ifndef FUNC_INIT
#define FUNC_INIT
#endif

#ifndef FUNC_FINI
#define FUNC_FINI
#endif

#define __GLUE(part1, part2) __GLUE_INT(part1, part2)
#define __GLUE_INT(part1, part2) part1 ## part2

#define GEMV(dtype, typec, TYPEC)			    \
  static int typec ## gemv(cb_order order, cb_transpose transA, size_t M, size_t N, dtype alpha, gpudata *A, size_t offA, size_t lda, gpudata *X, size_t offX, int incX, dtype beta, gpudata *Y, size_t offY, int incY) { \
    FETCH_CONTEXT(A);			    \
    FUNC_DECLS;							    \
    PREP_ORDER_GEMV;		                    \
								    \
    HANDLE_ORDER_GEMV;	                            \
    FUNC_INIT;							    \
								    \
    ARRAY_INIT(A);					    \
    ARRAY_INIT(X);					    \
    ARRAY_INIT(Y);					    \
								    \
    PRE_CALL __GLUE(PREFIX(typec, TYPEC), gemv)(INIT_ARGS ORDER TRANS(transA), SZ(M), SZ(N), SCAL(alpha), ARRAY(A, dtype), SZ(lda), ARRAY(X, dtype), (incX), SCAL(beta), ARRAY(Y, dtype), (incY) TRAIL_ARGS); \
    POST_CALL;							    \
								    \
    ARRAY_FINI(A);					    \
    ARRAY_FINI(X);					    \
    ARRAY_FINI(Y);					    \
    FUNC_FINI;							    \
								    \
    return GA_NO_ERROR;						    \
  }

GEMV(float, s, S)
GEMV(double, d, D)
#define GEMM(dtype, typec, TYPEC)			    \
  static int typec ## gemm(cb_order order, cb_transpose transA, cb_transpose transB, size_t M, size_t N, size_t K, dtype alpha, gpudata *A, size_t offA, size_t lda, gpudata *B, size_t offB, size_t ldb, dtype beta, gpudata *C, size_t offC, size_t ldc) { \
    FETCH_CONTEXT(A);			    \
    FUNC_DECLS;							    \
    PREP_ORDER_GEMM;		                    \
								    \
    HANDLE_ORDER_GEMM;	                            \
    FUNC_INIT;							    \
								    \
    ARRAY_INIT(A);					    \
    ARRAY_INIT(B);					    \
    ARRAY_INIT(C);					    \
								    \
    PRE_CALL __GLUE(PREFIX(typec, TYPEC), gemm)(INIT_ARGS ORDER TRANS(transA), TRANS(transB), SZ(M), SZ(N), SZ(K), SCAL(alpha), ARRAY(A, dtype), SZ(lda), ARRAY(B, dtype), SZ(ldb), SCAL(beta), ARRAY(C, dtype), SZ(ldc) TRAIL_ARGS); \
    POST_CALL;							    \
								    \
    ARRAY_FINI(A);					    \
    ARRAY_FINI(B);					    \
    ARRAY_FINI(C);					    \
    FUNC_FINI;							    \
								    \
    return GA_NO_ERROR;						    \
  }

GEMM(float, s, S)
GEMM(double, d, D)
#define GER(dtype, typec, TYPEC)			    \
  static int typec ## ger(cb_order order, size_t M, size_t N, dtype alpha, gpudata *X, size_t offX, int incX, gpudata *Y, size_t offY, int incY, gpudata *A, size_t offA, size_t lda) { \
    FETCH_CONTEXT(X);			    \
    FUNC_DECLS;							    \
    PREP_ORDER_GER;		                    \
								    \
    HANDLE_ORDER_GER;	                            \
    FUNC_INIT;							    \
								    \
    ARRAY_INIT(X);					    \
    ARRAY_INIT(Y);					    \
    ARRAY_INIT(A);					    \
								    \
    PRE_CALL __GLUE(PREFIX(typec, TYPEC), ger)(INIT_ARGS ORDER SZ(M), SZ(N), SCAL(alpha), ARRAY(X, dtype), (incX), ARRAY(Y, dtype), (incY), ARRAY(A, dtype), SZ(lda) TRAIL_ARGS); \
    POST_CALL;							    \
								    \
    ARRAY_FINI(X);					    \
    ARRAY_FINI(Y);					    \
    ARRAY_FINI(A);					    \
    FUNC_FINI;							    \
								    \
    return GA_NO_ERROR;						    \
  }

GER(float, s, S)
GER(double, d, D)

GPUARRAY_LOCAL gpuarray_blas_ops __GLUE(NAME, _ops) = {
  setup,
  teardown,
  sgemv,
  dgemv,
  sgemm,
  dgemm,
  sger,
  dger,
  sgemmBatch,
  dgemmBatch,
};
