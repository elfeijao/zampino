/*
 * Se conheces o verdadeiro Zamps, ele ja eh o filtro.
 * */

#include "zampino.h"


Filter::Filter(){
    Serial.println("Funcionando");
}

void Filter::coef(  float *b, uint16_t sizeb, 
                    float *a, uint16_t sizea ){


  _b = b;
  _sizeb = sizeb;
  
  _a = a;
  _sizea = sizea;

  xolds = (float*)malloc( sizeb * sizeof(float) );
  for( int i=0; i < sizeb; i++ ){
    xolds[i] = 0;  
  }

}

float Filter::fir( float x ){
  float y = 0;
  shiftx( x );
  
  for( int i = 0; i < _sizeb; i++ )
    y += xolds[i]*_b[i];
  
  return y;
}

float Filter::iir( float x ){

  return 0.001;
  
}

void Filter::shiftx( float x ){
  
  for( int i = _sizeb - 1; i > 0 ; i-- )
    xolds[i] = xolds[i-1];  

  xolds[0] = x;
}

