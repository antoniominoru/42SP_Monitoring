# Funcionamento da ferramenta de Monitoramento

-------------------------------------------------------

# Pré requisitos
- Linux;
- Ping instalado;
- Curl instalado;
- Nkloop instalado;
- Git instalado;

-------------------------------------------------------

# Explicações iniciais

## monitoring.db


O arquivo `monitoring.db` define como a aplicação funcionará.

A estrutura é definida por linhas e colunas, onde cada linha terá as configurações separadas por um TAB, que definem as colunas.

As configurações para cada protocolo são:

| Protocolo   | Configurações                                                           |
|-------------|-------------------------------------------------------------------------|
| HTTP        | nome, protocolo, endereço, método HTTP, código HTTP esperado, intervalo |
| PING        | nome, protocolo, endereço, intervalo                                    |
| DNS         | nome, protocolo, endereço, intervalo, servidor DNS                      |

Abaixo, exemplo do arquivo descrito acima:

```txt
intra	HTTP	intra.42.fr	GET	200	120
game ping test	PING	game.42sp.org.br	60
workspaces monitoring	PING	workspaces.42sp.org.br	60
```


## monitoring.log


Este é o arquivo de log localizado na pasta `log/` nele fica armazenado as informações completas do monitoramento.

## monitoring

O `monitoring` encontrado na raiz do projeto é o executável do programa de monitoramento.

Podendo ser executado com a seguinte sintaxe:
```txt
./monitoring
```

-------------------------------------------------------
# Projeto

O programa de monitoramento foi desenvolvido no workspace e projetado para funcionar em servidor dedicado para o monitoramento dos serviços.

## Servidor

Foi utilizado um servidor Debian onde foi configurado:

- Criptografado LVM;
- Configurado AppArmor;
- Configurado Firewall - UFW liberando porta 4242 e bloqueando porta padrão 22 do ssh;
- Configurado SSH na porta 4242;
- Configurado Politica de senha;
- Instalado Ping, Curl (Para teste HTTP), Nkloop (Para teste DNS) e Git (Para baixar projeto do github);

Foi configurado no Servidor conexão ssh com Github.

Para pegar a versão mais atual do monitoramento é necessário usar o comando:

`git pull`

Na sua pasta de monitoramento e precisa executa-lo novamente;


## Funcionamento em Desenvolvimento

**make**: Faz a combilação do programa criando o executáves "monitoring".

**make clean**: Remove todos os arquivos *.o.

**make fclean**: Remove todos os arquivos *.o e todos os executáves.

**make t**: Compila o teste e o executa.

**make git**: Limpa arquivo "monitoring.log", recompila, remove todos os *.o, remove todos os executávess menos o "monitoring", adiciona pacotes no git, comita e faz push no repositório.

**make re**: Recompila o arquivo "monitoring" primeiro remove todos os arquivos *.o e os executáves, e depois compila novamente.


## Funcionamento em Produção

### ./monitoring

Quando executado o `./monitoring` começa o monitoramento listado so arquivo `monitoring.db` sendo apresentado uma versão resumida no shell e uma versão mais completa fica registrado no `log/monitoring.log`

### ./monitoring --simplify

Quando executado o `./monitoring` com a flag `--simplify`, ou seja, executado `./monitoring --simplify` 
o programa faz a leitura do arquivo `log/monitoring.log` e traduz a informação colocando no shell uma uma versão resumida das informações.