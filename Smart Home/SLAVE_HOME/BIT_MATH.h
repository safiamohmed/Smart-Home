#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(NUM,N_BIT) (NUM|=(1<<N_BIT))
#define CLR_BIT(NUM,N_BIT) (NUM&=(~(1<<N_BIT)))
#define TOG_BIT(NUM,N_BIT) (NUM^=(1<<N_BIT))
#define GET_BIT(NUM,N_BIT) ((NUM>>N_BIT)&1)

#endif
