/* Random Forest Model converted by m2cgen */
#ifndef MODEL_H
#define MODEL_H

#include <string.h>
void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[3];
    double var1[3];
    double var2[3];
    double var3[3];
    double var4[3];
    double var5[3];
    double var6[3];
    double var7[3];
    double var8[3];
    double var9[3];
    double var10[3];
    double var11[3];
    double var12[3];
    double var13[3];
    double var14[3];
    double var15[3];
    if (input[5] <= 32.04999923706055) {
        if (input[5] <= 19.15000057220459) {
            if (input[8] <= 2.5) {
                if (input[3] <= 0.5550000071525574) {
                    if (input[1] <= 45.45000076293945) {
                        memcpy(var15, (double[]){0.0, 0.0578534861595615, 0.9421465138404386}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.5334852199247856, 0.1455463427469352, 0.3209684373282793}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 24.97651767730713) {
                        memcpy(var15, (double[]){0.05309805792352545, 0.3380137189915364, 0.6088882230849381}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.0, 0.10182195112227405, 0.898178048877726}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 1.1050000190734863) {
                    if (input[0] <= 18.65000057220459) {
                        memcpy(var15, (double[]){0.6360758554547992, 0.2272485992532437, 0.13667554529195716}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.08044940685338625, 0.2834994389230409, 0.6360511542235728}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 6.549999952316284) {
                        memcpy(var15, (double[]){0.09290414986081115, 0.5702910249390127, 0.33680482520017613}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.1538358224292896, 0.2929138805891796, 0.5532502969815308}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 29.75) {
                if (input[7] <= 1.5) {
                    if (input[1] <= 24.050000190734863) {
                        memcpy(var15, (double[]){0.0, 0.8363066188925902, 0.16369338110740986}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.34481182932706345, 0.3716053474983339, 0.28358282317460265}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 2.5) {
                        memcpy(var15, (double[]){0.45083707852897376, 0.32799503093440835, 0.2211678905366179}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.2227498299274152, 0.25321244371437274, 0.524037726358212}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 26.65000057220459) {
                    if (input[1] <= 32.60000038146973) {
                        memcpy(var15, (double[]){0.41168258755552545, 0.48670241510892126, 0.10161499733555336}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.09985242443270542, 0.25495631688343673, 0.645191258683858}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.2849999964237213) {
                        memcpy(var15, (double[]){0.06580664921720064, 0.557305993788947, 0.37688735699385245}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.35086079419895516, 0.40105928507892996, 0.24807992072211477}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 17.84999942779541) {
            if (input[0] <= 33.75) {
                if (input[5] <= 36.25) {
                    if (input[10] <= -2.25) {
                        memcpy(var15, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.0, 0.7971596894385705, 0.2028403105614295}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var15, (double[]){0.45086856294165406, 0.41002242077094453, 0.1391090162874015}, 3 * sizeof(double));
                }
            } else {
                if (input[9] <= 24.661900520324707) {
                    if (input[10] <= -1.9500000476837158) {
                        memcpy(var15, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9402002508711986, 0.03562597603801234, 0.024173773090789104}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var15, (double[]){0.9462189462189462, 0.053781053781053786, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[7] <= 1.5) {
                if (input[4] <= 1.25) {
                    if (input[2] <= 1.340000033378601) {
                        memcpy(var15, (double[]){0.3984141896770523, 0.38690612504406013, 0.21467968527888753}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.0, 0.8103855748610442, 0.1896144251389558}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 21.443635940551758) {
                        memcpy(var15, (double[]){0.35239648525121436, 0.26705946372182815, 0.3805440510269574}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.0, 0.4890078539945855, 0.5109921460054145}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -7.700000047683716) {
                    if (input[2] <= 0.7749999761581421) {
                        memcpy(var15, (double[]){0.16017505006418017, 0.36416024076911124, 0.47566470916670855}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.7874209958378295, 0.0, 0.21257900416217052}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 1.4449999928474426) {
                        memcpy(var15, (double[]){0.7532244633855881, 0.17124664660930275, 0.07552889000510926}, 3 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.0, 0.911631227372393, 0.08836877262760695}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    double var16[3];
    if (input[8] <= 0.5) {
        if (input[10] <= -14.75) {
            if (input[10] <= -18.0) {
                memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if (input[6] <= 0.5) {
                    memcpy(var16, (double[]){0.0, 0.8155401809473125, 0.1844598190526876}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 41.85000038146973) {
                        memcpy(var16, (double[]){0.0, 0.41238112153456175, 0.5876188784654384}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.0, 0.7164262839243555, 0.2835737160756446}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 35.35000038146973) {
                if (input[9] <= 18.657421112060547) {
                    if (input[0] <= 27.65000057220459) {
                        memcpy(var16, (double[]){0.41979243453919124, 0.3499481460459424, 0.23025941941486644}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.7139544590462064, 0.1724634653307664, 0.11358207562302723}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 38.39999961853027) {
                        memcpy(var16, (double[]){0.3535338831147002, 0.4791065519833731, 0.16735956490192672}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.7065555374051091, 0.20079550038777622, 0.09264896220711472}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -2.549999952316284) {
                    memcpy(var16, (double[]){0.6874256247520825, 0.31257437524791754, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[3] <= 0.5199999809265137) {
                        memcpy(var16, (double[]){0.8312619572294286, 0.12599238743927482, 0.04274565533129664}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.986802880589516, 0.013197119410484006, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 31.949999809265137) {
            if (input[0] <= 19.25) {
                if (input[10] <= 0.15000000223517418) {
                    if (input[6] <= 0.5) {
                        memcpy(var16, (double[]){0.11481690998139696, 0.5220757360954461, 0.36310735392315685}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.7695792656305069, 0.18590024239732889, 0.04452049197216422}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 60.85000038146973) {
                        memcpy(var16, (double[]){0.166073456435316, 0.4672433094140173, 0.3666832341506667}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.6591001897416903, 0.26972524787351804, 0.07117456238479178}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 18.800000190734863) {
                    if (input[5] <= 15.599999904632568) {
                        memcpy(var16, (double[]){0.01927347134810757, 0.35931177860049585, 0.6214147500513966}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.10322240788068317, 0.26336042182496033, 0.6334171702943565}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 41.54999923706055) {
                        memcpy(var16, (double[]){0.34206720807395585, 0.34885159273001004, 0.30908119919603405}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.20364242912007063, 0.34697187344911706, 0.4493856974308123}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[4] <= 1.1500000357627869) {
                if (input[5] <= 38.04999923706055) {
                    if (input[10] <= 6.450000047683716) {
                        memcpy(var16, (double[]){0.5553611586613082, 0.3171235258572443, 0.12751531548144757}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9340214964800029, 0.016988088614569935, 0.04899041490542726}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 36.04999923706055) {
                        memcpy(var16, (double[]){0.9000623799187073, 0.040926090904555186, 0.05901152917673749}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.44435897435897437, 0.5556410256410257, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 1.1399999856948853) {
                    if (input[9] <= 18.546615600585938) {
                        memcpy(var16, (double[]){0.7319613001072057, 0.16641243637751824, 0.10162626351527611}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.3335820728055011, 0.5056023723230139, 0.16081555487148513}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 34.5) {
                        memcpy(var16, (double[]){0.43648587452949944, 0.49617840324472823, 0.06733572222577243}, 3 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.956507340766089, 0.04349265923391103, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var15, var16, 3, var14);
    double var17[3];
    if (input[3] <= 0.574999988079071) {
        if (input[2] <= 0.4950000047683716) {
            if (input[1] <= 73.54999923706055) {
                if (input[6] <= 0.5) {
                    if (input[7] <= 2.5) {
                        memcpy(var17, (double[]){0.3302936342353469, 0.30478811786165233, 0.3649182479030007}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.11814775408243514, 0.881852245917565}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 20.65000057220459) {
                        memcpy(var17, (double[]){0.0, 0.6862102600945056, 0.3137897399054945}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.4310966388872726, 0.37130874558516197, 0.19759461552756544}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[6] <= 0.5) {
                    if (input[3] <= 0.5149999856948853) {
                        memcpy(var17, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.5077823221995, 0.4922176778004999}, 3 * sizeof(double));
                    }
                } else {
                    if (input[7] <= 1.5) {
                        memcpy(var17, (double[]){0.0, 0.7411523213287414, 0.2588476786712585}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.35956005279366476, 0.6404399472063352}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 1.3899999856948853) {
                if (input[10] <= -11.549999713897705) {
                    if (input[3] <= 0.39000000059604645) {
                        memcpy(var17, (double[]){0.0, 0.9464809610574102, 0.053519038942589796}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.4095163650211453, 0.5904836349788547}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 1.3499999642372131) {
                        memcpy(var17, (double[]){0.6460324815143698, 0.2423460566834919, 0.1116214618021384}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.474641981503383, 0.40221195872662474, 0.1231460597699921}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -1.149999976158142) {
                    if (input[2] <= 1.5549999475479126) {
                        memcpy(var17, (double[]){0.0, 0.9763396818895488, 0.023660318110451228}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.7022029762518471, 0.29779702374815276}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 31.0) {
                        memcpy(var17, (double[]){0.765397613321407, 0.0870071147284, 0.147595271950193}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.8805074812107839, 0.11949251878921602}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[5] <= 18.550000190734863) {
            if (input[4] <= 1.449999988079071) {
                if (input[1] <= 41.54999923706055) {
                    if (input[2] <= 0.004999999888241291) {
                        memcpy(var17, (double[]){0.0, 0.6919006781182009, 0.30809932188179917}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.23015446050964725, 0.2495544924909966, 0.520291046999356}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 20.84999942779541) {
                        memcpy(var17, (double[]){0.14490910846060848, 0.4694703920669857, 0.38562049947240584}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.01710411194052838, 0.2955369463053558, 0.6873589417541158}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 0.7549999952316284) {
                    memcpy(var17, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 19.149999618530273) {
                        memcpy(var17, (double[]){0.0, 0.5957546069512479, 0.404245393048752}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 0.15353517136695305, 0.846464828633047}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 43.85000038146973) {
                if (input[1] <= 27.84999942779541) {
                    if (input[4] <= 1.25) {
                        memcpy(var17, (double[]){0.20128703254647332, 0.48508664900582293, 0.31362631844770367}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.6187894104389001, 0.035170661816636854, 0.3460399277444631}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 23.460216522216797) {
                        memcpy(var17, (double[]){0.5892783096907334, 0.25576712660027945, 0.1549545637089873}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.32741278197496587, 0.40320452713881877, 0.2693826908862154}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -3.25) {
                    if (input[0] <= 30.15000057220459) {
                        memcpy(var17, (double[]){0.1489439424377091, 0.2950885098135278, 0.5559675477487631}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.6510895471319197, 0.14802612900748782, 0.20088432386059235}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 32.650001525878906) {
                        memcpy(var17, (double[]){0.26147583537795827, 0.43311313462078177, 0.30541103000126}, 3 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.9402002508711986, 0.03562597603801234, 0.024173773090789104}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var14, var17, 3, var13);
    double var18[3];
    if (input[2] <= 0.24499999731779099) {
        if (input[1] <= 36.54999923706055) {
            if (input[1] <= 33.54999923706055) {
                if (input[10] <= 2.950000047683716) {
                    if (input[1] <= 28.800000190734863) {
                        memcpy(var18, (double[]){0.6359106488310453, 0.21261056620568874, 0.15147878496326592}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.13413752532912637, 0.4726935182833092, 0.3931689563875644}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 18.334083557128906) {
                        memcpy(var18, (double[]){0.0, 0.7022029762518474, 0.29779702374815276}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0501385277728455, 0.3020752270492093, 0.6477862451779451}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[9] <= 19.28702449798584) {
                    if (input[0] <= 19.300000190734863) {
                        memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.8532187144737241, 0.07274268035977655, 0.07403860516649927}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 20.75763702392578) {
                        memcpy(var18, (double[]){0.0, 0.49558552440089265, 0.5044144755991073}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.5942566958768095, 0.14738738173978677, 0.25835592238340377}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 29.399999618530273) {
                if (input[10] <= -5.8500001430511475) {
                    if (input[1] <= 47.54999923706055) {
                        memcpy(var18, (double[]){0.0, 0.5352927941117548, 0.46470720588824527}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 0.181738263515442, 0.818261736484558}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 1.5) {
                        memcpy(var18, (double[]){0.2446025643542595, 0.2183738767856121, 0.5370235588601283}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.14860289718520497, 0.4377983122641847, 0.41359879055061033}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 1.3499999642372131) {
                    if (input[0] <= 34.14999961853027) {
                        memcpy(var18, (double[]){0.5413996369749632, 0.31858063564026884, 0.14001972738476806}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.823482548484288, 0.07488796863307778, 0.10162948288263413}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 30.100000381469727) {
                        memcpy(var18, (double[]){0.0, 0.2467036947597199, 0.7532963052402801}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 0.5581496995082863, 0.44185030049171364}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 33.95000076293945) {
            if (input[9] <= 17.86974048614502) {
                if (input[2] <= 0.32500000298023224) {
                    if (input[10] <= 0.5) {
                        memcpy(var18, (double[]){0.7411067226294227, 0.13639801138053675, 0.12249526599004046}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 0.4955855244008926, 0.5044144755991075}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 15.65670108795166) {
                        memcpy(var18, (double[]){0.0, 0.843841047667678, 0.1561589523323221}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.5332101312122086, 0.24245215429614558, 0.2243377144916459}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 31.75) {
                    if (input[9] <= 20.491947174072266) {
                        memcpy(var18, (double[]){0.04994953396176418, 0.7381463154995848, 0.21190415053865094}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.33398166530465645, 0.5011459448691452, 0.1648723898261983}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 32.25) {
                        memcpy(var18, (double[]){0.3220175967532126, 0.3732737806272392, 0.3047086226195482}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.4984545786053765, 0.30161712447866884, 0.19992829691595468}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[3] <= 0.5550000071525574) {
                if (input[3] <= 0.42499999701976776) {
                    if (input[0] <= 35.35000038146973) {
                        memcpy(var18, (double[]){0.550652908478355, 0.4068730809616466, 0.04247401055999841}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.8384298035094893, 0.12707880076273853, 0.03449139572777226}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 35.85000038146973) {
                        memcpy(var18, (double[]){0.5677903966050202, 0.3227198734310126, 0.10948972996396727}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.15099233661565578, 0.7208947450420865, 0.1281129183422577}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[6] <= 0.5) {
                    if (input[1] <= 41.849998474121094) {
                        memcpy(var18, (double[]){0.7345794287049602, 0.20875958951944198, 0.05666098177559795}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.2593314756458067, 0.5306343985228106, 0.21003412583138262}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.3149999976158142) {
                        memcpy(var18, (double[]){0.0, 0.7466744627978367, 0.2533255372021634}, 3 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.7371829830548575, 0.1641791935128827, 0.09863782343225977}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var13, var18, 3, var12);
    double var19[3];
    if (input[0] <= 28.449999809265137) {
        if (input[9] <= 18.09440517425537) {
            if (input[2] <= 0.024999999441206455) {
                if (input[3] <= 0.9350000023841858) {
                    if (input[3] <= 0.5249999761581421) {
                        memcpy(var19, (double[]){0.619954749464343, 0.14094758874146057, 0.23909766179419648}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.32942086934090037, 0.6705791306590997}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 3.100000023841858) {
                        memcpy(var19, (double[]){0.0, 0.9725047200495011, 0.027495279950498976}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -0.3500000089406967) {
                    if (input[2] <= 0.2849999964237213) {
                        memcpy(var19, (double[]){0.6939680519945853, 0.09860913606674357, 0.2074228119386711}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.3591612158623461, 0.31301393904064057, 0.32782484509701326}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 17.55322551727295) {
                        memcpy(var19, (double[]){0.12234464045729626, 0.5284893124427695, 0.34916604709993426}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[8] <= 0.5) {
                if (input[3] <= 0.5149999856948853) {
                    if (input[9] <= 23.579970359802246) {
                        memcpy(var19, (double[]){0.3969702302586744, 0.4247140849853506, 0.17831568475597492}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.6596398082502503, 0.20710148789787483, 0.13325870385187488}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 46.55000114440918) {
                        memcpy(var19, (double[]){0.04844670334172512, 0.6002862440028064, 0.3512670526554684}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.6184019370460049, 0.0, 0.3815980629539952}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 1.5) {
                    if (input[1] <= 75.14999771118164) {
                        memcpy(var19, (double[]){0.1819743028484158, 0.2492177404519526, 0.5688079566996316}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.33007963277302255, 0.6699203672269775}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 5.6499998569488525) {
                        memcpy(var19, (double[]){0.2908462953804339, 0.40052443097085144, 0.3086292736487146}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.10127609669084106, 0.29274978209224567, 0.6059741212169132}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[4] <= 1.449999988079071) {
            if (input[3] <= 0.4449999928474426) {
                if (input[2] <= 0.5550000071525574) {
                    if (input[5] <= 36.39999961853027) {
                        memcpy(var19, (double[]){0.3271745343339477, 0.48011228156417424, 0.19271318410187804}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.837542160175362, 0.14810163991560227, 0.014356199909035614}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 41.25) {
                        memcpy(var19, (double[]){0.11780878181654876, 0.7231678135974874, 0.1590234045859639}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.37123089362158973, 0.38823939503737404, 0.24052971134103626}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 32.64999961853027) {
                    if (input[1] <= 57.60000038146973) {
                        memcpy(var19, (double[]){0.5485528845625924, 0.3100040520490732, 0.1414430633883344}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.3999640643167399, 0.27279718639491435, 0.32723874928834584}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -4.700000047683716) {
                        memcpy(var19, (double[]){0.4548861773048927, 0.3345909324937044, 0.2105228902014028}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.716235232300714, 0.21551968142105926, 0.0682450862782268}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[10] <= -3.350000023841858) {
                if (input[1] <= 28.550000190734863) {
                    memcpy(var19, (double[]){0.567138265132355, 0.25787937272030914, 0.17498236214733584}, 3 * sizeof(double));
                } else {
                    memcpy(var19, (double[]){0.7642130460801915, 0.0, 0.2357869539198085}, 3 * sizeof(double));
                }
            } else {
                if (input[1] <= 32.29999923706055) {
                    if (input[2] <= 0.42000000178813934) {
                        memcpy(var19, (double[]){0.0, 0.9636725710093282, 0.03632742899067184}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.9218136702007669, 0.07818632979923301}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 30.34999942779541) {
                        memcpy(var19, (double[]){0.0, 0.3378108282875787, 0.6621891717124213}, 3 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 0.734273776210373, 0.265726223789627}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var12, var19, 3, var11);
    double var20[3];
    if (input[2] <= 0.22500000149011612) {
        if (input[1] <= 40.95000076293945) {
            if (input[10] <= 3.25) {
                if (input[9] <= 23.11604595184326) {
                    if (input[5] <= 18.300000190734863) {
                        memcpy(var20, (double[]){0.0, 0.8477346167738913, 0.1522653832261088}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.3280128786023464, 0.3588882974263555, 0.31309882397129823}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 21.799999237060547) {
                        memcpy(var20, (double[]){0.6437148455209951, 0.20732843024137454, 0.14895672423763037}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.2350789944530937, 0.3206732503676362, 0.4442477551792701}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[9] <= 19.86628246307373) {
                    if (input[4] <= 1.1500000357627869) {
                        memcpy(var20, (double[]){0.611640984393743, 0.18077467524897584, 0.20758434035728116}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.0, 0.3518944985729753, 0.6481055014270248}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 23.487722396850586) {
                        memcpy(var20, (double[]){0.038193504192280694, 0.25181706803289045, 0.7099894277748289}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.19716377780359776, 0.32124915594812015, 0.481587066248282}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 18.65000057220459) {
                if (input[8] <= 2.5) {
                    if (input[9] <= 27.37793731689453) {
                        memcpy(var20, (double[]){0.1376880093137503, 0.21564677127116058, 0.6466652194150891}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.0, 0.08315087782127778, 0.9168491221787223}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 16.550000190734863) {
                        memcpy(var20, (double[]){0.02354131930544904, 0.4335243302447205, 0.5429343504498304}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.0, 0.8155401809473124, 0.1844598190526876}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 1.5) {
                    if (input[1] <= 70.85000228881836) {
                        memcpy(var20, (double[]){0.17418434335211155, 0.2687214562554421, 0.5570942003924463}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.36522508424001554, 0.38749404975339974, 0.24728086600658478}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.1500000357627869) {
                        memcpy(var20, (double[]){0.02607293177870456, 0.5334946110056916, 0.4404324572156038}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.34299004100964353, 0.3704015359201084, 0.28660842307024803}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 0.4950000047683716) {
            if (input[10] <= 4.049999952316284) {
                if (input[1] <= 21.84999942779541) {
                    if (input[1] <= 17.0) {
                        memcpy(var20, (double[]){0.0, 0.868970210192046, 0.13102978980795404}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.777883605273154, 0.16211519259731919, 0.06000120212952677}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -12.550000190734863) {
                        memcpy(var20, (double[]){0.0, 0.5067976323821611, 0.4932023676178389}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.2886195919566737, 0.4351514265829607, 0.2762289814603656}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 33.95000076293945) {
                    if (input[0] <= 27.25) {
                        memcpy(var20, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.2695489313749113, 0.4289763143289125, 0.30147475429617615}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.7049999833106995) {
                        memcpy(var20, (double[]){0.7906553053530507, 0.12358266349538811, 0.08576203115156118}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.267353380438443, 0.5470485210817766, 0.18559809847978054}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 37.04999923706055) {
                if (input[9] <= 23.134521484375) {
                    if (input[9] <= 22.135525703430176) {
                        memcpy(var20, (double[]){0.46693757912630784, 0.3630635020895079, 0.1699989187841843}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.05783024446152724, 0.6968327552484777, 0.24533700028999506}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.25) {
                        memcpy(var20, (double[]){0.6249333291970813, 0.22388281048085823, 0.15118386032206052}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.13758420659555157, 0.4379194942764354, 0.4244962991280131}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 38.80000114440918) {
                    if (input[7] <= 1.5) {
                        memcpy(var20, (double[]){0.0, 0.7865237743286524, 0.21347622567134764}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.7315275526252097, 0.1330510586194265, 0.1354213887553638}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 19.600000381469727) {
                        memcpy(var20, (double[]){0.9887601985508073, 0.011239801449192675, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.7665858585368734, 0.17428437868639826, 0.059129762776728295}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var11, var20, 3, var10);
    double var21[3];
    if (input[2] <= 0.17500000447034836) {
        if (input[1] <= 35.54999923706055) {
            if (input[5] <= 19.15000057220459) {
                if (input[7] <= 1.5) {
                    if (input[1] <= 31.899999618530273) {
                        memcpy(var21, (double[]){0.0, 0.16893489656540941, 0.8310651034345905}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.11823314444251072, 0.6720118134787828, 0.20975504207870635}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 25.656320571899414) {
                        memcpy(var21, (double[]){0.06843597124066385, 0.1555901481178393, 0.7759738806414969}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.1268826684152032, 0.43270431063695963, 0.44041302094783713}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 33.900001525878906) {
                    if (input[10] <= 3.149999976158142) {
                        memcpy(var21, (double[]){0.4151772261594139, 0.36812540433730834, 0.21669736950327778}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.0, 0.25469798866873194, 0.745302011331268}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var21, (double[]){0.8469827516095915, 0.12035170374140906, 0.03266554464899952}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[3] <= 0.4099999964237213) {
                if (input[5] <= 22.949999809265137) {
                    memcpy(var21, (double[]){0.8818561752299039, 0.05012281203701416, 0.06802101273308186}, 3 * sizeof(double));
                } else {
                    if (input[5] <= 32.25) {
                        memcpy(var21, (double[]){0.0, 0.6761453888560128, 0.3238546111439873}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.5562492903271536, 0.37939218763225374, 0.06435852204059275}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 31.5) {
                    if (input[0] <= 19.15000057220459) {
                        memcpy(var21, (double[]){0.3104916749232161, 0.4042923125921455, 0.28521601248463835}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.13041010430803027, 0.29790106920407305, 0.5716888264878968}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 36.04999923706055) {
                        memcpy(var21, (double[]){0.8455292523440077, 0.11533936252401815, 0.03913138513197405}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.3970812467366555, 0.5416618968756225, 0.06125685638772211}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 34.14999961853027) {
            if (input[8] <= 0.5) {
                if (input[2] <= 0.2849999964237213) {
                    if (input[9] <= 17.794058799743652) {
                        memcpy(var21, (double[]){0.7963286558637532, 0.060348815235683556, 0.1433225289005633}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.04381088137209101, 0.5777070173773939, 0.37848210125051507}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -12.050000190734863) {
                        memcpy(var21, (double[]){0.0, 0.5572240993738895, 0.44277590062611044}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.5100204064879129, 0.34464064077574946, 0.14533895273633773}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 28.550000190734863) {
                    if (input[2] <= 0.19500000029802322) {
                        memcpy(var21, (double[]){0.5209604727681669, 0.17766164997460282, 0.3013778772572303}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.20985073242143437, 0.38008855682240483, 0.41006071075616085}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.4449999928474426) {
                        memcpy(var21, (double[]){0.11431916000891294, 0.6064478617129869, 0.27923297827810023}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.4201915867682572, 0.34822645470462144, 0.2315819585271214}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[3] <= 0.7350000143051147) {
                if (input[9] <= 16.620407104492188) {
                    memcpy(var21, (double[]){0.0, 0.8805074812107839, 0.11949251878921602}, 3 * sizeof(double));
                } else {
                    if (input[2] <= 0.7350000143051147) {
                        memcpy(var21, (double[]){0.7083730328253762, 0.20892922438504574, 0.08269774278957805}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.4768814504805715, 0.3686268846299905, 0.15449166488943802}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 35.5) {
                    if (input[10] <= 4.950000047683716) {
                        memcpy(var21, (double[]){0.0, 0.7747107509641635, 0.22528924903583653}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.6660581562133263, 0.0, 0.33394184378667363}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 44.5) {
                        memcpy(var21, (double[]){0.0, 0.7164262839243554, 0.2835737160756446}, 3 * sizeof(double));
                    } else {
                        memcpy(var21, (double[]){0.0, 0.9364573020936457, 0.06354269790635426}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var10, var21, 3, var9);
    double var22[3];
    if (input[0] <= 29.25) {
        if (input[5] <= 18.949999809265137) {
            if (input[1] <= 85.5) {
                if (input[8] <= 2.5) {
                    if (input[2] <= 0.11499999836087227) {
                        memcpy(var22, (double[]){0.056163228840088286, 0.27452897374748286, 0.669307797412429}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 60.80000114440918) {
                        memcpy(var22, (double[]){0.14045601034903205, 0.3619058885623453, 0.49763810108862266}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.5571334557124493, 0.22799714182993025, 0.2148694024576204}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 20.449999809265137) {
                    memcpy(var22, (double[]){0.8673645911073586, 0.06573218867018644, 0.06690322022245483}, 3 * sizeof(double));
                } else {
                    memcpy(var22, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[5] <= 28.449999809265137) {
                if (input[0] <= 19.449999809265137) {
                    if (input[3] <= 0.9550000131130219) {
                        memcpy(var22, (double[]){0.43088840871945183, 0.3918523555348275, 0.17725923574572064}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.9129045202271328, 0.051887533319314824, 0.035207946453552304}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 26.548129081726074) {
                        memcpy(var22, (double[]){0.29502491371334005, 0.41964453378232075, 0.28533055250433914}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.6204740879998947, 0.18808754812229928, 0.19143836387780605}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 37.45000076293945) {
                    if (input[0] <= 20.949999809265137) {
                        memcpy(var22, (double[]){0.8259953423384939, 0.1669255189492167, 0.007079138712289363}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.33382511080332977, 0.4186499826008141, 0.24752490659585608}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.17500000447034836) {
                        memcpy(var22, (double[]){0.0723643205945585, 0.3317846335857845, 0.5958510458196571}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.24778413731240956, 0.35249034823408804, 0.3997255144535024}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[5] <= 36.45000076293945) {
            if (input[0] <= 34.25) {
                if (input[4] <= 1.25) {
                    if (input[3] <= 0.4449999928474426) {
                        memcpy(var22, (double[]){0.3092947038812441, 0.51098174083031, 0.17972355528844602}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.5319627453746413, 0.28723839525927325, 0.1807988593660855}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.7950000166893005) {
                        memcpy(var22, (double[]){0.0, 0.6509280003288597, 0.34907199967114033}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.7665858585368736, 0.17428437868639826, 0.05912976277672831}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= 7.1499998569488525) {
                    if (input[10] <= 6.3500001430511475) {
                        memcpy(var22, (double[]){0.5891543121865518, 0.28849706476284076, 0.12234862305060752}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.0, 0.6627311060655207, 0.33726889393447945}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.199999988079071) {
                        memcpy(var22, (double[]){0.928722270953165, 0.020109173453990988, 0.05116855559284413}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.0, 0.4692840080847676, 0.5307159919152324}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[10] <= -8.150000095367432) {
                if (input[3] <= 0.5349999964237213) {
                    if (input[1] <= 42.20000076293945) {
                        memcpy(var22, (double[]){0.0, 0.8983994840827813, 0.1016005159172187}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.0, 0.7971596894385705, 0.2028403105614295}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.6899999976158142) {
                        memcpy(var22, (double[]){0.1651695391366376, 0.33796375405569357, 0.4968667068076689}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.8663500678426052, 0.0, 0.13364993215739485}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -2.950000047683716) {
                    if (input[10] <= -3.350000023841858) {
                        memcpy(var22, (double[]){0.7773851270104913, 0.14656455267803672, 0.07605032031147191}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.0, 0.9401911949106723, 0.059808805089327836}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.7750000059604645) {
                        memcpy(var22, (double[]){0.9366247785215231, 0.047320659452135684, 0.016054562026341257}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.6807775598996121, 0.25795956780193036, 0.06126287229845765}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var9, var22, 3, var8);
    double var23[3];
    if (input[3] <= 0.5649999976158142) {
        if (input[5] <= 38.54999923706055) {
            if (input[4] <= 1.050000011920929) {
                if (input[3] <= 0.19500000029802322) {
                    memcpy(var23, (double[]){0.8136884944887137, 0.11099593773637159, 0.07531556777491462}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 78.6500015258789) {
                        memcpy(var23, (double[]){0.3089222822832772, 0.4799317703408418, 0.211145947375881}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.0, 0.8633142161778458, 0.13668578382215413}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= 3.049999952316284) {
                    if (input[2] <= 0.29500000178813934) {
                        memcpy(var23, (double[]){0.10112787940936281, 0.5104127730050863, 0.38845934758555095}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.4291572529674181, 0.36295857041505203, 0.20788417661753}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 50.35000038146973) {
                        memcpy(var23, (double[]){0.5348950303057258, 0.21005215322187815, 0.2550528164723961}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.7682169270858706, 0.14289971271292543, 0.0888833602012039}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 24.550000190734863) {
                if (input[2] <= 0.5250000059604645) {
                    if (input[9] <= 22.322787284851074) {
                        memcpy(var23, (double[]){0.9462189462189462, 0.053781053781053786, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.8871489653060227, 0.06723152381815214, 0.045619510875825234}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 19.452314376831055) {
                        memcpy(var23, (double[]){0.6874256247520825, 0.31257437524791754, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.9021562392563007, 0.0879027841728586, 0.009940976570840768}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 22.65000057220459) {
                    if (input[9] <= 21.63545322418213) {
                        memcpy(var23, (double[]){0.0, 0.7466744627978367, 0.2533255372021634}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.0, 0.23679391790093413, 0.7632060820990658}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 24.800000190734863) {
                        memcpy(var23, (double[]){0.635140817911615, 0.1444001628720002, 0.22045901921638478}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.47971880841926057, 0.4674203540941109, 0.05286083748662845}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[4] <= 1.25) {
            if (input[10] <= -4.6499998569488525) {
                if (input[0] <= 20.800000190734863) {
                    if (input[2] <= 0.3200000077486038) {
                        memcpy(var23, (double[]){0.7752727671200473, 0.1410074877070046, 0.08371974517294797}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.0, 0.6885334291876348, 0.3114665708123652}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.7699999809265137) {
                        memcpy(var23, (double[]){0.11991738537558927, 0.32296627791065974, 0.5571163367137508}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.5117581364394064, 0.2908723395226863, 0.1973695240379073}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 34.14999961853027) {
                    if (input[5] <= 18.550000190734863) {
                        memcpy(var23, (double[]){0.19523471232578862, 0.2528122743165472, 0.5519530133576642}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.2911196954508089, 0.4013889410761197, 0.30749136347307127}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.050000011920929) {
                        memcpy(var23, (double[]){0.8200205151862692, 0.10486846317262372, 0.07511102164110721}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.6398515089570789, 0.2649653000779726, 0.09518319096494857}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 27.300000190734863) {
                if (input[0] <= 29.399999618530273) {
                    if (input[9] <= 27.914835929870605) {
                        memcpy(var23, (double[]){0.37688686614690725, 0.10710720229506743, 0.5160059315580254}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.7893090022849145, 0.13458788815648717, 0.07610310955859835}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var23, (double[]){0.0, 0.9364573020936456, 0.06354269790635425}, 3 * sizeof(double));
                }
            } else {
                if (input[10] <= -5.049999952316284) {
                    if (input[0] <= 25.550000190734863) {
                        memcpy(var23, (double[]){0.027223027799522834, 0.2042433972587397, 0.7685335749417376}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.20195903018022393, 0.38263059189751986, 0.41541037792225627}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.8650000095367432) {
                        memcpy(var23, (double[]){0.24062566280686024, 0.33034360712652044, 0.42903073006661935}, 3 * sizeof(double));
                    } else {
                        memcpy(var23, (double[]){0.04486436777769025, 0.4844989284243929, 0.4706367037979168}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var8, var23, 3, var7);
    double var24[3];
    if (input[4] <= 1.25) {
        if (input[3] <= 0.625) {
            if (input[0] <= 29.75) {
                if (input[1] <= 37.64999961853027) {
                    if (input[9] <= 18.351303100585938) {
                        memcpy(var24, (double[]){0.5598552078841686, 0.26093193964687994, 0.17921285246895136}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.3040018132978048, 0.4191505000576103, 0.2768476866445849}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 27.426523208618164) {
                        memcpy(var24, (double[]){0.18788885475013753, 0.4111491687398791, 0.4009619765099832}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.49775196859168236, 0.2160415353369134, 0.28620649607140425}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 38.04999923706055) {
                    if (input[5] <= 37.30000114440918) {
                        memcpy(var24, (double[]){0.5385610675413299, 0.3246793071977744, 0.13675962526089566}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.0, 0.8155401809473123, 0.1844598190526876}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 40.80000114440918) {
                        memcpy(var24, (double[]){0.7518989807281202, 0.21810261935759268, 0.029998399914287197}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.9142908833370598, 0.04724211929323842, 0.03846699736970188}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 34.35000038146973) {
                if (input[10] <= 5.6499998569488525) {
                    if (input[3] <= 0.8149999976158142) {
                        memcpy(var24, (double[]){0.18450492199119603, 0.3523586207859576, 0.4631364572228464}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.37135801846788097, 0.33338540146118545, 0.2952565800709335}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.014999999664723873) {
                        memcpy(var24, (double[]){0.4429275596290438, 0.18126037235367448, 0.3758120680172818}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.019648673313838554, 0.26802921935322754, 0.712322107332934}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 30.199999809265137) {
                    if (input[9] <= 27.82873249053955) {
                        memcpy(var24, (double[]){0.852306262403244, 0.061191484323542045, 0.08650225327321388}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.0, 0.7106683733095888, 0.2893316266904113}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 36.54999923706055) {
                        memcpy(var24, (double[]){0.6864699603224302, 0.2341048739472338, 0.07942516573033599}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.0, 0.6387927800241778, 0.3612072199758223}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 0.3149999976158142) {
            if (input[10] <= -5.8500001430511475) {
                if (input[5] <= 34.499999046325684) {
                    if (input[3] <= 0.5649999976158142) {
                        memcpy(var24, (double[]){0.0, 0.4820762878489973, 0.5179237121510027}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.0, 0.17888617420574907, 0.821113825794251}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.675000011920929) {
                        memcpy(var24, (double[]){0.0, 0.6143816792056821, 0.38561832079431796}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.0, 0.22764952313040382, 0.7723504768695962}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 0.7049999833106995) {
                    if (input[9] <= 26.87964153289795) {
                        memcpy(var24, (double[]){0.31036997653084114, 0.259969142427813, 0.4296608810413458}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.08234457029386294, 0.5429134796178176, 0.3747419500883196}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.08500000089406967) {
                        memcpy(var24, (double[]){0.10303215836202813, 0.32794309609056377, 0.569024745547408}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.029287730689046543, 0.5460057721302456, 0.42470649718070785}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[10] <= -5.599999904632568) {
                if (input[9] <= 25.738890647888184) {
                    memcpy(var24, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    if (input[2] <= 0.42499999701976776) {
                        memcpy(var24, (double[]){0.0, 0.42425249169435214, 0.5757475083056479}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.0, 0.7683000200548165, 0.2316999799451835}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 0.4050000011920929) {
                    memcpy(var24, (double[]){0.8755841859290135, 0.1244158140709865, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[9] <= 18.585865020751953) {
                        memcpy(var24, (double[]){0.917439980841765, 0.0, 0.08256001915823506}, 3 * sizeof(double));
                    } else {
                        memcpy(var24, (double[]){0.33960092796416586, 0.38150206414928317, 0.2788970078865509}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var7, var24, 3, var6);
    double var25[3];
    if (input[4] <= 1.25) {
        if (input[8] <= 0.5) {
            if (input[0] <= 28.449999809265137) {
                if (input[9] <= 31.663545608520508) {
                    if (input[3] <= 0.5450000166893005) {
                        memcpy(var25, (double[]){0.41266991277623366, 0.36724254475040047, 0.220087542473366}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.1578934257773329, 0.4871775555886217, 0.35492901863404547}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -7.8500001430511475) {
                        memcpy(var25, (double[]){0.0, 0.49558552440089265, 0.5044144755991073}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.8270747798346609, 0.14102746534399443, 0.0318977548213446}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 0.9000000059604645) {
                    if (input[2] <= 0.9899999797344208) {
                        memcpy(var25, (double[]){0.0, 0.3871065528217047, 0.6128934471782953}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.0, 0.837612443778111, 0.16238755622188905}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -2.850000023841858) {
                        memcpy(var25, (double[]){0.5443771995562231, 0.3517529473610776, 0.1038698530826993}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.7360006067720661, 0.17717376542641095, 0.0868256278015229}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 0.3449999988079071) {
                if (input[4] <= 1.1500000357627869) {
                    if (input[8] <= 1.5) {
                        memcpy(var25, (double[]){0.22175481495559185, 0.25983770274746854, 0.5184074822969397}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.2816895794113386, 0.37464876606185615, 0.34366165452680525}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 31.90000057220459) {
                        memcpy(var25, (double[]){0.362726323797479, 0.2869828719476049, 0.350290804254916}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.7856053280228023, 0.059536160654161216, 0.15485851132303646}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 1.5) {
                    if (input[1] <= 42.35000038146973) {
                        memcpy(var25, (double[]){0.7513180223677377, 0.20095672299846484, 0.04772525463379751}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.4316656656025235, 0.3459843773162833, 0.22234995708119312}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -2.649999976158142) {
                        memcpy(var25, (double[]){0.47370331174840585, 0.31112500644679547, 0.2151716818047987}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.17010120324867684, 0.5510866737678569, 0.2788121229834663}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 51.45000076293945) {
            if (input[9] <= 26.855341911315918) {
                if (input[0] <= 27.84999942779541) {
                    if (input[0] <= 21.550000190734863) {
                        memcpy(var25, (double[]){0.0, 0.574898201242652, 0.4251017987573479}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.14855900809464598, 0.2870883543617826, 0.5643526375435713}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.4950000047683716) {
                        memcpy(var25, (double[]){0.7842337668437346, 0.16458152823636987, 0.05118470491989558}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.19632417515322742, 0.5058585594061616, 0.29781726544061093}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 35.54999923706055) {
                    if (input[10] <= 1.75) {
                        memcpy(var25, (double[]){0.0, 0.5410730363857846, 0.4589269636142153}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.5414564320982052, 0.283132036218923, 0.1754115316828719}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var25, (double[]){0.928971873235538, 0.035200511449778996, 0.035827615314683044}, 3 * sizeof(double));
                }
            }
        } else {
            if (input[10] <= 0.05000000074505806) {
                if (input[8] <= 2.0) {
                    if (input[2] <= 0.2149999961256981) {
                        memcpy(var25, (double[]){0.0, 0.288031964169197, 0.711968035830803}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.10644850583995678, 0.38721949268037364, 0.5063320014796695}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -5.3500001430511475) {
                        memcpy(var25, (double[]){0.2567634241535419, 0.5253797472870512, 0.217856828559407}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.09598204401360938, 0.3709681077917805, 0.5330498481946102}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 0.48000000417232513) {
                    memcpy(var25, (double[]){0.8771452312023937, 0.06647340278779441, 0.056381366009811924}, 3 * sizeof(double));
                } else {
                    if (input[2] <= 0.17500000447034836) {
                        memcpy(var25, (double[]){0.03875815531656808, 0.41415090603127974, 0.5470909386521522}, 3 * sizeof(double));
                    } else {
                        memcpy(var25, (double[]){0.4791550183102083, 0.3268097124308518, 0.19403526925894}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var6, var25, 3, var5);
    double var26[3];
    if (input[3] <= 0.574999988079071) {
        if (input[0] <= 31.949999809265137) {
            if (input[8] <= 0.5) {
                if (input[9] <= 17.94337272644043) {
                    if (input[10] <= -2.149999976158142) {
                        memcpy(var26, (double[]){0.7031277926085614, 0.1692604563721502, 0.1276117510192884}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.0, 0.7660812574051021, 0.2339187425948978}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 20.551877975463867) {
                        memcpy(var26, (double[]){0.16556441703445138, 0.5753742225157366, 0.25906136044981204}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.39895603131092816, 0.3870003956736436, 0.21404357301542815}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 0.6550000011920929) {
                    if (input[2] <= 0.26500000059604645) {
                        memcpy(var26, (double[]){0.2231680047549133, 0.359065819004665, 0.41776617624042167}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.09872030785248352, 0.5296831566852468, 0.3715965354622698}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.1500000357627869) {
                        memcpy(var26, (double[]){0.3748140330425923, 0.3773785013257128, 0.24780746563169476}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.6941352449055419, 0.16995206227080514, 0.135912692823653}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[8] <= 1.5) {
                if (input[5] <= 33.14999961853027) {
                    if (input[0] <= 33.04999923706055) {
                        memcpy(var26, (double[]){0.7858020261964326, 0.12760942969309802, 0.08658854411046943}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.45865786430786987, 0.3939334968435099, 0.14740863884862027}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 39.80000114440918) {
                        memcpy(var26, (double[]){0.8258375725044659, 0.1206998611862515, 0.05346256630928265}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.5943810363073211, 0.3931152549841422, 0.01250370870853658}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 0.3200000077486038) {
                    memcpy(var26, (double[]){0.0, 0.39576957347073183, 0.6042304265292683}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 32.60000038146973) {
                        memcpy(var26, (double[]){0.0, 0.843841047667678, 0.15615895233232213}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.0, 0.9778821487371256, 0.022117851262874428}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 0.17500000447034836) {
            if (input[5] <= 30.84999942779541) {
                if (input[1] <= 39.45000076293945) {
                    if (input[4] <= 1.050000011920929) {
                        memcpy(var26, (double[]){0.0, 0.5916310872716962, 0.4083689127283038}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.33207653552717237, 0.29491433523357685, 0.3730091292392507}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 26.449999809265137) {
                        memcpy(var26, (double[]){0.14590619253540968, 0.34001278624019254, 0.5140810212243978}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.06165949786123452, 0.5887717083714419, 0.3495687937673237}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -14.299999713897705) {
                    memcpy(var26, (double[]){0.6845665807932519, 0.07781858996899634, 0.23761482923775173}, 3 * sizeof(double));
                } else {
                    if (input[10] <= -11.449999809265137) {
                        memcpy(var26, (double[]){0.0, 0.41019483375078886, 0.5898051662492112}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.0, 0.18725405302910578, 0.8127459469708943}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 28.65000057220459) {
                if (input[5] <= 29.25) {
                    if (input[10] <= 5.5) {
                        memcpy(var26, (double[]){0.21949420081597285, 0.5378360817326954, 0.24266971745133178}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -2.649999976158142) {
                        memcpy(var26, (double[]){0.2829925246491769, 0.24510000211419927, 0.47190747323662385}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.0, 0.6627311060655208, 0.33726889393447934}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= 6.25) {
                    if (input[0] <= 35.85000038146973) {
                        memcpy(var26, (double[]){0.46019841338347506, 0.3255054751841055, 0.21429611143241944}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.2549019630427797, 0.6664516991037708, 0.07864633785344965}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.1500000357627869) {
                        memcpy(var26, (double[]){0.9362301450509365, 0.023650360784129576, 0.04011949416493398}, 3 * sizeof(double));
                    } else {
                        memcpy(var26, (double[]){0.4923241786758838, 0.27982649509275564, 0.2278493262313605}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var5, var26, 3, var4);
    double var27[3];
    if (input[0] <= 31.949999809265137) {
        if (input[3] <= 0.574999988079071) {
            if (input[6] <= 0.5) {
                if (input[5] <= 39.39999961853027) {
                    if (input[2] <= 0.6649999916553497) {
                        memcpy(var27, (double[]){0.1525481167940808, 0.39217372402146444, 0.4552781591844547}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.4376521324277594, 0.3316694367696426, 0.230678430802598}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var27, (double[]){0.7886786616303357, 0.08965360435151538, 0.1216677340181489}, 3 * sizeof(double));
                }
            } else {
                if (input[1] <= 78.70000076293945) {
                    if (input[0] <= 31.550000190734863) {
                        memcpy(var27, (double[]){0.41121792183444295, 0.35897006777171087, 0.22981201039384616}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.0, 0.7583169506088975, 0.2416830493911025}, 3 * sizeof(double));
                    }
                } else {
                    if (input[10] <= -1.050000011920929) {
                        memcpy(var27, (double[]){0.0, 0.7912155998829664, 0.20878440011703353}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.0, 0.15977728772736519, 0.8402227122726349}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 36.25) {
                if (input[10] <= 2.950000047683716) {
                    if (input[8] <= 2.5) {
                        memcpy(var27, (double[]){0.0, 0.5410730363857847, 0.4589269636142153}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.6058585183973018, 0.20847557508332787, 0.18566590651937032}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.044999999925494194) {
                        memcpy(var27, (double[]){0.1981473875874646, 0.28831416765178924, 0.5135384447607462}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.0, 0.24300560935209156, 0.7569943906479084}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[8] <= 2.5) {
                    if (input[2] <= 0.29500000178813934) {
                        memcpy(var27, (double[]){0.1278543275865496, 0.2713000465348756, 0.6008456258785748}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.3498113291800482, 0.23196279233472133, 0.4182258784852304}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 27.25) {
                        memcpy(var27, (double[]){0.17410227144704457, 0.40690704679018763, 0.41899068176276794}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.08274533774133849, 0.6396171635216217, 0.27763749873703975}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[5] <= 38.14999961853027) {
            if (input[4] <= 1.25) {
                if (input[0] <= 33.95000076293945) {
                    if (input[0] <= 32.75) {
                        memcpy(var27, (double[]){0.5334609416188579, 0.37395622268319434, 0.09258283569794784}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.3167455231838734, 0.504087797427076, 0.1791666793890507}, 3 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 28.76084613800049) {
                        memcpy(var27, (double[]){0.7155298838473699, 0.19568360354898245, 0.08878651260364767}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.21191797729235123, 0.722697775994112, 0.06538424671353672}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 0.5) {
                    if (input[0] <= 35.64999961853027) {
                        memcpy(var27, (double[]){0.33635162669278396, 0.6117601427210936, 0.05188823058612251}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.6522362279418757, 0.24714471418455383, 0.10061905787357048}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 1.0549999475479126) {
                        memcpy(var27, (double[]){0.0, 0.673548581546924, 0.326451418453076}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.567138265132355, 0.25787937272030914, 0.17498236214733584}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 18.25) {
                memcpy(var27, (double[]){0.9850695365493198, 0.014930463450680208, 0.0}, 3 * sizeof(double));
            } else {
                if (input[5] <= 39.75) {
                    if (input[3] <= 0.5600000023841858) {
                        memcpy(var27, (double[]){0.7056423759571722, 0.28075038558711496, 0.013607238455712892}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.9214409145287784, 0.0785590854712216, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.100000023841858) {
                        memcpy(var27, (double[]){0.37115321411666474, 0.5906754555878599, 0.038171330295475314}, 3 * sizeof(double));
                    } else {
                        memcpy(var27, (double[]){0.8201891098594895, 0.16575213658249094, 0.014058753558019615}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var4, var27, 3, var3);
    double var28[3];
    if (input[8] <= 0.5) {
        if (input[10] <= -2.850000023841858) {
            if (input[0] <= 31.0) {
                if (input[5] <= 33.45000076293945) {
                    if (input[3] <= 0.375) {
                        memcpy(var28, (double[]){0.13276230800926728, 0.7545924604104343, 0.11264523158029845}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.37972155381308753, 0.3806378414632686, 0.2396406047236437}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 37.04999923706055) {
                        memcpy(var28, (double[]){0.05228210775109704, 0.6775254332799407, 0.2701924589689622}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.1523952480777896, 0.45734403127695783, 0.39026072064525263}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 31.34999942779541) {
                    memcpy(var28, (double[]){0.8442864540941984, 0.13710694209591714, 0.01860660380988445}, 3 * sizeof(double));
                } else {
                    if (input[5] <= 37.64999961853027) {
                        memcpy(var28, (double[]){0.0, 0.7642754155444924, 0.23572458445550745}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.6750762268347641, 0.27285250586435555, 0.052071267300880394}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 33.80000114440918) {
                if (input[0] <= 30.949999809265137) {
                    if (input[9] <= 24.865635871887207) {
                        memcpy(var28, (double[]){0.4706319754407742, 0.37134893252422646, 0.15801909203499936}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.8430509192287449, 0.05476251952454464, 0.10218656124671051}, 3 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 23.950000762939453) {
                        memcpy(var28, (double[]){0.0, 0.9298919859217605, 0.07010801407823941}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.43418309414957457, 0.19742428054810432, 0.36839262530232114}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 35.35000038146973) {
                    memcpy(var28, (double[]){0.6209942973688205, 0.2353065523786452, 0.1436991502525344}, 3 * sizeof(double));
                } else {
                    if (input[10] <= -0.6500000059604645) {
                        memcpy(var28, (double[]){0.9651095370100855, 0.03134557394954857, 0.0035448890403659405}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.8681779220991676, 0.11842888677682818, 0.013393191124004385}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 28.949999809265137) {
            if (input[8] <= 1.5) {
                if (input[1] <= 60.95000076293945) {
                    if (input[2] <= 0.19500000029802322) {
                        memcpy(var28, (double[]){0.027315568035043203, 0.2380589320384319, 0.7346254999265249}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.1731524153624932, 0.2558819017561137, 0.5709656828813932}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.4950000047683716) {
                        memcpy(var28, (double[]){0.4746161553086289, 0.30572985268870895, 0.21965399200266217}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.12893445340721288, 0.29658294146498765, 0.5744826051277995}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 1.1050000190734863) {
                    if (input[5] <= 26.199999809265137) {
                        memcpy(var28, (double[]){0.37983517219418184, 0.3121154862308177, 0.3080493415750006}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.15868576814498145, 0.42777528562172795, 0.4135389462332906}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 14.599999904632568) {
                        memcpy(var28, (double[]){0.1957343147610273, 0.3003781939451541, 0.5038874912938186}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.08772073043258978, 0.5717117195571979, 0.3405675500102124}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[10] <= 4.950000047683716) {
                if (input[3] <= 0.4449999928474426) {
                    if (input[5] <= 37.64999961853027) {
                        memcpy(var28, (double[]){0.2789869061219993, 0.49685319557291624, 0.2241598983050844}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.714341775542188, 0.2030082656979386, 0.08264995875987337}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.5049999952316284) {
                        memcpy(var28, (double[]){0.7145025440844764, 0.15619534953242692, 0.12930210638309667}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.46835397836132797, 0.31794308578761105, 0.21370293585106093}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[9] <= 26.379186630249023) {
                    if (input[9] <= 17.607556343078613) {
                        memcpy(var28, (double[]){0.9749331976078381, 0.0, 0.025066802392161854}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.5775294240744757, 0.2723303458523911, 0.15014023007313315}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 30.199999809265137) {
                        memcpy(var28, (double[]){0.9283896764812796, 0.0, 0.07161032351872047}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.5226145878558947, 0.35645149616022365, 0.12093391598388166}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var3, var28, 3, var2);
    double var29[3];
    if (input[3] <= 0.574999988079071) {
        if (input[6] <= 0.5) {
            if (input[5] <= 32.54999923706055) {
                if (input[1] <= 29.25) {
                    if (input[2] <= 0.02500000037252903) {
                        memcpy(var29, (double[]){0.0, 0.5511912983425415, 0.44880870165745856}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.0, 0.8118874829425629, 0.18811251705743703}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 30.84999942779541) {
                        memcpy(var29, (double[]){0.28000427906429104, 0.34254803155827673, 0.37744768937743217}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.435267482819599, 0.3381088150349972, 0.22662370214540375}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 27.399999618530273) {
                    if (input[2] <= 0.3100000023841858) {
                        memcpy(var29, (double[]){0.0, 0.15977728772736524, 0.8402227122726348}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.42154799919844504, 0.383358134297028, 0.19509386650452706}, 3 * sizeof(double));
                    }
                } else {
                    if (input[8] <= 1.5) {
                        memcpy(var29, (double[]){0.7143920703442028, 0.17015223987424916, 0.11545568978154805}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.33071003047130865, 0.3759369648173561, 0.2933530047113351}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 38.04999923706055) {
                if (input[0] <= 32.75) {
                    if (input[8] <= 2.5) {
                        memcpy(var29, (double[]){0.33469422798387954, 0.41739361471918046, 0.24791215729694002}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.5187095240693316, 0.2712374903125379, 0.21005298561813063}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.3499999642372131) {
                        memcpy(var29, (double[]){0.6394658175480776, 0.268050750049095, 0.09248343240282733}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.0, 0.8549669428404051, 0.14503305715959494}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= -8.150000095367432) {
                    if (input[1] <= 45.849998474121094) {
                        memcpy(var29, (double[]){0.10223597672804882, 0.5113568645578344, 0.38640715871411685}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.2890019366558146, 0.13140999774078585, 0.5795880656033995}, 3 * sizeof(double));
                    }
                } else {
                    if (input[3] <= 0.5550000071525574) {
                        memcpy(var29, (double[]){0.7687933098771408, 0.2083989854596164, 0.02280770466324269}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.9678815469867751, 0.019134716350775956, 0.012983736662448994}, 3 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[4] <= 1.25) {
            if (input[2] <= 0.2149999961256981) {
                if (input[2] <= 0.07499999925494194) {
                    if (input[0] <= 19.949999809265137) {
                        memcpy(var29, (double[]){0.5324924360779965, 0.22867438205106239, 0.23883318187094113}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.2051913686894853, 0.2876783778375953, 0.5071302534729193}, 3 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 30.84999942779541) {
                        memcpy(var29, (double[]){0.16148799916301035, 0.3163097530767153, 0.5222022477602744}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.06341472905735136, 0.14417428302710003, 0.7924109879155486}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[7] <= 1.5) {
                    if (input[2] <= 0.5399999916553497) {
                        memcpy(var29, (double[]){0.2193820855048818, 0.44556632376671435, 0.33505159072840385}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.5654299682854566, 0.24103369248175477, 0.19353633923278873}, 3 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 34.25) {
                        memcpy(var29, (double[]){0.31548727690016354, 0.4213930607066668, 0.26311966239316953}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.8423496796704004, 0.08617922573892785, 0.07147109459067176}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[3] <= 0.875) {
                if (input[2] <= 0.2849999964237213) {
                    if (input[2] <= 0.19500000029802322) {
                        memcpy(var29, (double[]){0.17503587550184418, 0.2785625762458662, 0.5464015482522895}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.07557398324525443, 0.46391000217138867, 0.46051601458335695}, 3 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 1.3499999642372131) {
                        memcpy(var29, (double[]){0.15090207836657296, 0.36023190894547735, 0.4888660126879497}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.4477024811766141, 0.27142877873988985, 0.280868740083496}, 3 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 1.0149999856948853) {
                    if (input[10] <= 3.850000023841858) {
                        memcpy(var29, (double[]){0.0, 0.4400887414650958, 0.5599112585349042}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.0, 0.16123398076639808, 0.838766019233602}, 3 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 0.004999999888241291) {
                        memcpy(var29, (double[]){0.6493770658530384, 0.0, 0.3506229341469616}, 3 * sizeof(double));
                    } else {
                        memcpy(var29, (double[]){0.0, 0.539283938022873, 0.460716061977127}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var2, var29, 3, var1);
    mul_vector_number(var1, 0.06666666666666667, 3, var0);
    memcpy(output, var0, 3 * sizeof(double));
}


#endif