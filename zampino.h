

#ifndef ZAMPINO_H
#define ZAMPINO_H

#include <Arduino.h>

class Filter{
    public:
        Filter();
        void coef( float *b, uint16_t sizeb, float *a, uint16_t sizea );
        float fir( float x );
        float iir( float x );
    private:
      float *_b;
      uint16_t _sizeb;
      float *_a;
      uint16_t _sizea;

      float *xolds;


      void shiftx( float x );
};


#endif // ZAMPINO_H


