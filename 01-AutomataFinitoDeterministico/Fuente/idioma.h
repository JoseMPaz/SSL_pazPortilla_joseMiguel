#ifndef _IDIOMA_H_
#define _IDIOMA_H_

/*En este archivo se establece el idioma a utilizar*/
#include "configuracion.h"

/*Si IDIOMA_CASTELLANO no esta comentado, entonces incluye "castellano.h" donde este incluida la biblioteca "idioma.h"*/
#ifdef IDIOMA_CASTELLANO
#include "castellano.h"
#endif

/*Si IDIOMA_INGLES no esta comentado, entonces incluye "ingles.h" donde este incluida la biblioteca "idioma.h"*/
#ifdef IDIOMA_INGLES
#include "ingles.h"
#endif

/*Si IDIOMA_FRANCES no esta comentado, entonces incluye "frances.h" donde este incluida la biblioteca "idioma.h"*/
#ifdef IDIOMA_FRANCES
#include "frances.h"
#endif

/*Si IDIOMA_ALEMAN no esta comentado, entonces incluye "aleman.h" donde este incluida la biblioteca "idioma.h"*/
#ifdef IDIOMA_ALEMAN
#include "aleman.h"
#endif

/*Si IDIOMA_SUECO no esta comentado, entonces incluye "sueco.h" donde este incluida la biblioteca "idioma.h"*/
#ifdef IDIOMA_SUECO
#include "sueco.h"
#endif

#endif
