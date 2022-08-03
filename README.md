# Funcionamento da ferramenta de Monitoramento

-------------------------------------------------------

# Pré requisitos
- Linux;
- ping instalado;
- curl instalado;
- nkloop instalado;
- Git instalado;

-------------------------------------------------------

# Referências

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

# Funcionamento em Desenvolvimento

**make**: Faz a combilação do programa criando o executáves "monitoring".

**make clean**: Remove todos os arquivos *.o.

**make fclean**: Remove todos os arquivos *.o e todos os executáves.

**make t**: Compila o teste e o executa.

**make git**: Limpa arquivo "monitoring.log", recompila, remove todos os *.o, remove todos os executávess menos o "monitoring", adiciona pacotes no git, comita e faz push no repositório.

**make re**: Recompila o arquivo "monitoring" primeiro remove todos os arquivos *.o e os executáves, e depois compila novamente.

-------------------------------------------------------

# Funcionamento em Produção

## ./monitoring

saída padrão -> de uma forma sucinta
informações detalhadas -> no arquivo monitoring.log

## ./monitoring --simplify

vai ler o arquivo monitoring.log e colocar na tela novamente as informações resumidas (mesmas da saida padrão)