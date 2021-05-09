#include "block.h"
//#include "user.h"


char source[] = "9IvPuZsh^D8&ae-6WgSNp&psl0&zvWmmkif7RaClwfRMaZxizoqWJ9i-eWShLy!-vs9Ft&5G1Q3tyV4N1L@-&&%FUP9d@I2rj26S#DkPvKd@k0k5ds8Yqw@^i^p*K8DVYhfAvmZ^&yX7#xc#%32URDyyiu3Rv#r/6ZIxMuyI-dyPde!Oq3a8Sto44V^FylsCBv&llL0Bb5$cSE!jQL8STV#^CV1AAEAqJ!*U$N?JLCDf?w_ERqLAiA2XXllQcs*AiTW&B1rYXDAx5TLnj6E*Bh2_3Hb_?dLXO?vFvvEXRJ6/nlVP?zA$@Y%XgMQOy/b7ykf%QXxumTVlje?s^O606%7MxPls3EJ4$?sNK/SgTgtM7xjoNExdQvNA?-h3U?u?XjFOELF2t3Jzs_rF&9jd&?Ed#LEQYk*jMDJIzexAxl9aqv8Kv1T_sib5#z?sU!fgbLZZL9W6zONQoeNG?aTM6bKf-?j3iWSlSHgDWlF0Rdk91*$2*r$O8py";
//71



char *hashfunction(block_ptr B)
{
    hash[0] = source[((B->block_index) + (B->nonce) * 3 * (B->t_array[17].to)) % 503];
    hash[1] = source[((B->nonce) * (B->block_index) + 21 * (int)(B->t_array[34].amt) + B->nonce) % 503];
    hash[2] = source[((int)(B->t_array[45].amt) * (B->block_index + B->nonce)) % 503];
    hash[3] = source[(B->nonce + B->block_index * 13 + 4) % 503];
    hash[4] = source[(B->t_array[25].to + B->nonce + 3988 + 3 * (B->block_index)) % 503];
    hash[5] = source[((B->nonce) * (int)(B->t_array[3].amt) + 3 + (B->block_index + B->nonce)) % 503];
    hash[6] = source[((B->block_index + B->t_array[43].from) - 478 + B->nonce * 2) % 503];
    hash[7] = source[(B->nonce + B->block_index + 9341) % 503];
    hash[8] = source[((int)B->t_array[28].amt * 3 + (int)B->t_array[5].amt) % 503];
    hash[9] = source[((B->nonce) + B->t_array[23].to + B->t_array[32].from) % 503];
    hash[10] = source[((B->block_index) * (B->t_array[12].from) + B->nonce) % 503];
    hash[11] = source[(B->nonce + ((int)B->t_array[43].amt) * (B->t_array[1].from)) % 503];
    hash[12] = '\0';
    return hash;
}