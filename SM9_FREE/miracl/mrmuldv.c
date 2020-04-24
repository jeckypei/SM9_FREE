
/* GCC inline assembly version for Linux64*/

#include "miracl.h"

mr_small muldiv(mr_small a,mr_small b,mr_small c,mr_small m,mr_small *rp)
{
    mr_small q;
    mr_large ldres,p=(mr_large)a*b+c;
    q=(mr_small)(MR_LROUND(p/m));
    *rp=(mr_small)(p-(mr_large)q*m);
    return q;
}

mr_small imuldiv(mr_small a,mr_small b,mr_small c,mr_small m,mr_large im,mr_small *rp)
{
    mr_small q;
    mr_large ldres,p=(mr_large)a*b+c;
    q=(mr_small)MR_LROUND(p*im);
    *rp=(mr_small)(p-(mr_large)q*m);
    return q;
}


mr_small muldvm(mr_small a,mr_small c,mr_small m,mr_small *rp)
{
    mr_small q;
    union doubleword dble;
    dble.h[MR_BOT]=c;
    dble.h[MR_TOP]=a;

    q=(mr_small)(dble.d/m);
    *rp=(mr_small)(dble.d-(mr_large)q*m);
    return q;
}

mr_small muldvd(mr_small a,mr_small b,mr_small c,mr_small *rp)
{
    union doubleword dble;
    dble.d=(mr_large)a*b+c;

    *rp=dble.h[MR_BOT];
    return dble.h[MR_TOP];
}

void muldvd2(mr_small a,mr_small b,mr_small *c,mr_small *rp)
{
    union doubleword dble;
    dble.d=(mr_large)a*b+*c+*rp;
    *rp=dble.h[MR_BOT];
    *c=dble.h[MR_TOP];
}


