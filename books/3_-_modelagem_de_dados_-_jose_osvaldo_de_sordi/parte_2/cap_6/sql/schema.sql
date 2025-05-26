CREATE TABLE IF NOT EXISTS mesa (
  id_mesa SERIAL PRIMARY KEY,
  setor VARCHAR(45) NOT NULL,
  criado_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS garcom (
  id_matricula SERIAL PRIMARY KEY,
  nome VARCHAR(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS produto (
  id_produto SERIAL PRIMARY KEY,
  nome VARCHAR(45) NOT NULL,
  categoria VARCHAR(45),
  setor VARCHAR(45),
  valor DECIMAL(10,2)
);

CREATE TABLE IF NOT EXISTS promocao (
  id_promocao SERIAL PRIMARY KEY,
  nome VARCHAR(45) NOT NULL,
  data_inicio DATE NOT NULL,
  data_termino DATE NOT NULL,
  desconto DECIMAL(10,2)
);

CREATE TABLE IF NOT EXISTS pedido (
  id_mesa INTEGER NOT NULL,
  id_produto INTEGER NOT NULL,
  qtde INTEGER NOT NULL,
  criado_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (id_mesa, id_produto),
  FOREIGN KEY (id_mesa) REFERENCES mesa(id_mesa),
  FOREIGN KEY (id_produto) REFERENCES produto(id_produto)
);

CREATE TABLE IF NOT EXISTS alocacao (
  id_mesa INTEGER NOT NULL,
  id_matricula INTEGER NOT NULL,
  data DATE NOT NULL,
  PRIMARY KEY (id_mesa, id_matricula),
  FOREIGN KEY (id_mesa) REFERENCES mesa(id_mesa),
  FOREIGN KEY (id_matricula) REFERENCES garcom(id_matricula)
);

CREATE TABLE IF NOT EXISTS produto_promocao (
  id_produto INTEGER NOT NULL,
  id_promocao INTEGER NOT NULL,
  PRIMARY KEY (id_produto, id_promocao),
  FOREIGN KEY (id_produto) REFERENCES produto(id_produto),
  FOREIGN KEY (id_promocao) REFERENCES promocao(id_promocao)
);