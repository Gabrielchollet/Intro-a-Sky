/* ### Sistema de gastos familiar

Crie um objeto que possuirá 2 propriedades, ambas do tipo array:
    * receitas: []
    * despesas: []

Agora, crie uma função que irá calcular o total de receitas e despesas e irá mostrar uma mensagem se a família está com saldo positivo ou negativo, seguido do valor do saldo

*/

var transactions = {
    nome: [],
    receitas: [],
    despesas: []
}

function addTransactions() {
    let name = String(document.getElementById("nameTransaction").value);
    let value = Number(document.getElementById("valor").value);

    transactions.nome.push(name);

    if (value > 0) {
        transactions.receitas.push(value);
    }
    else {
        transactions.despesas.push(value);
    }

    addRow(name, value);

    updateStatus();

    limpaInput();
}

function expressResult() {
    let balance = calcTotal().toFixed(2);
    let balanceText = (balance >= 0) ? "Saldo positivo" : "Saldo negativo";
    console.log(`${balanceText} igual a R$ ${balance}`);
    alert(`${balanceText} igual a R$ ${balance}`);
}

function limpaInput() {
    document.getElementById('valor').value = '';
    document.getElementById('nameTransaction').value = '';
}

function addRow(name, value) {
    const tbody = document.getElementById('rowTransactions');
    const amount = formatCurrency(value);
    const row = `<tr>
                <td>${name}</td>
                <td>${amount}</td>
            </tr>`;
    tbody.innerHTML += row;
}

function calcIncomes() {
    let income = 0;
    transactions.receitas.forEach((number) => {
        income += number;
    })
    return income;
}

function calcExpenses() {
    let expense = 0;
    transactions.despesas.forEach((number) => {
        expense += number;
    })
    return expense;
}

function formatCurrency(value) {
    value = Number(value) * 100
    // Aqui pegamos o valor e trabalhamos o sinal 
    const signal = Number(value) < 0 ? "-" : ""
    // Regex ou expressão regular para remoção de qualquer caractere especial
    value = String(value).replace(/\D/g, "")
    // Como ele é guardado multiplicado por 100, aqui o valor volta ao "estado original"
    value = Number(value) / 100
    // Formata como dinheiro
    value = value.toLocaleString("pt-BR", {
        style: "currency",
        currency: "BRL"
    })
    // Devolve o valor formatado com o respectivo sinal 
    return signal + value
}

function updateStatus() {
    document.getElementById('incomeDisplay').innerHTML = formatCurrency(calcIncomes());
    document.getElementById('expenseDisplay').innerHTML = formatCurrency(calcExpenses());
    document.getElementById('totalDisplay').innerHTML = formatCurrency(calcIncomes() + calcExpenses());
}