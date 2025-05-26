CREATE TABLE IF NOT EXISTS mesa (
  id_mesa SERIAL PRIMARY KEY,
  setor VARCHAR(45) NOT NULL,
  criado_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS garcom (
  id_matricula SERIAL PRIMARY KEY,
  nome VARCHAR(45) NOT NULL,
);

CREATE TABLE IF NOT EXISTS produto (
  id_produto SERIAL PRIMARY KEY,
  nome VARCHAR(45) NOT NULL,
  categoria VARCHAR(45),
  setor VARCHAR(45),
  valor decimal(10,2)
);


CREATE TABLE IF NOT EXISTS promocao (
  id_promocao SERIAL PRIMARY KEY,
  nome VARCHAR(45) NOT NULL,
  data_inicio DATE NOT NULL,
  data_termino DATE NOT NULL,
  desconto decimal(10,2)
);


CREATE TABLE IF NOT EXISTS pedido (
  id_mesa references mesa(id_mesa) NOT NULL,
  id_produto references produto(id_produto) NOT NULL,
  qtde interger NOT NULL
  criado_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS alocacao (
  id_mesa SERIAL references mesa(id_mesa) NOT NULL,
  id_matricula SERIAL references garcom(id_matricula) NOT NULL,
  data DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS produto_promocao (
  id_produto SERIAL references produto(id_produto) NOT NULL,
  id_promocao SERIAL references promocao(id_promocao) NOT NULL,
);
