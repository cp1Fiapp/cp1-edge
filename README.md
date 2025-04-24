Azor Biagioni Tartuce: RM:563995 .
Gabriel Viana De Souza: RM:564382 .
Pedro Pedreira de Cerqueira: RM:565024 .

# 🍷 Vinheria Agnello – Monitoramento Inteligente de Luminosidade com Arduino

## 📌 Descrição do Projeto

Este projeto simula um sistema embarcado de monitoramento para vinícolas, utilizando Arduino Uno, com o objetivo de garantir que os vinhos sejam armazenados em condições ideais de luminosidade. O sistema funciona localmente (edge computing), sem necessidade de conexão à internet.

---

## 🎯 Objetivos

- Monitorar a **luminosidade** usando um sensor LDR
- Classificar o ambiente em três níveis:
  - Ideal → LED verde
  - Alerta → LED amarelo + buzzer
  - Perigo → LED vermelho + buzzer
- Exibir os dados em um **display LCD**
- Realizar todas as ações localmente com lógica embarcada

---

## 🧩 Componentes Utilizados

| Componente          | Quantidade |
|---------------------|------------|
| Arduino Uno         | 1          |
| Sensor LDR          | 1          |
| Resistor 10kΩ       | 1          |
| LEDs (verde, amarelo, vermelho) | 3 |
| Resistores 220Ω     | 3          |
| Buzzer ativo        | 1          |
| Display LCD 16x2 (sem I2C) | 1    |
| Potenciômetro (para brilho do LCD) | 1 |
| Protoboard e jumpers| diversos   |

---

## ⚙️ Funcionamento

- A leitura do LDR é convertida em porcentagem (0 a 100%)
- Os LEDs e buzzer são ativados de acordo com a faixa:
  - **0 a 30%** → LED verde (ideal)
  - **31 a 60%** → LED amarelo + buzzer
  - **61 a 100%** → LED vermelho + buzzer
- O **LCD mostra a porcentagem e o status** em tempo real

---

## 🧪 Testes e Simulação

### ✅ Testes com LDR no Tinkercad:

| Valor do sensor | Porcentagem | Estado Esperado          |
|------------------|-------------|---------------------------|
| 0–300            | 0–30%       | LED verde (OK)           |
| 301–600          | 31–60%      | LED amarelo + buzzer     |
| 601–1023         | 61–100%     | LED vermelho + buzzer    |

### 🎮 Como simular:

1. Inicie a simulação no Tinkercad
2. Clique no sensor **LDR**
3. Ajuste a barra de "Sensor Value" para simular variação de luz
4. Observe os LEDs, buzzer e LCD reagindo

---

## 🎥 Vídeo de Apresentação

🔗 **Link do vídeo (até 3 min):**  
[Inserir link do YouTube ou Google Drive]

---

## 📚 Licença

Projeto acadêmico para a disciplina **Edge Computing & Sistemas Embarcados** – Engenharia de Software, 2025.
