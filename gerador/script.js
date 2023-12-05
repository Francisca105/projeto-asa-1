const exceljs = require('exceljs');
const fs = require('fs');
const path = require('path');

let workbook = new exceljs.Workbook();
let worksheet = workbook.addWorksheet('ASA 1');

const filePath = path.join(__dirname, 'teste.xlsx');

worksheet.columns = [
    {  header: 'O' },
    { header: 'Mediana' },
    { header: 'Desvio Mínimo' },
    { header: 'Desvio Máximo' },
    { header: 'Minimo' },
    { header: 'Máximo' },
];

let excel_rows = AddRows();
worksheet.addRows(excel_rows);

workbook.xlsx.writeFile(filePath)
  .then(() => {
    console.log(`Arquivo Excel criado e salvo em: ${filePath}`);
  })
  .catch((err) => {
    console.error('Erro ao criar e salvar o arquivo Excel:', err);
  });

function AddRows(){
    let rows = [];
    for(i = 0; i <= 4500; i+=250){
        let json = require(`./t${i}.json`);
        let mediana = json.results[0].median
        let min = json.results[0].min
        let max = json.results[0].max

                  // O atual,  Mediana
        rows.push([i*i*i, mediana, 
                  // Desvio Mínimo, Desvio Máximo
                  mediana - min, max - mediana,  
                  // Minimo, Máximo
                  min, max])
    }
    return rows
}