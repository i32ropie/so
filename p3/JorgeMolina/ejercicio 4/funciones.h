#ifndef FUNCIONES_H
#define FUNCIONES_H

  void* lectura(void* nombre);
  void* escritura(void* nombre);
  pthread_mutex_t lectores;
  pthread_mutex_t escritores;
  int n_lectores;

#endif
