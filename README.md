# Desafio de Programacao Paralela - ERAD-SP 2018

Este projeto usa [Cmake](www.cmake.org) para sua configuração.

## Instruções

É recomendável criar um diretório específico para seu `build`

```bash
$ mkdir build
$ cd build
```
Estando nele, você deve executar um desses dois comandos:

* Para configurar um ambiente de compilação para o compilador da `Intel`:

```bash
$ cmake ..

```
* Para deixar o script de configuração decidir o melhor ambiente para você:


```bash
$ cmake .. -DORIGINAL=OFF

```

Feito uma dessas duas operações, o próximo passo agora é gerar os binários:


```bash
$ make

```

Pronto. Agora os binários devem estar gerados nas pastas especificadas pelo `Makefile`

Para executar, dado o `setup` exemplificado, basta inserir algum desses comandos, em qualquer ordem:

```bash
$ ./A/barra < ../A/in.1
$ ./B/soma < ../B/in.1

```

