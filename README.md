
Zampino
=======

Biblioteca de processamento de sinais para Arduino.

ee. Se conheces o verdadeiro Z, encontraste o melhor dos filtros.

Como usar
=========

1. Clone o repositório dentro da pasta de bibliotecas do Arduino;
1. Abra um exemplo da biblioteca Zampino;
1. Modifique os coeficientes \[**b**, **a**\] da função de transferência;
1. Verifique o efeito através Serial Plot (*CTRL + SHIFT + l*).

#### Projeto de filtro

Os coeficiente \[**b**, **a**\] da função de transferência do filtro foram projetados a partir de um software de processamento:
1. Octave
1. Python - Scipy
1. Entre outros.

*Lembre-se: Nem um filtro deve ser aplicado em um sistema sem conhecer exatamente o efeito sobre o sinal.*

Recursos disponíveis
========

1. Filtro FIR.
1. Filtro IIR.

Referências
===========

