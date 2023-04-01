#ifndef _IDIOMA_H_
#define _IDIOMA_H_

#include "configuracion.h"

#ifdef IDIOMA_CASTELLANO
#include "castellano.h"
#endif

#ifdef IDIOMA_INGLES
#include "ingles.h"
#endif

#ifdef IDIOMA_FRANCES
#include "frances.h"
#endif

#endif
