let temperatura = Math.floor(Math.random() * 91);
const temperaturas = [];
const colores = ["#00f2ff80", "#fff20096", "#ff000080"];
const base = document.querySelector(".base").style;
const medidor = document.querySelector(".medidor").style;
const burbuja = document.querySelector(".burbuja").style;
const tubo = document.querySelector(".tubo").style;
let texto = document.getElementById("text");
const grados = document.getElementById("temp");
let monitor = document.querySelector(".monitor");

function actualizarMonitor(temperatura) {
  const fecha = new Date();
  temperaturas.push(temperatura);
  monitor.innerHTML = temperaturas
    .map(
      (t) => `<p> ${fecha.toLocaleString()} | ${t >= 10 ? t : "0" + t} °C</p>`,
    )
    .join("");
  monitor.scrollTop = monitor.scrollHeight;
}

function aplicarEstilos(temperatura) {
  let color;
  let mensaje;
  if (temperatura < 20) {
    color = colores[0];
    mensaje = "DEMASIADO FRIO!!!";
  } else if (temperatura >= 20 && temperatura < 30) {
    color = colores[1];
    mensaje = "TEMPERATURA AMBIENTE";
  } else {
    color = colores[2];
    mensaje = "DEMASIADO CALOR!!!";
  }

  grados.innerHTML = temperatura + " °C";
  actualizarMonitor(temperatura);
  texto.innerText = mensaje;
  texto.style.color = color;
  base.background = color;
  medidor.background = color;
  tubo.boxShadow = `0 0 10px 1px ${color}`;
  burbuja.boxShadow = `0 0 10px 1px ${color}`;
  medidor.height = `${temperatura}%`;
}

function actualizarTemperatura() {
  fetch("http://localhost:192/temp")
    .then((r) => r.text())
    .then((data) => {
      console.log(data);
      const temp = parseInt(data);
      aplicarEstilos(temp);
    })
    .catch((err) => console.error(err));
}

actualizarTemperatura();

setInterval(actualizarTemperatura, 1000);
