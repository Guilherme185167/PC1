const { get } = require("express/lib/response");

function cor(id, idd) {
    const move = document.getElementById(id);
    const more = document.getElementById(idd);
    more.style.boxShadow
        ? more.style.removeProperty('box-shadow')
        : more.style.boxShadow = '0 0 20px white';
    more.style.borderRadius = more.style.borderRadius === '5px' ? '30px' : '5px';
    move.style.backgroundColor = move.style.backgroundColor === '' ? '#afcadf' : '';
}
function trocar() {
    const d1 = document.getElementById("p1");
    const d2 = document.getElementById("p2");
    d1.style.display = d1.style.display === "none" ? "block" : "none";
    d2.style.display = d2.style.display === "none" ? "block" : "none";
}
