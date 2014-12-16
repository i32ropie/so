#ifndef FUNCIONES_H
#define FUNCIONES_H

  pthread_mutex_t vlock[5];
  pthread_cond_t lleno;
  pthread_cond_t vacio;

  int* V; //Vector que van a ir modificando los productores y los consumidores.
  void crear_reservarMem_vector(int nele);
  void printvector(int* V, int nele);
  void* Productor(void* arg);
  void* Consumidor(void* arg);

#endif
