/*
 * Se conheces o verdadeiro Zamps, ele ja eh o filtro.
 * */

#include "zampino.h"

Filter::Filter(){}

void Filter::coef(  float *b, uint16_t sizeb, 
                    float *a, uint16_t sizea ){


  _b = b;
  _sizeb = sizeb;
  
  _a = a;
  _sizea = (sizea-1);

  xolds = (float*)malloc( sizeb * sizeof(float) );
  yolds = (float*)malloc( sizea * sizeof(float) );

  for( int i=0; i < sizeb; i++ )
    xolds[i] = 0;  

  for( int i=0; i < sizea; i++ )
    yolds[i] = 0;  

}

float Filter::fir( float x ){
  float y = 0;
  shiftx( x );
  
  for( int i = 0; i < _sizeb; i++ )
    y += xolds[i]*_b[i];
  
  return y;
}

float Filter::iir( float x ){

  float yo = 0;
  for( int i = 0; i < _sizea; i++ )
      yo += yolds[i]*_a[i+1];

  float y = fir(x) - yo;
  shifty(y);

  return y;
  
}

void Filter::shiftx( float x ){
  
  for( int i = (_sizeb - 1); i > 0 ; i-- )
    xolds[i] = xolds[i-1];  

  xolds[0] = x;
}

void Filter::shifty( float y ){
  
  for( int i = (_sizea - 1); i > 0 ; i-- )
    yolds[i] = yolds[i-1];  

  yolds[0] = y;
}
