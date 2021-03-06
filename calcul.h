/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALCUL_H_RPCGEN
#define _CALCUL_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct intpair {
	int a;
	int b;
};
typedef struct intpair intpair;

struct floatpair {
	float a;
	float b;
};
typedef struct floatpair floatpair;

#define CALCULATION_PROG 0x23451111
#define CALCULATION_VERS1 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADDD 1
extern  int * addd_1(intpair *, CLIENT *);
extern  int * addd_1_svc(intpair *, struct svc_req *);
#define MULL 2
extern  int * mull_1(intpair *, CLIENT *);
extern  int * mull_1_svc(intpair *, struct svc_req *);
extern int calculation_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADDD 1
extern  int * addd_1();
extern  int * addd_1_svc();
#define MULL 2
extern  int * mull_1();
extern  int * mull_1_svc();
extern int calculation_prog_1_freeresult ();
#endif /* K&R C */
#define CALCULATION_VERS2 2

#if defined(__STDC__) || defined(__cplusplus)
extern  float * addd_2(floatpair *, CLIENT *);
extern  float * addd_2_svc(floatpair *, struct svc_req *);
extern  float * mull_2(floatpair *, CLIENT *);
extern  float * mull_2_svc(floatpair *, struct svc_req *);
extern int calculation_prog_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
extern  float * addd_2();
extern  float * addd_2_svc();
extern  float * mull_2();
extern  float * mull_2_svc();
extern int calculation_prog_2_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_intpair (XDR *, intpair*);
extern  bool_t xdr_floatpair (XDR *, floatpair*);

#else /* K&R C */
extern bool_t xdr_intpair ();
extern bool_t xdr_floatpair ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALCUL_H_RPCGEN */
