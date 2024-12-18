#include "geo.h"

#include <string.h>

Coord getCoord(char *countryCode) {
    if (strcmp(countryCode, "BI") == 0) {
        return (Coord) {.x = 548, .y = 331};
    } else if (strcmp(countryCode, "CO") == 0) {
        return (Coord) {.x = 261, .y = 309};
    } else if (strcmp(countryCode, "FI") == 0) {
        return (Coord) {.x = 537, .y = 128};
    } else if (strcmp(countryCode, "DZ") == 0) {
        return (Coord) {.x = 475, .y = 219};
    } else if (strcmp(countryCode, "SA") == 0) {
        return (Coord) {.x = 595, .y = 253};
    } else if (strcmp(countryCode, "CV") == 0) {
        return (Coord) {.x = 399, .y = 276};
    } else if (strcmp(countryCode, "FM") == 0) {
        return (Coord) {.x = 864, .y = 297};
    } else if (strcmp(countryCode, "AL") == 0) {
        return (Coord) {.x = 521, .y = 203};
    } else if (strcmp(countryCode, "HK") == 0) {
        return (Coord) {.x = 780, .y = 258};
    } else if (strcmp(countryCode, "CN") == 0) {
        return (Coord) {.x = 783, .y = 204};
    } else if (strcmp(countryCode, "VI") == 0) {
        return (Coord) {.x = 289, .y = 270};
    } else if (strcmp(countryCode, "PA") == 0) {
        return (Coord) {.x = 246, .y = 297};
    } else if (strcmp(countryCode, "MN") == 0) {
        return (Coord) {.x = 760, .y = 182};
    } else if (strcmp(countryCode, "SS") == 0) {
        return (Coord) {.x = 551, .y = 304};
    } else if (strcmp(countryCode, "SE") == 0) {
        return (Coord) {.x = 513, .y = 136};
    } else if (strcmp(countryCode, "LS") == 0) {
        return (Coord) {.x = 543, .y = 405};
    } else if (strcmp(countryCode, "PH") == 0) {
        return (Coord) {.x = 797, .y = 282};
    } else if (strcmp(countryCode, "KZ") == 0) {
        return (Coord) {.x = 665, .y = 170};
    } else if (strcmp(countryCode, "MU") == 0) {
        return (Coord) {.x = 620, .y = 375};
    } else if (strcmp(countryCode, "CH") == 0) {
        return (Coord) {.x = 488, .y = 182};
    } else if (strcmp(countryCode, "MK") == 0) {
        return (Coord) {.x = 526, .y = 200};
    } else if (strcmp(countryCode, "NP") == 0) {
        return (Coord) {.x = 699, .y = 243};
    } else if (strcmp(countryCode, "MQ") == 0) {
        return (Coord) {.x = 298, .y = 280};
    } else if (strcmp(countryCode, "CK") == 0) {
        return (Coord) {.x = 27, .y = 366};
    } else if (strcmp(countryCode, "SO") == 0) {
        return (Coord) {.x = 591, .y = 313};
    } else if (strcmp(countryCode, "CZ") == 0) {
        return (Coord) {.x = 506, .y = 172};
    } else if (strcmp(countryCode, "AS") == 0) {
        return (Coord) {.x = 984, .y = 342};
    } else if (strcmp(countryCode, "SG") == 0) {
        return (Coord) {.x = 751, .y = 317};
    } else if (strcmp(countryCode, "PM") == 0) {
        return (Coord) {.x = 310, .y = 183};
    } else if (strcmp(countryCode, "TL") == 0) {
        return (Coord) {.x = 811, .y = 345};
    } else if (strcmp(countryCode, "BB") == 0) {
        return (Coord) {.x = 305, .y = 283};
    } else if (strcmp(countryCode, "CA") == 0) {
        return (Coord) {.x = 254, .y = 187};
    } else if (strcmp(countryCode, "PT") == 0) {
        return (Coord) {.x = 442, .y = 209};
    } else if (strcmp(countryCode, "PR") == 0) {
        return (Coord) {.x = 284, .y = 271};
    } else if (strcmp(countryCode, "AE") == 0) {
        return (Coord) {.x = 616, .y = 254};
    } else if (strcmp(countryCode, "KI") == 0) {
        return (Coord) {.x = 994, .y = 326};
    } else if (strcmp(countryCode, "PY") == 0) {
        return (Coord) {.x = 309, .y = 391};
    } else if (strcmp(countryCode, "EE") == 0) {
        return (Coord) {.x = 536, .y = 137};
    } else if (strcmp(countryCode, "SZ") == 0) {
        return (Coord) {.x = 552, .y = 396};
    } else if (strcmp(countryCode, "IR") == 0) {
        return (Coord) {.x = 607, .y = 221};
    } else if (strcmp(countryCode, "CF") == 0) {
        return (Coord) {.x = 516, .y = 306};
    } else if (strcmp(countryCode, "DK") == 0) {
        return (Coord) {.x = 496, .y = 152};
    } else if (strcmp(countryCode, "FO") == 0) {
        return (Coord) {.x = 444, .y = 123};
    } else if (strcmp(countryCode, "MF") == 0) {
        return (Coord) {.x = 299, .y = 272};
    } else if (strcmp(countryCode, "TC") == 0) {
        return (Coord) {.x = 267, .y = 269};
    } else if (strcmp(countryCode, "CM") == 0) {
        return (Coord) {.x = 498, .y = 310};
    } else if (strcmp(countryCode, "LB") == 0) {
        return (Coord) {.x = 564, .y = 225};
    } else if (strcmp(countryCode, "DJ") == 0) {
        return (Coord) {.x = 582, .y = 290};
    } else if (strcmp(countryCode, "VU") == 0) {
        return (Coord) {.x = 921, .y = 362};
    } else if (strcmp(countryCode, "BZ") == 0) {
        return (Coord) {.x = 222, .y = 275};
    } else if (strcmp(countryCode, "CW") == 0) {
        return (Coord) {.x = 278, .y = 286};
    } else if (strcmp(countryCode, "CR") == 0) {
        return (Coord) {.x = 235, .y = 295};
    } else if (strcmp(countryCode, "PS") == 0) {
        return (Coord) {.x = 562, .y = 231};
    } else if (strcmp(countryCode, "IL") == 0) {
        return (Coord) {.x = 563, .y = 229};
    } else if (strcmp(countryCode, "WF") == 0) {
        return (Coord) {.x = 975, .y = 355};
    } else if (strcmp(countryCode, "TZ") == 0) {
        return (Coord) {.x = 570, .y = 343};
    } else if (strcmp(countryCode, "TH") == 0) {
        return (Coord) {.x = 742, .y = 281};
    } else if (strcmp(countryCode, "ZA") == 0) {
        return (Coord) {.x = 520, .y = 417};
    } else if (strcmp(countryCode, "BT") == 0) {
        return (Coord) {.x = 714, .y = 244};
    } else if (strcmp(countryCode, "SN") == 0) {
        return (Coord) {.x = 421, .y = 281};
    } else if (strcmp(countryCode, "KN") == 0) {
        return (Coord) {.x = 295, .y = 277};
    } else if (strcmp(countryCode, "SC") == 0) {
        return (Coord) {.x = 613, .y = 330};
    } else if (strcmp(countryCode, "CU") == 0) {
        return (Coord) {.x = 242, .y = 258};
    } else if (strcmp(countryCode, "ZW") == 0) {
        return (Coord) {.x = 549, .y = 373};
    } else if (strcmp(countryCode, "BH") == 0) {
        return (Coord) {.x = 605, .y = 247};
    } else if (strcmp(countryCode, "JE") == 0) {
        return (Coord) {.x = 459, .y = 175};
    } else if (strcmp(countryCode, "CY") == 0) {
        return (Coord) {.x = 557, .y = 222};
    } else if (strcmp(countryCode, "NG") == 0) {
        return (Coord) {.x = 487, .y = 296};
    } else if (strcmp(countryCode, "ET") == 0) {
        return (Coord) {.x = 574, .y = 298};
    } else if (strcmp(countryCode, "UM") == 0) {
        return (Coord) {.x = 39, .y = 267};
    } else if (strcmp(countryCode, "AM") == 0) {
        return (Coord) {.x = 588, .y = 205};
    } else if (strcmp(countryCode, "VG") == 0) {
        return (Coord) {.x = 289, .y = 271};
    } else if (strcmp(countryCode, "VA") == 0) {
        return (Coord) {.x = 499, .y = 198};
    } else if (strcmp(countryCode, "YE") == 0) {
        return (Coord) {.x = 590, .y = 279};
    } else if (strcmp(countryCode, "NA") == 0) {
        return (Coord) {.x = 513, .y = 386};
    } else if (strcmp(countryCode, "KG") == 0) {
        return (Coord) {.x = 673, .y = 199};
    } else if (strcmp(countryCode, "VC") == 0) {
        return (Coord) {.x = 298, .y = 283};
    } else if (strcmp(countryCode, "NC") == 0) {
        return (Coord) {.x = 920, .y = 380};
    } else if (strcmp(countryCode, "IE") == 0) {
        return (Coord) {.x = 447, .y = 161};
    } else if (strcmp(countryCode, "ME") == 0) {
        return (Coord) {.x = 518, .y = 196};
    } else if (strcmp(countryCode, "AF") == 0) {
        return (Coord) {.x = 652, .y = 223};
    } else if (strcmp(countryCode, "AQ") == 0) {
        return (Coord) {.x = 639, .y = 481};
    } else if (strcmp(countryCode, "BA") == 0) {
        return (Coord) {.x = 515, .y = 192};
    } else if (strcmp(countryCode, "LK") == 0) {
        return (Coord) {.x = 687, .y = 302};
    } else if (strcmp(countryCode, "ST") == 0) {
        return (Coord) {.x = 484, .y = 323};
    } else if (strcmp(countryCode, "LI") == 0) {
        return (Coord) {.x = 494, .y = 181};
    } else if (strcmp(countryCode, "BO") == 0) {
        return (Coord) {.x = 282, .y = 364};
    } else if (strcmp(countryCode, "MA") == 0) {
        return (Coord) {.x = 445, .y = 228};
    } else if (strcmp(countryCode, "SK") == 0) {
        return (Coord) {.x = 518, .y = 176};
    } else if (strcmp(countryCode, "IM") == 0) {
        return (Coord) {.x = 453, .y = 157};
    } else if (strcmp(countryCode, "TJ") == 0) {
        return (Coord) {.x = 657, .y = 209};
    } else if (strcmp(countryCode, "TN") == 0) {
        return (Coord) {.x = 492, .y = 220};
    } else if (strcmp(countryCode, "BD") == 0) {
        return (Coord) {.x = 712, .y = 255};
    } else if (strcmp(countryCode, "BR") == 0) {
        return (Coord) {.x = 335, .y = 367};
    } else if (strcmp(countryCode, "TK") == 0) {
        return (Coord) {.x = 996, .y = 341};
    } else if (strcmp(countryCode, "AI") == 0) {
        return (Coord) {.x = 294, .y = 271};
    } else if (strcmp(countryCode, "GY") == 0) {
        return (Coord) {.x = 304, .y = 305};
    } else if (strcmp(countryCode, "PG") == 0) {
        return (Coord) {.x = 861, .y = 339};
    } else if (strcmp(countryCode, "LU") == 0) {
        return (Coord) {.x = 483, .y = 172};
    } else if (strcmp(countryCode, "NZ") == 0) {
        return (Coord) {.x = 947, .y = 440};
    } else if (strcmp(countryCode, "PL") == 0) {
        return (Coord) {.x = 523, .y = 163};
    } else if (strcmp(countryCode, "SM") == 0) {
        return (Coord) {.x = 498, .y = 193};
    } else if (strcmp(countryCode, "LV") == 0) {
        return (Coord) {.x = 533, .y = 146};
    } else if (strcmp(countryCode, "UY") == 0) {
        return (Coord) {.x = 312, .y = 418};
    } else if (strcmp(countryCode, "MZ") == 0) {
        return (Coord) {.x = 563, .y = 372};
    } else if (strcmp(countryCode, "QA") == 0) {
        return (Coord) {.x = 606, .y = 251};
    } else if (strcmp(countryCode, "SL") == 0) {
        return (Coord) {.x = 434, .y = 298};
    } else if (strcmp(countryCode, "CD") == 0) {
        return (Coord) {.x = 518, .y = 331};
    } else if (strcmp(countryCode, "SR") == 0) {
        return (Coord) {.x = 312, .y = 310};
    } else if (strcmp(countryCode, "PK") == 0) {
        return (Coord) {.x = 651, .y = 243};
    } else if (strcmp(countryCode, "BW") == 0) {
        return (Coord) {.x = 534, .y = 386};
    } else if (strcmp(countryCode, "KR") == 0) {
        return (Coord) {.x = 817, .y = 216};
    } else if (strcmp(countryCode, "AT") == 0) {
        return (Coord) {.x = 506, .y = 181};
    } else if (strcmp(countryCode, "ZM") == 0) {
        return (Coord) {.x = 543, .y = 362};
    } else if (strcmp(countryCode, "HR") == 0) {
        return (Coord) {.x = 508, .y = 190};
    } else if (strcmp(countryCode, "KP") == 0) {
        return (Coord) {.x = 813, .y = 207};
    } else if (strcmp(countryCode, "AG") == 0) {
        return (Coord) {.x = 294, .y = 276};
    } else if (strcmp(countryCode, "SY") == 0) {
        return (Coord) {.x = 570, .y = 222};
    } else if (strcmp(countryCode, "JM") == 0) {
        return (Coord) {.x = 254, .y = 272};
    } else if (strcmp(countryCode, "GL") == 0) {
        return (Coord) {.x = 345, .y = 128};
    } else if (strcmp(countryCode, "BF") == 0) {
        return (Coord) {.x = 461, .y = 287};
    } else if (strcmp(countryCode, "RS") == 0) {
        return (Coord) {.x = 523, .y = 194};
    } else if (strcmp(countryCode, "GP") == 0) {
        return (Coord) {.x = 293, .y = 279};
    } else if (strcmp(countryCode, "JP") == 0) {
        return (Coord) {.x = 848, .y = 216};
    } else if (strcmp(countryCode, "IO") == 0) {
        return (Coord) {.x = 667, .y = 326};
    } else if (strcmp(countryCode, "KE") == 0) {
        return (Coord) {.x = 568, .y = 322};
    } else if (strcmp(countryCode, "LR") == 0) {
        return (Coord) {.x = 439, .y = 305};
    } else if (strcmp(countryCode, "MD") == 0) {
        return (Coord) {.x = 544, .y = 181};
    } else if (strcmp(countryCode, "NF") == 0) {
        return (Coord) {.x = 928, .y = 398};
    } else if (strcmp(countryCode, "GH") == 0) {
        return (Coord) {.x = 463, .y = 301};
    } else if (strcmp(countryCode, "GG") == 0) {
        return (Coord) {.x = 458, .y = 173};
    } else if (strcmp(countryCode, "EG") == 0) {
        return (Coord) {.x = 551, .y = 237};
    } else if (strcmp(countryCode, "LC") == 0) {
        return (Coord) {.x = 298, .y = 283};
    } else if (strcmp(countryCode, "ES") == 0) {
        return (Coord) {.x = 456, .y = 205};
    } else if (strcmp(countryCode, "GF") == 0) {
        return (Coord) {.x = 320, .y = 310};
    } else if (strcmp(countryCode, "MX") == 0) {
        return (Coord) {.x = 190, .y = 264};
    } else if (strcmp(countryCode, "SB") == 0) {
        return (Coord) {.x = 893, .y = 339};
    } else if (strcmp(countryCode, "MV") == 0) {
        return (Coord) {.x = 672, .y = 313};
    } else if (strcmp(countryCode, "BG") == 0) {
        return (Coord) {.x = 539, .y = 196};
    } else if (strcmp(countryCode, "IN") == 0) {
        return (Coord) {.x = 677, .y = 247};
    } else if (strcmp(countryCode, "AU") == 0) {
        return (Coord) {.x = 877, .y = 418};
    } else if (strcmp(countryCode, "GM") == 0) {
        return (Coord) {.x = 423, .y = 285};
    } else if (strcmp(countryCode, "DE") == 0) {
        return (Coord) {.x = 500, .y = 163};
    } else if (strcmp(countryCode, "TT") == 0) {
        return (Coord) {.x = 298, .y = 292};
    } else if (strcmp(countryCode, "MP") == 0) {
        return (Coord) {.x = 866, .y = 281};
    } else if (strcmp(countryCode, "GI") == 0) {
        return (Coord) {.x = 451, .y = 218};
    } else if (strcmp(countryCode, "BQ") == 0) {
        return (Coord) {.x = 278, .y = 287};
    } else if (strcmp(countryCode, "ID") == 0) {
        return (Coord) {.x = 760, .y = 340};
    } else if (strcmp(countryCode, "NE") == 0) {
        return (Coord) {.x = 488, .y = 275};
    } else if (strcmp(countryCode, "GW") == 0) {
        return (Coord) {.x = 425, .y = 289};
    } else if (strcmp(countryCode, "GU") == 0) {
        return (Coord) {.x = 855, .y = 281};
    } else if (strcmp(countryCode, "US") == 0) {
        return (Coord) {.x = 250, .y = 214};
    } else if (strcmp(countryCode, "TG") == 0) {
        return (Coord) {.x = 469, .y = 299};
    } else if (strcmp(countryCode, "BJ") == 0) {
        return (Coord) {.x = 473, .y = 295};
    } else if (strcmp(countryCode, "DM") == 0) {
        return (Coord) {.x = 296, .y = 278};
    } else if (strcmp(countryCode, "HN") == 0) {
        return (Coord) {.x = 227, .y = 281};
    } else if (strcmp(countryCode, "AW") == 0) {
        return (Coord) {.x = 273, .y = 285};
    } else if (strcmp(countryCode, "MG") == 0) {
        return (Coord) {.x = 593, .y = 375};
    } else if (strcmp(countryCode, "BN") == 0) {
        return (Coord) {.x = 782, .y = 310};
    } else if (strcmp(countryCode, "SV") == 0) {
        return (Coord) {.x = 222, .y = 284};
    } else if (strcmp(countryCode, "MW") == 0) {
        return (Coord) {.x = 561, .y = 361};
    } else if (strcmp(countryCode, "HT") == 0) {
        return (Coord) {.x = 266, .y = 269};
    } else if (strcmp(countryCode, "AD") == 0) {
        return (Coord) {.x = 470, .y = 197};
    } else if (strcmp(countryCode, "GE") == 0) {
        return (Coord) {.x = 585, .y = 199};
    } else if (strcmp(countryCode, "KW") == 0) {
        return (Coord) {.x = 597, .y = 239};
    } else if (strcmp(countryCode, "GA") == 0) {
        return (Coord) {.x = 497, .y = 323};
    } else if (strcmp(countryCode, "GT") == 0) {
        return (Coord) {.x = 218, .y = 278};
    } else if (strcmp(countryCode, "LT") == 0) {
        return (Coord) {.x = 534, .y = 152};
    } else if (strcmp(countryCode, "BY") == 0) {
        return (Coord) {.x = 542, .y = 157};
    } else if (strcmp(countryCode, "BE") == 0) {
        return (Coord) {.x = 479, .y = 170};
    } else if (strcmp(countryCode, "MH") == 0) {
        return (Coord) {.x = 931, .y = 307};
    } else if (strcmp(countryCode, "BM") == 0) {
        return (Coord) {.x = 288, .y = 230};
    } else if (strcmp(countryCode, "BL") == 0) {
        return (Coord) {.x = 295, .y = 271};
    } else if (strcmp(countryCode, "IQ") == 0) {
        return (Coord) {.x = 586, .y = 225};
    } else if (strcmp(countryCode, "PW") == 0) {
        return (Coord) {.x = 833, .y = 299};
    } else if (strcmp(countryCode, "TD") == 0) {
        return (Coord) {.x = 513, .y = 285};
    } else if (strcmp(countryCode, "YT") == 0) {
        return (Coord) {.x = 588, .y = 355};
    } else if (strcmp(countryCode, "CL") == 0) {
        return (Coord) {.x = 271, .y = 418};
    } else if (strcmp(countryCode, "AO") == 0) {
        return (Coord) {.x = 508, .y = 350};
    } else if (strcmp(countryCode, "MS") == 0) {
        return (Coord) {.x = 295, .y = 278};
    } else if (strcmp(countryCode, "PF") == 0) {
        return (Coord) {.x = 44, .y = 374};
    } else if (strcmp(countryCode, "NI") == 0) {
        return (Coord) {.x = 232, .y = 286};
    } else if (strcmp(countryCode, "RE") == 0) {
        return (Coord) {.x = 618, .y = 382};
    } else if (strcmp(countryCode, "BS") == 0) {
        return (Coord) {.x = 252, .y = 254};
    } else if (strcmp(countryCode, "GB") == 0) {
        return (Coord) {.x = 464, .y = 164};
    } else if (strcmp(countryCode, "WS") == 0) {
        return (Coord) {.x = 981, .y = 354};
    } else if (strcmp(countryCode, "NU") == 0) {
        return (Coord) {.x = 8, .y = 365};
    } else if (strcmp(countryCode, "HU") == 0) {
        return (Coord) {.x = 518, .y = 181};
    } else if (strcmp(countryCode, "LA") == 0) {
        return (Coord) {.x = 747, .y = 269};
    } else if (strcmp(countryCode, "SX") == 0) {
        return (Coord) {.x = 298, .y = 271};
    } else if (strcmp(countryCode, "MC") == 0) {
        return (Coord) {.x = 485, .y = 195};
    } else if (strcmp(countryCode, "FJ") == 0) {
        return (Coord) {.x = 952, .y = 367};
    } else if (strcmp(countryCode, "IS") == 0) {
        return (Coord) {.x = 409, .y = 114};
    } else if (strcmp(countryCode, "KY") == 0) {
        return (Coord) {.x = 242, .y = 270};
    } else if (strcmp(countryCode, "NR") == 0) {
        return (Coord) {.x = 909, .y = 320};
    } else if (strcmp(countryCode, "GR") == 0) {
        return (Coord) {.x = 528, .y = 209};
    } else if (strcmp(countryCode, "SI") == 0) {
        return (Coord) {.x = 506, .y = 186};
    } else if (strcmp(countryCode, "LY") == 0) {
        return (Coord) {.x = 503, .y = 231};
    } else if (strcmp(countryCode, "MR") == 0) {
        return (Coord) {.x = 429, .y = 268};
    } else if (strcmp(countryCode, "VE") == 0) {
        return (Coord) {.x = 281, .y = 295};
    } else if (strcmp(countryCode, "TO") == 0) {
        return (Coord) {.x = 979, .y = 371};
    } else if (strcmp(countryCode, "CG") == 0) {
        return (Coord) {.x = 520, .y = 333};
    } else if (strcmp(countryCode, "TW") == 0) {
        return (Coord) {.x = 798, .y = 254};
    } else if (strcmp(countryCode, "GN") == 0) {
        return (Coord) {.x = 430, .y = 292};
    } else if (strcmp(countryCode, "EC") == 0) {
        return (Coord) {.x = 249, .y = 325};
    } else if (strcmp(countryCode, "IT") == 0) {
        return (Coord) {.x = 499, .y = 196};
    } else if (strcmp(countryCode, "GQ") == 0) {
        return (Coord) {.x = 495, .y = 318};
    } else if (strcmp(countryCode, "UZ") == 0) {
        return (Coord) {.x = 646, .y = 203};
    } else if (strcmp(countryCode, "TM") == 0) {
        return (Coord) {.x = 628, .y = 209};
    } else if (strcmp(countryCode, "RU") == 0) {
        return (Coord) {.x = 568, .y = 148};
    } else if (strcmp(countryCode, "JO") == 0) {
        return (Coord) {.x = 565, .y = 234};
    } else if (strcmp(countryCode, "AR") == 0) {
        return (Coord) {.x = 285, .y = 414};
    } else if (strcmp(countryCode, "TR") == 0) {
        return (Coord) {.x = 555, .y = 207};
    } else if (strcmp(countryCode, "KH") == 0) {
        return (Coord) {.x = 753, .y = 289};
    } else if (strcmp(countryCode, "AZ") == 0) {
        return (Coord) {.x = 601, .y = 205};
    } else if (strcmp(countryCode, "NO") == 0) {
        return (Coord) {.x = 492, .y = 131};
    } else if (strcmp(countryCode, "TV") == 0) {
        return (Coord) {.x = 961, .y = 333};
    } else if (strcmp(countryCode, "MM") == 0) {
        return (Coord) {.x = 729, .y = 263};
    } else if (strcmp(countryCode, "FK") == 0) {
        return (Coord) {.x = 302, .y = 479};
    } else if (strcmp(countryCode, "OM") == 0) {
        return (Coord) {.x = 624, .y = 261};
    } else if (strcmp(countryCode, "NL") == 0) {
        return (Coord) {.x = 480, .y = 163};
    } else if (strcmp(countryCode, "VN") == 0) {
        return (Coord) {.x = 756, .y = 263};
    } else if (strcmp(countryCode, "DO") == 0) {
        return (Coord) {.x = 272, .y = 269};
    } else if (strcmp(countryCode, "RO") == 0) {
        return (Coord) {.x = 537, .y = 188};
    } else if (strcmp(countryCode, "KM") == 0) {
        return (Coord) {.x = 585, .y = 351};
    } else if (strcmp(countryCode, "ML") == 0) {
        return (Coord) {.x = 448, .y = 284};
    } else if (strcmp(countryCode, "SD") == 0) {
        return (Coord) {.x = 555, .y = 272};
    } else if (strcmp(countryCode, "ER") == 0) {
        return (Coord) {.x = 571, .y = 279};
    } else if (strcmp(countryCode, "MY") == 0) {
        return (Coord) {.x = 748, .y = 312};
    } else if (strcmp(countryCode, "PE") == 0) {
        return (Coord) {.x = 257, .y = 353};
    } else if (strcmp(countryCode, "UA") == 0) {
        return (Coord) {.x = 550, .y = 171};
    } else if (strcmp(countryCode, "GD") == 0) {
        return (Coord) {.x = 295, .y = 284};
    } else if (strcmp(countryCode, "MO") == 0) {
        return (Coord) {.x = 777, .y = 269};
    } else if (strcmp(countryCode, "RW") == 0) {
        return (Coord) {.x = 548, .y = 326};
    } else if (strcmp(countryCode, "UG") == 0) {
        return (Coord) {.x = 555, .y = 320};
    } else if (strcmp(countryCode, "CI") == 0) {
        return (Coord) {.x = 452, .y = 304};
    } else if (strcmp(countryCode, "AX") == 0) {
        return (Coord) {.x = 520, .y = 132};
    } else if (strcmp(countryCode, "MT") == 0) {
        return (Coord) {.x = 505, .y = 219};
    } else if (strcmp(countryCode, "FR") == 0) {
        return (Coord) {.x = 471, .y = 178};
    }

    return (Coord) {.x = 0, .y = 0};
}

